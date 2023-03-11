/*
C++ Random Learning Programs
By J RAJAN
For Learners
Title: Armstrong Number Check
*/

#include <iostream>

using namespace std;

void main()
{
    cout << "ARMSTRONG NUMBER CHECK";

    int num;
    int originalNum;
    int remainder; 
    int n = 0;
    int result = 0;

    cout << "\nEnter a positive number: ";
    cin >> num;
    originalNum = num;

    //Count the number of digits
    while (originalNum != 0)
    {
        originalNum /= 10;
        ++n;
    }

    originalNum = num;

    //Calculate the result
    while (originalNum != 0)
    {
        remainder = originalNum % 10;

        // Calculate power of individual digits
        int power = 1;
        for (int i = 1; i <= n; ++i)
        {
            power *= remainder;
        }

        result += power;

        originalNum /= 10;
    }

    // Check
    if (result == num)
    {
        cout << num << " is an ARMSTRONG number.\n";
    }
    else
    {
        cout << num << " is NOT an ARMSTRONG number.\n";
    }
}

