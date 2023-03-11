/*
C++ Random Learning Programs
By J RAJAN
For Learners
Title: Prime Number Check
*/

#include <iostream>

using namespace std;

void main()
{
    cout << "PRIME NUMBER CHECK";

    int num;
    bool PrimeFlag = true;

    cout << "\nEnter a positive number: ";
    cin >> num;

    if (num == 0 || num == 1)
    {
        cout << "\n 0 and 1 are NOT PRIME numbers";
    }
    else
    {
        for (int i = 2; i <= num / 2; ++i)
        {
            if (num % i == 0)
            {
                PrimeFlag = false;
                break;
            }
        }
    }

    if (PrimeFlag == true)
    {
        cout << num << " is a PRIME number.\n";
    }
    else
    {
        cout << num << " is NOT a PRIME number.\n";
    }
}
