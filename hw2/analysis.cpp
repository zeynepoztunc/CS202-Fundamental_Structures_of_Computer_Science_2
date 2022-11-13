#include <random>
#include <chrono>
#include <algorithm>
#include <iterator>
#include "BST.h"
#include "analysis.h"
/**
* Title : Binary Search Trees
* Author : Zeynep Selcen Öztunç
* ID: 21902941
* Section : 01
* Assignment : 2
* Description : Includes the functions for analysis of an array
*/
using namespace std;
void randomArray(int*& arr,int size){
    arr = new int[size];
    srand((unsigned) time(0));

    //fills the array with random elements using rand()
    for(int i = 0; i < size; i++){
       arr[i] = rand();
    }
}
void shuffleArray(int* arr,int size){

    //calls the shuffle function from the standart library
    random_shuffle(arr, arr + (size));

}
void createTree(int* arr,int size,BST& tree){
    tree= BST();

    printf("\n-----------------------------------------\n");

    printf("%s\t%s\n", "Tree Size","Tree Height");

    printf("-----------------------------------------\n");
    for(int i = 0; i < size; i++){

       //at each 1500 insertion, prints the number of nodes and the height of the tree
       if(i % 1500 == 0 && i>0 ){
          printf("%d\t\t%d\n", tree.numOfNodes(), tree.getHeight());
       }
       //inserts items one by one
       tree.insert(arr[i]);
    }
    printf("%d\t\t%d\n", tree.numOfNodes(), tree.getHeight());
}
void deleteTree(int* arr,int size,BST& tree){
    printf("\n-----------------------------------------\n");

    printf("%s\t%s\n", "Tree Size","Tree Height");

    printf("-----------------------------------------\n");

    //at each 1500 deletion, prints the number of nodes and the height of the tree
    for(int i = 0; i <size; i++){
       if(i % 1500 == 0  && i>0){
          printf("%d\t\t%d\n", tree.numOfNodes(), tree.getHeight());
       }
       //deletes the items one by one
       tree.deleteKey(arr[i]);
    }
    printf("%d\t\t%d\n", tree.numOfNodes(), tree.getHeight());
}

void heightAnalysis(){
    int size=30000;
    int* arr;

    //creates a random array
    randomArray(arr,size);

    //inserts the array items to a binary tree
    printf("Part f - Analysis of BST height - part 1");
    BST tree=BST();
    createTree(arr,size,tree);

    //shuffles the array
     shuffleArray(arr,size);

    //deletes the tree and prints the tree size vs height
    cout<<endl;
    printf("Part f - Analysis of BST height - part 2");
    deleteTree(arr,size,tree);

    //deallocates array
    delete arr;
    arr=NULL;
}
