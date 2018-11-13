/*********************************************
* Names: Dixant Patel, Jade Legare, Ali Afzal, Kathleen McCulloch-Cop
* GROUP: team 3 Section 1 (Tuesday lab)
* Course: Software Design 3 (cis*3250)
* Date: October 15 2018
*********************************************/
#ifndef CONNECT_H
#define CONNECT_H

//libraries
#include <stdio.h>
#include <strings.h>
#include <windows.h>

#define INTENSITY SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY)

//Global variables
char arr[100][100];
char arrSaveAction[100] = {0};
char arrRestorePlace[100] = {0};

int width, height, highScores, numberOfPlay, savePlace, numberOfCol;
char playerInput[20], whichPlayer;
int restorePlace = 0, scoreOne = 0, scoreTwo = 0, gameOut = 0;
int highScoreList[50] = {0}, listLength = 0;

//function definition
void arrInitialization(int Height, int Width);
void saveGame();
void highScoresList(int flag);
void loadGame();
void printArrayValue(int Height, int Width);
void updateScore(int row, int col);
void playAgain();
void undo();
void redo();
void computerPlayer();
void player(char numberOfCol, int numberOfPlay);
void readXml();


#endif
