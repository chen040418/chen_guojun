#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<graphics.h>//����ͼ�ο�ͷ�ļ�������ʹ��ͼ�ο���ĺ�����
#include<conio.h>//ʹ��_getch()
#include<mmsystem.h>//������ý���豸�ӿ�ͷ�ļ�
#pragma comment(lib,"winmm.lib")//���ؾ�̬��

#define WIDTH 1500//1920 //1500
#define HEIGHT 900//1080 //900

extern "C"{
#include"thread_relevant.h"
}

//��������
void BGM1();//���ű�������
void title(int x, int y, int w, int h, const char* text);//�����������
void content(int x, int y, int w, int h, const char* text);//�ı���������
void button(int x, int y, int w, int h, const char* text);//��ť����
bool  mouse_on_button(ExMessage *msg,int x, int y, int w, int h);//�ж�����Ƿ��ڰ�ť��
int start_interface();//1����ʼ����
int how_play_interface();//2���淨���ܽ���
int Select_level_interface();//3��ѡ��ؿ�
int music_settings();//4����������
int fastest_record();//5������¼
void game_title();//���ڱ���
void game_end();//��һ����Ϸ��������
void game_end2();//�ڶ�����Ϸ�������� 
void game_end3();//��������Ϸ�������� 
void game_end4();//���Ĺأ�Ӱ����Ϸ�������� 
void game_end5();//����أ������Ϸ�������� 
void player_victory();//���ʤ������
void boss_victory();//BOSSʤ������
void music_open();//�������ֵ��� 
void music_close();//�ر����ֵ��� 
void record_breake();//���Ƽ�¼����
void  record_unbreake();//δ���Ƽ�¼����
void open_console();//��ʾ�򿪿���̨���� 
void HideCursor();//���ع��
int first_game();//��һ��
int second_game();//�ڶ��� 
int  third_game();//������
int four_game();//���Ĺأ�Ӱ�� 
int five_game();//����أ����  
int ret_game_time();//���ص�һ�������Ϸ��¼ 
void write_game_time(int i);//д���һ�������Ϸ��¼ 
int ret_game_time2();//���صڶ��������Ϸ��¼ 
void write_game_time2(int i);//д��ڶ��������Ϸ��¼ 
int ret_game_time3();//���ص����������Ϸ��¼ 
void write_game_time3(int i);//д������������Ϸ��¼ 
int ret_game_time4();//���ص��Ĺأ�Ӱ�������Ϸ��¼ 
void write_game_time4(int i);//д����Ĺأ�Ӱ�������Ϸ��¼ 
int ret_game_time5();//���ص���أ�Ӱ�������Ϸ��¼ 
void write_game_time5(int i);//д�����أ�Ӱ�������Ϸ��¼ 

//���ű�������
void BGM1()
{
	//�����֣���������
	mciSendString("open ./music.mp3 alias BGM1", 0, 0, 0);//alias ,��BGM1���ƴ���./music.mp3
	mciSendString("play BGM1 repeat", 0, 0, 0);//play���ţ� repeat �ظ�����

}

//��������
void title(int x, int y, int w, int h, const char* text)
{
	//��������
	//����������ɫ
	settextcolor(BLACK);
	//����������ʽ����С������
	settextstyle(70, 0, "����");
	//���ñ���ģʽ
	setbkmode(TRANSPARENT);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);

}

