/**
* Title: AVL Trees
* Author: Zeynep Selcen Öztunç
* ID: 21902941
* Section: 1
* Assignment: 3
* Description: Header file for the dictionary 2 3 tree class
*/
#include "DictionarySearchTree.h"
#include "BinaryNode.h"
#include "TriNode.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Dictionary23Tree : public DictionarySearchTree {
public:
	Dictionary23Tree(string dictionaryFile) : DictionarySearchTree(dictionaryFile) {

		size = 0;
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
	~Dictionary23Tree();//destructor
	TriNode* root;//root node
	int size;//size of the 23 tree

	void insert(string word);
	void search(string word, int& numComparisons, bool& found) const;
	void search(string queryFile, string outputFile)  const;

	//helper functions
	void destructorHelper(TriNode* node);
	void searchHelper(string word, TriNode* search, bool& isFound, int& numComparisons)const;
	void split(TriNode* first, TriNode* second, TriNode* third, TriNode* fourth, TriNode* curr,
			   string key);//function to split the nodes in the case of an overflow

	TriNode* findLeaf(TriNode*& n, string &word);//finds the leaf node for insertion

};