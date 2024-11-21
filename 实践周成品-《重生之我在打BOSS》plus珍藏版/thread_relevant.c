//#ifdef __cplusplus
//extern "C"{
//#endif

#include<stdio.h>

#include"thread_relevant.h" 

//boss移动输出线程 
void* thread_boss_print(void* arg){
	boss_val* px=(boss_val*)arg;
	while(px->p1->pthread_quit){
		Sleep(100);//控制boss的移动时长 
			move_rivalry_people(px->people,px->time_num,px->attack_num);
	}
	pthread_exit(NULL); 
}

void* two_thread_boss_print(void* arg){
	boss_val* px=(boss_val*)arg;
	while(px->p1->pthread_quit){
		Sleep(100);//控制boss的移动时长 
			move_rivalry_people(px->people,px->time_num,px->attack_num);
			if(px->people->blood==0){
				if(px->people2){
					px->people=px->people2;
					px->people2=NULL;
				}
			}
	}
	pthread_exit(NULL); 
}

void* four_boss_print(void* arg){
	boss_val* px=(boss_val*)arg;
	while(px->p1->pthread_quit){
		Sleep(100);//控制boss的移动时长 
		if(px->people->blood<=0){
			break;
		}
			move_rivalry_people(px->people,px->time_num,px->attack_num);
	}
	pthread_exit(NULL); 
}

//冷却控制线程
void* thread_list_cooling(void* arg){
	thread_attack_cooling* tac=(thread_attack_cooling*)arg;
	long long int a1=time(NULL);
	int xix=0;
    int i=13;
    int j=155;
    xy_coord* coordx=get_rudder('d') ;
    j=coordx->x+5;
    pthread_mutex_lock(&(tac->thread_var->mutex_print));
    printf("\033[%d;%dH",i+3,j);
    printf("boss 普攻冷却时间");
    printf("\033[%d;%dH",i+6,j);
    printf("boss 技能1冷却时间");
    printf("\033[%d;%dH",i+9,j);
    printf("玩家 普攻冷却时间");
    printf("\033[%d;%dH",i+12,j);
    printf("玩家 技能j冷却时间");
    printf("\033[%d;%dH",i+15,j);
    printf("玩家 技能k冷却时间");
    pthread_mutex_unlock(&(tac->thread_var->mutex_print));
    while(tac->thread_var->pthread_quit){
    	long long int a2=time(NULL);
    	if(a2>a1+xix){
    		++xix;
    		int tm=0;
    		int cg=1;
    		while(tm<2){
    			cg+=3;
    			if(tac->rivalry_cooling[tm].time_cooling){
    				--(tac->rivalry_cooling[tm].time_cooling);
    				pthread_mutex_lock(&(tac->thread_var->mutex_print));
    				printf("\033[%d;%dH",i+cg,j);
    				printf("%d",tac->rivalry_cooling[tm].time_cooling);
    				pthread_mutex_unlock(&(tac->thread_var->mutex_print));
				}
				++tm;
			}
			tm=0;
			while(tm<3){
				cg+=3;
    			if(tac->friend_cooling[tm].time_cooling){
    				--(tac->friend_cooling[tm].time_cooling);
    				pthread_mutex_lock(&(tac->thread_var->mutex_print));
    				printf("\033[%d;%dH",i+cg,j);
    				printf("%d",tac->friend_cooling[tm].time_cooling);
    				pthread_mutex_unlock(&(tac->thread_var->mutex_print));
				}
				++tm;
			}
		}
		Sleep(100);
	}
	pthread_exit(NULL);
}

