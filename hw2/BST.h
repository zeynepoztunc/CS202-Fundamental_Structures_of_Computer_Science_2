/**
* Title : Binary Search Trees
* Author : Zeynep Selcen Öztunç
* ID: 21902941
* Section : 01
* Assignment : 2
* Description : Header class for a binary tree
*/
#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED


#include <stdio.h>
#include "TreeNode.h"

class BST{
public:
    // default constructor
    BST();
    BST(const BST& tree);

    //desctructor
    ~BST();

    //functions wanted in the homework
    bool insert(int key);
    bool deleteKey(int key);
    int getHeight();
    double medianOfBST();
    void rangeSearch(int a, int b);

    //traversals
    void preorderTraverse();
    void inorderTraverse();
    void postorderTraverse();


    //helpers
    void destructorHelper(TreeNode* node);//destructr helper function
    int getHeightHelper(TreeNode* node);//helper function to find the height of the tree
    int numOfNodesHelper(TreeNode* node);//helper function for finding the number of nodes
    bool insertHelper(TreeNode*& node, int item);//insert helper function
    bool deleteHelper(TreeNode*& node, int searchItem);// delete helper function
    void deleteNodeItem(TreeNode*& node);//deletes a node item
    void processLeftmost(TreeNode *&nodePtr, int& treeItem);//helper function for deleting a key
    void preorder(TreeNode* node);//preorder traversal helper function
    void inorder(TreeNode* node,int *&arr,int &index);//inorder traversal helper function
    void postorder(TreeNode* node);//postorder traversal helper function
    double medianHelper(TreeNode* node);//helper function to find median of the tree
    void rangeSearchHelper(int a,int b, TreeNode* node);////helper function to find keys in range
    bool isEmpty();// finds whether the tree is empty
    int numOfNodes();//finds the numbr of nodes

private:
    TreeNode* root;
};

#endif


