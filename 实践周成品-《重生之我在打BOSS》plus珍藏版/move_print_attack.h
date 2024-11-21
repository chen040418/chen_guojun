#ifndef MOVE_PRINT_ATTACK_H
#define MOVE_PRINT_ATTACK_H

#ifdef __cplusplus
extern "C"{
#endif

#pragma once
#include"variate.h"
//移动打印和攻击相关 

//将指定区域的所有内容清除
void empty_shape(xy_coord* coord, int num);//num为0则只清除该点的内容 
//coord是所要清除区域的中心坐标 ,num是清除区域的半径 (2*num+1 为清除区域的高宽(正方形区域)) 

//判断是否能移动
int if_move(xy_coord* coord1, xy_coord* coord2, xy_coord* coord3, char rudder, int num);
//coord1是所要移动物体的坐标,coord2是对应的墙壁坐标,coord3是所要攻击人物的坐标,rudder是物体前进的方向
//num是 移动的步数大小 
//碰到墙壁不能移动返回0,碰到敌对人物不能移动返回-1,能移动返回1 

//技能移动
void move_skill(skill* skill_move);
//skill_move是要移动技能的指针

//普通攻击的移动
void move_pool(pool_attack* pool);
//pool是普通攻击的指针

//人物的移动
void move_person(person* people);
//people是对应人物的指针

//判断玩家的移动和技能释放//后面要整合字符一起使用
char command_person(person* people, char move_and_attack);
//移动字符或者技能字符 

//攻击
//////////////////////////////////////////////////////////// 

//判断能否攻击
int send_skill(attack_cooling* people_attack_cooling, int num,char skill_char);
//people_attack_cooling是对应人物的攻击冷却,num是冷却攻击的变量个数,skill_char是攻击的字符
//返回技能冷却时间，返回为0则代表攻击能发射

 //普通攻击位置赋值 //用于攻击创建 
 void pool_coord_value(person* people,pool_attack* pool_at);
 //people是发出攻击的人物
 //pool_at是创建好的普攻指针 
 
  //技能攻击位置赋值 //用于攻击创建 
 void skill_coord_value(person* people,skill* skill_at);
 //people是发出攻击的人物
 //skill_at是创建好的普攻指针
 
 //判断攻击是否会出界
 int judge_attack_interface(xy_coord* coord1,char rudder,char attack_char);
 //coord1是此时发出攻击的人物坐标
 //rudder是发出攻击的人物方向 
//返回 为0不可以释放攻击,返回为真可以释放攻击 
 //attack_char是攻击所代表的字符 
 
 
 
 //将普通攻击整合到普通攻击数组上
 void make_pool_attack(pool_attack* pak,person* people,attack_cooling* attackcooling,char rudder);
 //pak是对应的普通攻击顺序表,people是发出普通攻击的指针,attackcooling是对应的普通冷却数组,rudder是技能释放的方向
 
  
 //将技能攻击整合到技能攻击数组上
 void make_skill_attack(skill* pak,person* people,attack_cooling* attackcooling,char rudder,int num,int attackchar,int time_num,int attack_num);
 //pak是对应的技能攻击顺序表,people是发出技能攻击的指针,attackcooling是对应的技能冷却数组,rudder是技能释放的方向,num是该冷却数组的大小 ,attackchar是技能的符号,time_num是技能的冷却时间 

#ifdef __cplusplus
}
#endif

#endif
