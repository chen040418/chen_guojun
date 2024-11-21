#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<graphics.h>//包含图形库头文件，就能使用图形库里的函数了
#include<conio.h>//使用_getch()
#include<mmsystem.h>//包含多媒体设备接口头文件
#pragma comment(lib,"winmm.lib")//加载静态库

#define WIDTH 1500//1920 //1500
#define HEIGHT 900//1080 //900

extern "C"{
#include"thread_relevant.h"
}

//函数声明
void BGM1();//播放背景音乐
void title(int x, int y, int w, int h, const char* text);//界面标题设置
void content(int x, int y, int w, int h, const char* text);//文本内容设置
void button(int x, int y, int w, int h, const char* text);//按钮设置
bool  mouse_on_button(ExMessage *msg,int x, int y, int w, int h);//判断鼠标是否在按钮里
int start_interface();//1、开始界面
int how_play_interface();//2、玩法介绍界面
int Select_level_interface();//3、选择关卡
int music_settings();//4、音乐设置
int fastest_record();//5、最快记录
void game_title();//窗口标题
void game_end();//第一关游戏结束弹窗
void game_end2();//第二关游戏结束弹窗 
void game_end3();//第三关游戏结束弹窗 
void game_end4();//第四关：影子游戏结束弹窗 
void game_end5();//第五关：虚幻游戏结束弹窗 
void player_victory();//玩家胜利弹窗
void boss_victory();//BOSS胜利弹窗
void music_open();//开启音乐弹窗 
void music_close();//关闭音乐弹窗 
void record_breake();//打破记录弹窗
void  record_unbreake();//未打破记录弹窗
void open_console();//提示打开控制台弹窗 
void HideCursor();//隐藏光标
int first_game();//第一关
int second_game();//第二关 
int  third_game();//第三关
int four_game();//第四关：影子 
int five_game();//第五关：虚幻  
int ret_game_time();//返回第一关最快游戏记录 
void write_game_time(int i);//写入第一关最快游戏记录 
int ret_game_time2();//返回第二关最快游戏记录 
void write_game_time2(int i);//写入第二关最快游戏记录 
int ret_game_time3();//返回第三关最快游戏记录 
void write_game_time3(int i);//写入第三关最快游戏记录 
int ret_game_time4();//返回第四关：影子最快游戏记录 
void write_game_time4(int i);//写入第四关：影子最快游戏记录 
int ret_game_time5();//返回第五关：影子最快游戏记录 
void write_game_time5(int i);//写入第五关：影子最快游戏记录 

//播放背景音乐
void BGM1()
{
	//打开音乐，播放音乐
	mciSendString("open ./music.mp3 alias BGM1", 0, 0, 0);//alias ,用BGM1名称代替./music.mp3
	mciSendString("play BGM1 repeat", 0, 0, 0);//play播放， repeat 重复播放

}

//标题设置
void title(int x, int y, int w, int h, const char* text)
{
	//绘制文字
	//设置文字颜色
	settextcolor(BLACK);
	//设置字体样式，大小，字体
	settextstyle(70, 0, "黑体");
	//设置背景模式
	setbkmode(TRANSPARENT);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);

}