//�ı���������
void content(int x, int y, int w, int h, const char* text)
{
	//��������
	//����������ɫ
	settextcolor(WHITE);
	//����������ʽ����С������
	settextstyle(40, 0, "����");
	//���ñ���ģʽ
	setbkmode(TRANSPARENT);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

//��ť����
void button(int x, int y, int w, int h, const char* text)
{
//	ExMessage msg;
//	if(mouse_on_button(&msg, x, y,  w,  h))
//	{
//		//���ð�ť�����ɫ
//		setfillcolor(WHITE);
//	}else
//	{
		
//	}
	
	//���ñ���ģʽ
	setbkmode(TRANSPARENT);
	//���ð�ť�����ɫ
		setfillcolor(BROWN);
	//����������ɫ
	settextcolor(BLACK);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	settextstyle(30, 0, "����");

	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
	

}

//�ж��Ƿ񱻵��
//bool mouse_clicked()
//{
//	
// } 

//�ж�����Ƿ��ڰ�ť��
//bool  mouse_on_button(ExMessage *msg,int x, int y, int w, int h)
//{
//	if(msg->x > x && msg->y > y && msg->x < x+w && msg->y < y+h)
//	{
//		return true;
//	}
//	return false;
//}


//1����ʼ����
int start_interface()
{
	
	//���ͼƬ
	IMAGE img1;//����һ������������
	//˫�������� 
//	BeginBatchDraw();
//	cleardevice(); 
	//����ͼƬ
	loadimage(&img1, "./image/background1.1.jpg", WIDTH, HEIGHT);
	putimage(0, 0, &img1);

	//��Ϸ����
	title(WIDTH / 2 - 250, HEIGHT / 2 - 300, 400, 100, "������֮���ڴ�BOSS��");
	//��ť
	button(WIDTH / 2 - 150, HEIGHT / 2 - 100, 200, 50, "��ʼ��Ϸ");
	button(WIDTH / 2 - 150, HEIGHT / 2, 200, 50, "�淨˵��");
	button(WIDTH / 2 - 150, HEIGHT / 2 + 100, 200, 50, "�˳���Ϸ");
	button(WIDTH / 2 - 150, HEIGHT / 2 + 200, 200, 50, "��������");
	button(WIDTH / 2 - 150, HEIGHT / 2 + 300, 200, 50, "����¼");
	
//	EndBatchDraw();
	ExMessage msg;
	
	while (1)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= WIDTH / 2 - 150 && msg.y >= HEIGHT / 2 - 100 && msg.x <= WIDTH / 2 + 50 && msg.y <= HEIGHT / 2 - 50)
				{
					Select_level_interface();
					msg.message = 0;//����Ϣ��������Ϊ0 
				}
				if (msg.x >= WIDTH / 2 - 150 && msg.y >= HEIGHT / 2 && msg.x <= WIDTH / 2 + 50 && msg.y <= HEIGHT / 2 + 50)
				{
					how_play_interface();
					msg.message = 0;//����Ϣ��������Ϊ0 
				}
				if (msg.x >= WIDTH / 2 - 150 && msg.y >= HEIGHT / 2 + 100 && msg.x <= WIDTH / 2 + 50 && msg.y <= HEIGHT / 2 + 150)
				{
					exit(0);
				}
				if (msg.x >= WIDTH / 2 - 150 && msg.y >= HEIGHT / 2 + 200 && msg.x <= WIDTH / 2 + 50 && msg.y <= HEIGHT / 2 + 250)
				{
					music_settings();
					msg.message = 0;//����Ϣ��������Ϊ0 
				}
				if (msg.x >= WIDTH / 2 - 150 && msg.y >= HEIGHT / 2 + 300 && msg.x <= WIDTH / 2 + 50 && msg.y <= HEIGHT / 2 + 350)
				{
					fastest_record();
					msg.message = 0;//����Ϣ��������Ϊ0 
				}
			default:
				break;
			}
		}
	}
	return 0;
}

//2���淨���ܽ���
int how_play_interface()
{
	//���ͼƬ
	IMAGE img2;//����һ������������
	//����ͼƬ
	loadimage(&img2, "./image/background1.1.jpg", WIDTH, HEIGHT);
	putimage(0, 0, &img2);


	//����
	title(WIDTH / 2 - 250, HEIGHT / 2 - 300, 400, 100, "�淨����");
	content(WIDTH / 2 - 150, HEIGHT / 2 - 150, 200, 50, "�������");
	
	content(WIDTH / 2 - 550,HEIGHT / 2 - 50 , 200, 50, "�� ��:"); 
	content(WIDTH / 2 - 400,HEIGHT / 2 - 100, 200, 50, "�� ��: w"); 
	content(WIDTH / 2 - 400,HEIGHT / 2 - 50, 200, 50, "�� ��: s"); 
	content(WIDTH / 2 - 400,HEIGHT / 2 , 200, 50, "�� ��: a"); 	
	content(WIDTH / 2 - 400,HEIGHT / 2 + 50, 200, 50, "�� ��: d"); 
	
	content(WIDTH / 2 ,HEIGHT / 2 - 50 , 200, 50, "����:"); 
	content(WIDTH / 2 + 250,HEIGHT / 2 - 100, 200, 50, "�� ��: j   �˺�: 2 "); 
	content(WIDTH / 2 + 250,HEIGHT / 2 - 50, 200, 50, "�� ��: k   �˺�: 3"); 
	content(WIDTH / 2 + 250,HEIGHT / 2 , 200, 50, "�� ��: l   �˺�: 5"); 	
 

	//���ذ�ť
	button(WIDTH - 500, HEIGHT - 200, 200, 50, "����");

	ExMessage msg;
	while (1)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= WIDTH - 500 && msg.y >= HEIGHT - 200 && msg.x <= WIDTH - 300 && msg.y <= HEIGHT - 150)
				{
					start_interface();
					msg.message = 0;//����Ϣ��������Ϊ0 
				}
			default:
				break;
			}
		}
	}
	return 0;
}


