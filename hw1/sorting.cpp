/*
* Title: Sorting and Algorithm Efficiency
* Author: Zeynep Selcen Öztunç
* ID: 21902941
* Section: 1
* Assignment: 1
* Description: this file contains sorting functions as well as helper functions
*/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include "sorting.h"
using namespace std;

void bubbleSort(int a[],const int size,int &compCount, int &moveCount){
    bool sorted=false;
    for(int i = 1;i<size && !sorted;i++){
        sorted=true;
        for(int temp=0;temp<size-i;temp++){
            int newTemp=temp+1;

            if(a[temp]>a[newTemp]){
                swap(a[temp],a[newTemp]);
                moveCount= moveCount + 3;//swap function makes 3 data moves
                sorted=false;
            }
            compCount++;
        }
    }
}
void merge(int *a,int first,int mid,int last,int &compCount, int &moveCount){
    int *tempAr=new int[99999];
    int first1= first;
    int last1=mid;
    int first2=mid+1;
    int last2=last;
    int index =first1;
    for(;(first1<=last1)&&(first2<=last2);++index){
        if(a[first1]<a[first2]){
            tempAr[index]=a[first1];
            ++first1;
        }
        else{
            tempAr[index]=a[first2];

            ++first2;
        }
        moveCount++;
        compCount++;
    }
     //if one of the arrays end, put remaining items to temp
        for(;first1<=last1;++first1,++index){
            tempAr[index]=a[first1];
            moveCount++;
        }
        for(;first2<=last2;first2++,index++){
            tempAr[index]=a[first2];
            moveCount++;
        }
        //put the elements in the temp to the original array
        for(index = first;index<=last;index++){
            a[index]=tempAr[index];
            moveCount++;
        }
        delete [] tempAr;

}
void newMergeSort(int *arr, int first, int last, int &compCount, int &moveCount){

    if(first<last){
        int mid = (first+last)/2;

        newMergeSort(arr,first,mid,compCount,moveCount);
        newMergeSort(arr,mid+1,last,compCount,moveCount);
        merge(arr,first,mid,last,compCount,moveCount);
    }
}
void mergeSort(int *arr,const int size, int &compCount, int &moveCount){
    newMergeSort(arr,0,size-1,compCount,moveCount);

}

void partition(int *arr, int start, int end, int &pivotIndex, int &compCount, int &moveCount){
    int lastS1=start;
    int pivot= arr[start];
    moveCount++;//assignment
    int firstUnknown= start+1;

    for(; firstUnknown <= end; ++firstUnknown){
            //if element is less than pivot
            if(arr[firstUnknown]<=pivot){
                ++lastS1;
                swap(arr[firstUnknown],arr[lastS1]);
                moveCount = moveCount + 3; //swap
            }
            compCount++;
    }
    swap(arr[start],arr[lastS1]);
    moveCount = moveCount+3;//swap
    pivotIndex = lastS1;
}

void newQuickSort(int *arr, int first, int last, int &compCount, int &moveCount){
    int pivotIndex;
    if(first<last){
        partition(arr,first,last,pivotIndex,compCount,moveCount);
        newQuickSort(arr,first,pivotIndex-1,compCount,moveCount);
        newQuickSort(arr,pivotIndex+1,last,compCount,moveCount);
    }
}
void quickSort(int *arr, const int size, int &compCount, int &moveCount){
   newQuickSort(arr,0,size-1,compCount,moveCount);
}

void displayArray( const int *arr1,int size){
    //display the contents of the array
    for(int i = 0;i<size;i++){
        //if it is the last element of the array, move to next line
        if(i == size-1){
            cout<<arr1[i]<< endl;
        }
        else{
            cout<<arr1[i]<< " ";
        }
    }
}
void swap(int &a,int &b){
    //swaps the values of a and b
    int temp = a;
    a=b;
    b=temp;
}
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, const int size){
    srand((int)time(0));
    for(int i = 0;i<size;i++){
        int randomNumber= rand();//gets a random number

        //all arrays are identical
        arr1[i]=randomNumber;
        arr2[i]=randomNumber;
        arr3[i]=randomNumber;
    }
}
void ascend(int *arr,const int size){
    //sorts the array in ascending order
    int xVal;//temp to hold the x value
    int x,y;
    for(x=0;x<size;x++)
	{
		for(y=x+1;y<size;y++)
		{
		    //if the value of the item with the smaller index is larger
			if(arr[x]>arr[y])
			{
			    //swap elements
				xVal =arr[x];
				arr[x]=arr[y];
				arr[y]=xVal;
			}
		}
	}
}
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size){
    //creates random arrays
    createRandomArrays(arr1,arr2,arr3,size);

    //calls the ascend function to sort them in ascending order
    ascend(arr1,size);
    ascend(arr2,size);
    ascend(arr3,size);
}
void descend(int *arr,const int size){
    //sorts the array in descending order
    int xVal;
    int x,y;
    for(x=0;x<size;x++)
	{
		for(y= x+1; y<size; y++)
		{
		     //if the value of the item with the smaller index is smaller
			if(arr[x]<arr[y])
			{
			    //swap elements
				xVal  =arr[x];
				arr[x]=arr[y];
				arr[y]=xVal;
			}
		}
	}
}
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size){
    //creates random arrays
   createRandomArrays(arr1,arr2,arr3,size);

    //calls the descend function to sort them in descending order
   descend(arr1,size);
   descend(arr2,size);
   descend(arr3,size);
}

