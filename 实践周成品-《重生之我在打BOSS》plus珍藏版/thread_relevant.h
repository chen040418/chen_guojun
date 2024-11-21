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

//boss���ƶ��͹���
void move_rivalry_people(person* people,int time_num,int attack_num);
//��Ϸ���к���
int run_game(int rivalry_blood,int friend_blood,int time_game,int y_size,int x_size,int time_num,int attack_num,int people_num);
int run_game_two(int rivalry_blood,int friend_blood,int time_game,int y_size,int x_size,int time_num,int attack_num,int people_num);
int run_game_four(int rivalry_blood,int friend_blood,int time_game,int y_size,int x_size,int time_num,int attack_num,int people_num);
// rivalry_blood����Ѫ��, friend_blood ���Ѫ�� ,time_game����Ϸ���е���ʱ��,y_size������ĳ���,x_size�Ǻ���ĳ��� 
//time_num��boss������ȴʱ��,attack_num��boss���ܹ����� //people_num����boss�ȼ� 

//boss�ƶ�����߳� 
void* thread_boss_print(void* arg); 
void* two_thread_boss_print(void* arg);
void* four_boss_print(void* arg);
//��ȴ�����߳�
void* thread_list_cooling(void* arg);
void* three_thread_list_cooling(void* arg);
//��������߳�
void* thread_list_attack(void* arg);
void* two_thread_list_attack(void* arg);
//ʱ���ӡ�߳�
void* print_time(void* arg); 

//Ѫ������߳�
void* print_blood(void* arg);
void* two_print_blood(void* arg);
//boss��ӡ�̴߳������ 
typedef struct boss_val{
	person* people;//bossָ�� //ִ��ʱ��ֵ 
	person* people2;//���Ĺصĵڶ���boss�����ؿ���Ϊ�� 
	//void (*boss_exex)(person* );
	pthread_variable* p1;
	int time_num;//boss������ȴʱ�� 
	int attack_num;//boss���ܹ����� 
}boss_val;

boss_val boss_var;
boss_val boss_var1;




#ifdef __cplusplus
}
#endif

#endif
