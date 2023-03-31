/*
C++ Random Learning Programs
By J RAJAN
For Learners
Title:TIC-TAC-TOE
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Pre-defined placeholders
vector<string> board = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

void display_board() {
    cout << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---------" << "\n";
    cout << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---------" << "\n";
    cout << board[6] << " | " << board[7] << " | " << board[8] << "\n";
}

bool place_marker(int position, string marker) 
{
    if (position < 1 || position > 9) 
    {
        return false;
    }
    if (board[position - 1] == "X" || board[position - 1] == "O") 
    {
        return false;
    }
    board[position - 1] = marker;
    return true;
}

//All possible winning conditions
bool check_win(string marker) 
{
    return ((board[0] == marker && board[1] == marker && board[2] == marker) ||
        (board[3] == marker && board[4] == marker && board[5] == marker) ||
        (board[6] == marker && board[7] == marker && board[8] == marker) ||
        (board[0] == marker && board[3] == marker && board[6] == marker) ||
        (board[1] == marker && board[4] == marker && board[7] == marker) ||
        (board[2] == marker && board[5] == marker && board[8] == marker) ||
        (board[0] == marker && board[4] == marker && board[8] == marker) ||
        (board[2] == marker && board[4] == marker && board[6] == marker));
}

//Check Tie
bool board_full_check() 
{
    for (int i = 0; i < 9; i++) {
        if (board[i] != "X" && board[i] != "O") {
            return false;
        }
    }
    return true;
}

void main() 
{
    cout << "TIC-TAC-TOE\n";
    cout << "Player 1 : X \nPlayer 2 : O\n";
    bool player1_turn = true;

    while (true) 
    {
        cout << "\n";
        display_board();

        int position;
        
        if (player1_turn) 
        {
            cout << "\nPlayer 1, Enter a Mark position : ";
        }
        else {
            cout << "\nPlayer 2, Enter a Mark position : ";
        }
        cin >> position;

        //Input validation
        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 9." << "\n";
            continue;
        }

        if (place_marker(position, player1_turn ? "X" : "O")) 
        {
            if (check_win(player1_turn ? "X" : "O")) 
            {
                display_board();
                if (player1_turn) 
                {
                    cout << "Player 1 wins!" << "\n";
                }
                else 
                {
                    cout << "Player 2 wins!" << "\n";
                }
                break;
            }
            else if (board_full_check()) 
            {
                display_board();
                cout << "It's a tie!" << "\n";
                break;
            }
            player1_turn = !player1_turn;
        }
        else 
        {
            cout << "Invalid position. Try again." << "\n";
        }
    }
}
