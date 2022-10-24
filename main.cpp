/*
* Title: Sorting and Algorithm Efficiency
* Author: Zeynep Selcen Öztunç
* ID: 21902941
* Section: 1
* Assignment: 1
* Description: main file for testing the code
*/
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "sorting.h"
#include <iomanip>
using namespace std;

int main()
{
    cout<<"hello "<<endl;
    // the bubble sort
    cout<<"Bubble Sort:---------------------------------------------------"<<endl;
    int newArray[] = { 40, 25, 29, 56, 37, 27, 24, 32, 79, 12, 35, 38, 23, 31,33, 26};
    int keyCount=0;
    int moveCount=0;
    bubbleSort(newArray,16,keyCount,moveCount);
    cout<<"Number of key comparisons in the bubble sort algorithm is: " << keyCount <<endl;
    cout<<"Number of data moves in the bubble sort algorithm is: " << moveCount <<endl;
    cout<<"The contents of the array after bubble sort is: "<<endl;

    displayArray(newArray,16);

    //test the merge sort
    cout << "Merge Sort:---------------------------------------------------"<< endl;
    int newArray2[] = { 40, 25, 29, 56, 37, 27, 24, 32, 79, 12, 35, 38, 23, 31,33, 26};
    keyCount=0;
    moveCount=0;
    mergeSort(newArray2,16,keyCount,moveCount);
    cout<<"Number of key comparisons in the merge sort algorithm is: " << keyCount <<endl;
    cout<<"Number of data moves in the merge sort algorithm is: " << moveCount <<endl;
    cout<<"The contents of the array after merge sort is: "<<endl;
    displayArray(newArray2,16);

    //test the quick sort
    cout << "Quick Sort:---------------------------------------------------"<< endl;
    int newArray3[] = { 40, 25, 29, 56, 37, 27, 24, 32, 79, 12, 35, 38, 23, 31,33, 26};
    keyCount=0;
    moveCount=0;
    quickSort(newArray3,16,keyCount,moveCount);
    cout<<"Number of key comparisons in the quick sort algorithm is: " << keyCount <<endl;
    cout<<"Number of data moves in the quick sort algorithm is: " << moveCount <<endl;
    cout<<"The contents of the array after quick sort is: "<<endl;
    displayArray(newArray3,16);

    //performance analysis
    performanceAnalysis();
    return 0;
};
