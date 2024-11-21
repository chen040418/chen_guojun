#ifndef THREAD_RELEVANT_H
#define THREAD_RELEVANT_H

#ifdef __cplusplus
extern "C"{
#endif

#pragma once
#include<time.h>
#include"variate.h"
#include"person_attack.h"
#include"move_print_attack.h"

//boss的移动和攻击
void move_rivalry_people(person* people,int time_num,int attack_num);
//游戏运行函数
int run_game(int rivalry_blood,int friend_blood,int time_game,int y_size,int x_size,int time_num,int attack_num,int people_num);
int run_game_two(int rivalry_blood,int friend_blood,int time_game,int y_size,int x_size,int time_num,int attack_num,int people_num);
int run_game_four(int rivalry_blood,int friend_blood,int time_game,int y_size,int x_size,int time_num,int attack_num,int people_num);
// rivalry_blood敌人血量, friend_blood 玩家血量 ,time_game是游戏进行的总时长,y_size是竖轴的长度,x_size是横轴的长度 
//time_num是boss技能冷却时间,attack_num是boss技能攻击力 //people_num代表boss等级 

//boss移动输出线程 
void* thread_boss_print(void* arg); 
void* two_thread_boss_print(void* arg);
void* four_boss_print(void* arg);
//冷却控制线程
void* thread_list_cooling(void* arg);
void* three_thread_list_cooling(void* arg);
//攻击输出线程
void* thread_list_attack(void* arg);
void* two_thread_list_attack(void* arg);
//时间打印线程
void* print_time(void* arg); 

//血量输出线程
void* print_blood(void* arg);
void* two_print_blood(void* arg);
//boss打印线程传入参数 
typedef struct boss_val{
	person* people;//boss指针 //执行时赋值 
	person* people2;//第四关的第二个boss其它关卡置为空 
	//void (*boss_exex)(person* );
	pthread_variable* p1;
	int time_num;//boss技能冷却时间 
	int attack_num;//boss技能攻击力 
}boss_val;

boss_val boss_var;
boss_val boss_var1;




#ifdef __cplusplus
}
#endif

#endif
