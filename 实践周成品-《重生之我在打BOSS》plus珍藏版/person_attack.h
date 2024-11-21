#ifndef PERSON_ATTACK_H
#define PERSON_ATTACK_H

#ifdef __cplusplus
extern "C"{
#endif

#pragma once
#include "variate.h"
//���﹥��ͷ�ļ�  
//��������ĳ�ʼ�� ���ܵĳ�ʼ�� ��ͨ�����ĳ�ʼ�� 

//�����ʼ��
void friend_person(person* friend1, char rudder, int attack,xy_coord* coord,attack_cooling* time_attack);//��� 
void rivalry_person(person* friend1, char rudder, int attack,xy_coord* coord,attack_cooling* time_attack);//���� 
void two_rivalry_person(person* friend1, char rudder, int attack,xy_coord* coord,attack_cooling* time_attack);
void three_rivalry_person(person* friend1, char rudder, int attack,xy_coord* coord,attack_cooling* time_attack);
//rivalry ����ָ�� ,rudder����ĳ�ʼ���� ,attack�������ͨ������ ,coord����ĳ�ʼ�����ָ��,time_attack�ǹ���ָ���ȫ��ʱ����ȴ attack_cd���� 

//����Ѫ����ʼ��
int person_init(person* people, int blood);//�ɸ���������Ĺ������� 
//people����ָ��,blood����ĳ�ʼ��Ѫ�� 

//���ܹ�����ʼ��
void rivalry_attackk(person* people,skill* people_attack, int harm);//���˼��� 
void two_rivalry_attackl(person* people,skill* people_attack, int harm);//���˼��� 
void friend_attackk(person* people,skill* people_attack, int harm);//��� k ���� 
void friend_attackl(person* people,skill* people_attack, int harm);//��� l ���� 
//people_attack�Ǽ���ָ�� ,rudder�Ǽ��ܵķ����ַ� ,harm�Ǽ��ܵ��˺� ,num�Ǽ�����ȴʱ��

//��ͨ������ʼ��
void attack_initj(person* people,pool_attack* pool);
//people������ָ�� ,pool��ͨ������ָ�� 

#ifdef __cplusplus
}
#endif

#endif
