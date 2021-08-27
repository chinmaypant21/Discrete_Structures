#include <iostream>
using namespace std;

class Set
{
    int *set,size;
    public:
    Set(int size):set(new int[size]){this->size=size;};

    void insertElement()
    {
        for(int i=0;i<size;i++)
        {
            cout<<"Enter element "<<i+1<<": ";
            cin>>set[i];
        }
    }

 /* bool checkDuplicate(int element,int currentIndex)
    {
        for(int i=0;i<currentIndex;i++)
        {
            if (element == set[i])
                return true;
        }
        return false;
    }*/

    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<set[i]<<", ";
        }
    }

    bool hasSubset(Set s)
    {
        if (s.size > this->size) return false;

        for(int i=0;i<s.size;i++)
        {
            bool isPresent = false;
            for(int j=0;j<(this->size);j++)
            {
                if (s.set[i] == set[j]) {isPresent = true; break;};
            }
            if (!isPresent) return false;
        }
        return true;
    }

    Set unionWith(Set s2)
    {
        Set temp(size+(s2.size));
        int index;

        for(index=0;index<size;index++)
        {
            temp.set[index] = set[index];
        }

        for(int j=0;j<s2.size;j++)
        {
            bool append = 1;
            for(int k=0;k<size;k++)
            {
                if (s2.set[j] == temp.set[k])
                {
                    append = 0;
                    break;
                }
            }
            if(append)
            {
                temp.set[index++] = s2.set[j];
            }
        }

        temp.size = index;
        return temp;
    }

    Set intersectionWith(Set s2)
    {
        Set temp(size);
        int index=0;
        for(int i=0;i<s2.size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(s2.set[i] == set[j])
                {
                    temp.set[index] = s2.set[i];
                    index++;
                    break;
                }
            }
        }
        temp.size = index;
        return temp;
    }

    Set differenceWith(Set s2)
    {
        Set difference_set(size);
        bool append=1;
        int numElements=0;
        
        for(int j=0;j<size;j++)
        {
            for(int i=0;i<s2.size;i++)
            {
                if(set[j] == s2.set[i])
                {
                    append=0;
                    break;
                }
            }
            if(append) difference_set.set[numElements++] = set[j];
            append=1;
        }
        difference_set.size = numElements;
        return difference_set;
    }

    Set symmetricDifferenceWith(Set s2)
    {
        Set part1(size),part2(s2.size);
        part1 = this->differenceWith(s2);
        part2 = s2.differenceWith(*this);
        return (part1.unionWith(part2));
        /*
            A symmetric_diff B = (A-B) U (B- A)
        */
    }

    Set getComplement(Set U)
    {
        // Set duplicateSet(size);
        // duplicateSet.set = set;
        return U.differenceWith(*this);
    }

    void cartesianProduct(Set s2)
    {
        cout<<"{";
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < s2.size; j++)
            {
                cout<<"("<<set[i]<<", "<<s2.set[j]<<"), ";
            }
            cout<<endl;
        }
        cout<<"}";
    }
};

int main()
{
    Set universal(10);

    int set_size = 4;
    Set s1(set_size),s2(set_size);

    cout<<"Enter Universal Set\n";
    universal.insertElement();

    cout<<"\nEnter Set 1\n";
    s1.insertElement();

    cout<<"\nEnter Set2\n";
    s2.insertElement();

    if(s1.hasSubset(s2))
    {
        cout<<"\nS2 is subset of S1";
    };

    if(s2.hasSubset(s1))
    {
        cout<<"\nS1 is subset of S2\n";
    };

    cout<<"\n\nUnion of sets: \n";
    s1.unionWith(s2).display();

    cout<<"\n\nIntersection of sets: \n";
    s1.intersectionWith(s2).display();

    cout<<"\n\nDifference between sets S1 and S2: \n";
    s1.differenceWith(s2).display();

    cout<<"\n\nSymmetric Difference between sets: \n";
    s1.symmetricDifferenceWith(s2).display();

    cout<<"\n\nComplement of Set 1: \n";
    s1.getComplement(universal).display();

    cout<<"\n\nComplement of Set 2: \n";
    s2.getComplement(universal).display();

    cout<<"\n\nCartesian Product of sets: \n";
    s1.cartesianProduct(s2);

    return 0;
}
