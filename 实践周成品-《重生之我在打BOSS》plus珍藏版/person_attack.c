//#ifdef __cplusplus
//extern "C"{
//#endif

#include<stdio.h>

#include "person_attack.h"

 
/////////////////////////////////////////////////////////////////////////////////////
//人物相关

//敌对人物创建
void rivalry_person(person* rivalry, char rudder, int attack,xy_coord* coord,attack_cooling* time_attack) {//还有血量未初始化
	if (rivalry == NULL || coord == NULL) return;
	rivalry->people_num=1;
	rivalry->higt = 5;
	rivalry->width = 5;
	strcpy(rivalry->people_shape[0], " # # ");
	strcpy(rivalry->people_shape[1], "## ##");
	strcpy(rivalry->people_shape[2], "#0#0#");
	strcpy(rivalry->people_shape[3], "##H##");
	strcpy(rivalry->people_shape[4], "#   #");
	rivalry->people_type = 'e';
	rivalry->rudder = rudder;
	rivalry->attack = attack;
	rivalry->attack_skill_cd=time_attack;
	rivalry->run_num=2;
	rivalry->coord1.x = rivalry->coord2.x = coord->x;
	rivalry->coord1.y = rivalry->coord2.y = coord->y;
	return;
}

void two_rivalry_person(person* rivalry, char rudder, int attack,xy_coord* coord,attack_cooling* time_attack) {//还有血量未初始化
	if (rivalry == NULL || coord == NULL) return;
	rivalry->people_num=2;
	rivalry->higt = 5;
	rivalry->width = 5;
	strcpy(rivalry->people_shape[0], "00 00");
	strcpy(rivalry->people_shape[1], " &0& ");
	strcpy(rivalry->people_shape[2], "8& &8");
	strcpy(rivalry->people_shape[3], "&&H&&");
	strcpy(rivalry->people_shape[4], " & & ");
	rivalry->people_type = 'e';
	rivalry->rudder = rudder;
	rivalry->attack = attack;
	rivalry->attack_skill_cd=time_attack;
	rivalry->run_num=2;
	rivalry->coord1.x = rivalry->coord2.x = coord->x;
	rivalry->coord1.y = rivalry->coord2.y = coord->y;
	return;
}

void three_rivalry_person(person* rivalry, char rudder, int attack,xy_coord* coord,attack_cooling* time_attack) {//还有血量未初始化
	if (rivalry == NULL || coord == NULL) return;
	rivalry->people_num=3;
	rivalry->higt = 5;
	rivalry->width = 5;
	strcpy(rivalry->people_shape[0], "0=0=0");
	strcpy(rivalry->people_shape[1], " 8+8 ");
	strcpy(rivalry->people_shape[2], "=====");
	strcpy(rivalry->people_shape[3], "00000");
	strcpy(rivalry->people_shape[4], " & & ");
	rivalry->people_type = 'e';
	rivalry->rudder = rudder;
	rivalry->attack = attack;
	rivalry->attack_skill_cd=time_attack;
	rivalry->run_num=2;
	rivalry->coord1.x = rivalry->coord2.x = coord->x;
	rivalry->coord1.y = rivalry->coord2.y = coord->y;
	return;
}

//玩家人物创建
void friend_person(person* friend1, char rudder, int attack,xy_coord* coord,attack_cooling* time_attack) {//只有血量未初始化
	if (friend1 == NULL) return;
	friend1->people_num=1;
	friend1->higt = 5;
	friend1->width = 5;
	strcpy(friend1->people_shape[0], " ### ");
	strcpy(friend1->people_shape[1], " 0#0 ");
	strcpy(friend1->people_shape[2], "#####");
	strcpy(friend1->people_shape[3], " # # ");
	strcpy(friend1->people_shape[4], "#   #");
	friend1->people_type = 'q';
	friend1->rudder = rudder;
	friend1->attack = attack;
	friend1->attack_skill_cd=time_attack;
	friend1->run_num=2;
	friend1->coord1.x = friend1->coord2.x = coord->x;
	friend1->coord1.y = friend1->coord2.y = coord->y;
	return;
}

//人物血量初始化
int person_init(person* people, int blood) {
	if (people == NULL || blood < 0){
		people->blood=0;
	 	return 0; 
	}
	people->blood = blood;
	return blood;
}

////////////////////////////////////////////////////////////////////////////
//攻击相关

//普通攻击初始化
 void attack_initj(person* people,pool_attack* pool) {//玩家boss  j技能 
	if (pool == NULL) return;
	pool->attack_shape = '0';
	pool->num_attack=people->attack;
	pool->rivalry_coord=people->change_coord;
	pool->rudder=people->rudder; 
	pool->people_type=people->people_type;
	pool->run = 1;
	return;
}


