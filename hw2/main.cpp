/**
* Title : Binary Search Trees
* Author : Zeynep Selcen Öztunç
* ID: 21902941
* Section : 01
* Assignment : 2
* Description : main function
*/
#include "BST.h"
#include "analysis.h"

using namespace std;
int main(){
    //create a binary search tree
    BST tree= BST();

    //insert following numbers
    tree.insert(30);
    tree.insert(40);
    tree.insert(35);
    tree.insert(20);
    tree.insert(50);
    tree.insert(45);
    tree.insert(10);
    tree.insert(25);
    tree.insert(5);
    tree.insert(15);

    // delete following numbers
    tree.deleteKey(35);
    tree.deleteKey(45);
    tree.deleteKey(50);


     //get the height of the tree
    cout<<"The height of the tree is: "<< tree.getHeight()<<endl;

    //Finds the median of numbers by using medianOfBST method
    cout<<"Median of the tree is: "<<tree.medianOfBST()<<endl;

    //finds the numbers in a range
    int n=5;
    int m=43;
    cout<<"The numbers between "<<n <<" and " << m << " are: "<<endl;
    tree.rangeSearch(5,43);


    //gets the height analysis of the tree
    cout<<"\n-------------Height Analysis-------------"<<endl;
    heightAnalysis();
    return 0;
};

