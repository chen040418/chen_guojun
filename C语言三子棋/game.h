#pragma once

#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>

#define ROW 3
#define COL 3

//��������

//��ӡ�˵�
int menu();

//��ʼ������
void init_board(char board[ROW][COL], int row, int col);

//��ӡ����
void display_board(char board[ROW][COL], int row, int col);

//��һغ�
void play_move(char board[ROW][COL], int row, int col);

//���Իغ�-�ҿհ�λ������
void computer_move(char board[ROW][COL], int row, int col);

//�ж������Ƿ�����
int is_full(char board[ROW][COL], int row, int col);

//��Ϸ�����ж�
char game_judge(char board[ROW][COL], int row ,int col);

//��Ϸ����
void game();