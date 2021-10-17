/* Program To Implement Bubble sort using random generated values
?Taking random values as input in the array from 1-9
 */

#include<iostream>
#include <bits/stdc++.h>
#include<time.h>
using namespace std;

int counter=0;

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
            swap(arr[j], arr[j+1]);
        printArray(arr, n);
    }       
}
  

int main()
{
    srand(time(0));
    int n=0,choice;
    do{
    cout<<"\nEnter the size of the array: ";
    cin>>n;
    if(n==0) break;
    int *arr = new int[n];
    cout<<"\n 1. Take User input"<<"\n 2. Take random values"<<"\n Choose a desired option: ";
    cin>>choice; 
    switch(choice){
        case 1: cout<<"\nEnter the elements in the array: ";
                for(int i=0; i<n; i++) cin>>arr[i];
                break;
        case 2: cout<<"\nTaking random generated values..."<<endl;
                for(int i=0; i<n; i++) arr[i] = (rand() % 10) + 1;
                break;
        default: cout<<"\n Invalid input!!";        
    }
    bubbleSort(arr, n);
    cout<<"Sorted array: \n";
    printArray(arr, n);
    cout<<"\nThe no. of comparisons are: "<<counter;
    delete[] arr;
    }while(n>0);
    return 0;
}
 