//3��ѡ��ؿ�
int Select_level_interface()
{
	
	//���ͼƬ
	IMAGE img3;//����һ������������
	//����ͼƬ
	loadimage(&img3, "./image/background1.1.jpg", WIDTH, HEIGHT);
	putimage(0, 0, &img3);

	//����
	title(WIDTH / 2 - 250, HEIGHT / 2 - 300, 400, 100, "ѡ��ؿ�");
	//��ť
	button(WIDTH / 2 - 350, HEIGHT / 2 - 100, 200, 50, "��һ��");
	button(WIDTH / 2 + 50, HEIGHT / 2 - 100, 200, 50, "�ڶ���");
	button(WIDTH / 2 -350, HEIGHT / 2 , 200, 50, "������");
	button(WIDTH / 2 + 50,HEIGHT / 2 ,200,50,"Ӱ��" ); 
	button(WIDTH / 2 -350,HEIGHT / 2 + 100 ,200,50,"���"); 

	//���ذ�ť
	button(WIDTH - 500, HEIGHT - 200, 200, 50, "����");

	ExMessage msg;
	while (1)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= WIDTH / 2 - 350 && msg.y >= HEIGHT / 2 - 100 && msg.x <= WIDTH / 2 - 150 && msg.y <= HEIGHT / 2 - 50)
				{
					//��ʾ�򿪿���̨ 
					open_console(); 
					//��һ��
					first_game();
					msg.message = 0;//����Ϣ��������Ϊ0	
				}
				if(msg.x >= WIDTH / 2 + 50 && msg.y >= HEIGHT / 2 - 100 && msg.x <= WIDTH / 2 + 250 && msg.y <= HEIGHT / 2 - 50)
				{
					//��ʾ�򿪿���̨ 
					open_console(); 
					//�ڶ��� 
					second_game();
					msg.message = 0;//����Ϣ��������Ϊ0 
				}
				if(msg.x >= WIDTH / 2 -350 && msg.y >= HEIGHT / 2 && msg.x <= WIDTH / 2 -150 && msg.y <= HEIGHT / 2 + 50)
				{
					//��ʾ�򿪿���̨ 
					open_console(); 
					//������
					third_game();
					msg.message = 0;//����Ϣ��������Ϊ0
				}
				if(msg.x >= WIDTH / 2 + 50 && msg.y >= HEIGHT / 2  && msg.x <= msg.x <= WIDTH / 2 + 250 && msg.y <= HEIGHT / 2 + 50)
				{
					//��ʾ�򿪿���̨ 
					open_console(); 
					//Ӱ��
					four_game();
					msg.message = 0;//����Ϣ��������Ϊ0
				}
				if(msg.x >= WIDTH / 2 -350 &&  msg.y >= HEIGHT / 2 + 100 && msg.x <= msg.x <= WIDTH / 2 -150 && msg.y <= HEIGHT / 2 + 150)
				{
					//��ʾ�򿪿���̨ 
					open_console(); 
					//��� 
					five_game();
					msg.message = 0;//����Ϣ��������Ϊ0
				}
				if (msg.x >= WIDTH - 500 && msg.y >= HEIGHT - 200 && msg.x <= WIDTH - 300 && msg.y <= HEIGHT - 150)
				{
					start_interface();
					msg.message = 0;//����Ϣ��������Ϊ0
				}
			default:
				break;
			}
		}
	}

	return 0;
}

//4����������
int music_settings()
{
	//���ͼƬ
	IMAGE img3;//����һ������������
	//����ͼƬ
	loadimage(&img3, "./image/background1.1.jpg", WIDTH, HEIGHT);
	putimage(0, 0, &img3);

	//����
	title(WIDTH / 2 - 250, HEIGHT / 2 - 300, 400, 100, "��������");
	//��ť
	button(WIDTH / 2 - 150, HEIGHT / 2 - 50, 200, 50, "��������");
	button(WIDTH / 2 - 150, HEIGHT / 2 + 50, 200, 50, "�ر�����");
	button(WIDTH - 500, HEIGHT - 200, 200, 50, "����");

	ExMessage msg;
	while (1)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= WIDTH / 2 - 150 && msg.y >= HEIGHT / 2 - 50 && msg.x <= WIDTH / 2 + 50 && msg.y <= HEIGHT / 2 )
				{
					//��������
					music_open();
					msg.message = 0;//����Ϣ��������Ϊ0 
				}
				if (msg.x >= WIDTH / 2 - 150 && msg.y >= HEIGHT / 2 + 50 && msg.x <= WIDTH / 2 + 50 && msg.y <= HEIGHT / 2 + 100)
				{
					//�ر�����
					music_close();
					msg.message = 0;//����Ϣ��������Ϊ0 
				}
				if (msg.x >= WIDTH - 500 && msg.y >= HEIGHT - 200 && msg.x <= WIDTH - 300 && msg.y <= HEIGHT - 150)
				{
					start_interface();
					msg.message = 0;//����Ϣ��������Ϊ0 
				}
			default:
				break;
			}
		}
	}
	return 0;
}

