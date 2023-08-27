/*
C++ Random Learning Programs
By J RAJAN
For Learners
Title: Transpose of Matrix
*/

#include <iostream>
using namespace std;

int main() 
{
    int matrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int transpose[3][3];

    // Transposing the matrix
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            transpose[i][j] = matrix[j][i];
        }
    }

    // Printing the transposed matrix
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