void* three_thread_list_cooling(void* arg){
	thread_attack_cooling* tac=(thread_attack_cooling*)arg;
	long long int a1=time(NULL);
	int xix=0;
    int i=13;
    int j=155;
    xy_coord* coordx=get_rudder('d') ;
    j=coordx->x+5;
    pthread_mutex_lock(&(tac->thread_var->mutex_print));
    printf("\033[%d;%dH",i+12,j);
    printf("玩家 普攻冷却时间");
    printf("\033[%d;%dH",i+15,j);
    printf("玩家 技能j冷却时间");
    printf("\033[%d;%dH",i+18,j);
    printf("玩家 技能k冷却时间");
    pthread_mutex_unlock(&(tac->thread_var->mutex_print));
    while(tac->thread_var->pthread_quit){
    	long long int a2=time(NULL);
    	if(a2>a1+xix){
    		++xix;
    		int tm=0;
    		int cg=1;
    		while(tm<3){
    			cg+=3;
    			if(tac->rivalry_cooling[tm].time_cooling){
    				--(tac->rivalry_cooling[tm].time_cooling);
    				//pthread_mutex_lock(&(tac->thread_var->mutex_print));
    				//printf("\033[%d;%dH",i+cg,j);
    				//printf("%d",tac->rivalry_cooling[tm].time_cooling);
    				//pthread_mutex_unlock(&(tac->thread_var->mutex_print));
				}
				++tm;
			}
			tm=0;
			while(tm<3){
				cg+=3;
    			if(tac->friend_cooling[tm].time_cooling){
    				--(tac->friend_cooling[tm].time_cooling);
    				pthread_mutex_lock(&(tac->thread_var->mutex_print));
    				printf("\033[%d;%dH",i+cg,j);
    				printf("%d",tac->friend_cooling[tm].time_cooling);
    				pthread_mutex_unlock(&(tac->thread_var->mutex_print));
				}
				++tm;
			}
		}
		Sleep(100);
	}
	pthread_exit(NULL);
}

//攻击输出线程
void* thread_list_attack(void* arg){
	thread_attack_arr* taa=(thread_attack_arr*)arg;
	int i=0;
	int j=0;
	int ret_blood=100;
	xy_coord* coord1=NULL;
	int ret=0;
	while(taa->p1->pthread_quit){
		pthread_mutex_lock(&(taa->p1->mutex_attack));
		while(i<100){//普通攻击 
			if(taa->pa[i].run){
				pthread_mutex_lock(&(taa->p1->mutex_print));
				printf("\033[0;31m");
				coord1=get_rudder(taa->pa[i].rudder);
				ret=if_move(&taa->pa[i].coord2, coord1, taa->pa[i].rivalry_coord, taa->pa[i].rudder, 2);
				empty_shape(&taa->pa[i].coord1, 0);
				if(ret<=0){
					taa->pa[i].run=0;
				}else{
					move_pool(taa->pa+i);
				}
				if(ret==-1){
					if(taa->pa[i].people_type=='q'){
						ret_blood=person_init(taa->rivalrypeople, taa->rivalrypeople->blood-taa->pa[i].num_attack);
					}else{
						ret_blood=person_init(taa->friendpeople, taa->friendpeople->blood-taa->pa[i].num_attack);
					}
					if(!ret_blood) taa->p1->pthread_quit=0;
				}
				printf("\033[0m");
				pthread_mutex_unlock(&(taa->p1->mutex_print));
			}
			++i;
		}
		i=0;
		while(j<100){//技能 
			if(taa->s[j].run){
				pthread_mutex_lock(&(taa->p1->mutex_print));
				//printf("\033[0;31m");
				coord1=get_rudder(taa->s[j].rudder);
				ret=if_move(&taa->s[j].coord2, coord1, taa->s[j].rivalry_coord, taa->s[j].rudder, 2);
				empty_shape(&taa->s[j].coord1, 2);
				if(ret<=0){
					taa->s[j].run=0;
				}else{
					move_skill(taa->s+j);
				}
				if(ret==-1){
					if(taa->s[j].people_type=='q'){
						ret_blood=person_init(taa->rivalrypeople, taa->rivalrypeople->blood-taa->s[j].skill_attack);
					}else{
						ret_blood=person_init(taa->friendpeople, taa->friendpeople->blood-taa->s[j].skill_attack);
					}
					if(!ret_blood) taa->p1->pthread_quit=0;
				}
				//printf("\033[0m");
				pthread_mutex_unlock(&(taa->p1->mutex_print));
			}
			++j;
		}
		j=0;
		pthread_mutex_unlock(&(taa->p1->mutex_attack));
		Sleep(50);
	}
	int xxx=0;
	while(xxx<100){
		taa->s[xxx].run=0;
		taa->pa[xxx].run=0;
		++xxx;
	}
	pthread_exit(NULL);
}

