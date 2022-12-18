/**
* Title: AVL Trees
* Author: Zeynep Selcen Öztunç
* ID: 21902941
* Section: 1
* Assignment: 3
* Description: Header file for the dictionary search tree class, which is a
* super class of other trees
*/
#ifndef DictionarySearchTree_h
#define DictionarySearchTree_h

#include <iostream>
#include <string>
#include <fstream>

using namespace  std;

//Search tree implementation for the dictionary
class DictionarySearchTree {
public:
	//Constructor that constructs the dictionary from the input file
	DictionarySearchTree(string dictionaryFile);
	//Destructor
	virtual ~DictionarySearchTree();
	//Inserts the given word into the dictionary
	virtual void insert(string word);
	//Searches the given word in the dictionary, and returns the number
	//of comparisons made and whether the word is found or not
	virtual void search(string word, int& numComparisons, bool& found) const;
	//Searches all words in the query file in the dictionary, and
	//summarizes the results in the output file
	virtual void search(string queryFile, string outputFile) const;

private:
};
#endif