/**
* Title: AVL Trees
* Author: Zeynep Selcen Öztunç
* ID: 21902941
* Section: 1
* Assignment: 3
* Description: Header file for the dictionary binary search tree class
*/
#include "DictionarySearchTree.h"
#include "BinaryNode.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class DictionaryBST : public DictionarySearchTree {
public:
	DictionaryBST(string dictionaryFile) : DictionarySearchTree(dictionaryFile) {

		this->root = NULL;
		ifstream file;
		file.open(dictionaryFile.c_str());
		string line;

		if (file.is_open()) {

			while (getline(file, line)) {
				//cout << "getting the file" << endl;
				string str = line.c_str();
				//cout << str << endl;
				insert(str);
			}
			file.close();
		}
	};
	~DictionaryBST(); //destructor

	BinaryNode* root;
    void insert(string word);
    void search(string word, int& numComparisons, bool& found) const;
    void search(string queryFile, string outputFile)  const;

	//helper functions
	void insertHelper(BinaryNode*& root, string &word);
	void searchHelper(string word, BinaryNode* root,bool& isFound, int& numComparisons)const;
	void destructorHelper(BinaryNode* node);
};