void* two_thread_list_attack(void* arg){
	thread_attack_arr* taa=(thread_attack_arr*)arg;
	int i=0;
	int j=0;
	int ret_blood=100;
	xy_coord* coord1=NULL;
	int ret=0;
	while(taa->p1->pthread_quit){
		pthread_mutex_lock(&(taa->p1->mutex_attack));
		while(i<100){//普通攻击 
			if(taa->pa[i].run){
				pthread_mutex_lock(&(taa->p1->mutex_print));
				printf("\033[0;31m");
				coord1=get_rudder(taa->pa[i].rudder);
				ret=if_move(&taa->pa[i].coord2, coord1, taa->pa[i].rivalry_coord, taa->pa[i].rudder, 2);
				empty_shape(&taa->pa[i].coord1, 0);
				if(ret<=0){
					taa->pa[i].run=0;
				}else{
					move_pool(taa->pa+i);
				}
				if(ret==-1){
					if(taa->pa[i].people_type=='q'){
						ret_blood=person_init(taa->rivalrypeople, taa->rivalrypeople->blood-taa->pa[i].num_attack);
					}else{
						ret_blood=person_init(taa->friendpeople, taa->friendpeople->blood-taa->pa[i].num_attack);
					}
					if(taa->rivalrypeople->blood==0&&taa->rivalrytwopeople!=NULL){
						taa->rivalrypeople=taa->rivalrytwopeople;
						//taa->rivalrytwopeople=NULL;
						ret_blood=1;
						int i=5;
						int j=156;
						xy_coord* coordx=get_rudder('d') ;
						j=coordx->x+5;
						pthread_mutex_unlock(&(taa->p1->mutex_print));
						pthread_mutex_lock(&(taa->p1->mutex_print));
						//boss血量初始输出 
						int aj=0;
						int zzz=taa->rivalrytwopeople->blood/10;
						printf("\033[%d;%dH",i,j);
						printf("boss 血量");
						printf("\033[%d;%dH",i+2,j);
						for(aj=0;aj<zzz+2;++aj){
							printf("*");
						}
						printf("\033[%d;%dH",i+3,j);
						printf("*");
						printf("\033[0;31m");
						for(aj=0;aj<zzz;++aj){
							printf("=");
						}
						printf("\033[0m");
						printf("*");
						printf("\033[%d;%dH",i+4,j);
						for(aj=0;aj<zzz+2;++aj){
							printf("*");
						}
						taa->rivalrytwopeople=NULL;
						pthread_mutex_unlock(&(taa->p1->mutex_print));
					}
					if(!ret_blood) taa->p1->pthread_quit=0;
				}
				printf("\033[0m");
				pthread_mutex_unlock(&(taa->p1->mutex_print));
			}
			++i;
		}
		i=0;
		while(j<100){//技能 
			if(taa->s[j].run){
				pthread_mutex_lock(&(taa->p1->mutex_print));
				//printf("\033[0;31m");
				coord1=get_rudder(taa->s[j].rudder);
				ret=if_move(&taa->s[j].coord2, coord1, taa->s[j].rivalry_coord, taa->s[j].rudder, 2);
				empty_shape(&taa->s[j].coord1, 2);
				if(ret<=0){
					taa->s[j].run=0;
				}else{
					move_skill(taa->s+j);
				}
				if(ret==-1){
					if(taa->s[j].people_type=='q'){
						ret_blood=person_init(taa->rivalrypeople, taa->rivalrypeople->blood-taa->s[j].skill_attack);
					}else{
						ret_blood=person_init(taa->friendpeople, taa->friendpeople->blood-taa->s[j].skill_attack);
					}
					if(taa->rivalrypeople->blood==0&&taa->rivalrytwopeople!=NULL){
						taa->rivalrypeople=taa->rivalrytwopeople;
						//taa->rivalrytwopeople=NULL;
						ret_blood=1;
						int i=5;
						int j=156;
						xy_coord* coordx=get_rudder('d') ;
						j=coordx->x+5;
						pthread_mutex_unlock(&(taa->p1->mutex_print));
						pthread_mutex_lock(&(taa->p1->mutex_print));
						//boss血量初始输出 
						int aj=0;
						int zzz=taa->rivalrytwopeople->blood/10;
						printf("\033[%d;%dH",i,j);
						printf("boss 血量");
						printf("\033[%d;%dH",i+2,j);
						for(aj=0;aj<zzz+2;++aj){
							printf("*");
						}
						printf("\033[%d;%dH",i+3,j);
						printf("*");
						printf("\033[0;31m");
						for(aj=0;aj<zzz;++aj){
							printf("=");
						}
						printf("\033[0m");
						printf("*");
						printf("\033[%d;%dH",i+4,j);
						for(aj=0;aj<zzz+2;++aj){
							printf("*");
						}
						taa->rivalrytwopeople=NULL;
						pthread_mutex_unlock(&(taa->p1->mutex_print));
					}
					if(!ret_blood) taa->p1->pthread_quit=0;
				}
				//printf("\033[0m");
				pthread_mutex_unlock(&(taa->p1->mutex_print));
			}
			++j;
		}
		j=0;
		pthread_mutex_unlock(&(taa->p1->mutex_attack));
		Sleep(50);
	}
	int xxx=0;
	while(xxx<100){
		taa->s[xxx].run=0;
		taa->pa[xxx].run=0;
		++xxx;
	}

	pthread_exit(NULL);
}