//5������¼ 
int fastest_record()
{
	//���ͼƬ
	IMAGE img3;//����һ������������
	//����ͼƬ
	loadimage(&img3, "./image/background1.1.jpg", WIDTH, HEIGHT);
	putimage(0, 0, &img3);
	//��һ�� ��¼ 
	int fastest_record_time = ret_game_time();
	char buf1[10];
	memset(buf1,0x00,10);
	sprintf(buf1,"%d",fastest_record_time);
	//�ڶ��ؼ�¼ 
	int fastest_record_time2 = ret_game_time2();
	char buf2[10];
	memset(buf2,0x00,10);
	sprintf(buf2,"%d",fastest_record_time2);
	//�����ؼ�¼
	int fastest_record_time3 = ret_game_time3();
	char buf3[10];
	memset(buf3,0x00,10);
	sprintf(buf3,"%d",fastest_record_time3); 
	//���Ĺأ�Ӱ�Ӽ�¼
	int fastest_record_time4 = ret_game_time4();
	char buf4[10];
	memset(buf4,0x00,10);
	sprintf(buf4,"%d",fastest_record_time4);
	//����أ���ü�¼
	int fastest_record_time5 = ret_game_time5();
	char buf5[10];
	memset(buf5,0x00,10);
	sprintf(buf5,"%d",fastest_record_time5);
	
	//����
	title(WIDTH / 2 - 250, HEIGHT / 2 - 300, 400, 100, "ͨ������¼(��)");
	//����
	title(WIDTH / 2 - 300, HEIGHT / 2 - 100, 200, 50, "��һ��:");
	content(WIDTH / 2 - 150, HEIGHT / 2 - 100, 200, 50,buf1);
	title(WIDTH / 2 - 300, HEIGHT / 2 , 200, 50, "�ڶ���:");
	content(WIDTH / 2 - 150, HEIGHT / 2 , 200, 50,buf2);
	title(WIDTH / 2 - 300, HEIGHT / 2 + 100, 200, 50, "������:");
	content(WIDTH / 2 - 150, HEIGHT / 2 + 100 , 200, 50,buf3);
	title(WIDTH / 2 - 300, HEIGHT / 2 + 200, 200, 50, "Ӱ��:");
	content(WIDTH / 2 - 150, HEIGHT / 2 + 200 , 200, 50,buf4);
	title(WIDTH / 2 - 300, HEIGHT / 2 + 300, 200, 50, "���:");
	content(WIDTH / 2 - 150, HEIGHT / 2 + 300 , 200, 50,buf5);
	
	//��ť
	button(WIDTH - 500, HEIGHT - 200, 200, 50, "����");

	ExMessage msg;
	while (1)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= WIDTH - 500 && msg.y >= HEIGHT - 200 && msg.x <= WIDTH - 300 && msg.y <= HEIGHT - 150)
				{
					start_interface();
					msg.message = 0;//����Ϣ��������Ϊ0 
				}
			default:
				break;
			}
		}
	}
}

//���ڱ���
void game_title()
{
	//��ȡ���ھ��
	HWND title = GetHWnd();
	//���ô��ڱ���
	SetWindowText(title, "����֮���ڴ�BOSS");
}

//��һ����Ϸ��������
void game_end(int game_results)
{
	int fastest_time;
	HWND game = GetHWnd();
	//������Ϸ������
	MessageBox(game, "��Ϸ����!", "��ʾ", MB_OKCANCEL);//MessageBox���ص���int����
	if (game_results > 0)//���ʤ��
	{
		//���������Ϸ��¼ 
		fastest_time = ret_game_time();
		if(fastest_time >= game_results)
		{
			player_victory();
			//�Ƽ�¼����
			record_breake();
			//д�������Ϸ��¼
			write_game_time(game_results); 
			
		}else
		{
			player_victory();
			//δ�Ƽ�¼����
			record_unbreake();
			
		}
	}
	else if(game_results == 0)//BOSSʤ��
	{
		boss_victory();
	}
}

