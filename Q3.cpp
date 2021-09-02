#include <iostream>
using namespace std;
/*
Create a class RELATION, use Matrix notation to represent a relation. Include functions to
check if a relation is reflexive, Symmetric, Anti-symmetric and Transitive. Write a Program
to use this class.
*/

class Relation
{
    public:
    int *set,size,relation_size;
    int **relation_pair;

    Relation(int size,int relation_size):relation_pair(new int*[relation_size]),set(new int[size]){
        this->size = size;
        this->relation_size = relation_size;
        for(int i = 0; i < relation_size; i++) relation_pair[i] = new int[2];
    };

    void setInput()
    {
        for(int i = 0; i < size; i++)
        {
            cout<<"Enter element "<<i+1<<": ";
            cin>>set[i];
        }
    }

    void setRelations()
    {
        cout<<"\nEnter Relation pairs\n";
        for(int i=0; i < relation_size; i++)
        {
            cout<<"Enter element "<<i<<" 1: ";
            cin>>relation_pair[i][0];

            cout<<"Enter element "<<i<<" 2: ";
            cin>>relation_pair[i][1];

        }
    }

    bool isReflexive()
    {
        bool check_reflexive = false;
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < relation_size; j++)
            {
                if((set[i]==relation_pair[j][0]) && (set[i]==relation_pair[j][1]))
                {
                    check_reflexive = true;
                    break;
                }
            }
            if(!check_reflexive) return false;
            check_reflexive = false;
        }
        return true;
    }

    bool isSymmetric()
    {
        bool check_symmetric = false;
        for(int i = 0; i < relation_size; i++)
        {
            for(int j = 0; j < relation_size; j++)
            {
                if(relation_pair[i][0] == relation_pair[j][1] && relation_pair[i][1] == relation_pair[j][0])
                {
                    check_symmetric = true;
                    break;
                }
            }
                if(!check_symmetric) return false;
                check_symmetric = false;
        }
        return true;
    }

    bool isAntiSymmetric()
    {
        bool check_anti_symmetric = true;
        for(int i = 0; i < relation_size; i++)
        {
            for(int j = 0; j < relation_size; j++)
            {
                if(relation_pair[i][0] == relation_pair[i][1]) break;
                if(relation_pair[i][0] == relation_pair[j][1] && relation_pair[i][1] == relation_pair[j][0])
                {
                    check_anti_symmetric = false;
                    break;
                }
            }
                if(!check_anti_symmetric) return false;
                check_anti_symmetric = true;
        }
        return true;
    }

    bool isTransitive()
    {
        bool check_transitive = false;
        for(int i = 0; i < relation_size; i++)
        {
            for(int j = 0; j < relation_size; j++)
            {
                    if(relation_pair[i][1] == relation_pair[j][0])
                    {
                        for(int k = 0; k < relation_size; k++)
                        {
                            if(relation_pair[i][0] == relation_pair[k][0] && relation_pair[j][1] == relation_pair[k][1])
                            {check_transitive=true; break;}
                        }

                        if(!check_transitive) return false;
                        check_transitive=false;
                    }
            }
        }
        return true;
    }
};

int main()
{
    Relation r(3,5);
    cout<<"Enter elements in the Set\n";
    r.setInput();
    r.setRelations();
    cout<<"Checking for Reflexive:\n";
    cout<<r.isReflexive();
    cout<<"\nChecking forSymmetric\n";
    cout<<r.isSymmetric();
    cout<<"\nChecking for Anti Symmetric\n";
    cout<<r.isAntiSymmetric();
    cout<<"\nChecking for Transitive\n";
    cout<<r.isTransitive();
    return 0;
}