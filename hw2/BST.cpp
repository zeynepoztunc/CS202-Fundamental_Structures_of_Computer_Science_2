/**
* Title : Binary Search Trees
* Author : Zeynep Selcen Öztunç
* ID: 21902941
* Section : 01
* Assignment : 2
* Description : Source file for a binary tree
*/
#include <iostream>
#include <string>
#include "BST.h"
using namespace std;
BST::BST(){
    root=NULL;
}
//copy constructor
BST::BST(const BST& tree){
    root=tree.root;
}

BST::~BST(){
    destructorHelper(root);
}

void BST::destructorHelper(TreeNode* node){
    if(node!=NULL){
        destructorHelper(node->leftChildPtr);
        destructorHelper(node->rightChildPtr);

        //deletes the node
        delete node;
        node=NULL;
    }
}

bool BST::isEmpty(){
    return root==NULL;
}
int BST::getHeight(){
     return getHeightHelper(root);
}
int BST::getHeightHelper(TreeNode *node){
    int leftTree;
    int rightTree;
    if(node==NULL){
        return 0;
    }
    leftTree = getHeightHelper(node->leftChildPtr);
    rightTree = getHeightHelper(node->rightChildPtr);
    return (1+ max(leftTree,rightTree));
}
void BST::preorderTraverse(){
    preorder(root);
}
void BST::preorder(TreeNode *treePtr){
    if(treePtr!=NULL){
        cout << treePtr->item<<endl;
        preorder(treePtr->leftChildPtr);
        preorder(treePtr->rightChildPtr);
    }
}
void BST::inorderTraverse(){
    int size= getHeight();
    int* arr=new int[size];
    int index = 0;
    inorder(root,arr,index);

    delete [] arr;
    arr=NULL;
}
void BST::inorder(TreeNode *treePtr,int *&arr,int &index){
    //int i = 0;//index counter for the array
    if(treePtr!=NULL){
        inorder(treePtr->leftChildPtr,arr,index);

        arr[index]=treePtr->item;

        index++;
        inorder(treePtr->rightChildPtr,arr,index);
    }
}
void BST::postorderTraverse(){
    postorder(root);
}
void BST::postorder(TreeNode *treePtr){
    if(treePtr!=NULL){
        postorder(treePtr->leftChildPtr);
        postorder(treePtr->rightChildPtr);
        cout << treePtr->item<<endl;
    }
}
bool BST::insert(int key){
    return insertHelper(root,key);
}
bool BST::insertHelper(TreeNode*& node,int newItem){
    if(node==NULL){
        node= new TreeNode(newItem,NULL,NULL);
        return true;
    }
    else if(newItem < node->item&&newItem!=node->item){
            insertHelper(node->leftChildPtr,newItem);

    }
    else if(newItem>node->item && newItem!=node->item){
        insertHelper(node->rightChildPtr,newItem);
    }
    return false;
}
bool BST::deleteKey(int key){
    return deleteHelper(root, key);
}
bool BST::deleteHelper(TreeNode*& node,int newItem){
    //if the node is empty
    if(node==NULL){
        return false;
    }
    //if the key is found
    else if(node->item==newItem){
        deleteNodeItem(node);
        return true;
    }
    //if the key is smaller then the item in the node
    else if(node->item<newItem){
        deleteHelper(node->rightChildPtr,newItem);
    }
    //if the key is larger then the item in the node
    else if(node->item>newItem){
        deleteHelper(node->leftChildPtr,newItem);
    }
    return false;
}
// the function that actually deletes the nodes
void BST::deleteNodeItem(TreeNode*& node){
    TreeNode* delPtr;
    int replacementItem;

    //test for a leaf
    if(node->leftChildPtr==NULL &&node->rightChildPtr==NULL){
            delete node;
            node=NULL;
    }
    //test for no left child
    else if(node->leftChildPtr==NULL ){
        delPtr= node;
        node=node->rightChildPtr;
        delPtr->rightChildPtr=NULL;
        delete delPtr;
    }
    //test for no right child
    else if(node->rightChildPtr==NULL ){
        delPtr= node;
        node=node->leftChildPtr;
        delPtr->leftChildPtr=NULL;
        delete delPtr;
    }
    // test for two children
    else{
        processLeftmost(node->rightChildPtr,replacementItem);
        node->item=replacementItem;
    }
}
void BST::processLeftmost(TreeNode *&nodePtr, int& treeItem){
    TreeNode* delPtr;
    //if the left child pointer is empty
    if(nodePtr->leftChildPtr==NULL){
        treeItem=nodePtr->item;
        delPtr=nodePtr;
        nodePtr=nodePtr->rightChildPtr;
        delPtr->rightChildPtr=NULL;
        delete delPtr;
    }
    else{
        processLeftmost(nodePtr->leftChildPtr,treeItem);
    }
}
double BST::medianOfBST(){
    return medianHelper(root);
}
double BST::medianHelper(TreeNode*nodePtr){
    int num = numOfNodes();
    int index =0;
    int *newArr= new int[num];

    inorder(nodePtr,newArr,index);

    //put to items in the dynamic array to a temp array
    int array2[num];
    for(int i = 0;i<num;i++){
        array2[i]=newArr[i];
    }

    //delete the dynamically allocated array
    delete []newArr;
    newArr=NULL;

    //if the number of nodes is an even number
    if(num%2==0){
        return (array2[num/2]+array2[(num/2)-1])/2.0;
     }

    //if it is an odd number
    else{
         return array2[num/2];
    }
}
int BST::numOfNodes(){
   return numOfNodesHelper(root);
}
int BST::numOfNodesHelper(TreeNode* node){
     if(node==NULL){
        return 0;
    }
    return 1+ numOfNodesHelper(node->rightChildPtr)+ numOfNodesHelper(node->leftChildPtr);
}
void BST::rangeSearch(int a, int b){
    rangeSearchHelper(a, b, root);
}
void BST::rangeSearchHelper(int a,int b, TreeNode* node){

    if(node==NULL)
        return;

    //look for the left subtree
    if(a <= node->item )
    rangeSearchHelper(a, b,node->leftChildPtr);

    //if the item is in the range, print the item
    if ( a <= node->item && b >= node->item )
        cout<<node->item<<" ";

    //look for the right subtree
   if(b > node->item )
   rangeSearchHelper(a, b,node->rightChildPtr );
    return;
}