//�ڶ�����Ϸ��������
void game_end2(int game_results)
{
	int fastest_time;
	HWND game = GetHWnd();
	//������Ϸ������
	MessageBox(game, "��Ϸ����!", "��ʾ", MB_OKCANCEL);//MessageBox���ص���int����
	if (game_results > 0)//���ʤ��
	{
		//���������Ϸ��¼ 
		fastest_time = ret_game_time();
		if(fastest_time >= game_results)
		{
			player_victory();
			//�Ƽ�¼����
			record_breake();
			//д�������Ϸ��¼
			write_game_time2(game_results); 
			
		}else
		{
			player_victory();
			//δ�Ƽ�¼����
			record_unbreake();
			
		}
	}
	else if(game_results == 0)//BOSSʤ��
	{
		boss_victory();
	}
}

//��������Ϸ��������
void game_end3(int game_results)
{
	int fastest_time;
	HWND game = GetHWnd();
	//������Ϸ������
	MessageBox(game, "��Ϸ����!", "��ʾ", MB_OKCANCEL);//MessageBox���ص���int����
	if (game_results > 0)//���ʤ��
	{
		//���������Ϸ��¼ 
		fastest_time = ret_game_time();
		if(fastest_time >= game_results)
		{
			player_victory();
			//�Ƽ�¼����
			record_breake();
			//д�������Ϸ��¼
			write_game_time3(game_results); 
			
		}else
		{
			player_victory();
			//δ�Ƽ�¼����
			record_unbreake();
			
		}
	}
	else if(game_results == 0)//BOSSʤ��
	{
		boss_victory();
	}
}

//���Ĺأ�Ӱ����Ϸ��������
void game_end4(int game_results)
{
	int fastest_time;
	HWND game = GetHWnd();
	//������Ϸ������
	MessageBox(game, "��Ϸ����!", "��ʾ", MB_OKCANCEL);//MessageBox���ص���int����
	if (game_results > 0)//���ʤ��
	{
		//���������Ϸ��¼ 
		fastest_time = ret_game_time();
		if(fastest_time >= game_results)
		{
			player_victory();
			//�Ƽ�¼����
			record_breake();
			//д�������Ϸ��¼
			write_game_time4(game_results); 
			
		}else
		{
			player_victory();
			//δ�Ƽ�¼����
			record_unbreake();
			
		}
	}
	else if(game_results == 0)//BOSSʤ��
	{
		boss_victory();
	}
}

//����أ������Ϸ��������
void game_end5(int game_results)
{
	int fastest_time;
	HWND game = GetHWnd();
	//������Ϸ������
	MessageBox(game, "��Ϸ����!", "��ʾ", MB_OKCANCEL);//MessageBox���ص���int����
	if (game_results > 0)//���ʤ��
	{
		//���������Ϸ��¼ 
		fastest_time = ret_game_time();
		if(fastest_time >= game_results)
		{
			player_victory();
			//�Ƽ�¼����
			record_breake();
			//д�������Ϸ��¼
			write_game_time5(game_results); 
			
		}else
		{
			player_victory();
			//δ�Ƽ�¼����
			record_unbreake();
			
		}
	}
	else if(game_results == 0)//BOSSʤ��
	{
		boss_victory();
	}
}

//���ʤ������
void player_victory()
{
	HWND player = GetHWnd();
	MessageBox(player, "���ʤ����", "��Ϸ���", MB_OKCANCEL);
}

//BOSSʤ������
void boss_victory()
{
	HWND boss = GetHWnd();
	MessageBox(boss, "BOSSʤ����", "��Ϸ���", MB_OKCANCEL);
	int isok = MessageBox(boss, "�Ƿ����¿�ʼ��", "��ʾ", MB_OKCANCEL);
	if (isok == IDOK)
	{
		//���¼�����Ϸ
		first_game();
	}
	else if (isok == IDCANCEL)
	{
		Select_level_interface();
	}
}

//�������ֵ��� 
void music_open()
{
	HWND music = GetHWnd();
	//�����Ի���
	int isok = MessageBox(music, "�Ƿ������֣�", "��������", MB_OKCANCEL);//MessageBox���ص���int����
	if (isok == IDOK)
	{
		//�����֣���������
		mciSendString("open ./music.mp3 alias BGM1", 0, 0, 0);//alias ,��BGM���ƴ���./music.mp3
		mciSendString("play BGM1 repeat", 0, 0, 0);//play���ţ� repeat �ظ�����
	}
 
}

