//#ifdef __cplusplus
//extern "C"{
//#endif
#include<stdio.h>
#include"move_print_attack.h"
#include"person_attack.h"
//将指定区域的所有内容清除
//除判断之外的其他函数使用多线程时需要加锁 
//在移动之前需要使用清除函数清除原区域的内容 
void empty_shape(xy_coord* coord, int num) {
	if (coord == NULL) return;
	int numhigt = coord->y - num;
	int numwidth = coord->x - num;
	int i = 0, j = 0;
	for (i = 0; i < 2 * num + 1; ++i) {
		printf("\033[%d;%dH", numhigt + i, numwidth);
		for (j = 0; j < 2 * num + 1; ++j) {
			printf(" ");
		}
	}
	return;
}

//判断是否能移动
int if_move(xy_coord* coord1, xy_coord* coord2, xy_coord* coord3, char rudder, int num) {
	if (coord1 == NULL || coord2 == NULL || coord3 == NULL) return 0;
	switch (rudder) {
	case'w':
		if (coord1->y - num <= coord3->y + num + 1 && coord1->y - num >= coord3->y - num - 1 && coord1->x >= coord3->x - num - 1 && coord1->x <= coord3->x + num + 1) {
			return -1;
		}
		if (coord1->y - num > coord2->y) {
			coord1->y = coord1->y - num;
			num = 0;
		}
		return coord1->y - num > coord2->y;
	case's':
		if (coord1->y + num >= coord3->y - num - 1 && coord1->y + num <= coord3->y + num + 1 && coord1->x >= coord3->x - num - 1 && coord1->x <= coord3->x + num + 1) {
			return -1;
		}
		if (coord1->y + num < coord2->y) {
			coord1->y = coord1->y + num;
			num = 0;
		}
		return coord1->y + num < coord2->y;
	case'a':
		if (coord1->x - num >= coord3->x - num - 1 && coord1->x - num <= coord3->x + num + 1 && coord1->y >= coord3->y - num - 1 && coord1->y <= coord3->y + num + 1) {
			return -1;
		}
		if (coord1->x - num > coord2->x) {
			coord1->x = coord1->x - num;
			num = 0;
		}
		return coord1->x - num > coord2->x;
	case'd':
		if (coord1->x + num >= coord3->x - num - 1 && coord1->x + num <= coord3->x + num + 1 && coord1->y >= coord3->y - num - 1 && coord1->y <= coord3->y + num + 1) {
			return -1;
		}
		if (coord1->x + num < coord2->x) {
			coord1->x = coord1->x + num;
			num = 0;
		}
		return coord1->x + num < coord2->x;
	default:
		return 0;
	}
}

//人物的移动
void move_person(person* people) {
	if (people == NULL) return;
	int numhigt = people->coord2.y - (people->higt) / 2;
	int numwidth = people->coord2.x - (people->width) / 2;
	int higt = 0, width = 0;
	for (higt = 0; higt < people->higt; ++higt) {
		printf("\033[%d;%dH", numhigt + higt, numwidth);
		for (width = 0; width < people->width; ++width) {
			printf("%c", (people->people_shape)[higt][width]);
		}
	}
	switch (people->rudder) {
	case'w':
		printf("\033[%d;%dH", people->coord2.y - 2, people->coord2.x);
		break;
	case's':
		printf("\033[%d;%dH", people->coord2.y + 2, people->coord2.x);
		break;
	case'a':
		printf("\033[%d;%dH", people->coord2.y, people->coord2.x - 2);
		break;
	case'd':
		printf("\033[%d;%dH", people->coord2.y, people->coord2.x + 2);
		break;
	default:
		break;
	}
	char c = '#';
	printf("\033[0;31m%c\033[0m", c);
	printf("\033[%d;%dH", numhigt + people->higt - 1, numwidth + people->width - 1);
	printf("%c", people->people_shape[higt / 2][width / 2]);
	people->coord1.x = people->coord2.x;
	people->coord1.y = people->coord2.y;
	return;
}

//普通攻击的移动
void move_pool(pool_attack* pool) {
	if (pool == NULL) return;
	int numhigt = pool->coord2.y;
	int numwidth = pool->coord2.x;
	printf("\033[%d;%dH", numhigt, numwidth);
	printf("\033[0;31m%c\033[0m",pool->attack_shape);
	pool->coord1.x = pool->coord2.x;
	pool->coord1.y = pool->coord2.y;
	return;
}

