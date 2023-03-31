/*
C++ Random Learning Programs
By J RAJAN
For Learners
Title: THREE NUMBER INTER-CHANGING WITHOUT USING FOURTH VARIABLE
*/

#include<iostream>

using namespace std;

void main()
{
	int a, b, c;
	cout << "Enter number A : ";
	cin >> a;
	cout << "\n";

	cout << "Enter number B : ";
	cin >> b;
	cout << "\n";

	cout << "Enter number C : ";
	cin >> c;
	cout << "\n";


	a = a ^ b ^ c;
	b = a ^ b ^ c;
	c = a ^ b ^ c;
	a = a ^ b ^ c;

	cout << "Swapped Numbers are A: " << a << ", B: " << b << ", C: " << c;
}