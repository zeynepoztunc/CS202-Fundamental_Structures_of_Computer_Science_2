/**
* Title: AVL Trees
* Author: Zeynep Selcen Öztunç
* ID: 21902941
* Section : 1
* Assignment : 3
* Description : Source code file for a dictionary tree
*/
#include <fstream>
#include "Dictionary23Tree.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
void Dictionary23Tree::search(string word, int& numComparisons, bool& found)const {
    found = false;
    numComparisons = 0;
	searchHelper(word,root,found,numComparisons);
}
void Dictionary23Tree::search(string queryFile, string outputFile) const
{
    int max = 0;//maximum number of comparisons
    double average = 0;//average number of comparisions
    double sum = 0;//sum of the comparisons
    int numOfQueries = 0;//number of queries
    int numComparisons = 0;//number of comparisons
    bool found;//whether the word is found
    string comparisons = " ";//string that holds the number of comparisons

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
void Dictionary23Tree::searchHelper(string word, TriNode* search,
	bool& isFound, int& numComparisons)const {
    if (size == 0) {
        isFound == 0;
        return;
    }

    //while the node is not null
    while (search) {
       
        //if the node is a two node
        if (search->isTwoNode()) {
            if (search->smallItem == word) {
                numComparisons++;
                isFound = 1;
                return;
            }
            else if(search->smallItem > word) {
                numComparisons++;
                search = search->leftChildPtr;
            }
            else {
                numComparisons++;
                search = search->midChildPtr;
            }
        }
        //if the node is a three node
        else {
            if (search->smallItem == word) {
                numComparisons++;
                isFound = 1;
                return;
            }
            if (search->smallItem > word) {
                numComparisons++;
                search = search->leftChildPtr;
            }
            else {
                //could not find it in the small item
                numComparisons++;
                if (search->largeItem == word) {
                    numComparisons++;
                    isFound = 1;
                    return;
                }
                
                else if (search->smallItem < word && search->largeItem > word) {
                    numComparisons++;
                    search = search->midChildPtr;
                }
                else {
                    numComparisons++;
                    search = search->rightChildPtr;
                 }
            }
            
        }
    }
}
void Dictionary23Tree::split(TriNode* node1, TriNode* node2,
    TriNode* node3, TriNode* node4, TriNode* curr, string key ){

    //arrange the items 
    string firstItem = curr->smallItem;
    string secondItem = curr->largeItem;
    string thirdItem ="";

    //cout << "smaller item for split is: " << firstItem << endl;
    //cout << "larger item for split is: " << secondItem << endl;

    //if the new item is smaller then the firstItem item of the node
   //min will be the parent node
    if (key < firstItem) {
        thirdItem = secondItem;//large item is the largest
        secondItem = firstItem;//firstItem is in the middle
        firstItem = key;//new item is the smallest
    }

    //if the new item is smaller than the large item of the node but larger than the firstItem
    else if (key < secondItem) {
        thirdItem = secondItem;//previous large item will be the max
        secondItem = key;//new item is gonna be in the middle
    }

    //if the new item is the largest
    else {
        thirdItem = key;
    }

    //new children nodes that represent the left and right child of the new splitted node
    TriNode* newChild1 = new TriNode;//new child node (smaller)
    TriNode* newChild2 = new TriNode;//new child node (larger)

    TriNode* newParent;
    if (curr == this->root) {
        newParent = new TriNode;
    }
    else {
        newParent = curr->parent;
    }

    //their parents is p
    newChild1->parent = newParent;
    newChild2->parent = newParent;

    //rearrange the pointers based on split
    newChild1->smallItem = firstItem;
    newChild2->smallItem = thirdItem;


    //if the node to be splitted is not a leaf node
    if (curr->isLeaf == 0) {
        newChild1->leftChildPtr = node1;
        newChild1->midChildPtr = node2;

        //set the new childs as the parents of node
        node1->parent = newChild1;
        node2->parent = newChild1;

        newChild2->leftChildPtr = node3;
        newChild2->midChildPtr = node4;


        //set the new childs as the parents of node
        node3->parent = newChild2;
        node4->parent = newChild2;

        //the new childs are not leafs 
        newChild1->isLeaf = 0;
        newChild2->isLeaf = 0;
    }

    //if the current node is a root node
    if (curr == this->root) {
        //this is the new root of the tree
        this->root = newParent;

        newParent->smallItem = secondItem;//mid item
        //cout << "NEW ROOT ALERT" << p->smallItem << endl;

        newParent->leftChildPtr = newChild1;//small child
        newParent->midChildPtr = newChild2;//large child
        newParent->isLeaf = false;//not a leaf anymore
    }
    //if theres room in the parent
    else if (!newParent->has2Items) {

        if (secondItem < newParent->smallItem) {
            newParent->largeItem = newParent->smallItem;
            newParent->smallItem = secondItem;

            newParent->rightChildPtr = newParent->midChildPtr;
            newParent->midChildPtr = newChild2;
            newParent->leftChildPtr = newChild1;
        }
        //if the new item is larger than the item on its parent
        else {
            newParent->largeItem = secondItem;
            newParent->midChildPtr = newChild1;

            newParent->rightChildPtr = newChild2;
        }
        newParent->has2Items = true;
    }

    //if the parent node is full, split again
    else {
        if (curr == newParent->rightChildPtr) {
            split(newParent->leftChildPtr, newParent->midChildPtr, newChild1, newChild2,newParent, secondItem );
           
        }
        else if (curr == newParent->midChildPtr) {
            split(newParent->leftChildPtr, newChild1, newChild2, newParent->rightChildPtr, newParent, secondItem);
        }
        //if the current node is a left child
        else {
            split(newChild1, newChild2, newParent->midChildPtr, newParent->rightChildPtr,newParent, secondItem);
        }
    }
   
    delete curr;
}
//finds the proper leaf for inserting an item
TriNode* Dictionary23Tree:: findLeaf(TriNode*&n, string &word) {

    //find the leaf to for insertion
    while (!n->isLeaf) {
        if (word < n->smallItem) {
            n = n->leftChildPtr;
        }
        //look at its middle children
        else if (!n->has2Items || word < n->largeItem) {
            n = n->midChildPtr;
        }
        else {
            n = n->rightChildPtr;
        }
    }
    //return n;
    //if (!n->leaf) {
    //
    //    if (word < n->smallItem) {
    //        findLeaf(n->leftChildPtr,word);
    //    }
    //     //look at its middle children
    //    else if (!n->has2Items || word < n->largeItem) {
    //        findLeaf(n->midChildPtr,word);

    //    }
    //    else {
    //        findLeaf(n->rightChildPtr,word);
    //    }
    //}
    //else {
      return n;
    //}
}

void Dictionary23Tree:: insert(string word){
   
    //check whether the tree contains any items
    if (root == NULL) {

        this->root = new TriNode;//create the first node

        //put the word in the small item of the node
        this->root->smallItem = word;

        this->size++;//increment the size
        return;
    }
    TriNode* insertionLeaf = this->root;

    //find the proper leaf node for insertion using a helper function
    findLeaf(insertionLeaf, word);
    
    //if the leaf node is full
    if (insertionLeaf->has2Items) {
        //cout << "the word to be splitted is: " << word << endl;
        split(NULL, NULL, NULL, NULL,insertionLeaf, word);
    }

    //if is not full (has only one item) 
    else {
        //if the word is bigger than the item in the node
        if (word > insertionLeaf->smallItem) {

            //set the word as the large item
            insertionLeaf->largeItem = word;
            //cout << "larger word is inserted: " << word << endl;
        }

        //if the word is smaller than the item in the node
        else if (word < insertionLeaf->smallItem){
  
            //now the item in the node is the large item
            insertionLeaf->largeItem = insertionLeaf->smallItem;
            insertionLeaf->smallItem = word;//word is the small item
            //cout << "smaller word is inserted: " << word << endl;

        }
        //after the insertion the node is full
        insertionLeaf->has2Items = true;
    }
    this->size++;
}
//destructor
Dictionary23Tree::~Dictionary23Tree() {
    destructorHelper(root);
}

//destructor helper
void Dictionary23Tree::destructorHelper(TriNode* node) {
    if (node != NULL) {
        destructorHelper(node->leftChildPtr);
        destructorHelper(node->midChildPtr);
        destructorHelper(node->rightChildPtr);

        //deletes the node
        delete node;
        node = NULL;
    }
}