//技能移动
void move_skill(skill* skill_move) {
	if (skill_move == NULL) return;
	int numhigt = skill_move->coord2.y - (skill_move->higt) / 2;
	int numwidth = skill_move->coord2.x - (skill_move->width) / 2;
	int i = 0, j = 0;
	for (i = 0; i < skill_move->higt; ++i) {
		printf("\033[%d;%dH", numhigt + i, numwidth);
		for (j = 0; j < skill_move->width; ++j) {
			printf("%c", skill_move->skill_shape[i][j]);
		}
	}
	skill_move->coord1.x = skill_move->coord2.x;
	skill_move->coord1.y = skill_move->coord2.y;
	return;
}

//判断玩家的移动和技能释放//后面要整合字符一起使用
char command_person(person* people, char move_and_attack) {//若能成功操作则返回相应的字符,反之返回 & //若是移动则将玩家的移动方向改为对应的移动方向
	if (people == NULL) return '&';
	int ret = 0;
	xy_coord* coordx = NULL;
	switch (move_and_attack) {
	case 'j':
	case 'k':
	case 'l':
		ret = send_skill(friend_attack_cooling,3, move_and_attack);
		if (ret) move_and_attack = '&';
		break;
	case 'w':
	case 'a':
	case 's':
	case 'd':
		coordx=get_rudder(move_and_attack);//输入对应字符获取对应的墙壁坐标,否则返回(0,0);
		if (coordx == NULL) {
			move_and_attack = '&';
			break;
		}
		ret=if_move(&people->coord2, coordx, people->change_coord, move_and_attack, people->run_num);
		if (ret <=0) move_and_attack='&';
		else people->rudder = move_and_attack;
		break;
	default:
		move_and_attack = '&';
		break;
	}
	return move_and_attack;
}


//攻击
/////////////////////////////////////////////////////////////////////////////////////////////////////
//判断能否攻击
int send_skill(attack_cooling* people_attack_cooling, int num,char skill_char){
	if(people_attack_cooling==NULL || num<=0) return 1;
	int i=0;
	for(i=0;i<num;++i){
		if(people_attack_cooling[i].attack_char==skill_char){
			return people_attack_cooling[i].time_cooling;
		}
	} 
	return 1;//避免输入的字符有误 
} 


