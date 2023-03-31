/*
C++ Random Learning Programs
By J RAJAN
For Learners
Title: Rotating Cube
*/

#include <iostream>
#include <cmath>
#include <windows.h>
#include <conio.h>

using namespace std;

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;

struct Point
{
    float x, y, z;
};

struct Face
{
    int a, b, c, d;
};

Point cubeVertices[8] =
{
    {-1, -1, 1}, {1, -1, 1}, {1, 1, 1}, {-1, 1, 1}, //Front vertices
    {-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1} //Rear vertices
};

Face cubeFaces[6] = {
    {0, 1, 2, 3}, //Front face
    {1, 5, 6, 2}, //Right face
    {4, 5, 6, 7}, //Rear face
    {0, 4, 7, 3}, //Left face
    {3, 2, 6, 7}, //Top face
    {0, 1, 5, 4}  //Bottom face
};

void clearScreen()
{
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

void drawPixel(int x, int y, char c)
{
    COORD coord = { x, y };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, coord);
    cout << c;
}

void drawLine(int x1, int y1, int x2, int y2, char c)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (true)
    {
        drawPixel(x1, y1, c);

        if (x1 == x2 && y1 == y2)
        {
            break;
        }

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void drawCube()
{
    //Making Cube using dotted lines
    for (int i = 0; i < 6; i++)
    {
        int x1 = SCREEN_WIDTH / 2 + cubeVertices[cubeFaces[i].a].x * 10;
        int y1 = SCREEN_HEIGHT / 2 - cubeVertices[cubeFaces[i].a].y * 10;
        int x2 = SCREEN_WIDTH / 2 + cubeVertices[cubeFaces[i].b].x * 10;
        int y2 = SCREEN_HEIGHT / 2 - cubeVertices[cubeFaces[i].b].y * 10;

        drawLine(x2, y2, x1, y1, '.'); //Replace with some other character to better visuals

        x1 = SCREEN_WIDTH / 2 + cubeVertices[cubeFaces[i].b].x * 10;
        y1 = SCREEN_HEIGHT / 2 - cubeVertices[cubeFaces[i].b].y * 10;
        x2 = SCREEN_WIDTH / 2 + cubeVertices[cubeFaces[i].c].x * 10;
        y2 = SCREEN_HEIGHT / 2 - cubeVertices[cubeFaces[i].c].y * 10;

        drawLine(x1, y1, x2, y2, '.');

        x1 = SCREEN_WIDTH / 2 + cubeVertices[cubeFaces[i].c].x * 10;
        y1 = SCREEN_HEIGHT / 2 - cubeVertices[cubeFaces[i].c].y * 10;
        x2 = SCREEN_WIDTH / 2 + cubeVertices[cubeFaces[i].d].x * 10;
        y2 = SCREEN_HEIGHT / 2 - cubeVertices[cubeFaces[i].d].y * 10;

        drawLine(x1, y1, x2, y2, '.');

        x1 = SCREEN_WIDTH / 2 + cubeVertices[cubeFaces[i].d].x * 10;
        y1 = SCREEN_HEIGHT / 2 - cubeVertices[cubeFaces[i].d].y * 10;
        x2 = SCREEN_WIDTH / 2 + cubeVertices[cubeFaces[i].a].x * 10;
        y2 = SCREEN_HEIGHT / 2 - cubeVertices[cubeFaces[i].a].y * 10;

        drawLine(x1, y1, x2, y2, '.');
    }
}

int main()
{
    float theta = 0.0;
    while (true)
    {
        clearScreen();
        drawCube();

        for (int i = 0; i < 8; i++)
        {
            float x = cubeVertices[i].x;
            float y = cubeVertices[i].y * cos(theta) - cubeVertices[i].z * sin(theta);
            float z = cubeVertices[i].y * sin(theta) + cubeVertices[i].z * cos(theta);
            cubeVertices[i].x = x * cos(theta) + z * sin(theta);
            cubeVertices[i].y = y;
            cubeVertices[i].z = -x * sin(theta) + z * cos(theta);
        }
        theta += 0.05;
        Sleep(100);
    }
    return 0;
}