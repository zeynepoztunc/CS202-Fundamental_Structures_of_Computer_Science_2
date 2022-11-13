/**
* Title : Binary Search Trees
* Author : Zeynep Selcen Öztunç
* ID: 21902941
* Section : 01
* Assignment : 2
* Description : Source file for a tree node
*/

#include "TreeNode.h"
#include <string>
#include <iostream>
    TreeNode::TreeNode(){}
    TreeNode::TreeNode(const int& nodeItem,
    TreeNode *left,TreeNode *right){
        item = nodeItem;
        leftChildPtr = left;
        rightChildPtr = right;
    }


