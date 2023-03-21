/*
C++ Random Learning Programs
By J RAJAN
For Learners
Title: POWERSET 
(Make all possible sub-sets from a given set)
*/

#include <iostream>

using namespace std;

void PowerSet(int set[], int n);

void main() 
{
    int set[] = {1, 2, 3, 4, 5 };           //Pre-defininh elements. Can be takes as input
    int n = sizeof(set) / sizeof(set[0]);   //Getting number of elements in array
    PowerSet(set, n);                       //Make subsets;
}

void PowerSet(int set[], int n)
{
    int Subsets = pow(2, n);           //Total number of sub-sets to be created
    for (int i = 0; i < Subsets; i++) 
    {
        for (int j = 0; j < n; j++)    //This loop runs per subset
        {
            if (i & (1 << j))
            {
                cout << set[j] << " "; //Print each element of subset
            }
        }
        cout << "\n"; //End of line for new Sub-set
    }
}