//文本内容设置
void content(int x, int y, int w, int h, const char* text)
{
	//绘制文字
	//设置文字颜色
	settextcolor(WHITE);
	//设置字体样式，大小，字体
	settextstyle(40, 0, "宋体");
	//设置背景模式
	setbkmode(TRANSPARENT);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

//按钮设置
void button(int x, int y, int w, int h, const char* text)
{
//	ExMessage msg;
//	if(mouse_on_button(&msg, x, y,  w,  h))
//	{
//		//设置按钮填充颜色
//		setfillcolor(WHITE);
//	}else
//	{
		
//	}
	
	//设置背景模式
	setbkmode(TRANSPARENT);
	//设置按钮填充颜色
		setfillcolor(BROWN);
	//设置文字颜色
	settextcolor(BLACK);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	settextstyle(30, 0, "黑体");

	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
	

}

//判断是否被点击
//bool mouse_clicked()
//{
//	
// } 

//判断鼠标是否在按钮里
//bool  mouse_on_button(ExMessage *msg,int x, int y, int w, int h)
//{
//	if(msg->x > x && msg->y > y && msg->x < x+w && msg->y < y+h)
//	{
//		return true;
//	}
//	return false;
//}


//1、开始界面
int start_interface()
{
	
	//输出图片
	IMAGE img1;//定义一个变量（对象）
	//双缓冲区域 
//	BeginBatchDraw();
//	cleardevice(); 
	//加载图片
	loadimage(&img1, "./image/background1.1.jpg", WIDTH, HEIGHT);
	putimage(0, 0, &img1);

	//游戏标题
	title(WIDTH / 2 - 250, HEIGHT / 2 - 300, 400, 100, "《重生之我在打BOSS》");
	//按钮
	button(WIDTH / 2 - 150, HEIGHT / 2 - 100, 200, 50, "开始游戏");
	button(WIDTH / 2 - 150, HEIGHT / 2, 200, 50, "玩法说明");
	button(WIDTH / 2 - 150, HEIGHT / 2 + 100, 200, 50, "退出游戏");
	button(WIDTH / 2 - 150, HEIGHT / 2 + 200, 200, 50, "音乐设置");
	button(WIDTH / 2 - 150, HEIGHT / 2 + 300, 200, 50, "最快纪录");
	
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
					msg.message = 0;//把消息类型设置为0 
				}
				if (msg.x >= WIDTH / 2 - 150 && msg.y >= HEIGHT / 2 && msg.x <= WIDTH / 2 + 50 && msg.y <= HEIGHT / 2 + 50)
				{
					how_play_interface();
					msg.message = 0;//把消息类型设置为0 
				}
				if (msg.x >= WIDTH / 2 - 150 && msg.y >= HEIGHT / 2 + 100 && msg.x <= WIDTH / 2 + 50 && msg.y <= HEIGHT / 2 + 150)
				{
					exit(0);
				}
				if (msg.x >= WIDTH / 2 - 150 && msg.y >= HEIGHT / 2 + 200 && msg.x <= WIDTH / 2 + 50 && msg.y <= HEIGHT / 2 + 250)
				{
					music_settings();
					msg.message = 0;//把消息类型设置为0 
				}
				if (msg.x >= WIDTH / 2 - 150 && msg.y >= HEIGHT / 2 + 300 && msg.x <= WIDTH / 2 + 50 && msg.y <= HEIGHT / 2 + 350)
				{
					fastest_record();
					msg.message = 0;//把消息类型设置为0 
				}
			default:
				break;
			}
		}
	}
	return 0;
}

//2、玩法介绍界面
int how_play_interface()
{
	//输出图片
	IMAGE img2;//定义一个变量（对象）
	//加载图片
	loadimage(&img2, "./image/background1.1.jpg", WIDTH, HEIGHT);
	putimage(0, 0, &img2);


	//标题
	title(WIDTH / 2 - 250, HEIGHT / 2 - 300, 400, 100, "玩法介绍");
	content(WIDTH / 2 - 150, HEIGHT / 2 - 150, 200, 50, "人物介绍");
	
	content(WIDTH / 2 - 550,HEIGHT / 2 - 50 , 200, 50, "移 动:"); 
	content(WIDTH / 2 - 400,HEIGHT / 2 - 100, 200, 50, "上 移: w"); 
	content(WIDTH / 2 - 400,HEIGHT / 2 - 50, 200, 50, "下 移: s"); 
	content(WIDTH / 2 - 400,HEIGHT / 2 , 200, 50, "左 移: a"); 	
	content(WIDTH / 2 - 400,HEIGHT / 2 + 50, 200, 50, "右 移: d"); 
	
	content(WIDTH / 2 ,HEIGHT / 2 - 50 , 200, 50, "技能:"); 
	content(WIDTH / 2 + 250,HEIGHT / 2 - 100, 200, 50, "普 攻: j   伤害: 2 "); 
	content(WIDTH / 2 + 250,HEIGHT / 2 - 50, 200, 50, "技 能: k   伤害: 3"); 
	content(WIDTH / 2 + 250,HEIGHT / 2 , 200, 50, "技 能: l   伤害: 5"); 	
 

	//返回按钮
	button(WIDTH - 500, HEIGHT - 200, 200, 50, "返回");

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
					msg.message = 0;//把消息类型设置为0 
				}
			default:
				break;
			}
		}
	}
	return 0;
}


