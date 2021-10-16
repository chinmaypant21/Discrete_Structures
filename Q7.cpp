/*                      BINARY SEARCH USING RECURSION AND ITERATION               */
#include<iostream>
#include<algorithm>
using namespace std;

class Array{
    public: int arr[10];
            int size;
};

int BinSearch(Array A,int key){

    int l=0,h=A.size-1,mid=0;
    while(l<=h){
        mid=(l+h)/2;
        if(A.arr[mid]==key)
            return mid;
        else if(key<A.arr[mid])
            h=mid-1;
        else
            l=mid+1;       
    }
    return -1;
}

int RBinSearch(Array A,int l,int h,int key){

    int mid=0;
    while(l<=h){
        mid=(l+h)/2;
        if(A.arr[mid]==key)
            return mid;
        else if(key<A.arr[mid])
            return RBinSearch(A,l,mid-1,key);
        else
            return RBinSearch(A,mid+1,h,key);
    }
    return -1;
}

int main(){
    int key,flag=0;
    Array A;
    cout<<"\nEnter the size of the array: ";
    cin>>A.size;
    cout<<"\nEnter the Array: ";
    for(int i=0;i<A.size;i++) cin>>A.arr[i];

    for(int i=0;i<A.size;i++){
        if(A.arr[i+1]<A.arr[i])
            flag=1;
    }
    if(flag==1) {
        cout<<"\nWARNING: Entered array is not sorted, Your array is being sorted... ";
        sort(A.arr,A.arr+A.size);
        cout<<"\n Sorted Array is:  ";
        for(int i=0;i<A.size;i++) cout<<A.arr[i]<<" ";
    }
    cout<<"\nEnter the element you want to search for: "<<endl;
    cin>>key;
    cout<<"\n1. The key is present at index(using Iteration): "<<BinSearch(A,key);
    cout<<"\n2. The key is present at index(using Recursion): "<<RBinSearch(A,0,A.size,key)<<endl;
    return 0;
}