/* Program To Implement Insertion sort using random generated values
?Taking random values as input in the array from 1-9
 */

#include<iostream>
#include<time.h>
using namespace std;

int counter=0;
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        counter++;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            counter++;
        }
        arr[j + 1] = key;
        for(int k=0;k<n;k++) cout<<arr[k]<<" ";
        cout<<endl;
    }
}
 
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout<<arr[i] << " ";
    cout<<endl;
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
    insertionSort(arr, n);
    cout<<"Sorted array: \n";
    printArray(arr, n);
    cout<<"\nThe no. of comparisons are: "<<counter;
    counter=0;
    delete[] arr;
    }while(n>0);
    return 0;
}