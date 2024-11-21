#ifndef VARIATE_H
#define VARIATE_H

#ifdef __cplusplus
extern "C"{
#endif

#pragma once
#include<stdio.h>
#include<conio.h>
#include<pthread.h>
#include<stdlib.h>
#include<windows.h> 
//变量定义头文件

//坐标结构体
typedef struct xy_coord {
	int x;//横坐标
	int y;//竖坐标
}xy_coord; 

//技能结构体
typedef struct skill {//攻击技能
	char skill_shape[5][6];//攻击形状
	int run;//技能攻击的运行状态(为真运行,为假该空间被释放)
	int higt;//技能的高
	int width;//技能的宽
	char rudder;//技能的前进方向
	int skill_attack;//攻击力
	xy_coord coord1;//技能原坐标             0//在发出时使用函数赋值 
	xy_coord coord2;//技能变化后的坐标       0//在发出时使用函数赋值 
	char people_type;//发出该攻击的人物类型 
	xy_coord* rivalry_coord;//所攻击对象的坐标指针 
}skill;


//普攻结构体
typedef struct pool_attack {
	char attack_shape;//普通攻击的形状
	char rudder;//普通攻击的前进方向
	int num_attack;//普通攻击的攻击力 
	int run;//普通攻击的运行状态(为真运行,为假该空间被释放)
	xy_coord coord1;//普攻原坐标             0//在发出攻击时单独有函数进行赋值 
	xy_coord coord2;//普攻变化后的坐标       0//在发出攻击时单独有函数进行赋值
	char people_type;//发出该攻击的人物类型 
	xy_coord* rivalry_coord;//所攻击对象的坐标指针 
}pool_attack; 
//人物相关攻击冷却结构体 
typedef struct attack_cooling{
	char attack_char;//攻击符号
	int time_cooling;//对应攻击冷却时间 
}attack_cooling;

//物相关攻击冷却全局变量
//boss相关攻击冷却 
 attack_cooling rivalry_attack_cooling[2];
 attack_cooling three_rivalry_attack_cooling[3];

//玩家相关攻击冷却
 attack_cooling friend_attack_cooling[3];

//人物结构体
typedef struct person {//人物
    int people_num;//代表人物的量级//玩家1//一级boss1//二级boss2//三级boss3
	char people_shape[5][6];//人物形状
	int higt;//人物的高
	int width;//人物的宽
	char people_type;//字符q代表玩家,字符e代表boss
	int run_num;//人物每次移动的距离     0
	char rudder;//人物的前进方向
	int blood;//血量               0
 	int attack;//人物普攻攻击力
	attack_cooling* attack_skill_cd;//人物的攻击冷却时间 
	xy_coord coord1;//人物原坐标
	xy_coord coord2;//人物变化后的坐标
	xy_coord* change_coord;//敌对人物的坐标地址  0
}person;

//墙壁坐标结构体 
typedef struct coord_char {
	char rudder;//所存储的对应方向的字符
	xy_coord coord1;//字符所对应的墙壁的坐标
}coord_char;
typedef struct coord_char_arr {
	coord_char coord_arr[4];//对应四个坐标
}coord_char_arr;


//线程相关
///////////////////////////////////////////////////////////////////////// 
typedef struct pthread_variable{
	int pthread_quit;//控制部分子线程退出的全局变量，为真则所有子线程运行 
	int time_print; //游戏总时长 //时间输出变量 
	pthread_mutex_t mutex_cooling;//操作冷却锁
	pthread_mutex_t mutex_attack;//操作攻击锁
	pthread_mutex_t mutex_print;//所有的光标定位打印锁
}pthread_variable; 

pthread_variable xpthread_var;//需要在程序运行时初始化 

 
//时间冷却初始化函数
void attack_cooling_init(attack_cooling* cooling,int num);
//cooling是相对应全局变量 ，num是该cooling的变量个数 

//攻击冷却线程传入参数 
typedef struct thread_attack_cooling{
	attack_cooling* rivalry_cooling;//boss攻击冷却指针
	attack_cooling* friend_cooling;//玩家攻击冷却指针 
	pthread_variable* thread_var;//子线程控制相关 
}thread_attack_cooling;

thread_attack_cooling thread_cooling;//需要在程序运行时赋值 

//血量输出线程传入参数
typedef struct thread_blood{
	person* thread_friend_people;//玩家指针 
	person* thread_rivalry_people;//boss指针 
	person* rivalry_two_people;//第四关boss指针 
	pthread_variable* p2;//线程控制变量 
}thread_blood; 

thread_blood thread_blood_mul;

//攻击线程和攻击时使用参数
	pool_attack pla[100];//普通攻击储存数组
	skill sk[100];//技能攻击存储数组

//攻击线程传入参数 
typedef struct thread_attack_arr{
	pool_attack* pa;//普通攻击存储数组起始指针 
	skill* s;//技能攻击存储数组起始指针 
	pthread_variable* p1;//线程控制变量指针 
	person* friendpeople;//玩家指针 
	person* rivalrypeople;//boss指针 
	person* rivalrytwopeople;//第四关的boss指针// 
}thread_attack_arr; 
	 
	 thread_attack_arr thread_attack;


//所有头文件都可能使用到的函数 
////////////////////////////////////////////////////////////////////////////////
//定义的墙壁全局坐标
coord_char_arr rudder_coord;//地图输出时就已经初始化 

//地图界面输出
void print_1(int num1, int num2) ;//并设置全局变量地图墙壁坐标的值
//num1是地图的高y//num2是地图的宽x

//墙壁坐标获取函数   
xy_coord* get_rudder(char rudder_char) ;
//输入对应字符获取对应的墙壁坐标地址,否则返回NULL;


#ifdef __cplusplus
}
#endif

#endif


