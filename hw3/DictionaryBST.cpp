/**
* Title: AVL Trees
* Author: Zeynep Selcen Öztunç
* ID: 21902941
* Section: 1
* Assignment: 3
* Description: Header file for the dictionary binary search tree class
*/
#include <stdio.h>
#include <string>
#include "DictionaryBST.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>  
using namespace std;

void DictionaryBST::insert(string word) {
	insertHelper(root, word);
}

void DictionaryBST::insertHelper(BinaryNode*& root, string& word) {

	if (root == NULL) {
		root = new BinaryNode(word, NULL, NULL);
	}
    //if the new item is smaller than the item on the node
    else if (word < root->item && word != root->item) {
        insertHelper(root->leftChildPtr, word);

    }
    //if the new item is larger than the item on the node
    else if (word > root->item && word != root->item) {
        insertHelper(root->rightChildPtr, word);
    }
    //if the new item already exists in the tree
    return;
}
void DictionaryBST::search(string word, int& numComparisons, bool& found) const{
    searchHelper(word,root,found,numComparisons);
};
void DictionaryBST::searchHelper(string word, BinaryNode* search,
    bool& isFound, int& numComparisons)const {

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
      
void DictionaryBST::search(string queryFile, string outputFile) const{

    int max=0;//maximum number of comparisons
    double average=0;//average number of comparisions
    double sum = 0;//sum of the comparisons
    int numOfQueries = 0;//number of queries
    int numComparisons = 0;//number of comparisons
    bool found;//whether the word is found
    string comparisons = "";//string to store the comparisons

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
            output<< setw(25-length) << found << "  " << numComparisons << endl;

            //get the number of comparions in a string
            comparisons = comparisons + std::to_string(numComparisons) + " ";

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
        //cout << compNum << "\n";
    }
    
    average = sum / numOfQueries;
    output << "Number of queries: " << numOfQueries << endl;
    output << "Maximum number of comparisons: " << max << endl;
    output << "Average number of comparisons: " << average << endl;

    file.close();
    output.close();
}
DictionaryBST::~DictionaryBST() {
    destructorHelper(root);
}

void DictionaryBST::destructorHelper(BinaryNode* node) {
    if (node != NULL) {
        destructorHelper(node->leftChildPtr);
        destructorHelper(node->rightChildPtr);

        //deletes the node
        delete node;
        node = NULL;
    }
}

