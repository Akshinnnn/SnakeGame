                                                                           ***SNAKE GAME CREATED IN C++ USING ARRAY***

THIS IS A TERMINAL BASED SIMPLE SNAKE GAME WITHOUT ASSETS.
THIS GAME HAS TWO STATES:
1.GAME DIFFICULTY STATE - Displays the options of game difficulty
2.GAME PLAY STATE - The actual game play

FEATURES:
1.Snake can be controlled with "WASD" keys
2.Game can be overed by pressing "O" key
3.You can choose the difficulty of the game(options: 1-easy, 2-medium, 3-hard)
4.Snake automatically advances
5.Food noted by "F" letter 
6.Food randomly generates 
7.After eating the food snake can growth in length
8.Each food increases the player's score by 1 point
9.If snake hits its tail game is over

BUILD INSTRUCTIONS:
Requirent- C++ compiler

In this code 4 functions implemented:
1.Setup - Setup of the game.
2.Draw - Basic sceleton of the game(map, appearances of snake, food and its tail, and etc.)
3.Logic - Logic of the game. Implemented basic features of the game such as: After eating the food snake can growth in length, if snake hits its tail game is over and etc.
4.Input - Here we used two functions(_kbhit(); _getch()) from the library <conio.h> for getting a character from the console window.

Just run SnakeGame.cpp to play the game on console.