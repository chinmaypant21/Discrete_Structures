#include <iostream>
using namespace std;
/*Tower of Hanoi using Recursion*/
void TOH(int tower_size,int start, int destination)
{
    if (tower_size == 1)
    {
        cout<<"From "<<start<<" -> "<<destination<<endl;
        return;
    }

    int middle = 6 - (start + destination);
    TOH(tower_size-1,start,middle);
    cout<<"From "<<start<<" -> "<<destination<<endl;
    TOH(tower_size-1,middle,destination);
}

int main()
{
    int tower_size = 3;
    TOH(tower_size,1,3);
}
