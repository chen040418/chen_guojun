#ifndef PERSON_ATTACK_H
#define PERSON_ATTACK_H

#ifdef __cplusplus
extern "C"{
#endif

#pragma once
#include "variate.h"
//人物攻击头文件  
//包含人物的初始化 技能的初始化 普通攻击的初始化 

//人物初始化
void friend_person(person* friend1, char rudder, int attack,xy_coord* coord,attack_cooling* time_attack);//玩家 
void rivalry_person(person* friend1, char rudder, int attack,xy_coord* coord,attack_cooling* time_attack);//敌人 
void two_rivalry_person(person* friend1, char rudder, int attack,xy_coord* coord,attack_cooling* time_attack);
void three_rivalry_person(person* friend1, char rudder, int attack,xy_coord* coord,attack_cooling* time_attack);
//rivalry 人物指针 ,rudder人物的初始方向 ,attack人物的普通攻击力 ,coord人物的初始坐标的指针,time_attack是攻击指向的全局时间冷却 attack_cd数组 

//人物血量初始化
int person_init(person* people, int blood);//可复用于人物的攻击减伤 
//people人物指针,blood人物的初始化血量 

//技能攻击初始化
void rivalry_attackk(person* people,skill* people_attack, int harm);//敌人技能 
void two_rivalry_attackl(person* people,skill* people_attack, int harm);//敌人技能 
void friend_attackk(person* people,skill* people_attack, int harm);//玩家 k 技能 
void friend_attackl(person* people,skill* people_attack, int harm);//玩家 l 技能 
//people_attack是技能指针 ,rudder是技能的方向字符 ,harm是技能的伤害 ,num是技能冷却时间

//普通攻击初始化
void attack_initj(person* people,pool_attack* pool);
//people是人物指针 ,pool普通攻击的指针 

#ifdef __cplusplus
}
#endif

#endif
