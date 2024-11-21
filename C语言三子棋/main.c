#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

int main()
{
	srand((unsigned)time(NULL));//设置随机数的生成起点，每次使用rand()函数时都要设置这个
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
			printf("选择错误，请输入正确的选择！\n");
			break;
		}
	} while (1);

	return 0;
}