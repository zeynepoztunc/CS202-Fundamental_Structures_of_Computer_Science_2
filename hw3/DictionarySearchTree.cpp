/**
* Title: AVL Trees
* Author: Zeynep Selcen Öztunç
* ID: 21902941
* Section : 1
* Assignment : 3
* Description : Source code file for the dictionary search tree class, which is a
* super class of other trees
*/
#include "DictionarySearchTree.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Search tree implementation for the dictionary
//Constructor that constructs the dictionary from the input file
DictionarySearchTree::DictionarySearchTree(string dictionaryFile) {
	ifstream file;
	file.open(dictionaryFile.c_str());
	string line;

	if (file.is_open()) {
		while (getline(file, line)) {
			string str = line.c_str();
			insert(str);
		}
		file.close();
	}
};

//Inserts the given word into the dictionary
void DictionarySearchTree::insert(string word) {};
//Searches the given word in the dictionary, and returns the number
//of comparisons made and whether the word is found or not
void DictionarySearchTree::search(string word, int& numComparisons, bool& found) const {};
//Searches all words in the query file in the dictionary, and
//summarizes the results in the output file
void DictionarySearchTree::search(string queryFile, string outputFile) const {};
DictionarySearchTree::~DictionarySearchTree() {};

