/**
* Title: AVL Trees
* Author: Zeynep Selcen Öztunç
* ID: 21902941
* Section : 1
* Assignment : 3
* Description : Source code file for an AVL tree
*/
#include "DictionaryAVLTree.h"
#include <iomanip>

void DictionaryAVLTree::insert(string word)
{
    root = insertHelper(root, word);
}

void DictionaryAVLTree::search(string word, int& numComparisons, bool& found) const
{
    searchHelper(word, root, found, numComparisons);
}

void DictionaryAVLTree::search(string queryFile, string outputFile) const
{
    int max = 0;//maximum number of comparisons
    double average = 0;//average number of comparisions
    double sum = 0;//sum of the comparisons
    int numOfQueries = 0;//number of queries
    int numComparisons = 0;//number of comparisons
    bool found;//whether the word is found
    string comparisons="";//string that holds the num of comparisons

    ifstream file;
    ofstream output;
    file.open(queryFile.c_str());
    output.open(outputFile.c_str());
    string line;

    if (file.is_open()) {

        while (getline(file, line)) {
            numOfQueries++;//increment the number of queries

            string str = line.c_str();
            numComparisons = 0;
            found = 0;
            search(str, numComparisons, found);

            //printing the results in the output file
            output << str;
            int length = str.length();//length of the word
            output << setw(25 - length) << found << "  " << numComparisons << endl;

            //get the number of comparions in a string
            comparisons = comparisons + to_string(numComparisons) + " ";
        }
    }

    istringstream ss(comparisons);
    string compNum;

    //find the max number of comparsions and the sum
    while (ss >> compNum)
    {
        if (max < stoi(compNum)) {
            max = stoi(compNum);
        }
        sum = sum + stoi(compNum);
    }

    average = sum / numOfQueries;
    output << "Number of queries: " << numOfQueries << endl;
    output << "Maximum number of comparisons: " << max << endl;
    output << "Average number of comparisons: " << average << endl;

    file.close();
    output.close();
}

BinaryNode* DictionaryAVLTree::insertHelper(BinaryNode* node, string& word)
{
    //check whether the root is null
    if (node==NULL) {
        node = new BinaryNode(word,NULL,NULL);

        //cout << "The root is inserted " << word << endl;

        return node;
    }

    //check whether the word is smaller than the item on the root node
    if (word < node->item) {
        //cout << "smaller word no rotation " << word << endl;

        node->leftChildPtr = insertHelper(node->leftChildPtr, word);
    }
    //if the word is larger than the item on the root node
    else if (word > node->item) {
        //cout << "larger word no rotation " << word << endl;

        node->rightChildPtr = insertHelper(node->rightChildPtr, word);
    }
    //same item is not allowed
    else {
        return node;
    }

    //update height using the height() function
    node->height = 1 + max(height (node->leftChildPtr), height(node->rightChildPtr));
    //node->height = height(node);

    // get the balance factor
    int bln = getBalance(node);

    //if the node is imbalaced, there are four cases 
    
    //left left imbalance
    if (node->leftChildPtr!=NULL&& word < node->leftChildPtr->item && bln > 1) {
        //cout << "ll imbalance " << word << endl;

        //return rightRotation(node);
        return leftleftRotate(node);
    }

    //right right imbalance
    if (node->rightChildPtr != NULL && word > node->rightChildPtr->item && bln < -1) {

        //cout << "rr imbalance " << word << endl;

        //return leftRotation(node);
        return rightrightRotate(node);
    }

    //left right imbalance
    if (node->leftChildPtr != NULL &&word > node->leftChildPtr->item && bln>1) {

        //cout << "lr imbalance " << word << endl;

        //left rotate the left child of the node
       // node->leftChildPtr = leftRotation(node->leftChildPtr);

        // right rotate the node
        //return rightRotation(node);
        return leftrightRotate(node);
    }

    

    //right left imbalance
    if (node->rightChildPtr != NULL &&word < node->rightChildPtr->item && bln < -1) {

        //cout << "rl imbalance " << word << endl;

        //right rotate the right child of the node
        //node->rightChildPtr = rightRotation(node->rightChildPtr);

        // left rotate the node
        //return leftRotation(node);
        return rightleftRotate(node);

    }
      
    return node;
}
//returns the height of the node
int DictionaryAVLTree::height(BinaryNode* node)
{
    if (node == NULL) {
        return 0;
    }
    int leftTree = height(node->leftChildPtr);
    int rightTree = height(node->rightChildPtr);

    return 1 + max(leftTree, rightTree);
}

