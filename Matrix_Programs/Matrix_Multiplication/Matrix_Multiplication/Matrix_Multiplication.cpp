/*
C++ Random Learning Programs
By J RAJAN
For Learners
Title: Matrix Multiplication [3 x 3]
*/

#include <iostream>
using namespace std;

int main() 
{
    int A[3][3], B[3][3], result[3][3] = { 0 };

    cout << "Enter the elements of Matrix A:\n";

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter the elements of Matrix B:\n";

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cin >> B[i][j];
        }
    }

    // Matrix multiplication
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            for (int k = 0; k < 3; k++) 
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant Matrix after multiplication:\n";
    
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