//�ر����ֵ��� 
void music_close()
{
	HWND music = GetHWnd();
	//������Ϸ������
	int isok = MessageBox(music, "�Ƿ�ر����֣�", "��������", MB_OKCANCEL);//MessageBox���ص���int����
	if (isok == IDOK)
	{
		mciSendString("close BGM1 ", 0, 0, 0);
	}
	
}

//���Ƽ�¼����
void record_breake()
{
	HWND record_breake = GetHWnd();
	int isok = MessageBox(record_breake, "��ϲ�����Ƽ�¼��", "��ʾ", MB_OKCANCEL);//MessageBox���ص���int����
	if (isok == IDOK)
	{
		Select_level_interface(); 
	}
}

//δ���Ƽ�¼����
void  record_unbreake()
{
	HWND record_unbreake = GetHWnd();
	int isok = MessageBox(record_unbreake, "���ź�����δ���Ƽ�¼��", "��ʾ", MB_OKCANCEL);//MessageBox���ص���int����
	if (isok == IDOK)
	{
		Select_level_interface(); 
	}
}

//��ʾ�򿪿���̨���� 
void open_console()
{
	HWND open_console = GetHWnd();
	int isok = MessageBox(open_console, "���ڿ���̨�Ͻ�����Ϸ!!!(ע:�뽫����̨���)", "��ʾ", MB_OKCANCEL);//MessageBox���ص���int����
//	if (isok == IDOK)
//	{
//		//��ȡ����̨���ھ��
//		HWND game = GetConsoleWindow();
//  	//������̨�������ڶ��� 
//		SetWindowPos(game,HWND_TOPMOST,0,0,0,0,0);
//	}
}

//���ع��
void HideCursor()
{
	CONSOLE_CURSOR_INFO curInfo; //��������Ϣ�Ľṹ�����
	curInfo.dwSize = 1; //������С����Ϊ1�����û��ֵ�Ļ������������Ч
	curInfo.bVisible = FALSE; //�ɼ���Ϊ�٣������������Ϊ���ɼ� 
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
	SetConsoleCursorInfo(handle, &curInfo); //���ù����Ϣ
}

//��һ��
int first_game()
{
	//�رջ�ͼ���� 
	closegraph();

	int boss_blood = 100;//Ĭ��bossѪ��ֵ 
	int player_blood = 100;//Ĭ�����Ѫ��ֵ 
	int time_game = 300;//Ĭ����Ϸʱ�� 
	int height_map = 50;//Ĭ�ϵ�ͼ�ĸ� 
	int width_map = 150;//Ĭ�ϵ�ͼ�Ŀ�
	int boss_cd = 5;//Ĭ��boss����cdʱ�� 
	int boss_attck = 10;//Ĭ��boss����ֵ  
	int boss_number = 1;//1��BOSS 
					
	pthread_mutex_init(&xpthread_var.mutex_attack,NULL);
    pthread_mutex_init(&xpthread_var.mutex_print,NULL);
    pthread_mutex_init(&xpthread_var.mutex_cooling,NULL);
	Sleep(5000);
	
	//run_game(BOSSѪ��,���Ѫ��,��Ϸʱ��,��ͼ�ĸ�,��ͼ�Ŀ�; 
	//���������ʵ���Զ�����Ϸ���� 
	int game_results = run_game(boss_blood,player_blood,time_game,height_map,width_map,boss_cd,boss_attck,boss_number);
	
	pthread_mutex_destroy(&xpthread_var.mutex_attack);
    pthread_mutex_destroy(&xpthread_var.mutex_print);
    pthread_mutex_destroy(&xpthread_var.mutex_cooling);
	
	if(game_results >= 0)
	{
		//���»��ƴ���
		initgraph(1920, 1080,EX_SHOWCONSOLE);
		game_title();
		game_end(game_results);
	}
	
 } 
 
//�ڶ��� 
int second_game()
{
	//�رջ�ͼ���� 
	closegraph();

	int boss_blood = 150;//Ĭ��bossѪ��ֵ 
	int player_blood = 100;//Ĭ�����Ѫ��ֵ 
	int time_game = 240;//Ĭ����Ϸʱ�� 
	int height_map = 40;//Ĭ�ϵ�ͼ�ĸ� 
	int width_map = 150;//Ĭ�ϵ�ͼ�Ŀ�
	int boss_cd = 3;//Ĭ��boss����ʱ��
	int boss_attck = 15;//Ĭ��boss����ֵ 
	int boss_number = 2;//2��BOSS 
					
	pthread_mutex_init(&xpthread_var.mutex_attack,NULL);
    pthread_mutex_init(&xpthread_var.mutex_print,NULL);
    pthread_mutex_init(&xpthread_var.mutex_cooling,NULL);
	Sleep(5000);
	
	//run_game(BOSSѪ��,���Ѫ��,��Ϸʱ��,��ͼ�ĸ�,��ͼ�Ŀ�; 
	//���������ʵ���Զ�����Ϸ���� 
	int game_results = run_game(boss_blood,player_blood,time_game,height_map,width_map,boss_cd,boss_attck,boss_number);
	
	pthread_mutex_destroy(&xpthread_var.mutex_attack);
    pthread_mutex_destroy(&xpthread_var.mutex_print);
    pthread_mutex_destroy(&xpthread_var.mutex_cooling);
	
	if(game_results >= 0)
	{
		//���»��ƴ���
		initgraph(1920, 1080,EX_SHOWCONSOLE);
		game_title();
		game_end2(game_results);
	}
	
}

