#include <iostream>
using namespace std;

class Set
{
    int cardinality {};
    int elements[50] {};

    public:
    void addElements()
    {
        cout<<"\nEnter no. of elements";
        cin>>cardinality;

        for(int i = 0; i < cardinality; i++)
        {
            int n;cin>>n;
            if(!checkDuplicate(n,i))
            {
                elements[i] = n;
            }

            else
            {
                i--;
                cardinality--;
            }
            
        }
    }

    void displaySet()
    {
        for(int i=0; i<cardinality; i++)
        {
            cout<<elements[i]<<" ";
        }
        cout<<endl;
    }

    bool isMember(int a)
    {
        for(int i = 0; i < cardinality; i++)
        {
            if(elements[i] == a)
            return true;
        }
        return false;
    }

    bool checkDuplicate(int element,int currentIndex)
    {
        for(int i=0;i<currentIndex;i++)
        {
            if (element == elements[i])
                return true;
        }
        return false;
    }

    void powerSet(int current_index=0,string power_set_string = "")
    {
        if (current_index == (cardinality))
        {
            if(power_set_string=="") {power_set_string="{}";}
            cout<<power_set_string<<endl;
            return;
        }

        string appended_string = power_set_string+" "+to_string(elements[current_index]);
        powerSet(current_index+1,appended_string);
        powerSet(current_index+1,power_set_string);

    }
};

int main()
{
    Set s;
    s.addElements();
    cout<<"\n\nIt is"<<(s.isMember(3) ? " member ":" not a member ")<<"of the set.\n\n";
    //Enter the number to check in place of 3
    cout<<"\nPowerset of Given set:\n";
    s.powerSet();
    return 0;
}
