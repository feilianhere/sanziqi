#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
//≥ı ºªØ∆Â≈Ã
void InitBoard(char board[ROW][COL], int row, int col);
//¥Ú”°∆Â≈Ã
void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void ComeputerMove(char board[ROW][COL], int row, int col);

char If_Win(char board[ROW][COL], int row, int col);