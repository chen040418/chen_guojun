#pragma once

#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>

#define ROW 3
#define COL 3

//函数声明

//打印菜单
int menu();

//初始化棋盘
void init_board(char board[ROW][COL], int row, int col);

//打印棋盘
void display_board(char board[ROW][COL], int row, int col);

//玩家回合
void play_move(char board[ROW][COL], int row, int col);

//电脑回合-找空白位置下棋
void computer_move(char board[ROW][COL], int row, int col);

//判断棋盘是否下完
int is_full(char board[ROW][COL], int row, int col);

//游戏结束判断
char game_judge(char board[ROW][COL], int row ,int col);

//游戏主体
void game();