//时间打印线程
void* print_time(void* arg){
	int i=2;
	int j=155;
	xy_coord* coordx=get_rudder('d') ;
	j=coordx->x+5;
pthread_variable* pxx=(pthread_variable*)arg;
    pthread_mutex_lock(&(pxx->mutex_print));
    printf("\033[%d;%dH",i,j);
    printf("游戏时间");
    printf("\033[%d;%dH",i+2,j);
    printf("03:00");
    pthread_mutex_unlock(&(pxx->mutex_print));
    long long int a1=time(NULL);
    int xi=0;
while(pxx->pthread_quit){
	Sleep(100);
	long long int a2=time(NULL);
	if(a2>a1+xi){
		++xi;
		--(pxx->time_print);
		pthread_mutex_lock(&(pxx->mutex_print));
    	printf("\033[%d;%dH",i+2,j);
    	printf("%02d:%02d",pxx->time_print/60,pxx->time_print%60);
    	pthread_mutex_unlock(&(pxx->mutex_print));
	}
	if(pxx->time_print==0){
		pxx->pthread_quit=0;
	}
}
pthread_exit(NULL);
}

//血量输出线程
void* print_blood(void* arg){
	thread_blood* px1=(thread_blood*)arg;
	int friend_blood=px1->thread_friend_people->blood;
	int rivalry_blood=px1->thread_rivalry_people->blood;
	int i=5;
	int j=156;
	xy_coord* coordx=get_rudder('d') ;
	j=coordx->x+5;
	pthread_mutex_lock(&(px1->p2->mutex_print));
	//boss血量初始输出 
	int aj=0;
	int zzz=px1->thread_rivalry_people->blood/10;
	printf("\033[%d;%dH",i,j);
	printf("boss 血量");
	printf("\033[%d;%dH",i+2,j);
	for(aj=0;aj<zzz+2;++aj){
		printf("*");
	}
	printf("\033[%d;%dH",i+3,j);
	printf("*");
	printf("\033[0;31m");
	for(aj=0;aj<zzz;++aj){
		printf("=");
	}
	printf("\033[0m");
	printf("*");
	printf("\033[%d;%dH",i+4,j);
	for(aj=0;aj<zzz+2;++aj){
		printf("*");
	}
			
	//玩家血量初始输出 
	printf("\033[%d;%dH",i+6,j);
	printf("玩家 血量");
	printf("\033[%d;%dH",i+8,j);
	printf("************");
	printf("\033[%d;%dH",i+9,j);
	printf("*");
	printf("\033[0;31m==========\033[0m");
	printf("*");
	printf("\033[%d;%dH",i+10,j);
	printf("************");
	pthread_mutex_unlock(&(px1->p2->mutex_print));
	int fblood1=0;//1除 2余 
	int fblood2=0;
	int rblood1=0;
	int rblood2=0;
	
	int fix=px1->thread_friend_people->blood/10;
	int rix=px1->thread_rivalry_people->blood/zzz;
	while(px1->p2->pthread_quit){
		if(px1->thread_friend_people->blood<friend_blood){
			pthread_mutex_lock(&(px1->p2->mutex_print));
			friend_blood=px1->thread_friend_people->blood;
			fblood1=px1->thread_friend_people->blood/fix;
			fblood2=px1->thread_friend_people->blood%fix;
			if(fblood2){
				fblood2=1;
			}
			fblood1=fblood1+fblood2;
			printf("\033[%d;%dH",i+9,j+1);
			printf("\033[0;31m");
			for(rblood1=0;rblood1<10;++rblood1){
				if(rblood1>=fblood1){
					printf(" ");
					continue;
				}
				printf("=");
			}
			printf("\033[0m");
			printf("*");
			pthread_mutex_unlock(&(px1->p2->mutex_print));
		}
		
		if(px1->thread_rivalry_people->blood<rivalry_blood){
			pthread_mutex_lock(&(px1->p2->mutex_print));
			rivalry_blood=px1->thread_rivalry_people->blood;
			rblood1=px1->thread_rivalry_people->blood/rix;
			rblood2=px1->thread_rivalry_people->blood%rix;
			if(rblood2){
				rblood2=1;
			}
			rblood1=rblood1+rblood2;
			printf("\033[%d;%dH",i+3,j+1);
			printf("\033[0;31m");
			for(fblood1=0;fblood1<zzz;++fblood1){
				if(fblood1>=rblood1){
					printf(" ");
					continue;
				}
				printf("=");
			}
			printf("\033[0m");
			printf("*");
			pthread_mutex_unlock(&(px1->p2->mutex_print));
		}
		if(px1->thread_rivalry_people->blood==0 || px1->thread_friend_people->blood==0){
			px1->p2->pthread_quit=0;
		}
	}
	pthread_exit(NULL);
}

