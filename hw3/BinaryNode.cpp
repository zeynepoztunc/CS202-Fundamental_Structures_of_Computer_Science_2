/**
* Title: AVL Trees
* Author: Zeynep Selcen Öztunç
* ID: 21902941
* Section : 1
* Assignment : 3
* Description : Source code file for a binary node
*/
#include <stdio.h>
#include "BinaryNode.h"
BinaryNode::BinaryNode() { 
    height = 0;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
    item = "";
}

BinaryNode::BinaryNode(const string& nodeItem,
    BinaryNode* left, BinaryNode* right) {
    item = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
    height = 0;
}
