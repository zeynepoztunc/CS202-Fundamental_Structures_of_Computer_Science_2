/*
* Title: Sorting and Algorithm Efficiency
* Author: Zeynep Selcen Öztunç
* ID: 21902941
* Section: 1
* Assignment: 1
* Description: this is the header file for functions
*/
using namespace std;
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);
void printArray(int *arr, int size);
void newMergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
void performanceAnalysis();
void merge(int *arr, int start, int mid, int end, int &compCount, int &moveCount);
void partition(int *arr, int start, int end, int &pivotIndex, int &compCount, int &moveCount);
void swap(int &a, int &b);
void displayArray(const int *arr, const int size);
void newQuickSort(int *arr, int first, int last, int &compCount, int &moveCount);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
void performanceAnalysis();
void descend(int *arr,const int size);
void ascend(int *arr,const int size);
string printedAnalysis(int type,int* arr,int size);
void resultArray(string *arr,int size);