//3、选择关卡
int Select_level_interface()
{
	
	//输出图片
	IMAGE img3;//定义一个变量（对象）
	//加载图片
	loadimage(&img3, "./image/background1.1.jpg", WIDTH, HEIGHT);
	putimage(0, 0, &img3);

	//标题
	title(WIDTH / 2 - 250, HEIGHT / 2 - 300, 400, 100, "选择关卡");
	//按钮
	button(WIDTH / 2 - 350, HEIGHT / 2 - 100, 200, 50, "第一关");
	button(WIDTH / 2 + 50, HEIGHT / 2 - 100, 200, 50, "第二关");
	button(WIDTH / 2 -350, HEIGHT / 2 , 200, 50, "第三关");
	button(WIDTH / 2 + 50,HEIGHT / 2 ,200,50,"影子" ); 
	button(WIDTH / 2 -350,HEIGHT / 2 + 100 ,200,50,"虚幻"); 

	//返回按钮
	button(WIDTH - 500, HEIGHT - 200, 200, 50, "返回");

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
					//提示打开控制台 
					open_console(); 
					//第一关
					first_game();
					msg.message = 0;//把消息类型设置为0	
				}
				if(msg.x >= WIDTH / 2 + 50 && msg.y >= HEIGHT / 2 - 100 && msg.x <= WIDTH / 2 + 250 && msg.y <= HEIGHT / 2 - 50)
				{
					//提示打开控制台 
					open_console(); 
					//第二关 
					second_game();
					msg.message = 0;//把消息类型设置为0 
				}
				if(msg.x >= WIDTH / 2 -350 && msg.y >= HEIGHT / 2 && msg.x <= WIDTH / 2 -150 && msg.y <= HEIGHT / 2 + 50)
				{
					//提示打开控制台 
					open_console(); 
					//第三关
					third_game();
					msg.message = 0;//把消息类型设置为0
				}
				if(msg.x >= WIDTH / 2 + 50 && msg.y >= HEIGHT / 2  && msg.x <= msg.x <= WIDTH / 2 + 250 && msg.y <= HEIGHT / 2 + 50)
				{
					//提示打开控制台 
					open_console(); 
					//影子
					four_game();
					msg.message = 0;//把消息类型设置为0
				}
				if(msg.x >= WIDTH / 2 -350 &&  msg.y >= HEIGHT / 2 + 100 && msg.x <= msg.x <= WIDTH / 2 -150 && msg.y <= HEIGHT / 2 + 150)
				{
					//提示打开控制台 
					open_console(); 
					//虚幻 
					five_game();
					msg.message = 0;//把消息类型设置为0
				}
				if (msg.x >= WIDTH - 500 && msg.y >= HEIGHT - 200 && msg.x <= WIDTH - 300 && msg.y <= HEIGHT - 150)
				{
					start_interface();
					msg.message = 0;//把消息类型设置为0
				}
			default:
				break;
			}
		}
	}

	return 0;
}