//������
int  third_game()
{
	//�رջ�ͼ���� 
	closegraph();
	
	int boss_blood = 150;//Ĭ��bossѪ��ֵ 
	int player_blood = 100;//Ĭ�����Ѫ��ֵ 
	int time_game = 180;//Ĭ����Ϸʱ�� 
	int height_map = 50;//Ĭ�ϵ�ͼ�ĸ� 
	int width_map = 150;//Ĭ�ϵ�ͼ�Ŀ�
	int boss_cd = 10;//Ĭ��boss����cdʱ�� 
	int boss_attck = 15;//Ĭ��boss����ֵ  
	int boss_number=3;//3��BOSS 
					
	pthread_mutex_init(&xpthread_var.mutex_attack,NULL);
    pthread_mutex_init(&xpthread_var.mutex_print,NULL);
    pthread_mutex_init(&xpthread_var.mutex_cooling,NULL);
	Sleep(5000);
	
	//run_game(BOSSѪ��,���Ѫ��,��Ϸʱ��,��ͼ�ĸ�,��ͼ�Ŀ�; 
	//���������ʵ���Զ�����Ϸ���� 
	int game_results = run_game(boss_blood,player_blood,time_game,height_map,width_map,boss_cd,boss_attck,boss_number);
	
	pthread_mutex_destroy(&xpthread_var.mutex_attack);
    pthread_mutex_destroy(&xpthread_var.mutex_print);
    pthread_mutex_destroy(&xpthread_var.mutex_cooling);
	
	if(game_results >= 0)
	{
		//���»��ƴ���
		initgraph(1920, 1080,EX_SHOWCONSOLE);
		game_title();
		game_end3(game_results);
	} 
}

//���Ĺأ�Ӱ��
int four_game()
{
	//�رջ�ͼ���� 
	closegraph();
	
	int boss_blood = 20;//Ĭ��bossѪ��ֵ 
	int player_blood = 100;//Ĭ�����Ѫ��ֵ 
	int time_game = 300;//Ĭ����Ϸʱ�� 
	int height_map = 50;//Ĭ�ϵ�ͼ�ĸ� 
	int width_map = 150;//Ĭ�ϵ�ͼ�Ŀ�
	int boss_cd = 5;//Ĭ��boss����cdʱ�� 
	int boss_attck = 15;//Ĭ��boss����ֵ  
	int boss_number=3;//3��BOSS 
					
	pthread_mutex_init(&xpthread_var.mutex_attack,NULL);
    pthread_mutex_init(&xpthread_var.mutex_print,NULL);
    pthread_mutex_init(&xpthread_var.mutex_cooling,NULL);
	Sleep(5000);
	
	//run_game(BOSSѪ��,���Ѫ��,��Ϸʱ��,��ͼ�ĸ�,��ͼ�Ŀ�; 
	//���������ʵ���Զ�����Ϸ���� 
	int game_results = run_game_two(boss_blood,player_blood,time_game,height_map,width_map,boss_cd,boss_attck,boss_number);
	
	pthread_mutex_destroy(&xpthread_var.mutex_attack);
    pthread_mutex_destroy(&xpthread_var.mutex_print);
    pthread_mutex_destroy(&xpthread_var.mutex_cooling);
	
	if(game_results >= 0)
	{
		//���»��ƴ���
		initgraph(1920, 1080,EX_SHOWCONSOLE);
		game_title();
		game_end4(game_results);
	}
 } 
 
 //����أ���� 
