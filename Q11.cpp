//Write a Program to calculate Permutation and Combination for an input value n and r using recursive formula of nCr and nPr .
#include <iostream>
using namespace std;
int main()
{
    long long factorial=1, numerator, denominator;
    int perm,comb, n, r, i=1, sub;
    cout<<"Enter the Value of n: ";
    cin>>n;
    cout<<"Enter the Value of r: ";
    cin>>r;
    while(i<=n)
    {
        factorial = i*factorial;
        i++;
    }
    numerator = factorial;                    // n!
    sub = n-r;
    factorial = 1;
    i = 1;
    while(i<=sub)
    {
        factorial = i*factorial;
        i++;
    }
    denominator = factorial;                // (n-r)!
    perm = numerator/denominator;
    cout<<"\nPermutation (nPr) = "<<perm;
    cout<<endl;
    
     factorial = 1;
    i = 1;
    while(i<=r)
    {
        factorial = i*factorial;
        i++;
    }
    denominator = (factorial*denominator);
    comb = numerator/denominator;
    cout<<"\nCombination (nCr) = "<<comb;
    cout<<endl;
    return 0;
}
