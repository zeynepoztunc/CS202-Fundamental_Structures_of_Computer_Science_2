/**
* Title : Binary Search Trees
* Author : Zeynep Selcen Öztunç
* ID: 21902941
* Section : 01
* Assignment : 2
* Description : Header file for a tree node
*/
#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;

class TreeNode {            // node in the tree
private:
    TreeNode();
    //TreeNode(const int& nodeItem,TreeNode *left,TreeNode *right);
     TreeNode(const int& nodeItem,
        TreeNode *left,
        TreeNode *right)
        :item(nodeItem),leftChildPtr(left),rightChildPtr(right) {}
    int item;       // data portion
    TreeNode *leftChildPtr;  // pointer to left child
    TreeNode *rightChildPtr; // pointer to right child

    friend class BST;
};

#endif // TREENODE_H_INCLUDED
