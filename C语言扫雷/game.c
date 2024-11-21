#define _CRT_SECURE_NO_WARNINGS 

#include"game.h"

//打印菜单
int menu()
{
	printf("******************************\n");
	printf("******** 1.开始扫雷 ***********\n");
	printf("******** 2.设置大小 ***********\n");
	printf("******** 0.exit **************\n");
	printf("******************************\n");
	printf("请输入您的选择：");
	int nmuber = 0;
	scanf("%d", &nmuber);
	return nmuber;
}

//初始化数组内容
void init_board(char board[ROWS][COLS], int rows, int cols, char str)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = str;
		}
	}

}

//布置雷
void set_mine(char board[ROWS][COLS], int row, int col)
{
	int count = MINE_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//0~9
		int y = rand() % col + 1;//0~9

		if (board[x][y] == '0')//判断是否已经在该位置布置过雷了
		{
			board[x][y] = '1';//布置雷为'1'
			count--;//布置雷成功才count--，否则继续进入下一次循环
		}
	}
}

//打印
void display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("--------------------扫雷游戏------------------------\n");
	//打印列号
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

//统计x,y周围方格的雷个数
int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	////循环的思路
	//for (i = -1; i <= 1; i++)
	//{
	//	for (j = -1; j <= 1; j++)
	//	{

	//	}
	//}

	//把是'1'的雷数相加思路;'1'-'0'=1
	return (
		board[x - 1][y] +			//涉及字符和数字之间的转化，即减去ASCII码的差值
		board[x - 1][y - 1] +
		board[x][y - 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] +
		board[x][y + 1] +
		board[x - 1][y + 1] - 8 * '0'//八是x,y的周围有八个方格，所以有八个字符
		);
}

//排查雷
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;//找到非雷的个数
	while (win < row * col - MINE_COUNT)
	{
		printf("请输入您要排查雷的坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("该坐标已经被排查过了,请重新排查！\n");
			}
			else
			{
				if (mine[x][y] == '1')//是雷结果
				{
					printf("嘭！你被炸死了！\n");
					display_board(mine, ROW, COL);
					break;
				}
				else//不是雷的结果
				{
					win++;
					//统计周围雷的个数
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';//将数字转化为字符再存入
					display_board(show, ROW, COL);
				}
			}
			
		}
		else
		{
			printf("输入坐标不合法,请重新输入！\n");
		}
	}
	if (win == row * col - MINE_COUNT)
	{
		printf("恭喜您排雷成功！\n");
		display_board(mine, ROW, COL);
	}
	
}

//游戏主体
void game()
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷信息
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息
	//初始化数组的内容为指定的内容
	//mine数组在没有布置雷的时候，数组内容全为'0'
	init_board(mine, ROWS, COLS, '0');

	//show数组在没有排查雷的时候，数组内容全为'*'
	init_board(show, ROWS, COLS, '*');

	//布置雷
	set_mine(mine, ROW, COL);

	//打印
	display_board(show, ROW, COL);
	//display_board(mine, ROW, COL);

	//排查雷
	find_mine(mine, show, ROW, COL);
	
}