void* two_print_blood(void* arg){
	thread_blood* px1=(thread_blood*)arg;
	int friend_blood=px1->thread_friend_people->blood;
	int rivalry_blood=px1->thread_rivalry_people->blood;
	int i=5;
	int j=156;
	xy_coord* coordx=get_rudder('d') ;
	j=coordx->x+5;
	pthread_mutex_lock(&(px1->p2->mutex_print));
	//boss血量初始输出 
	int aj=0;
	int zzz=px1->thread_rivalry_people->blood/10;
	printf("\033[%d;%dH",i,j);
	printf("boss 血量");
	printf("\033[%d;%dH",i+2,j);
	for(aj=0;aj<zzz+2;++aj){
		printf("*");
	}
	printf("\033[%d;%dH",i+3,j);
	printf("*");
	printf("\033[0;31m");
	for(aj=0;aj<zzz;++aj){
		printf("=");
	}
	printf("\033[0m");
	printf("*");
	printf("\033[%d;%dH",i+4,j);
	for(aj=0;aj<zzz+2;++aj){
		printf("*");
	}
			
	//玩家血量初始输出 
	printf("\033[%d;%dH",i+6,j);
	printf("玩家 血量");
	printf("\033[%d;%dH",i+8,j);
	printf("************");
	printf("\033[%d;%dH",i+9,j);
	printf("*");
	printf("\033[0;31m==========\033[0m");
	printf("*");
	printf("\033[%d;%dH",i+10,j);
	printf("************");
	pthread_mutex_unlock(&(px1->p2->mutex_print));
	int fblood1=0;//1除 2余 
	int fblood2=0;
	int rblood1=0;
	int rblood2=0;
	
	int fix=px1->thread_friend_people->blood/10;
	int rix=px1->thread_rivalry_people->blood/zzz;
	while(px1->p2->pthread_quit){
		if(px1->thread_friend_people->blood<friend_blood){
			pthread_mutex_lock(&(px1->p2->mutex_print));
			friend_blood=px1->thread_friend_people->blood;
			fblood1=px1->thread_friend_people->blood/fix;
			fblood2=px1->thread_friend_people->blood%fix;
			if(fblood2){
				fblood2=1;
			}
			fblood1=fblood1+fblood2;
			printf("\033[%d;%dH",i+9,j+1);
			printf("\033[0;31m");
			for(rblood1=0;rblood1<10;++rblood1){
				if(rblood1>=fblood1){
					printf(" ");
					continue;
				}
				printf("=");
			}
			printf("\033[0m");
			printf("*");
			pthread_mutex_unlock(&(px1->p2->mutex_print));
		}
		
		if(px1->thread_rivalry_people->blood<rivalry_blood){
			pthread_mutex_lock(&(px1->p2->mutex_print));
			rivalry_blood=px1->thread_rivalry_people->blood;
			rblood1=px1->thread_rivalry_people->blood/rix;
			rblood2=px1->thread_rivalry_people->blood%rix;
			if(rblood2){
				rblood2=1;
			}
			rblood1=rblood1+rblood2;
			printf("\033[%d;%dH",i+3,j+1);
			printf("\033[0;31m");
			for(fblood1=0;fblood1<zzz;++fblood1){
				if(fblood1>=rblood1){
					printf(" ");
					continue;
				}
				printf("=");
			}
			printf("\033[0m");
			printf("*");
			pthread_mutex_unlock(&(px1->p2->mutex_print));
		}
		if(px1->thread_rivalry_people->blood==0&&px1->rivalry_two_people!=NULL){
			px1->thread_rivalry_people=px1->rivalry_two_people;
			px1->thread_friend_people->change_coord=&(px1->rivalry_two_people->coord2);
			rix=px1->thread_rivalry_people->blood/10;
			rivalry_blood=px1->thread_rivalry_people->blood;
			px1->rivalry_two_people=NULL;
		}
		if(px1->thread_friend_people->blood==0){
			px1->p2->pthread_quit=0;
		}
	}
	pthread_exit(NULL);
}
/*

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

*/
//boss的移动和攻击
void move_rivalry_people(person* people,int time_num,int attack_num) {//调用一次该函数boss就移动一次
	if (people == NULL) return;
	int xix=20;
	if(people->people_num==3){
		xix=15;
	}
	int ret = 0;
	char attack_char='0';
	if (people->coord2.x >= people->change_coord->x-1 && people->coord2.x<=people->change_coord->x+1 ) {
		//同x轴
		if(people->coord2.y<people->change_coord->y){
			people->rudder='s';
		}else {
			people->rudder='w';
		}
		//放技能
		pthread_mutex_lock(&xpthread_var.mutex_attack);//攻击锁 
		if(people->people_num==1){
			if(!send_skill(rivalry_attack_cooling, 2,'k')) make_skill_attack(sk,people,rivalry_attack_cooling,people->rudder,2,'k',time_num,attack_num);
			else make_pool_attack(pla,people,rivalry_attack_cooling,people->rudder);
		}else if(people->people_num==2){
			if(!send_skill(rivalry_attack_cooling, 2,'k')) make_skill_attack(sk,people,rivalry_attack_cooling,people->rudder,2,'k',time_num,attack_num);
		    else make_pool_attack(pla,people,rivalry_attack_cooling,people->rudder);
		}else if(people->people_num==3){
			if(!send_skill(three_rivalry_attack_cooling, 3,'l')) make_skill_attack(sk,people,three_rivalry_attack_cooling,people->rudder,3,'l',time_num,attack_num);
		    else if(!send_skill(three_rivalry_attack_cooling, 3,'k')) make_skill_attack(sk,people,three_rivalry_attack_cooling,people->rudder,3,'k',8,20);
			else make_pool_attack(pla,people,three_rivalry_attack_cooling,people->rudder);
		}
		pthread_mutex_unlock(&xpthread_var.mutex_attack);
		if (people->coord2.y - people->change_coord->y <= xix && people->coord2.y - people->change_coord->y >= -xix) {
			return;
		}
		else {//同轴移动 
			if (people->coord2.y < people->change_coord->y) people->rudder = 's';
			else people->rudder = 'w';
			ret = 1;
		}
	}
	else if (people->coord2.y >= people->change_coord->y - 1 && people->coord2.y <= people->change_coord->y + 1 ) {
		//同y轴
		if(people->coord2.x<people->change_coord->x){
			people->rudder='d';
		}else {
			people->rudder='a';
		}
		pthread_mutex_lock(&xpthread_var.mutex_attack);//攻击锁 
		if(people->people_num==1){
			if(!send_skill(rivalry_attack_cooling, 2,'k')) make_skill_attack(sk,people,rivalry_attack_cooling,people->rudder,2,'k',time_num,attack_num);
			else make_pool_attack(pla,people,rivalry_attack_cooling,people->rudder);
		}else if(people->people_num==2){
			if(!send_skill(rivalry_attack_cooling, 2,'k')) make_skill_attack(sk,people,rivalry_attack_cooling,people->rudder,2,'k',time_num,attack_num);
		    else make_pool_attack(pla,people,rivalry_attack_cooling,people->rudder);
		}else if(people->people_num==3){
			if(!send_skill(three_rivalry_attack_cooling, 3,'l')) make_skill_attack(sk,people,three_rivalry_attack_cooling,people->rudder,3,'l',time_num,attack_num);
		    else if(!send_skill(three_rivalry_attack_cooling, 3,'k')) make_skill_attack(sk,people,three_rivalry_attack_cooling,people->rudder,3,'k',5,20);
			else make_pool_attack(pla,people,three_rivalry_attack_cooling,people->rudder);
		}
	
		pthread_mutex_unlock(&xpthread_var.mutex_attack);
		if (people->coord2.x - people->change_coord->x <= xix && people->coord2.x - people->change_coord->x >= -xix) {
			//放技能
			
			return;
		}
		else {//同轴移动 
			if (people->coord2.x < people->change_coord->x) people->rudder = 'd';
			else people->rudder = 'a';
			ret = 1;
		}
	}
	else {
		//这两个变量的作用是使boss向近的一轴移动
		int numax = people->coord2.x - people->change_coord->x;
		if (numax < 0) numax = -numax;
		int numay = people->coord2.y - people->change_coord->y;
		if (numay < 0) numay = -numay;

		if (people->coord2.x < people->change_coord->x && people->coord2.y < people->change_coord->y) {
			//区域一 x<0 y>0
			if (numax > numay)  people->rudder = 's';
			else people->rudder = 'd';
		}
		else if (people->coord2.x > people->change_coord->x && people->coord2.y < people->change_coord->y) {
			//区域二 x>0 y>0
			if (numax > numay) people->rudder = 's';
			else people->rudder = 'a';
		}
		else if (people->coord2.x > people->change_coord->y && people->coord2.y > people->change_coord->y) {
			//区域三 x>0 y<0
			if (numax > numay) people->rudder = 'w';
			else people->rudder = 'a';
		}
		else if (people->coord2.x < people->change_coord->x && people->coord2.y > people->change_coord->y) {
			//区域四 x<0 y<0
			if (numax > numay) people->rudder = 'w';
			else people->rudder = 'd';
		}
	}
	xy_coord* coordx= get_rudder(people->rudder);//输入对应字符获取对应的墙壁坐标地址,否则返回NULL;
	pthread_mutex_lock(&xpthread_var.mutex_print);//光标锁 
	ret=if_move(&(people->coord2), coordx, people->change_coord, people->rudder, people->run_num);
	if (ret == 1) {
		empty_shape(&people->coord1, (people->higt) / 2);
		move_person(people);
	}
	pthread_mutex_unlock(&xpthread_var.mutex_print);
}




//#ifdef __cplusplus
//}
//#endif
