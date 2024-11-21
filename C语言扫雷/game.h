#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define MINE_COUNT 10

//打印菜单
int menu();

//初始化数组内容
void init_board(char board[ROWS][COLS], int rows, int cols, char str);

//布置雷
void set_mine(char board[ROWS][COLS], int row, int col);

//打印
void display_board(char board[ROWS][COLS], int row, int col);

//排查雷
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//统计x,y周围方格的雷个数
int get_mine_count(char board[ROWS][COLS], int x, int y);

//游戏主体
void game();
