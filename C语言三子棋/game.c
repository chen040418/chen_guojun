#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

//打印菜单
int menu()
{
	printf("******************************\n");
	printf("******** 1.玩家对战电脑 *******\n");
	printf("******** 2.玩家对战玩家 *******\n");
	printf("******** 0.exit **************\n");
	printf("******************************\n");
	printf("请输入您的选择：");
	int nmuber = 0;
	scanf("%d", &nmuber);
	return nmuber;
}

//初始化棋盘
void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}


////打印棋盘---不灵活的版本
//void display_board(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//打印数据
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);//这里列是写死的
//		//打印分割棋盘
//		if (i < row - 1)
//			printf("---|---|---\n");
//	}
//}

//打印棋盘
void display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//打印数据
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		//打印分割棋盘
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

//玩家回合
void play_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("该回合为玩家下棋:\n");
	while (1)
	{
		printf("请输入要下的棋的坐标(X/行,Y/列):>");
		scanf("%d %d", &x, &y);
		//输入的坐标合法判断
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
				printf("该位置已有棋，请玩家重新下棋！\n");
		}
		else
		{
			printf("输入坐标错误，请重新输入有效坐标！\n");
		}
	}
}

//电脑回合
void computer_move(char board[ROW][COL], int row, int col)
{
	printf("电脑回合:\n");
	int x = 0;
	int y = 0;

	while (1)
	{
		x = rand() % row;//这里要让x为随机值，不能大于3，这里模%上ROW=3,这样得到的余数就不可能大于3，在0~2之间；
		y = rand() % col;//0~2
	
		if (board[x][y] == ' ')
		{
			board[x][y] = '@';
			break;
		}
	}
	
}

//判断棋盘是否下完
int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

//游戏结束判断
char game_judge(char board[ROW][COL], int row, int col)
{
	//行
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//列
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//没有人赢
	if (is_full(board, row, col))
	{
		printf("平局！\n");
		return 'q';
	}
}

//游戏主体
void game()
{
	char board[ROW][COL] = { 0 };
	char ret = ' ';
	//初始化棋盘
	init_board(board, ROW, COL);
	display_board(board, ROW, COL);
	do
	{
	//玩家回合
	play_move(board, ROW, COL);
	display_board(board, ROW, COL);
	//判断输赢
	ret = game_judge(board, ROW, COL);
	if (ret == '#')
	{
		printf("玩家胜利！\n");
		break;
	}
	if (ret == 'q')
		break;
	//电脑回合
	computer_move(board, ROW, COL);
	display_board(board, ROW, COL);
	//判断输赢
	ret = game_judge(board, ROW, COL);
	if (ret == '@')
	{
		printf("电脑胜利！\n");
		break;
	}
	if (ret == 'q')
		break;
	} while (1);
}