//敌对人物的攻击技能
void rivalry_attackk(person* people,skill* people_attack, int harm) {//boss k技能 
	if (people_attack == NULL || harm < 0) return;
	people_attack->higt = 5;
	people_attack->width = 5;

	switch (people->rudder) {
	case 'w':
	case 's':
		strcpy(people_attack->skill_shape[0], "| | |");
		strcpy(people_attack->skill_shape[1], "| | |");
		strcpy(people_attack->skill_shape[2], "| | |");
		strcpy(people_attack->skill_shape[3], "| | |");
		strcpy(people_attack->skill_shape[4], "| | |");
		break;
	case 'a':
	case 'd':
		strcpy(people_attack->skill_shape[0], "_____");
		strcpy(people_attack->skill_shape[1], "     ");
		strcpy(people_attack->skill_shape[2], "_____");
		strcpy(people_attack->skill_shape[3], "     ");
		strcpy(people_attack->skill_shape[4], "_____");
		break;
	default:
		strcpy(people_attack->skill_shape[0], "0 0 0");
		strcpy(people_attack->skill_shape[1], "0   0");
		strcpy(people_attack->skill_shape[2], "0   0");
		strcpy(people_attack->skill_shape[3], "0   0");
		strcpy(people_attack->skill_shape[4], "00000");
		break;
	}
	people_attack->rudder = people->rudder;
	people_attack->skill_attack = harm;
	people_attack->people_type = people->people_type;
	people_attack->run=1;
	return;
}

void two_rivalry_attackl(person* people,skill* people_attack, int harm) {//boss k技能 
	if (people_attack == NULL || harm < 0) return;
	people_attack->higt = 5;
	people_attack->width = 5;

	switch (people->rudder) {
	case 'w':
	case 's':
		strcpy(people_attack->skill_shape[0], "00000");
		strcpy(people_attack->skill_shape[1], "0 0 0");
		strcpy(people_attack->skill_shape[2], "00000");
		strcpy(people_attack->skill_shape[3], "0 0 0");
		strcpy(people_attack->skill_shape[4], "00000");
		break;
	case 'a':
	case 'd':
		strcpy(people_attack->skill_shape[0], "00000");
		strcpy(people_attack->skill_shape[1], "0 0 0");
		strcpy(people_attack->skill_shape[2], "00000");
		strcpy(people_attack->skill_shape[3], "0 0 0");
		strcpy(people_attack->skill_shape[4], "00000");
		break;
	default:
		strcpy(people_attack->skill_shape[0], "0 0 0");
		strcpy(people_attack->skill_shape[1], "0   0");
		strcpy(people_attack->skill_shape[2], "0   0");
		strcpy(people_attack->skill_shape[3], "0   0");
		strcpy(people_attack->skill_shape[4], "00000");
		break;
	}
	people_attack->rudder = people->rudder;
	people_attack->skill_attack = harm;
	people_attack->people_type = people->people_type;
	people_attack->run=1;
	return;
}

//玩家攻击技能
void friend_attackk(person* people,skill* people_attack, int harm) {//玩家 k技能 
	if (people_attack == NULL || harm < 0) return;
	people_attack->higt = 5;
	people_attack->width = 5;
	switch (people->rudder) {
	case 'a':
		strcpy(people_attack->skill_shape[0], "   H*");
		strcpy(people_attack->skill_shape[1], " *## ");
		strcpy(people_attack->skill_shape[2], " ###H");
		strcpy(people_attack->skill_shape[3], " *## ");
		strcpy(people_attack->skill_shape[4], "   H*");
		break;
	case 'w':
		strcpy(people_attack->skill_shape[0], "     ");
		strcpy(people_attack->skill_shape[1], " *#* ");
		strcpy(people_attack->skill_shape[2], " ### ");
		strcpy(people_attack->skill_shape[3], "H###H");
		strcpy(people_attack->skill_shape[4], "* H *");
		break;
	case 'd':
		strcpy(people_attack->skill_shape[0], "*H   ");
		strcpy(people_attack->skill_shape[1], " ##* ");
		strcpy(people_attack->skill_shape[2], "H### ");
		strcpy(people_attack->skill_shape[3], " ##* ");
		strcpy(people_attack->skill_shape[4], "*H   ");
		break;
	case 's':
		strcpy(people_attack->skill_shape[0], "* H *");
		strcpy(people_attack->skill_shape[1], "H###H");
		strcpy(people_attack->skill_shape[2], " ### ");
		strcpy(people_attack->skill_shape[3], " *#* ");
		strcpy(people_attack->skill_shape[4], "     ");
		break;
	default:
		strcpy(people_attack->skill_shape[0], "*****");
		strcpy(people_attack->skill_shape[1], "*****");
		strcpy(people_attack->skill_shape[2], "*****");
		strcpy(people_attack->skill_shape[3], "*****");
		strcpy(people_attack->skill_shape[4], "*****");
		break;

	}
	people_attack->rudder = people->rudder;
	people_attack->skill_attack = harm;
	people_attack->people_type=people->people_type; 
	people_attack->run=1;
	return;
}

void friend_attackl(person* people,skill* people_attack, int harm) {//玩家 l技能 
	if (people_attack == NULL || harm < 0) return;
	people_attack->higt = 5;
	people_attack->width = 5;
	strcpy(people_attack->skill_shape[0], "     ");
	strcpy(people_attack->skill_shape[1], " # # ");
	strcpy(people_attack->skill_shape[2], "  #  ");
	strcpy(people_attack->skill_shape[3], " # # ");
	strcpy(people_attack->skill_shape[4], "     ");
	people_attack->rudder = people->rudder;
	people_attack->skill_attack = harm;
	people_attack->people_type=people->people_type;
	people_attack->run=1;
	return;
}

//#ifdef __cplusplus
//}
//#endif
