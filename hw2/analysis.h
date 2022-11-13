/**
* Title : Binary Search Trees
* Author : Zeynep Selcen Öztunç
* ID: 21902941
* Section : 01
* Assignment : 2
* Description : Header file for analysis of an array
*/
#ifndef ANALYSIS_H_INCLUDED
#define ANALYSIS_H_INCLUDED

    void randomArray(int*& arr,int size);//creates a random array
    void shuffleArray(int* arr,int size);//shuffles an array
    void createTree(int* arr,int size,BST& tree);//creates a binary tree from an array
    void deleteTree(int* arr,int size,BST& tree);// deletes a given binary tree
    void heightAnalysis();// prints an analysis of a binary tree

#endif // ANALYSIS_H_INCLUDED