string printedAnalysis(int type,int* arr,int size){
    clock_t start;
    int moveCount=0;
    int compCount=0;
    stringstream a_stream ;
    string analysis = "";

    //if the sorting type is bubble sort
    if(type==0){

        //calculate the time it takes to bubble sort the array
        start = clock();
        bubbleSort(arr, size, compCount, moveCount);
        start = clock() - start;
        double timeElapsed = (double) start * 1000 / CLOCKS_PER_SEC;

        //print the calculated type
        a_stream << to_string(size) << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;
        analysis = a_stream.str();
    }
    //if the sorting type is merge sort
    else if(type==1){

        //calculate the time it takes to merge sort the array
        start = clock();
        mergeSort(arr, size, compCount, moveCount);
        start = clock() - start;
        double timeElapsed = (double) start * 1000 / CLOCKS_PER_SEC;

        //print the calculated type
        a_stream << to_string(size) << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;
        analysis = a_stream.str();

    }
    //if the sorting type is quick sort
    else if(type==2){

        //calculate the time it takes to quick sort the array
        start = clock();
        quickSort(arr, size, compCount, moveCount);
        start = clock() - start;
        double timeElapsed = (double) start * 1000 / CLOCKS_PER_SEC;

        //print the calculated type
        a_stream << to_string(size) << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;
        analysis = a_stream.str();
    }
     return analysis;
}
void resultArray(string *arr,int size){

    //initialize variables
    string perf1="";
    string perf2="";
    string perf3="";
    string perf4="";
    string perf5="";
    string perf6="";
    string perf7="";
    string perf8="";
    string perf9="";

    //bubble sort
    int *arr1 = new int[size];// random
    int *arr2 =  new int[size]; // ascending
    int *arr3 =  new int[size];//descending

    //merge sort
    int *arr4 = new int[size];//random
    int *arr5 =  new int[size];//ascending
    int *arr6 =  new int[size];//descending

    //quick sort
    int *arr7 = new int[size];//random
    int *arr8 =  new int[size];//ascending
    int *arr9 =  new int[size];//descending

    //calls the random array function for bubble merge and quick sort
    createRandomArrays(arr1, arr4, arr7,  size);// creates three identical random arrays

    //get the analysis of the random arrays for the given size
    perf1 = printedAnalysis(0,arr1, size);
    perf2 = printedAnalysis(1,arr4, size);
    perf3 = printedAnalysis(2,arr7, size);

    //calls the ascending array function for bubble merge and quick sort
    createAscendingArrays(arr2, arr5, arr8,  size); // create three identical random arrays

    //get the analysis of the ascending arrays
    perf4 = printedAnalysis(0,arr2, size);
    perf5 = printedAnalysis(1, arr5, size);
    perf6 = printedAnalysis(2,arr8, size);

    //calls the descending array function for bubble merge and quick sort
    createDescendingArrays(arr3, arr6, arr9,  size); // create three identical descending arrays

    //get the analysis of the descending arrays
    perf7 = printedAnalysis(0,arr3, size);
    perf8 = printedAnalysis(1,arr6, size);
    perf9 = printedAnalysis(2,arr9, size);

    //put each performance in an array
    //random arrays
    arr[0] = perf1;
    arr[1] = perf2;
    arr[2] = perf3;

    //ascending arrays
    arr[3] = perf4;
    arr[4] = perf5;
    arr[5] = perf6;

    //descending arrays
    arr[6] = perf7;
    arr[7] = perf8;
    arr[8] = perf9;

    // delete those arrays
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
    delete [] arr5;
    delete [] arr6;
    delete [] arr7;
    delete [] arr8;
    delete [] arr9;
}

