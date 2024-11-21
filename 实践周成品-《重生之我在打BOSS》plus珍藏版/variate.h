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
//��������ͷ�ļ�

//����ṹ��
typedef struct xy_coord {
	int x;//������
	int y;//������
}xy_coord; 

//���ܽṹ��
typedef struct skill {//��������
	char skill_shape[5][6];//������״
	int run;//���ܹ���������״̬(Ϊ������,Ϊ�ٸÿռ䱻�ͷ�)
	int higt;//���ܵĸ�
	int width;//���ܵĿ�
	char rudder;//���ܵ�ǰ������
	int skill_attack;//������
	xy_coord coord1;//����ԭ����             0//�ڷ���ʱʹ�ú�����ֵ 
	xy_coord coord2;//���ܱ仯�������       0//�ڷ���ʱʹ�ú�����ֵ 
	char people_type;//�����ù������������� 
	xy_coord* rivalry_coord;//���������������ָ�� 
}skill;


//�չ��ṹ��
typedef struct pool_attack {
	char attack_shape;//��ͨ��������״
	char rudder;//��ͨ������ǰ������
	int num_attack;//��ͨ�����Ĺ����� 
	int run;//��ͨ����������״̬(Ϊ������,Ϊ�ٸÿռ䱻�ͷ�)
	xy_coord coord1;//�չ�ԭ����             0//�ڷ�������ʱ�����к������и�ֵ 
	xy_coord coord2;//�չ��仯�������       0//�ڷ�������ʱ�����к������и�ֵ
	char people_type;//�����ù������������� 
	xy_coord* rivalry_coord;//���������������ָ�� 
}pool_attack; 
//������ع�����ȴ�ṹ�� 
typedef struct attack_cooling{
	char attack_char;//��������
	int time_cooling;//��Ӧ������ȴʱ�� 
}attack_cooling;

//����ع�����ȴȫ�ֱ���
//boss��ع�����ȴ 
 attack_cooling rivalry_attack_cooling[2];
 attack_cooling three_rivalry_attack_cooling[3];

//�����ع�����ȴ
 attack_cooling friend_attack_cooling[3];

//����ṹ��
typedef struct person {//����
    int people_num;//�������������//���1//һ��boss1//����boss2//����boss3
	char people_shape[5][6];//������״
	int higt;//����ĸ�
	int width;//����Ŀ�
	char people_type;//�ַ�q�������,�ַ�e����boss
	int run_num;//����ÿ���ƶ��ľ���     0
	char rudder;//�����ǰ������
	int blood;//Ѫ��               0
 	int attack;//�����չ�������
	attack_cooling* attack_skill_cd;//����Ĺ�����ȴʱ�� 
	xy_coord coord1;//����ԭ����
	xy_coord coord2;//����仯�������
	xy_coord* change_coord;//�ж�����������ַ  0
}person;

//ǽ������ṹ�� 
typedef struct coord_char {
	char rudder;//���洢�Ķ�Ӧ������ַ�
	xy_coord coord1;//�ַ�����Ӧ��ǽ�ڵ�����
}coord_char;
typedef struct coord_char_arr {
	coord_char coord_arr[4];//��Ӧ�ĸ�����
}coord_char_arr;


//�߳����
///////////////////////////////////////////////////////////////////////// 
typedef struct pthread_variable{
	int pthread_quit;//���Ʋ������߳��˳���ȫ�ֱ�����Ϊ�����������߳����� 
	int time_print; //��Ϸ��ʱ�� //ʱ��������� 
	pthread_mutex_t mutex_cooling;//������ȴ��
	pthread_mutex_t mutex_attack;//����������
	pthread_mutex_t mutex_print;//���еĹ�궨λ��ӡ��
}pthread_variable; 

pthread_variable xpthread_var;//��Ҫ�ڳ�������ʱ��ʼ�� 

 
//ʱ����ȴ��ʼ������
void attack_cooling_init(attack_cooling* cooling,int num);
//cooling�����Ӧȫ�ֱ��� ��num�Ǹ�cooling�ı������� 

//������ȴ�̴߳������ 
typedef struct thread_attack_cooling{
	attack_cooling* rivalry_cooling;//boss������ȴָ��
	attack_cooling* friend_cooling;//��ҹ�����ȴָ�� 
	pthread_variable* thread_var;//���߳̿������ 
}thread_attack_cooling;

thread_attack_cooling thread_cooling;//��Ҫ�ڳ�������ʱ��ֵ 

//Ѫ������̴߳������
typedef struct thread_blood{
	person* thread_friend_people;//���ָ�� 
	person* thread_rivalry_people;//bossָ�� 
	person* rivalry_two_people;//���Ĺ�bossָ�� 
	pthread_variable* p2;//�߳̿��Ʊ��� 
}thread_blood; 

thread_blood thread_blood_mul;

//�����̺߳͹���ʱʹ�ò���
	pool_attack pla[100];//��ͨ������������
	skill sk[100];//���ܹ����洢����

//�����̴߳������ 
typedef struct thread_attack_arr{
	pool_attack* pa;//��ͨ�����洢������ʼָ�� 
	skill* s;//���ܹ����洢������ʼָ�� 
	pthread_variable* p1;//�߳̿��Ʊ���ָ�� 
	person* friendpeople;//���ָ�� 
	person* rivalrypeople;//bossָ�� 
	person* rivalrytwopeople;//���Ĺص�bossָ��// 
}thread_attack_arr; 
	 
	 thread_attack_arr thread_attack;


//����ͷ�ļ�������ʹ�õ��ĺ��� 
////////////////////////////////////////////////////////////////////////////////
//�����ǽ��ȫ������
coord_char_arr rudder_coord;//��ͼ���ʱ���Ѿ���ʼ�� 

//��ͼ�������
void print_1(int num1, int num2) ;//������ȫ�ֱ�����ͼǽ�������ֵ
//num1�ǵ�ͼ�ĸ�y//num2�ǵ�ͼ�Ŀ�x

//ǽ�������ȡ����   
xy_coord* get_rudder(char rudder_char) ;
//�����Ӧ�ַ���ȡ��Ӧ��ǽ�������ַ,���򷵻�NULL;


#ifdef __cplusplus
}
#endif

#endif