//4、音乐设置
int music_settings()
{
	//输出图片
	IMAGE img3;//定义一个变量（对象）
	//加载图片
	loadimage(&img3, "./image/background1.1.jpg", WIDTH, HEIGHT);
	putimage(0, 0, &img3);

	//标题
	title(WIDTH / 2 - 250, HEIGHT / 2 - 300, 400, 100, "音乐设置");
	//按钮
	button(WIDTH / 2 - 150, HEIGHT / 2 - 50, 200, 50, "开启音乐");
	button(WIDTH / 2 - 150, HEIGHT / 2 + 50, 200, 50, "关闭音乐");
	button(WIDTH - 500, HEIGHT - 200, 200, 50, "返回");

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
					//开启音乐
					music_open();
					msg.message = 0;//把消息类型设置为0 
				}
				if (msg.x >= WIDTH / 2 - 150 && msg.y >= HEIGHT / 2 + 50 && msg.x <= WIDTH / 2 + 50 && msg.y <= HEIGHT / 2 + 100)
				{
					//关闭音乐
					music_close();
					msg.message = 0;//把消息类型设置为0 
				}
				if (msg.x >= WIDTH - 500 && msg.y >= HEIGHT - 200 && msg.x <= WIDTH - 300 && msg.y <= HEIGHT - 150)
				{
					start_interface();
					msg.message = 0;//把消息类型设置为0 
				}
			default:
				break;
			}
		}
	}
	return 0;
}

//5、最快纪录 
int fastest_record()
{
	//输出图片
	IMAGE img3;//定义一个变量（对象）
	//加载图片
	loadimage(&img3, "./image/background1.1.jpg", WIDTH, HEIGHT);
	putimage(0, 0, &img3);
	//第一关 纪录 
	int fastest_record_time = ret_game_time();
	char buf1[10];
	memset(buf1,0x00,10);
	sprintf(buf1,"%d",fastest_record_time);
	//第二关纪录 
	int fastest_record_time2 = ret_game_time2();
	char buf2[10];
	memset(buf2,0x00,10);
	sprintf(buf2,"%d",fastest_record_time2);
	//第三关纪录
	int fastest_record_time3 = ret_game_time3();
	char buf3[10];
	memset(buf3,0x00,10);
	sprintf(buf3,"%d",fastest_record_time3); 
	//第四关：影子纪录
	int fastest_record_time4 = ret_game_time4();
	char buf4[10];
	memset(buf4,0x00,10);
	sprintf(buf4,"%d",fastest_record_time4);
	//第五关：虚幻纪录
	int fastest_record_time5 = ret_game_time5();
	char buf5[10];
	memset(buf5,0x00,10);
	sprintf(buf5,"%d",fastest_record_time5);
	
	//标题
	title(WIDTH / 2 - 250, HEIGHT / 2 - 300, 400, 100, "通关最快纪录(秒)");
	//内容
	title(WIDTH / 2 - 300, HEIGHT / 2 - 100, 200, 50, "第一关:");
	content(WIDTH / 2 - 150, HEIGHT / 2 - 100, 200, 50,buf1);
	title(WIDTH / 2 - 300, HEIGHT / 2 , 200, 50, "第二关:");
	content(WIDTH / 2 - 150, HEIGHT / 2 , 200, 50,buf2);
	title(WIDTH / 2 - 300, HEIGHT / 2 + 100, 200, 50, "第三关:");
	content(WIDTH / 2 - 150, HEIGHT / 2 + 100 , 200, 50,buf3);
	title(WIDTH / 2 - 300, HEIGHT / 2 + 200, 200, 50, "影子:");
	content(WIDTH / 2 - 150, HEIGHT / 2 + 200 , 200, 50,buf4);
	title(WIDTH / 2 - 300, HEIGHT / 2 + 300, 200, 50, "虚幻:");
	content(WIDTH / 2 - 150, HEIGHT / 2 + 300 , 200, 50,buf5);
	
	//按钮
	button(WIDTH - 500, HEIGHT - 200, 200, 50, "返回");

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
					msg.message = 0;//把消息类型设置为0 
				}
			default:
				break;
			}
		}
	}
}

//窗口标题
void game_title()
{
	//获取窗口句柄
	HWND title = GetHWnd();
	//设置窗口标题
	SetWindowText(title, "重生之我在打BOSS");
}

