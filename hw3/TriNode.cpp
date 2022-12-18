/**
* Title: AVL Trees
* Author: Zeynep Selcen Öztunç
* ID: 21902941
* Section : 1
* Assignment : 3
* Description : Source code file for a 2-3 Tree Node
*/
#include <stdio.h>
#include "TriNode.h"

//constructor
TriNode::TriNode() {

    //set the children pointers as null
    this->rightChildPtr = NULL;
    this->midChildPtr = NULL;
    this->leftChildPtr = NULL;

    //init the items inside the node
    this->smallItem = "";
    this->largeItem = "";

    //set leaf as true and full as false
    this->isLeaf = true;
    this->has2Items = false;
}
bool TriNode::isTwoNode() const
{
    if (smallItem != "" && largeItem == "")
        return true;
    else return false;
}
