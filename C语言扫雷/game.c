#define _CRT_SECURE_NO_WARNINGS 

#include"game.h"

//��ӡ�˵�
int menu()
{
	printf("******************************\n");
	printf("******** 1.��ʼɨ�� ***********\n");
	printf("******** 2.���ô�С ***********\n");
	printf("******** 0.exit **************\n");
	printf("******************************\n");
	printf("����������ѡ��");
	int nmuber = 0;
	scanf("%d", &nmuber);
	return nmuber;
}

//��ʼ����������
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

//������
void set_mine(char board[ROWS][COLS], int row, int col)
{
	int count = MINE_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//0~9
		int y = rand() % col + 1;//0~9

		if (board[x][y] == '0')//�ж��Ƿ��Ѿ��ڸ�λ�ò��ù�����
		{
			board[x][y] = '1';//������Ϊ'1'
			count--;//�����׳ɹ���count--���������������һ��ѭ��
		}
	}
}

//��ӡ
void display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("--------------------ɨ����Ϸ------------------------\n");
	//��ӡ�к�
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//��ӡ�к�
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

//ͳ��x,y��Χ������׸���
int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	////ѭ����˼·
	//for (i = -1; i <= 1; i++)
	//{
	//	for (j = -1; j <= 1; j++)
	//	{

	//	}
	//}

	//����'1'���������˼·;'1'-'0'=1
	return (
		board[x - 1][y] +			//�漰�ַ�������֮���ת��������ȥASCII��Ĳ�ֵ
		board[x - 1][y - 1] +
		board[x][y - 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] +
		board[x][y + 1] +
		board[x - 1][y + 1] - 8 * '0'//����x,y����Χ�а˸����������а˸��ַ�
		);
}

//�Ų���
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;//�ҵ����׵ĸ���
	while (win < row * col - MINE_COUNT)
	{
		printf("��������Ҫ�Ų��׵�����:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("�������Ѿ����Ų����,�������Ų飡\n");
			}
			else
			{
				if (mine[x][y] == '1')//���׽��
				{
					printf("�أ��㱻ը���ˣ�\n");
					display_board(mine, ROW, COL);
					break;
				}
				else//�����׵Ľ��
				{
					win++;
					//ͳ����Χ�׵ĸ���
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';//������ת��Ϊ�ַ��ٴ���
					display_board(show, ROW, COL);
				}
			}
			
		}
		else
		{
			printf("�������겻�Ϸ�,���������룡\n");
		}
	}
	if (win == row * col - MINE_COUNT)
	{
		printf("��ϲ�����׳ɹ���\n");
		display_board(mine, ROW, COL);
	}
	
}

//��Ϸ����
void game()
{
	char mine[ROWS][COLS] = { 0 };//��Ų��úõ�����Ϣ
	char show[ROWS][COLS] = { 0 };//����Ų�����׵���Ϣ
	//��ʼ�����������Ϊָ��������
	//mine������û�в����׵�ʱ����������ȫΪ'0'
	init_board(mine, ROWS, COLS, '0');

	//show������û���Ų��׵�ʱ����������ȫΪ'*'
	init_board(show, ROWS, COLS, '*');

	//������
	set_mine(mine, ROW, COL);

	//��ӡ
	display_board(show, ROW, COL);
	//display_board(mine, ROW, COL);

	//�Ų���
	find_mine(mine, show, ROW, COL);
	
}