//第一关游戏结束弹窗
void game_end(int game_results)
{
	int fastest_time;
	HWND game = GetHWnd();
	//弹出游戏结束框
	MessageBox(game, "游戏结束!", "提示", MB_OKCANCEL);//MessageBox返回的是int类型
	if (game_results > 0)//玩家胜利
	{
		//返回最快游戏记录 
		fastest_time = ret_game_time();
		if(fastest_time >= game_results)
		{
			player_victory();
			//破纪录弹窗
			record_breake();
			//写入最快游戏记录
			write_game_time(game_results); 
			
		}else
		{
			player_victory();
			//未破记录弹窗
			record_unbreake();
			
		}
	}
	else if(game_results == 0)//BOSS胜利
	{
		boss_victory();
	}
}

//第二关游戏结束弹窗
void game_end2(int game_results)
{
	int fastest_time;
	HWND game = GetHWnd();
	//弹出游戏结束框
	MessageBox(game, "游戏结束!", "提示", MB_OKCANCEL);//MessageBox返回的是int类型
	if (game_results > 0)//玩家胜利
	{
		//返回最快游戏记录 
		fastest_time = ret_game_time();
		if(fastest_time >= game_results)
		{
			player_victory();
			//破纪录弹窗
			record_breake();
			//写入最快游戏记录
			write_game_time2(game_results); 
			
		}else
		{
			player_victory();
			//未破记录弹窗
			record_unbreake();
			
		}
	}
	else if(game_results == 0)//BOSS胜利
	{
		boss_victory();
	}
}

//第三关游戏结束弹窗
void game_end3(int game_results)
{
	int fastest_time;
	HWND game = GetHWnd();
	//弹出游戏结束框
	MessageBox(game, "游戏结束!", "提示", MB_OKCANCEL);//MessageBox返回的是int类型
	if (game_results > 0)//玩家胜利
	{
		//返回最快游戏记录 
		fastest_time = ret_game_time();
		if(fastest_time >= game_results)
		{
			player_victory();
			//破纪录弹窗
			record_breake();
			//写入最快游戏记录
			write_game_time3(game_results); 
			
		}else
		{
			player_victory();
			//未破记录弹窗
			record_unbreake();
			
		}
	}
	else if(game_results == 0)//BOSS胜利
	{
		boss_victory();
	}
}

//第四关：影子游戏结束弹窗
void game_end4(int game_results)
{
	int fastest_time;
	HWND game = GetHWnd();
	//弹出游戏结束框
	MessageBox(game, "游戏结束!", "提示", MB_OKCANCEL);//MessageBox返回的是int类型
	if (game_results > 0)//玩家胜利
	{
		//返回最快游戏记录 
		fastest_time = ret_game_time();
		if(fastest_time >= game_results)
		{
			player_victory();
			//破纪录弹窗
			record_breake();
			//写入最快游戏记录
			write_game_time4(game_results); 
			
		}else
		{
			player_victory();
			//未破记录弹窗
			record_unbreake();
			
		}
	}
	else if(game_results == 0)//BOSS胜利
	{
		boss_victory();
	}
}

//第五关：虚幻游戏结束弹窗
void game_end5(int game_results)
{
	int fastest_time;
	HWND game = GetHWnd();
	//弹出游戏结束框
	MessageBox(game, "游戏结束!", "提示", MB_OKCANCEL);//MessageBox返回的是int类型
	if (game_results > 0)//玩家胜利
	{
		//返回最快游戏记录 
		fastest_time = ret_game_time();
		if(fastest_time >= game_results)
		{
			player_victory();
			//破纪录弹窗
			record_breake();
			//写入最快游戏记录
			write_game_time5(game_results); 
			
		}else
		{
			player_victory();
			//未破记录弹窗
			record_unbreake();
			
		}
	}
	else if(game_results == 0)//BOSS胜利
	{
		boss_victory();
	}
}

//玩家胜利弹窗
void player_victory()
{
	HWND player = GetHWnd();
	MessageBox(player, "玩家胜利！", "游戏结果", MB_OKCANCEL);
}