int five_game()
{
	//�رջ�ͼ���� 
	closegraph();
	
	int boss_blood = 100;//Ĭ��bossѪ��ֵ 
	int player_blood = 100;//Ĭ�����Ѫ��ֵ 
	int time_game = 300;//Ĭ����Ϸʱ�� 
	int height_map = 50;//Ĭ�ϵ�ͼ�ĸ� 
	int width_map = 150;//Ĭ�ϵ�ͼ�Ŀ�
	int boss_cd = 5;//Ĭ��boss����cdʱ�� 
	int boss_attck = 15;//Ĭ��boss����ֵ  
	int boss_number=3;//3��BOSS 
					
	pthread_mutex_init(&xpthread_var.mutex_attack,NULL);
    pthread_mutex_init(&xpthread_var.mutex_print,NULL);
    pthread_mutex_init(&xpthread_var.mutex_cooling,NULL);
	Sleep(5000);
	
	//run_game(BOSSѪ��,���Ѫ��,��Ϸʱ��,��ͼ�ĸ�,��ͼ�Ŀ�; 
	//���������ʵ���Զ�����Ϸ���� 
	int game_results = run_game_four(boss_blood,player_blood,time_game,height_map,width_map,boss_cd,boss_attck,boss_number);
	
	pthread_mutex_destroy(&xpthread_var.mutex_attack);
    pthread_mutex_destroy(&xpthread_var.mutex_print);
    pthread_mutex_destroy(&xpthread_var.mutex_cooling);
	
	if(game_results >= 0)
	{
		//���»��ƴ���
		initgraph(1920, 1080,EX_SHOWCONSOLE);
		game_title();
		game_end5(game_results);
	}
 } 

//���ص�һ�������Ϸ��¼ 
int ret_game_time(){
	FILE* pf=fopen("fastest_game_time.txt","r");
	int i=0;
	if(pf==NULL){
		pf=fopen("fastest_game_time.txt","w");
		i=300;
	}else{
		fscanf(pf,"%d",&i);
	}
	fclose(pf);
	return i;
}

//д���һ�������Ϸ��¼
void write_game_time(int i){
	FILE* pf=fopen("fastest_game_time.txt","w");
	fprintf(pf,"%d ",i);
	fclose(pf);
	return;
}

//���صڶ��������Ϸ��¼ 
int ret_game_time2(){
	FILE* pf=fopen("fastest_game_time2.txt","r");
	int i=0;
	if(pf==NULL){
		pf=fopen("fastest_game_time2.txt","w");
		i=300;
	}else{
		fscanf(pf,"%d",&i);
	}
	fclose(pf);
	return i;
}

//д��ڶ��������Ϸ��¼
void write_game_time2(int i){
	FILE* pf=fopen("fastest_game_time2.txt","w");
	fprintf(pf,"%d ",i);
	fclose(pf);
	return;
}

//���ص����������Ϸ��¼ 
int ret_game_time3(){
	FILE* pf=fopen("fastest_game_time3.txt","r");
	int i=0;
	if(pf==NULL){
		pf=fopen("fastest_game_time3.txt","w");
		i=300;
	}else{
		fscanf(pf,"%d",&i);
	}
	fclose(pf);
	return i;
}

//д������������Ϸ��¼
void write_game_time3(int i){
	FILE* pf=fopen("fastest_game_time3.txt","w");
	fprintf(pf,"%d ",i);
	fclose(pf);
	return;
}

//���ص��Ĺأ�Ӱ�������Ϸ��¼ 
int ret_game_time4(){
	FILE* pf=fopen("fastest_game_time4.txt","r");
	int i=0;
	if(pf==NULL){
		pf=fopen("fastest_game_time4.txt","w");
		i=300;
	}else{
		fscanf(pf,"%d",&i);
	}
	fclose(pf);
	return i;
}

//д����Ĺأ�Ӱ�������Ϸ��¼
void write_game_time4(int i){
	FILE* pf=fopen("fastest_game_time4.txt","w");
	fprintf(pf,"%d ",i);
	fclose(pf);
	return;
}

//���ص���أ���������Ϸ��¼ 
int ret_game_time5(){
	FILE* pf=fopen("fastest_game_time5.txt","r");
	int i=0;
	if(pf==NULL){
		pf=fopen("fastest_game_time5.txt","w");
		i=300;
	}else{
		fscanf(pf,"%d",&i);
	}
	fclose(pf);
	return i;
}

//д�����أ���������Ϸ��¼
void write_game_time5(int i){
	FILE* pf=fopen("fastest_game_time5.txt","w");
	fprintf(pf,"%d ",i);
	fclose(pf);
	return;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	
	//����cmd���ڵ�����
	system("title ������֮���ڴ�BOSS��"); 
	initgraph(1920, 1080,EX_SHOWCONSOLE);
	//��������
	BGM1();
	//���ڱ���
	game_title();
	//���ع�� 
	HideCursor();
	//��ʼ����
	start_interface();
	
	return 0;
}