//补充函数判断攻击是否会出界
 int judge_attack_interface(xy_coord* coord1,char rudder,char attack_char){
 	xy_coord* coord2=get_rudder(rudder);//输入对应字符获取对应的墙壁坐标地址,否则返回NULL;
 	if(coord2==NULL) 0;
 	int i=0;
 	switch(attack_char){
 		case 'j':
 			i=3;
 			break;
 		case 'k':
 		case 'l':
 			i=5;
 			break;
 		default:
 			return 0;
 			break;
	 }
 	switch(rudder){
 		case 'w':
 			if(coord1->y-i>coord2->y){
 				return 1;
			 }else{
			 	return 0;
			 }
 			break;
 		case 's':
 			if(coord1->y+i<coord2->y){
 				return 1;
			 }else{
			 	return 0;
			 }
 			break;
 		case 'a':
 			if(coord1->x-i>coord2->x){
 				return 1;
			 }else{
			 	return 0;
			 }
 			break;
 		case 'd':
 			if(coord1->x+i<coord2->x){
 				return 1;
			 }else{
			 	return 0;
			 }
 			break;
 			default:
 				return 0;
 				break;
	 }
 }
 
 //技能攻击位置赋值 //用于攻击创建 
 void skill_coord_value(person* people,skill* skill_at){
 	switch(skill_at->rudder){
 		case 'w':
 			skill_at->coord1.x=skill_at->coord2.x=people->coord2.x;
 			skill_at->coord1.y=skill_at->coord2.y=people->coord2.y-5;
 			break;
 			
 		case 's':
 			skill_at->coord1.x=skill_at->coord2.x=people->coord2.x;
 			skill_at->coord1.y=skill_at->coord2.y=people->coord2.y+5;
 			break;
 		
 		case 'd':
 			skill_at->coord1.x=skill_at->coord2.x=people->coord2.x+5;
 			skill_at->coord1.y=skill_at->coord2.y=people->coord2.y;
 			break;
 			
 		case 'a':
 			skill_at->coord1.x=skill_at->coord2.x=people->coord2.x-5;
 			skill_at->coord1.y=skill_at->coord2.y=people->coord2.y;
 			break;
	 }
 }
 
 //普通攻击位置赋值 //用于攻击创建 
 void pool_coord_value(person* people,pool_attack* pool_at){
 	switch(pool_at->rudder){
 		case 'w':
 			pool_at->coord1.x=pool_at->coord2.x=people->coord2.x;
 			pool_at->coord1.y=pool_at->coord2.y=people->coord2.y-3;
 			break;
 			
 		case 's':
 			pool_at->coord1.x=pool_at->coord2.x=people->coord2.x;
 			pool_at->coord1.y=pool_at->coord2.y=people->coord2.y+3;
 			break;
 		
 		case 'd':
 			pool_at->coord1.x=pool_at->coord2.x=people->coord2.x+3;
 			pool_at->coord1.y=pool_at->coord2.y=people->coord2.y;
 			break;
 			
 		case 'a':
 			pool_at->coord1.x=pool_at->coord2.x=people->coord2.x-3;
 			pool_at->coord1.y=pool_at->coord2.y=people->coord2.y;
 			break;
	 }
 }
 
 
  //将普通攻击整合到普通攻击数组上
 void make_pool_attack(pool_attack* pak,person* people,attack_cooling* attackcooling,char rudder){
 	if(pak==NULL || people==NULL || attackcooling==NULL) return;
 	if(!attackcooling[0].time_cooling){
 		int i=0;
		 while(i<100 && pak[i].run){
		 	++i;
		 } 
		 if(i==100) return;
		 int ret=judge_attack_interface(&(people->coord2),rudder,'j');
		 if(ret==0) return;
		 attack_initj(people,pak+i);
		 pak[i].rudder=rudder;
		 pool_coord_value(people,pak+i);
		 attackcooling[0].time_cooling=1;
	 }
 }
 
 
  //将技能攻击整合到技能攻击数组上
 void make_skill_attack(skill* pak,person* people,attack_cooling* attackcooling,char rudder,int num,int attackchar,int time_num,int attack_num){
 	if(pak==NULL || people==NULL || attackcooling==NULL || num<0) return;
 	int ret=send_skill(attackcooling, num,attackchar);
 	if(!ret){
 		int i=0;
 		while(i<100 && pak[i].run){
 			++i;
		 }
		 if(i==100) return;
		 if(people->people_num==1){
		 	if(attackchar=='k'){
		 	if(people->people_type=='q'){
		 		friend_attackk(people,pak+i, attack_num);
			 }else{
			 	rivalry_attackk(people,pak+i, attack_num);
			 }
			 attackcooling[1].time_cooling=time_num;
		 	}else{
		 		
		 		friend_attackl(people,pak+i, attack_num);
				attackcooling[2].time_cooling=time_num;
		 	}
		 }else if(people->people_num==2){
		 	if(attackchar=='k'){
		 	if(people->people_type=='q'){
		 		friend_attackk(people,pak+i, attack_num);
			 }else{
			 	two_rivalry_attackl(people,pak+i, attack_num);
			 }
			 attackcooling[1].time_cooling=time_num;
		 	}else{
		 		friend_attackl(people,pak+i, attack_num);
				attackcooling[2].time_cooling=time_num;
		 	}
		 }else if(people->people_num==3){
		 	if(attackchar=='k'){
		 	if(people->people_type=='q'){
		 			friend_attackk(people,pak+i, attack_num);
			 	}else{
			 		rivalry_attackk(people,pak+i, attack_num);
			 	}
			 		attackcooling[1].time_cooling=time_num;
		 	}else{
		 		if(people->people_type=='q'){
		 			friend_attackk(people,pak+i, attack_num);
			 	}else{
			 		two_rivalry_attackl(people,pak+i, attack_num);
			 	}
			 		attackcooling[2].time_cooling=time_num;
		 	}
		 }
		 
		 pak[i].rudder=rudder;
		 pak[i].rivalry_coord=people->change_coord;
		 skill_coord_value(people,pak+i);
		 //printf("%d  %d   %d  %d",pak[i].coord1.x,pak[i].coord1.y,people->change_coord->x,people->change_coord->y);
	 }
 }
 
// #ifdef __cplusplus
//}
//#endif