//BOSS胜利弹窗
void boss_victory()
{
	HWND boss = GetHWnd();
	MessageBox(boss, "BOSS胜利！", "游戏结果", MB_OKCANCEL);
	int isok = MessageBox(boss, "是否重新开始？", "提示", MB_OKCANCEL);
	if (isok == IDOK)
	{
		//重新加载游戏
		first_game();
	}
	else if (isok == IDCANCEL)
	{
		Select_level_interface();
	}
}

//开启音乐弹窗 
void music_open()
{
	HWND music = GetHWnd();
	//弹出对话框
	int isok = MessageBox(music, "是否开启音乐？", "音乐设置", MB_OKCANCEL);//MessageBox返回的是int类型
	if (isok == IDOK)
	{
		//打开音乐，播放音乐
		mciSendString("open ./music.mp3 alias BGM1", 0, 0, 0);//alias ,用BGM名称代替./music.mp3
		mciSendString("play BGM1 repeat", 0, 0, 0);//play播放， repeat 重复播放
	}
 
}

//关闭音乐弹窗 
void music_close()
{
	HWND music = GetHWnd();
	//弹出游戏结束框
	int isok = MessageBox(music, "是否关闭音乐？", "音乐设置", MB_OKCANCEL);//MessageBox返回的是int类型
	if (isok == IDOK)
	{
		mciSendString("close BGM1 ", 0, 0, 0);
	}
	
}

//打破纪录弹窗
void record_breake()
{
	HWND record_breake = GetHWnd();
	int isok = MessageBox(record_breake, "恭喜您打破纪录！", "提示", MB_OKCANCEL);//MessageBox返回的是int类型
	if (isok == IDOK)
	{
		Select_level_interface(); 
	}
}

//未打破记录弹窗
void  record_unbreake()
{
	HWND record_unbreake = GetHWnd();
	int isok = MessageBox(record_unbreake, "很遗憾，您未打破纪录！", "提示", MB_OKCANCEL);//MessageBox返回的是int类型
	if (isok == IDOK)
	{
		Select_level_interface(); 
	}
}

//提示打开控制台弹窗 
void open_console()
{
	HWND open_console = GetHWnd();
	int isok = MessageBox(open_console, "请在控制台上进行游戏!!!(注:请将控制台最大化)", "提示", MB_OKCANCEL);//MessageBox返回的是int类型
//	if (isok == IDOK)
//	{
//		//获取控制台窗口句柄
//		HWND game = GetConsoleWindow();
//  	//将控制台窗口置于顶层 
//		SetWindowPos(game,HWND_TOPMOST,0,0,0,0,0);
//	}
}

//隐藏光标
void HideCursor()
{
	CONSOLE_CURSOR_INFO curInfo; //定义光标信息的结构体变量
	curInfo.dwSize = 1; //将光标大小设置为1，如果没赋值的话，光标隐藏无效
	curInfo.bVisible = FALSE; //可见性为假，即将光标设置为不可见 
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
	SetConsoleCursorInfo(handle, &curInfo); //设置光标信息
}

//第一关
int first_game()
{
	//关闭绘图窗口 
	closegraph();

	int boss_blood = 100;//默认boss血量值 
	int player_blood = 100;//默认玩家血量值 
	int time_game = 300;//默认游戏时间 
	int height_map = 50;//默认地图的高 
	int width_map = 150;//默认地图的宽
	int boss_cd = 5;//默认boss技能cd时间 
	int boss_attck = 10;//默认boss攻击值  
	int boss_number = 1;//1号BOSS 
					
	pthread_mutex_init(&xpthread_var.mutex_attack,NULL);
    pthread_mutex_init(&xpthread_var.mutex_print,NULL);
    pthread_mutex_init(&xpthread_var.mutex_cooling,NULL);
	Sleep(5000);
	
	//run_game(BOSS血量,玩家血量,游戏时间,地图的高,地图的宽）; 
	//可以让玩家实现自定义游戏设置 
	int game_results = run_game(boss_blood,player_blood,time_game,height_map,width_map,boss_cd,boss_attck,boss_number);
	
	pthread_mutex_destroy(&xpthread_var.mutex_attack);
    pthread_mutex_destroy(&xpthread_var.mutex_print);
    pthread_mutex_destroy(&xpthread_var.mutex_cooling);
	
	if(game_results >= 0)
	{
		//重新绘制窗口
		initgraph(1920, 1080,EX_SHOWCONSOLE);
		game_title();
		game_end(game_results);
	}
	
 } 
 
