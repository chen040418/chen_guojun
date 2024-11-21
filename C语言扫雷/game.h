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

//��ӡ�˵�
int menu();

//��ʼ����������
void init_board(char board[ROWS][COLS], int rows, int cols, char str);

//������
void set_mine(char board[ROWS][COLS], int row, int col);

//��ӡ
void display_board(char board[ROWS][COLS], int row, int col);

//�Ų���
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//ͳ��x,y��Χ������׸���
int get_mine_count(char board[ROWS][COLS], int x, int y);

//��Ϸ����
void game();
