//#ifdef __cplusplus
//extern "C"{
//#endif

#include<stdio.h>

#include"thread_relevant.h" 

//boss�ƶ�����߳� 
void* thread_boss_print(void* arg){
	boss_val* px=(boss_val*)arg;
	while(px->p1->pthread_quit){
		Sleep(100);//����boss���ƶ�ʱ�� 
			move_rivalry_people(px->people,px->time_num,px->attack_num);
	}
	pthread_exit(NULL); 
}

void* two_thread_boss_print(void* arg){
	boss_val* px=(boss_val*)arg;
	while(px->p1->pthread_quit){
		Sleep(100);//����boss���ƶ�ʱ�� 
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
		Sleep(100);//����boss���ƶ�ʱ�� 
		if(px->people->blood<=0){
			break;
		}
			move_rivalry_people(px->people,px->time_num,px->attack_num);
	}
	pthread_exit(NULL); 
}

//��ȴ�����߳�
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
    printf("boss �չ���ȴʱ��");
    printf("\033[%d;%dH",i+6,j);
    printf("boss ����1��ȴʱ��");
    printf("\033[%d;%dH",i+9,j);
    printf("��� �չ���ȴʱ��");
    printf("\033[%d;%dH",i+12,j);
    printf("��� ����j��ȴʱ��");
    printf("\033[%d;%dH",i+15,j);
    printf("��� ����k��ȴʱ��");
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
    printf("��� �չ���ȴʱ��");
    printf("\033[%d;%dH",i+15,j);
    printf("��� ����j��ȴʱ��");
    printf("\033[%d;%dH",i+18,j);
    printf("��� ����k��ȴʱ��");
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

