#define H 10
#define L 10
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void play();
void printBoard(char Board[H][L], int h, int l);
void setMines(char Board[H][L], int h, int l,int count);
int getCount(char Board[H][L], int x, int y);
void clearBoard(char Board[H][L], char ch,int h,int l);
void searchBoard(char Board[H][L], char showsBoard[H][L], char ch, int x, int y, int *win);