void performanceAnalysis(){

     string analysis[12][9];//this array will hold the analysis values for all arrays

    //array with given input sizes
    int arraySizes[12]={4000, 8000, 12000, 16000, 20000,
    24000, 28000, 32000, 36000, 40000, 44000, 48000};


    for (int x = 0; x < 12; x++) {
        string performances[9];//this array holds the performances of each sorting algorithm

        //calls the result array function which calculates the performances
        resultArray(performances,arraySizes[x]);

        //fills the analysis array
        for (int y = 0; y < 9; y++) {
            analysis[x][y] = performances[y];//merge bubble quick
        }
    }

    //prints the analysis for random arrays
    cout<<"--------------------------------"<<endl;
    cout<<"Random Arrays"<<endl;
    cout<<"--------------------------------"<<endl;

    //prints the analysis for bubble sort for random arrays
    cout << "Analysis of Bubble Sort" << endl;
    cout << "Array size" << setw(25) << "Elapsed time" << setw(25) << "compCount" << setw(25) << "moveCount" << endl;
    for (int x = 0; x < 12; x++) {

        cout << analysis[x][0] << endl;
    }

    //prints the analysis for merge sort for random arrays
    cout << "------------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "Array size" << setw(25) << "Elapsed time" << setw(25) << "compCount" << setw(25) << "moveCount" << endl;
    for (int x = 0; x < 12; x++) {

        cout << analysis[x][1] << endl;// random MERGE
    }

    //prints the analysis for quick sort for random arrays
    cout << "------------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    cout << "Array size" << setw(25) << "Elapsed time" << setw(25) << "compCount" << setw(25) << "moveCount" << endl;
    for (int x = 0; x < 12; x++) {

        cout << analysis[x][2] << endl;// random QUICK
    }

    //prints the analysis for ascending arrays
    cout<<"--------------------------------"<<endl;
    cout<<"Ascending Arrays"<<endl;
    cout<<"--------------------------------"<<endl;

    //prints the analysis for bubble sort for ascending arrays
    cout << "Analysis of Bubble Sort" << endl;
    cout << "Array size" << setw(25) << "Elapsed time" << setw(25) << "compCount" << setw(25) << "moveCount" << endl;
    for (int x = 0; x < 12; x++) {

        cout << analysis[x][3] << endl;// ascending bubble
    }

    //prints the analysis for merge sort for ascending arrays
      cout << "------------------------------------" << endl;
      cout << "Analysis of Merge Sort" << endl;
      cout << "Array size" << setw(25) << "Elapsed time" << setw(25) << "compCount" << setw(25) << "moveCount" << endl;
      for (int x = 0; x < 12; x++) {

        cout << analysis[x][4] << endl;// ascending merge

    }
    //prints the analysis for quick sort for ascending arrays
      cout << "------------------------------------" << endl;
      cout << "Analysis of Quick Sort" << endl;
      cout << "Array size" << setw(25) << "Elapsed time" << setw(25) << "compCount" << setw(25) << "moveCount" << endl;
      for (int x = 0; x < 12; x++) {
        cout << analysis[x][5] << endl;// ascending quick
    }

    //prints the analysis for descending arrays
    cout<<"--------------------------------"<<endl;
    cout<<"Descending Arrays"<<endl;
    cout<<"--------------------------------"<<endl;

    //prints the analysis for bubble sort for descending arrays
     cout << "Analysis of Bubble Sort" << endl;
    cout << "Array size" << setw(25) << "Elapsed time" << setw(25) << "compCount" << setw(25) << "moveCount" << endl;
    for (int x = 0; x < 12; x++) {

        cout << analysis[x][6] << endl;// descending bubble
    }

     cout << "------------------------------------" << endl;
     cout << "Analysis of Merge Sort" << endl;
     cout << "Array size" << setw(25) << "Elapsed time" << setw(25) << "compCount" << setw(25) << "moveCount" << endl;
     //prints the analysis for merge sort for descending arrays
      for (int x = 0; x < 12; x++) {

        cout << analysis[x][7] << endl;// descending merge

    }
     //prints the analysis for quick sort for descending arrays
     cout << "------------------------------------" << endl;
     cout << "Analysis of Quick Sort" << endl;
     cout << "Array size" << setw(25) << "Elapsed time" << setw(25) << "compCount" << setw(25) << "moveCount" << endl;
      for (int x = 0; x < 12; x++) {

        cout << analysis[x][8] << endl;// descending quick
    }
}