//��������߳�
void* thread_list_attack(void* arg){
	thread_attack_arr* taa=(thread_attack_arr*)arg;
	int i=0;
	int j=0;
	int ret_blood=100;
	xy_coord* coord1=NULL;
	int ret=0;
	while(taa->p1->pthread_quit){
		pthread_mutex_lock(&(taa->p1->mutex_attack));
		while(i<100){//��ͨ���� 
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
		while(j<100){//���� 
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
		while(i<100){//��ͨ���� 
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
						//bossѪ����ʼ��� 
						int aj=0;
						int zzz=taa->rivalrytwopeople->blood/10;
						printf("\033[%d;%dH",i,j);
						printf("boss Ѫ��");
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
		while(j<100){//���� 
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
						//bossѪ����ʼ��� 
						int aj=0;
						int zzz=taa->rivalrytwopeople->blood/10;
						printf("\033[%d;%dH",i,j);
						printf("boss Ѫ��");
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

//ʱ���ӡ�߳�
void* print_time(void* arg){
	int i=2;
	int j=155;
	xy_coord* coordx=get_rudder('d') ;
	j=coordx->x+5;
pthread_variable* pxx=(pthread_variable*)arg;
    pthread_mutex_lock(&(pxx->mutex_print));
    printf("\033[%d;%dH",i,j);
    printf("��Ϸʱ��");
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

//Ѫ������߳�
void* print_blood(void* arg){
	thread_blood* px1=(thread_blood*)arg;
	int friend_blood=px1->thread_friend_people->blood;
	int rivalry_blood=px1->thread_rivalry_people->blood;
	int i=5;
	int j=156;
	xy_coord* coordx=get_rudder('d') ;
	j=coordx->x+5;
	pthread_mutex_lock(&(px1->p2->mutex_print));
	//bossѪ����ʼ��� 
	int aj=0;
	int zzz=px1->thread_rivalry_people->blood/10;
	printf("\033[%d;%dH",i,j);
	printf("boss Ѫ��");
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
			
	//���Ѫ����ʼ��� 
	printf("\033[%d;%dH",i+6,j);
	printf("��� Ѫ��");
	printf("\033[%d;%dH",i+8,j);
	printf("************");
	printf("\033[%d;%dH",i+9,j);
	printf("*");
	printf("\033[0;31m==========\033[0m");
	printf("*");
	printf("\033[%d;%dH",i+10,j);
	printf("************");
	pthread_mutex_unlock(&(px1->p2->mutex_print));
	int fblood1=0;//1�� 2�� 
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
	//bossѪ����ʼ��� 
	int aj=0;
	int zzz=px1->thread_rivalry_people->blood/10;
	printf("\033[%d;%dH",i,j);
	printf("boss Ѫ��");
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
			
	//���Ѫ����ʼ��� 
	printf("\033[%d;%dH",i+6,j);
	printf("��� Ѫ��");
	printf("\033[%d;%dH",i+8,j);
	printf("************");
	printf("\033[%d;%dH",i+9,j);
	printf("*");
	printf("\033[0;31m==========\033[0m");
	printf("*");
	printf("\033[%d;%dH",i+10,j);
	printf("************");
	pthread_mutex_unlock(&(px1->p2->mutex_print));
	int fblood1=0;//1�� 2�� 
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

*/
//boss���ƶ��͹���
void move_rivalry_people(person* people,int time_num,int attack_num) {//����һ�θú���boss���ƶ�һ��
	if (people == NULL) return;
	int xix=20;
	if(people->people_num==3){
		xix=15;
	}
	int ret = 0;
	char attack_char='0';
	if (people->coord2.x >= people->change_coord->x-1 && people->coord2.x<=people->change_coord->x+1 ) {
		//ͬx��
		if(people->coord2.y<people->change_coord->y){
			people->rudder='s';
		}else {
			people->rudder='w';
		}
		//�ż���
		pthread_mutex_lock(&xpthread_var.mutex_attack);//������ 
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
		else {//ͬ���ƶ� 
			if (people->coord2.y < people->change_coord->y) people->rudder = 's';
			else people->rudder = 'w';
			ret = 1;
		}
	}
	else if (people->coord2.y >= people->change_coord->y - 1 && people->coord2.y <= people->change_coord->y + 1 ) {
		//ͬy��
		if(people->coord2.x<people->change_coord->x){
			people->rudder='d';
		}else {
			people->rudder='a';
		}
		pthread_mutex_lock(&xpthread_var.mutex_attack);//������ 
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
			//�ż���
			
			return;
		}
		else {//ͬ���ƶ� 
			if (people->coord2.x < people->change_coord->x) people->rudder = 'd';
			else people->rudder = 'a';
			ret = 1;
		}
	}
	else {
		//������������������ʹboss�����һ���ƶ�
		int numax = people->coord2.x - people->change_coord->x;
		if (numax < 0) numax = -numax;
		int numay = people->coord2.y - people->change_coord->y;
		if (numay < 0) numay = -numay;

		if (people->coord2.x < people->change_coord->x && people->coord2.y < people->change_coord->y) {
			//����һ x<0 y>0
			if (numax > numay)  people->rudder = 's';
			else people->rudder = 'd';
		}
		else if (people->coord2.x > people->change_coord->x && people->coord2.y < people->change_coord->y) {
			//����� x>0 y>0
			if (numax > numay) people->rudder = 's';
			else people->rudder = 'a';
		}
		else if (people->coord2.x > people->change_coord->y && people->coord2.y > people->change_coord->y) {
			//������ x>0 y<0
			if (numax > numay) people->rudder = 'w';
			else people->rudder = 'a';
		}
		else if (people->coord2.x < people->change_coord->x && people->coord2.y > people->change_coord->y) {
			//������ x<0 y<0
			if (numax > numay) people->rudder = 'w';
			else people->rudder = 'd';
		}
	}
	xy_coord* coordx= get_rudder(people->rudder);//�����Ӧ�ַ���ȡ��Ӧ��ǽ�������ַ,���򷵻�NULL;
	pthread_mutex_lock(&xpthread_var.mutex_print);//����� 
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
