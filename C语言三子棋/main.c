#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

int main()
{
	srand((unsigned)time(NULL));//�����������������㣬ÿ��ʹ��rand()����ʱ��Ҫ�������
	do
	{
		int nmuber = menu();
		switch ((nmuber))
		{
		case 1:
			game();
			break;
		case 2:
			
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("ѡ�������������ȷ��ѡ��\n");
			break;
		}
	} while (1);

	return 0;
}