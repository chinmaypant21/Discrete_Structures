/* Program to calculate Permutation and Combination for an input value n and r using
recursive formula of nCr and nPr */

#include<iostream>
using namespace std;

int nCr(int n,int r){
    if(r==0 || n==r)
       return 1;
    else
        return nCr(n-1,r-1)+nCr(n-1,r);   
}

int nPr(int n,int r){
    if(r>n) return 0;
    else{
        if(r==n || r==0) return 1;
        else return nPr(n-1,r-1)*n;
    }    
}

int main(){
    int n=0,r=0;
    cout<<"\n\t\tProgram to calculate Permutation and Combination for an input value n and r using recursive formula of nCr and nPr"<<endl;
    cout<<"Enter n and r: ";
    cin>>n>>r;
    cout<<"\n The value of nCr is: "<<nCr(n,r);
    cout<<"\n The value of nPr is: "<<nPr(n,r);
    return 0;    
}