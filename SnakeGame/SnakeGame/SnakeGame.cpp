#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;

int lvl;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int lengthTail;
enum eMovement{LEFT, UP, DOWN, RIGHT, STOP = 0};
eMovement mov;


void Setup() {
    gameOver = false;
    mov = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw() {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
    
    //top of the map
    for (int i = 0; i < width+2; i++) {
        cout << "#";
    }cout << endl;

    // snake, food, tail and other sides of the map
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "#";
            }

            if (i == y && j == x) {
                cout << "O";

            }else if (i == fruitY && j == fruitX) {
                cout << "F";
            }else {
                bool print = false;
                for (int k = 0; k < lengthTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {

                        cout << "o";
                        print = true;
                    }
                }

                if (!print) {
                    cout << " ";
                }
            }

            if (j == width - 1) {
                cout << "#";
            }
        }cout << endl;
    }

    //bottom of the map
    for (int i = 0; i < width+2; i++) {
        cout << "#";
    }cout << endl;

    cout << "Score: " << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'w':
            if (mov == DOWN) {
                break;
            }
            mov = UP;
            break;
        case 'a':
            if (mov == RIGHT) {
                break;
            }
            mov = LEFT;
            break;
        case 'd':
            if (mov == LEFT) {
                break;
            }
            mov = RIGHT;
            break;
        case 's':
            if (mov == UP) {
                break;
            }
            mov = DOWN;
            break;
        case 'o':
            gameOver = true;
            break;
        }
    }
}

void Logic() {
    // tail of the snake using array
    for (int i = lengthTail; i >= 0; i--)
    {
        tailX[i] = tailX[i - 1];
        tailY[i] = tailY[i - 1];
    }
    tailX[0] = x;
    tailY[0] = y;

    switch (mov) 
    {
    case UP:
        y--;
        break;

    case LEFT:
        x--;
        break;

    case RIGHT:
        x++;
        break;

    case DOWN:
        y++;
        break;

    default:
        break;
    }

    //making snake appear on the other side of the map
    if (x >= width)
        x = x - width;
    if (x < 0)
        x = x + width;
    if (y >= height)
        y = y - height;
    if (y < 0)
        y = y + height;

    // snake meeting its tail
    for (int i = 0; i < lengthTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameOver = true;
            cout << "GAME OVER" << endl;
        }
    }

    //location of food
    if (x == fruitX && y == fruitY) {
        score += 1;
        fruitX = rand() % width;
        fruitY = rand() % height;
        lengthTail++;
    }
    
}

int main()
{
    //difficulty of the game
    cout << "Choose the difficulty: " << endl;
    cin >> lvl;
    if (lvl == 1) {
        Setup();
        while (!gameOver) {
            Draw();
            Input();
            Logic();
            Sleep(100);
        }
    }
    else if (lvl == 2) {
        Setup();
        while (!gameOver) {
            Draw();
            Input();
            Logic();
            Sleep(30);
        }
    }
    else if (lvl == 3) {
        Setup();
        while (!gameOver) {
            Draw();
            Input();
            Logic();
            Sleep(5);
        }
    }
    else {
        cout << "Error";
    }
    return 0;
}