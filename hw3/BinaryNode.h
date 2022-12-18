/**
* Title: AVL Trees
* Author: Zeynep Selcen Öztunç
* ID: 21902941
* Section : 1
* Assignment : 3
* Description : Header file for a binary node
*/
#ifndef BinaryNode_h
#define BinaryNode_h
#include <stdio.h>
#include <string>
using namespace std;

class BinaryNode {     

public:
    BinaryNode();
    BinaryNode(const string& nodeItem, BinaryNode* leftPtr = NULL,BinaryNode* rightPtr = NULL);
    BinaryNode* leftChildPtr;    
    BinaryNode* rightChildPtr;
    int height;
    string item;

    friend class DictionaryBST;
    friend class DictionaryAVLTree;
};

#endif 