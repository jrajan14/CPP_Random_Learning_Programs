/*
C++ Random Learning Programs
By J RAJAN
For Learners
Title: NUMBER SWAPPING WITHOUT USING THIRD VARIABLE
*/

#include <iostream>

using namespace std;

void main()
{
    cout << "NUMBER SWAPING WITHOUT USING THIRD VARIABLE";
    
    cout << "\nEnter 2 Numbers : ";
    int A;
    int B;

    //Input
    cout << "\nA : ";
    cin >> A;
    cout << "B : ";
    cin >> B;

    //Original Display
    cout << "\nA = " << A;
    cout << "\nB = " << B;

    //Swap Logic
    A = A + B;
    B = A - B;
    A = A - B;

    //Swapped Display
    cout << "\n\nAfter Swapping : ";
    cout << "\nA = " << A;
    cout << "\nB = " << B;

}