//第二关 
int second_game()
{
	//关闭绘图窗口 
	closegraph();

	int boss_blood = 150;//默认boss血量值 
	int player_blood = 100;//默认玩家血量值 
	int time_game = 240;//默认游戏时间 
	int height_map = 40;//默认地图的高 
	int width_map = 150;//默认地图的宽
	int boss_cd = 3;//默认boss技能时间
	int boss_attck = 15;//默认boss攻击值 
	int boss_number = 2;//2号BOSS 
					
	pthread_mutex_init(&xpthread_var.mutex_attack,NULL);
    pthread_mutex_init(&xpthread_var.mutex_print,NULL);
    pthread_mutex_init(&xpthread_var.mutex_cooling,NULL);
	Sleep(5000);
	
	//run_game(BOSS血量,玩家血量,游戏时间,地图的高,地图的宽）; 
	//可以让玩家实现自定义游戏设置 
	int game_results = run_game(boss_blood,player_blood,time_game,height_map,width_map,boss_cd,boss_attck,boss_number);
	
	pthread_mutex_destroy(&xpthread_var.mutex_attack);
    pthread_mutex_destroy(&xpthread_var.mutex_print);
    pthread_mutex_destroy(&xpthread_var.mutex_cooling);
	
	if(game_results >= 0)
	{
		//重新绘制窗口
		initgraph(1920, 1080,EX_SHOWCONSOLE);
		game_title();
		game_end2(game_results);
	}
	
}

//第三关
int  third_game()
{
	//关闭绘图窗口 
	closegraph();
	
	int boss_blood = 150;//默认boss血量值 
	int player_blood = 100;//默认玩家血量值 
	int time_game = 180;//默认游戏时间 
	int height_map = 50;//默认地图的高 
	int width_map = 150;//默认地图的宽
	int boss_cd = 10;//默认boss技能cd时间 
	int boss_attck = 15;//默认boss攻击值  
	int boss_number=3;//3号BOSS 
					
	pthread_mutex_init(&xpthread_var.mutex_attack,NULL);
    pthread_mutex_init(&xpthread_var.mutex_print,NULL);
    pthread_mutex_init(&xpthread_var.mutex_cooling,NULL);
	Sleep(5000);
	
	//run_game(BOSS血量,玩家血量,游戏时间,地图的高,地图的宽）; 
	//可以让玩家实现自定义游戏设置 
	int game_results = run_game(boss_blood,player_blood,time_game,height_map,width_map,boss_cd,boss_attck,boss_number);
	
	pthread_mutex_destroy(&xpthread_var.mutex_attack);
    pthread_mutex_destroy(&xpthread_var.mutex_print);
    pthread_mutex_destroy(&xpthread_var.mutex_cooling);
	
	if(game_results >= 0)
	{
		//重新绘制窗口
		initgraph(1920, 1080,EX_SHOWCONSOLE);
		game_title();
		game_end3(game_results);
	} 
}

