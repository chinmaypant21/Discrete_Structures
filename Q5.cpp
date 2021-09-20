#include <iostream>
using namespace std;
/* Fibonacci program using Recursion */

int fibonacci(int index)
{
    if(index==0 || index==1) return index;
    return fibonacci(index-1) + fibonacci(index-2);
}
int main()
{
    cout<<"Enter n: ";
    int n;
	cin>>n;
    for(int i=0;i<n;i++)
		cout<<fibonacci(i)<<" ";
}