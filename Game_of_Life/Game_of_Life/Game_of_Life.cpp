/*
C++ Random Learning Programs
By J RAJAN
For Learners
Title: Game Of Life
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

//DIMENSIONS
const int ROWS = 60;
const int COLS = 60;

//Number of Generations
const int GENERATIONS = 1000;

//Display 2D Grid
void printGrid(vector<vector<int>>& grid) 
{
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            if (grid[i][j] == 1) 
            {
                cout << "# "; //Visual Character (Living)
            }
            else 
            {
                cout << "  "; //Hidden Character (Dead)
            }
        }
        cout << endl;
    }
    cout << endl;
}

//Next generation
void updateGrid(vector<vector<int>>& current, vector<vector<int>>& next) 
{
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            int neighbors = 0;
            for (int x = -1; x <= 1; x++) 
            {
                for (int y = -1; y <= 1; y++) 
                {
                    if (x == 0 && y == 0) continue;
                    int row = (i + x + ROWS) % ROWS;
                    int col = (j + y + COLS) % COLS;
                    neighbors += current[row][col];
                }
            }
            if (current[i][j] == 1) 
            {
                if (neighbors < 2 || neighbors > 3) 
                {
                    next[i][j] = 0;
                }
                else 
                {
                    next[i][j] = 1;
                }
            }
            else 
            {
                if (neighbors == 3) 
                {
                    next[i][j] = 1;
                }
                else 
                {
                    next[i][j] = 0;
                }
            }
        }
    }
}

void main() 
{
    //Initialize grid
    vector<vector<int>> current(ROWS, vector<int>(COLS, 0));
    vector<vector<int>> next(ROWS, vector<int>(COLS, 0));
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            current[i][j] = rand() % 2;
        }
    }

    //Simulate
    for (int t = 0; t < GENERATIONS; t++) 
    {
        cout << "Generation : " << t << endl;
        printGrid(current);
        updateGrid(current, next);
        this_thread::sleep_for(chrono::milliseconds(100)); //Time intervel between 2 generations in millisecconds
        cout << "\033[2J\033[1;1H";                        //Clear Screen / Shift all contents up
        swap(current, next);
    }
}