//第四关：影子
int four_game()
{
	//关闭绘图窗口 
	closegraph();
	
	int boss_blood = 20;//默认boss血量值 
	int player_blood = 100;//默认玩家血量值 
	int time_game = 300;//默认游戏时间 
	int height_map = 50;//默认地图的高 
	int width_map = 150;//默认地图的宽
	int boss_cd = 5;//默认boss技能cd时间 
	int boss_attck = 15;//默认boss攻击值  
	int boss_number=3;//3号BOSS 
					
	pthread_mutex_init(&xpthread_var.mutex_attack,NULL);
    pthread_mutex_init(&xpthread_var.mutex_print,NULL);
    pthread_mutex_init(&xpthread_var.mutex_cooling,NULL);
	Sleep(5000);
	
	//run_game(BOSS血量,玩家血量,游戏时间,地图的高,地图的宽）; 
	//可以让玩家实现自定义游戏设置 
	int game_results = run_game_two(boss_blood,player_blood,time_game,height_map,width_map,boss_cd,boss_attck,boss_number);
	
	pthread_mutex_destroy(&xpthread_var.mutex_attack);
    pthread_mutex_destroy(&xpthread_var.mutex_print);
    pthread_mutex_destroy(&xpthread_var.mutex_cooling);
	
	if(game_results >= 0)
	{
		//重新绘制窗口
		initgraph(1920, 1080,EX_SHOWCONSOLE);
		game_title();
		game_end4(game_results);
	}
 } 
 
 //第五关：虚幻 
int five_game()
{
	//关闭绘图窗口 
	closegraph();
	
	int boss_blood = 100;//默认boss血量值 
	int player_blood = 100;//默认玩家血量值 
	int time_game = 300;//默认游戏时间 
	int height_map = 50;//默认地图的高 
	int width_map = 150;//默认地图的宽
	int boss_cd = 5;//默认boss技能cd时间 
	int boss_attck = 15;//默认boss攻击值  
	int boss_number=3;//3号BOSS 
					
	pthread_mutex_init(&xpthread_var.mutex_attack,NULL);
    pthread_mutex_init(&xpthread_var.mutex_print,NULL);
    pthread_mutex_init(&xpthread_var.mutex_cooling,NULL);
	Sleep(5000);
	
	//run_game(BOSS血量,玩家血量,游戏时间,地图的高,地图的宽）; 
	//可以让玩家实现自定义游戏设置 
	int game_results = run_game_four(boss_blood,player_blood,time_game,height_map,width_map,boss_cd,boss_attck,boss_number);
	
	pthread_mutex_destroy(&xpthread_var.mutex_attack);
    pthread_mutex_destroy(&xpthread_var.mutex_print);
    pthread_mutex_destroy(&xpthread_var.mutex_cooling);
	
	if(game_results >= 0)
	{
		//重新绘制窗口
		initgraph(1920, 1080,EX_SHOWCONSOLE);
		game_title();
		game_end5(game_results);
	}
 } 

//返回第一关最快游戏记录 
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

//写入第一关最快游戏记录
void write_game_time(int i){
	FILE* pf=fopen("fastest_game_time.txt","w");
	fprintf(pf,"%d ",i);
	fclose(pf);
	return;
}

//返回第二关最快游戏记录 
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

//写入第二关最快游戏记录
void write_game_time2(int i){
	FILE* pf=fopen("fastest_game_time2.txt","w");
	fprintf(pf,"%d ",i);
	fclose(pf);
	return;
}

//返回第三关最快游戏记录 
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

//写入第三关最快游戏记录
void write_game_time3(int i){
	FILE* pf=fopen("fastest_game_time3.txt","w");
	fprintf(pf,"%d ",i);
	fclose(pf);
	return;
}

//返回第四关：影子最快游戏记录 
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

//写入第四关：影子最快游戏记录
void write_game_time4(int i){
	FILE* pf=fopen("fastest_game_time4.txt","w");
	fprintf(pf,"%d ",i);
	fclose(pf);
	return;
}

//返回第五关：虚幻最快游戏记录 
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

//写入第五关：虚幻最快游戏记录
void write_game_time5(int i){
	FILE* pf=fopen("fastest_game_time5.txt","w");
	fprintf(pf,"%d ",i);
	fclose(pf);
	return;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	
	//设置cmd窗口的名字
	system("title 《重生之我在打BOSS》"); 
	initgraph(1920, 1080,EX_SHOWCONSOLE);
	//背景音乐
	BGM1();
	//窗口标题
	game_title();
	//隐藏光标 
	HideCursor();
	//开始界面
	start_interface();
	
	return 0;
}