//gets the balance factor of node
int DictionaryAVLTree::getBalance(BinaryNode* node)
{
    //if the node is null, the tree is balanced
    if (node == NULL)
        return 0;
    //else return the difference of the heights of the tree
    return height(node->leftChildPtr) - height(node->rightChildPtr);
}

//a function that gets the maximum of two integers
int DictionaryAVLTree::max(int x, int y)
{
    return (x > y) ? x : y;
}

//rotation for a left left imbalance
BinaryNode* DictionaryAVLTree::leftleftRotate(BinaryNode* node) {
    BinaryNode* mid;
    mid = node->leftChildPtr;
    node->leftChildPtr = mid->rightChildPtr;
    mid->rightChildPtr = node;

    //update heights accordingly
    node->height = max(height(node->leftChildPtr), height(node->rightChildPtr)) + 1;
    mid->height = max(height(mid->leftChildPtr),height(mid->rightChildPtr)) + 1;

    return mid;
}

//rotation for a left right imbalance
BinaryNode* DictionaryAVLTree::leftrightRotate(BinaryNode* node) {
    BinaryNode* mid;
    mid = node->leftChildPtr;
    node->leftChildPtr = rightrightRotate(mid);

    //update heights accordingly
    node->height = max(height(node->leftChildPtr), height(node->rightChildPtr)) + 1;
    mid->height = max(height(mid->leftChildPtr), height(mid->rightChildPtr)) + 1;

    return leftleftRotate(node);
}

//rotation for a right right imbalance
BinaryNode* DictionaryAVLTree::rightrightRotate(BinaryNode* node) {
    BinaryNode* mid;
    mid = node->rightChildPtr;
    node->rightChildPtr = mid->leftChildPtr;
    mid->leftChildPtr = node;

    //update heights accordingly
    node->height = max(height(node->leftChildPtr), height(node->rightChildPtr)) + 1;
    mid->height = max(height(mid->leftChildPtr), height(mid->rightChildPtr)) + 1;

    return mid;
}

//rotation for a right left imbalance
BinaryNode* DictionaryAVLTree::rightleftRotate(BinaryNode* node) {
    BinaryNode* mid;
    mid = node->rightChildPtr;
    node->rightChildPtr = leftleftRotate(mid);

    //update heights accordingly
    node->height = max(height(node->leftChildPtr), height(node->rightChildPtr)) + 1;
    mid->height = max(height(mid->leftChildPtr), height(mid->rightChildPtr)) + 1;

    return rightrightRotate(node);
}


void DictionaryAVLTree::searchHelper(string word, BinaryNode* search, bool& isFound, int& numComparisons) const
{
    //if the root is null
    if (search == NULL) {
        return;
    }

    //if the word is smaller than the item on the current node
    else if (word < search->item) {

        numComparisons++;//increment the number count

        //look at its left child
        searchHelper(word, search->leftChildPtr, isFound, numComparisons);
    }

    //if the word is larger than the item on the current node
    else if (word > search->item) {

        numComparisons++;//increment the number count

        //look at its right child
        searchHelper(word, search->rightChildPtr, isFound, numComparisons);
    }

    //if the word is equal to the item on the current node
    else {
        numComparisons++;//increment the number count

        isFound = true;//the word is found
    }

}
DictionaryAVLTree::~DictionaryAVLTree() {
    destructorHelper(root);
}

void DictionaryAVLTree::destructorHelper(BinaryNode* node) {

    //find the node to be deleted
    if (node != NULL) {
        destructorHelper(node->leftChildPtr);
        destructorHelper(node->rightChildPtr);

        //deletes the node
        delete node;
        node = NULL;
    }
}
