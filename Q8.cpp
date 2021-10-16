/* Write a Program to implement Bubble Sort. Find the number of comparisons during each
pass and display the intermediate result. Use the observed values to plot a graph to analyse
the complexity of algorithm.
?Taking random values as input in the array from 1-9
 */

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
using namespace std;

int counter=0;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++){
        counter++;
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
        printArray(arr, n);
    }       
}
  

int main()
{
    srand(time(0));
    int n=0;
    do{
    cout<<"\nEnter the size of the array: ";
    cin>>n;
    if(n==0) break;
    int *arr = new int[n];
    //cout<<"\nEnter the elements in the array: ";
    //for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<n; i++) arr[i] = (rand() % 10) + 1;
    bubbleSort(arr, n);
    cout<<"Sorted array: \n";
    printArray(arr, n);
    cout<<"\nThe no. of comparisons are: "<<counter;
    delete[] arr;
    }while(n>0);
    return 0;
}
 