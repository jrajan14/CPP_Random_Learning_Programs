/*
C++ Random Learning Programs
By J RAJAN
For Learners
Title: FIBONACCI SERIES
*/

#include <iostream>

using namespace std;

void main() 
{
    int limit, first = 0, second = 1, next;

    cout << "Enter the limit: ";
    cin >> limit;

    cout << "\nFIBONACCI SERIES : ";
    cout << first << " " << second << " ";

    next = first + second;

    while (next <= limit) 
    {
        cout << next << " ";
        first = second;
        second = next;
        next = first + second;
    }
    cout << "\n";
}