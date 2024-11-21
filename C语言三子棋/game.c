#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

//��ӡ�˵�
int menu()
{
	printf("******************************\n");
	printf("******** 1.��Ҷ�ս���� *******\n");
	printf("******** 2.��Ҷ�ս��� *******\n");
	printf("******** 0.exit **************\n");
	printf("******************************\n");
	printf("����������ѡ��");
	int nmuber = 0;
	scanf("%d", &nmuber);
	return nmuber;
}

//��ʼ������
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


////��ӡ����---�����İ汾
//void display_board(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//��ӡ����
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);//��������д����
//		//��ӡ�ָ�����
//		if (i < row - 1)
//			printf("---|---|---\n");
//	}
//}

//��ӡ����
void display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//��ӡ����
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		//��ӡ�ָ�����
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

//��һغ�
void play_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�ûغ�Ϊ�������:\n");
	while (1)
	{
		printf("������Ҫ�µ��������(X/��,Y/��):>");
		scanf("%d %d", &x, &y);
		//���������Ϸ��ж�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
				printf("��λ�������壬������������壡\n");
		}
		else
		{
			printf("�����������������������Ч���꣡\n");
		}
	}
}

//���Իغ�
void computer_move(char board[ROW][COL], int row, int col)
{
	printf("���Իغ�:\n");
	int x = 0;
	int y = 0;

	while (1)
	{
		x = rand() % row;//����Ҫ��xΪ���ֵ�����ܴ���3������ģ%��ROW=3,�����õ��������Ͳ����ܴ���3����0~2֮�䣻
		y = rand() % col;//0~2
	
		if (board[x][y] == ' ')
		{
			board[x][y] = '@';
			break;
		}
	}
	
}

//�ж������Ƿ�����
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

//��Ϸ�����ж�
char game_judge(char board[ROW][COL], int row, int col)
{
	//��
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//��
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//û����Ӯ
	if (is_full(board, row, col))
	{
		printf("ƽ�֣�\n");
		return 'q';
	}
}

//��Ϸ����
void game()
{
	char board[ROW][COL] = { 0 };
	char ret = ' ';
	//��ʼ������
	init_board(board, ROW, COL);
	display_board(board, ROW, COL);
	do
	{
	//��һغ�
	play_move(board, ROW, COL);
	display_board(board, ROW, COL);
	//�ж���Ӯ
	ret = game_judge(board, ROW, COL);
	if (ret == '#')
	{
		printf("���ʤ����\n");
		break;
	}
	if (ret == 'q')
		break;
	//���Իغ�
	computer_move(board, ROW, COL);
	display_board(board, ROW, COL);
	//�ж���Ӯ
	ret = game_judge(board, ROW, COL);
	if (ret == '@')
	{
		printf("����ʤ����\n");
		break;
	}
	if (ret == 'q')
		break;
	} while (1);
}