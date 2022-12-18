/**
* Title: AVL Trees
* Author: Zeynep Selcen Öztunç
* ID: 21902941
* Section: 1
* Assignment: 3
* Description: Header file for the dictionary AVL Tree class
*/
#include "DictionarySearchTree.h"
#include "BinaryNode.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class DictionaryAVLTree : public DictionarySearchTree {
public:
	DictionaryAVLTree(string dictionaryFile) : DictionarySearchTree(dictionaryFile) {

		size = 0;
		this->root = NULL;

		ifstream file;
		file.open(dictionaryFile.c_str());
		string line;

		if (file.is_open()) {

			while (getline(file, line)) {
				string str = line.c_str();

				//cout << "passing to insert function " <<str << endl;
				insert(str);
			}
			file.close();
		}
		
	};
	~DictionaryAVLTree();
	BinaryNode* root;//root node
	int size;//size of the AVL tree

	void insert(string word);
	void search(string word, int& numComparisons, bool& found) const;
	void search(string queryFile, string outputFile)  const;

	//helper functions
	BinaryNode* insertHelper(BinaryNode* root, string& word);
	void searchHelper(string word, BinaryNode* search, bool& isFound, int& numComparisons)const;
	void destructorHelper(BinaryNode* node);

	int height(BinaryNode* node);//gets the height of the tree
	int getBalance(BinaryNode* node);//gets the balance of tree
	int max(int a, int b);//gets the maximum of two numbers

	//BinaryNode* leftRotation(BinaryNode* x);
	BinaryNode* leftleftRotate(BinaryNode* node);//function for when there is a left left imbalance
	BinaryNode* leftrightRotate(BinaryNode* node);//function for when there is a left right imbalance
	BinaryNode* rightrightRotate(BinaryNode* node);//function for when there is a right right imbalance
	BinaryNode* rightleftRotate(BinaryNode* node);//function for when there is a right left imbalance
};