#ifndef MOVE_PRINT_ATTACK_H
#define MOVE_PRINT_ATTACK_H

#ifdef __cplusplus
extern "C"{
#endif

#pragma once
#include"variate.h"
//�ƶ���ӡ�͹������ 

//��ָ������������������
void empty_shape(xy_coord* coord, int num);//numΪ0��ֻ����õ������ 
//coord����Ҫ���������������� ,num���������İ뾶 (2*num+1 Ϊ�������ĸ߿�(����������)) 

//�ж��Ƿ����ƶ�
int if_move(xy_coord* coord1, xy_coord* coord2, xy_coord* coord3, char rudder, int num);
//coord1����Ҫ�ƶ����������,coord2�Ƕ�Ӧ��ǽ������,coord3����Ҫ�������������,rudder������ǰ���ķ���
//num�� �ƶ��Ĳ�����С 
//����ǽ�ڲ����ƶ�����0,�����ж����ﲻ���ƶ�����-1,���ƶ�����1 

//�����ƶ�
void move_skill(skill* skill_move);
//skill_move��Ҫ�ƶ����ܵ�ָ��

//��ͨ�������ƶ�
void move_pool(pool_attack* pool);
//pool����ͨ������ָ��

//������ƶ�
void move_person(person* people);
//people�Ƕ�Ӧ�����ָ��

//�ж���ҵ��ƶ��ͼ����ͷ�//����Ҫ�����ַ�һ��ʹ��
char command_person(person* people, char move_and_attack);
//�ƶ��ַ����߼����ַ� 

//����
//////////////////////////////////////////////////////////// 

//�ж��ܷ񹥻�
int send_skill(attack_cooling* people_attack_cooling, int num,char skill_char);
//people_attack_cooling�Ƕ�Ӧ����Ĺ�����ȴ,num����ȴ�����ı�������,skill_char�ǹ������ַ�
//���ؼ�����ȴʱ�䣬����Ϊ0��������ܷ���

 //��ͨ����λ�ø�ֵ //���ڹ������� 
 void pool_coord_value(person* people,pool_attack* pool_at);
 //people�Ƿ�������������
 //pool_at�Ǵ����õ��չ�ָ�� 
 
  //���ܹ���λ�ø�ֵ //���ڹ������� 
 void skill_coord_value(person* people,skill* skill_at);
 //people�Ƿ�������������
 //skill_at�Ǵ����õ��չ�ָ��
 
 //�жϹ����Ƿ�����
 int judge_attack_interface(xy_coord* coord1,char rudder,char attack_char);
 //coord1�Ǵ�ʱ������������������
 //rudder�Ƿ������������﷽�� 
//���� Ϊ0�������ͷŹ���,����Ϊ������ͷŹ��� 
 //attack_char�ǹ�����������ַ� 
 
 
 
 //����ͨ�������ϵ���ͨ����������
 void make_pool_attack(pool_attack* pak,person* people,attack_cooling* attackcooling,char rudder);
 //pak�Ƕ�Ӧ����ͨ����˳���,people�Ƿ�����ͨ������ָ��,attackcooling�Ƕ�Ӧ����ͨ��ȴ����,rudder�Ǽ����ͷŵķ���
 
  
 //�����ܹ������ϵ����ܹ���������
 void make_skill_attack(skill* pak,person* people,attack_cooling* attackcooling,char rudder,int num,int attackchar,int time_num,int attack_num);
 //pak�Ƕ�Ӧ�ļ��ܹ���˳���,people�Ƿ������ܹ�����ָ��,attackcooling�Ƕ�Ӧ�ļ�����ȴ����,rudder�Ǽ����ͷŵķ���,num�Ǹ���ȴ����Ĵ�С ,attackchar�Ǽ��ܵķ���,time_num�Ǽ��ܵ���ȴʱ�� 

#ifdef __cplusplus
}
#endif

#endif
