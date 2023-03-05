/*
C++ Random Learning Programs
By J RAJAN
For Learners
Title: Leap Year Check
(Most Accurate leap year program till now [maybe haha])
*/


/********************************************************************************
LEAP YEAR occurs because a single day is NOT exactly 24 hours long.
It is roughly 23 hours 56 Minutes 4 seconds long
This doesn't sound much. But it adds up every day
and make every year roughly 6 hours longer.
So, in 4 years, we have an extra day. Which we adjust as february 29th every 4 years.
However, A tropical year is not exactly 6 hours long.
It's roughly 5 hours 48 minutes and 45 seconds longer.
So, we don't need leap year every 4 years.
This is adjusted every 100 years, but it is needed again every 400 years.
************************************************************************************/

#include <iostream>

using namespace std;
int main()
{
    cout << "Leap Year Check\n";

    cout << "\nEnter a year to check if it's Leap year or Not";
    cout << "\nYear : ";
    int year;
    cin >> year;

    bool leap;
    // Leap year occurs every 400 years
    if (year % 400 == 0) {
        leap = true;
    }
    // Every 100th year is NOT leap year but every 400th year is.
    else if (year % 100 == 0) {
        leap = false;
    }
    // Every 4th year is Leap year except the 100th year, but 400th year is again Leap year
    else if (year % 4 == 0) {
        leap = true;
    }
    // Any other year is NOT a leap year
    else {
        leap = false;
    }
    
    //Printing Appropriately
    if (year < 0)
    {
        cout << "\nLeap year was introduced in 46 BC in Julian Calendar.";
        cout << "\nInitial leap years were 45 BC, 42 BC, 39 BC, 36 BC, 33 BC, 30 BC, 27 BC, 24 BC, 21 BC, 18 BC, 15 BC, 12 BC, 9 BC";
        cout << "\nProper leap year system was implemented in 1582 in Gregorian Calendar";
    }
    else if(year > 0)
    {
        if (year >= 1 && year < 8)
        {
            cout << "\nFirst Leap year of AD was 8 AD";
        }
        else if (year >= 8)
        {
            if (leap == true)
            {
                cout << year << " is a LEAP YEAR";
            }
            else if (leap == false)
            {
                cout << year << " is NOT a LEAP YEAR";
            }
        }
    }
    else
    {
        cout << "\nWe never had a year ZERO";
        cout << "\nAfter 1 BC, we had 1 AD";
    }

}

/*
* Leap year system is NOT SUPER ACURATE.
* Due to the earth rotating on it's own exis and revolution around the sun,
* there are very tiny changes that affects how long a day and a year will be.
* All these add up or get subtracted over the course of few years, sometimes several years, 
* even hundred years or maybe even millions of years. 
* According to the above program, year 4000 will be a leap year.
* But Who knows....
*/