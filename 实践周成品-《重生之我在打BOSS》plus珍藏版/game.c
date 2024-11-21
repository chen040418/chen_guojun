//#ifdef __cplusplus
//extern "C"{
//#endif
#include<stdio.h>
#include"thread_relevant.h"
int run_game(int rivalry_blood,int friend_blood,int time_game,int y_size,int x_size,int time_num,int attack_num,int people_num){
	//地图输出 
	print_1(y_size,x_size);
	
	//人物初始化 
	  //boss 
	  xy_coord* coordy=get_rudder('a') ;
	xy_coord coord1;//boss初始坐标 
	coord1.x = coordy->x+3;
	coord1.y = y_size/2;
	
	person rivalry_people;
	if(people_num==1){
		rivalry_person(&rivalry_people, 'd', 2,&coord1,rivalry_attack_cooling);//boss
		attack_cooling_init(rivalry_attack_cooling,2);
	}else if(people_num==2){
		two_rivalry_person(&rivalry_people, 'd', 2,&coord1,rivalry_attack_cooling);//boss
		attack_cooling_init(rivalry_attack_cooling,2);
	}else if(people_num==3){
		three_rivalry_person(&rivalry_people, 'd', 2,&coord1,three_rivalry_attack_cooling);//boss
		attack_cooling_init(three_rivalry_attack_cooling,3);
	}
	move_person(&rivalry_people); 
	person_init(&rivalry_people, rivalry_blood);
	  //玩家 
	  xy_coord* coordx=get_rudder('d') ;
	xy_coord coord2;//玩家初始坐标 
	coord2.x = coordx->x-3;
	coord2.y = y_size/2;

	person friend_people;
	friend_person(&friend_people, 'a', 2,&coord2,friend_attack_cooling);//玩家 
	move_person(&friend_people);
	person_init(&friend_people, friend_blood);

	  //人物对应敌人坐标赋值
	friend_people.change_coord=&rivalry_people.coord2;
	rivalry_people.change_coord=&friend_people.coord2;
	
	
	//全局变量初始化 
	  //时间冷却初始化 
	attack_cooling_init(friend_attack_cooling,3);
	  //攻击冷却线程传入参数初始化
	thread_cooling.friend_cooling= friend_attack_cooling;
	if(people_num==3) thread_cooling.rivalry_cooling=three_rivalry_attack_cooling;
	else thread_cooling.rivalry_cooling=rivalry_attack_cooling;
	thread_cooling.thread_var=&xpthread_var;
	  //线程控制变量初始化 
	xpthread_var.pthread_quit=1;
	xpthread_var.time_print=time_game;
	  //boss移动线程传入参数初始化
	boss_var.p1=&xpthread_var; 
	boss_var.people=&rivalry_people;
	boss_var.time_num=time_num;
	boss_var.attack_num=attack_num;
	  //血量打印线程传入参数初始化
	thread_blood_mul.thread_friend_people=&friend_people;
	thread_blood_mul.thread_rivalry_people=&rivalry_people;
	thread_blood_mul.p2=&xpthread_var;
	  //攻击线程传入参数初始化
    thread_attack.pa=pla;
	thread_attack.s=sk;
	thread_attack.p1=&xpthread_var;
	thread_attack.friendpeople=&friend_people;
	thread_attack.rivalrypeople=&rivalry_people;
    memset(pla,0x00,sizeof(pool_attack)*100);
    memset(sk,0x00,sizeof(skill)*100);
	//线程ID
	pthread_t thread[5];
	
	
	
	//创建子线程
	  //boss移动线程
	pthread_create(thread,NULL,thread_boss_print,&boss_var);
	  //时间打印线程
	pthread_create(thread+1,NULL,print_time,&xpthread_var);
	  //攻击冷却线程
	if(people_num==3)
	pthread_create(thread+2,NULL,three_thread_list_cooling,&thread_cooling);
	else  pthread_create(thread+2,NULL,thread_list_cooling,&thread_cooling);
	  //血量输出线程
	pthread_create(thread+3,NULL,print_blood,&thread_blood_mul);
	  //攻击输出线程
	pthread_create(thread+4,NULL,thread_list_attack,&thread_attack); 
	//玩家移动和攻击释放
	char move_char='0';
	while(xpthread_var.pthread_quit){
		move_char=_getch();
		move_char=command_person(&friend_people, move_char);
		switch(move_char){
			case 'w':
			case 's':
			case 'd':
			case 'a':
				pthread_mutex_lock(&xpthread_var.mutex_print);
				empty_shape(&friend_people.coord1, 2);
				move_person(&friend_people);
				pthread_mutex_unlock(&xpthread_var.mutex_print);
				break;
			case 'j':
				make_pool_attack(pla,&friend_people,friend_attack_cooling,friend_people.rudder);
				break;
			case 'k':
				make_skill_attack(sk,&friend_people,friend_attack_cooling,friend_people.rudder,3,'k',3,3);
				break;
			case 'l':
				make_skill_attack(sk,&friend_people,friend_attack_cooling,friend_people.rudder,3,'l',5,5);
				break;
			
			
		}
	} 
	
	//回收线程资源
	int i=0;
	for(i=0;i<5;++i){
		pthread_join(thread[i],NULL);
	} 
	
	Sleep(100);
	system("cls");
	//返回值判断 
	if(rivalry_people.blood<=0){
		return time_game-xpthread_var.time_print;
	}else{
		return 0;
	}
}


int run_game_two(int rivalry_blood,int friend_blood,int time_game,int y_size,int x_size,int time_num,int attack_num,int people_num){
	//地图输出 
	print_1(y_size,x_size);
	
	//人物初始化 
	  //boss 
	  xy_coord* coordy=get_rudder('a') ;
	xy_coord coord1;//boss初始坐标 
	coord1.x = coordy->x+3;
	coord1.y = y_size/2+5;
	
	person rivalry_people1;
	person rivalry_people2;
		rivalry_person(&rivalry_people1, 'd', 2,&coord1,rivalry_attack_cooling);//boss
		attack_cooling_init(rivalry_attack_cooling,2);
		coord1.y = y_size/2-5;
		two_rivalry_person(&rivalry_people2, 'd', 2,&coord1,rivalry_attack_cooling);//boss
		attack_cooling_init(rivalry_attack_cooling,2);
	move_person(&rivalry_people1); 
	move_person(&rivalry_people2);
	person_init(&rivalry_people1,rivalry_blood );
	person_init(&rivalry_people2, rivalry_blood);
	  //玩家 
	  xy_coord* coordx=get_rudder('d') ;
	xy_coord coord2;//玩家初始坐标 
	coord2.x = coordx->x-3;
	coord2.y = y_size/2;

	person friend_people;
	friend_person(&friend_people, 'a', 2,&coord2,friend_attack_cooling);//玩家 
	move_person(&friend_people);
	person_init(&friend_people, friend_blood);

	  //人物对应敌人坐标赋值
	friend_people.change_coord=&rivalry_people1.coord2;
	rivalry_people1.change_coord=&friend_people.coord2;
	rivalry_people2.change_coord=&friend_people.coord2;
	
	//全局变量初始化 
	  //时间冷却初始化 
	attack_cooling_init(friend_attack_cooling,3);
	  //攻击冷却线程传入参数初始化
	thread_cooling.friend_cooling= friend_attack_cooling;
	thread_cooling.rivalry_cooling=rivalry_attack_cooling;
	thread_cooling.thread_var=&xpthread_var;
	  //线程控制变量初始化 
	xpthread_var.pthread_quit=1;
	xpthread_var.time_print=time_game;
	  //boss移动线程传入参数初始化
	boss_var.p1=&xpthread_var; 
	boss_var.people=&rivalry_people1;
	boss_var.people2=&rivalry_people2;
	boss_var.time_num=time_num;
	boss_var.attack_num=attack_num;
	  //血量打印线程传入参数初始化
	thread_blood_mul.thread_friend_people=&friend_people;
	thread_blood_mul.thread_rivalry_people=&rivalry_people1;
	thread_blood_mul.rivalry_two_people=&rivalry_people2;
	thread_blood_mul.p2=&xpthread_var;
	  //攻击线程传入参数初始化
    thread_attack.pa=pla;
	thread_attack.s=sk;
	thread_attack.p1=&xpthread_var;
	thread_attack.friendpeople=&friend_people;
	thread_attack.rivalrypeople=&rivalry_people1;
	thread_attack.rivalrytwopeople=&rivalry_people2;
    memset(pla,0x00,sizeof(pool_attack)*100);
    memset(sk,0x00,sizeof(skill)*100);
	//线程ID
	pthread_t thread[5];
	
	
	
	//创建子线程
	  //boss移动线程
	pthread_create(thread,NULL,two_thread_boss_print,&boss_var);
	  //时间打印线程
	pthread_create(thread+1,NULL,print_time,&xpthread_var);
	  //攻击冷却线程
	pthread_create(thread+2,NULL,thread_list_cooling,&thread_cooling);
	  //血量输出线程
	pthread_create(thread+3,NULL,two_print_blood,&thread_blood_mul);
	  //攻击输出线程
	pthread_create(thread+4,NULL,two_thread_list_attack,&thread_attack); 
	//玩家移动和攻击释放
	char move_char='0';
	while(xpthread_var.pthread_quit){
		move_char=_getch();
		move_char=command_person(&friend_people, move_char);
		switch(move_char){
			case 'w':
			case 's':
			case 'd':
			case 'a':
				pthread_mutex_lock(&xpthread_var.mutex_print);
				empty_shape(&friend_people.coord1, 2);
				move_person(&friend_people);
				pthread_mutex_unlock(&xpthread_var.mutex_print);
				break;
			case 'j':
				make_pool_attack(pla,&friend_people,friend_attack_cooling,friend_people.rudder);
				break;
			case 'k':
				make_skill_attack(sk,&friend_people,friend_attack_cooling,friend_people.rudder,3,'k',3,3);
				break;
			case 'l':
				make_skill_attack(sk,&friend_people,friend_attack_cooling,friend_people.rudder,3,'l',5,5);
				break;
			
			
		}
	} 
	
	//回收线程资源
	int i=0;
	for(i=0;i<5;++i){
		pthread_join(thread[i],NULL);
	} 
	
	Sleep(100);
	system("cls");
	//返回值判断 
	if(friend_people.blood){
		return time_game-xpthread_var.time_print;
	}else{
		return 0;
	}
}

int run_game_four(int rivalry_blood,int friend_blood,int time_game,int y_size,int x_size,int time_num,int attack_num,int people_num){
	//地图输出 
	print_1(y_size,x_size);
	
	//人物初始化 
	  //boss 
	  xy_coord* coordy=get_rudder('a') ;
	xy_coord coord1;//boss初始坐标 
	coord1.x = coordy->x+3;
	coord1.y = y_size/2+5;
	
	person rivalry_people1;
	person rivalry_people2;
		rivalry_person(&rivalry_people1, 'd', 2,&coord1,rivalry_attack_cooling);//boss
		attack_cooling_init(rivalry_attack_cooling,2);
		coord1.y = y_size/2-5;
		three_rivalry_person(&rivalry_people2, 'd', 3,&coord1,three_rivalry_attack_cooling);//boss
		attack_cooling_init(rivalry_attack_cooling,2);
	move_person(&rivalry_people1); 
	move_person(&rivalry_people2);
	person_init(&rivalry_people1,rivalry_blood );
	person_init(&rivalry_people2, rivalry_blood);
	  //玩家 
	  xy_coord* coordx=get_rudder('d') ;
	xy_coord coord2;//玩家初始坐标 
	coord2.x = coordx->x-3;
	coord2.y = y_size/2;

	person friend_people;
	friend_person(&friend_people, 'a', 2,&coord2,friend_attack_cooling);//玩家 
	move_person(&friend_people);
	person_init(&friend_people, friend_blood);

	  //人物对应敌人坐标赋值
	friend_people.change_coord=&rivalry_people1.coord2;
	rivalry_people1.change_coord=&friend_people.coord2;
	rivalry_people2.change_coord=&friend_people.coord2;
	
	//全局变量初始化 
	  //时间冷却初始化 
	attack_cooling_init(friend_attack_cooling,3);
	  //攻击冷却线程传入参数初始化
	thread_cooling.friend_cooling= friend_attack_cooling;
	thread_cooling.rivalry_cooling=rivalry_attack_cooling;
	thread_cooling.thread_var=&xpthread_var;
	//thread_cooling.friend_cooling= friend_attack_cooling;
	//thread_cooling.rivalry_cooling=three_rivalry_attack_cooling;
	//thread_cooling.thread_var=&xpthread_var;
	  //线程控制变量初始化 
	xpthread_var.pthread_quit=1;
	xpthread_var.time_print=time_game;
	  //boss移动线程传入参数初始化
	boss_var.p1=&xpthread_var; 
	boss_var.people=&rivalry_people1;
	boss_var.people2=&rivalry_people2;
	boss_var.time_num=time_num;
	boss_var.attack_num=attack_num;
	boss_var1.p1=&xpthread_var; 
	boss_var1.people=&rivalry_people2;
	boss_var1.people2=NULL;
	boss_var1.time_num=time_num;
	boss_var1.attack_num=attack_num;
	  //血量打印线程传入参数初始化
	thread_blood_mul.thread_friend_people=&friend_people;
	thread_blood_mul.thread_rivalry_people=&rivalry_people1;
	thread_blood_mul.rivalry_two_people=&rivalry_people2;
	thread_blood_mul.p2=&xpthread_var;
	  //攻击线程传入参数初始化
    thread_attack.pa=pla;
	thread_attack.s=sk;
	thread_attack.p1=&xpthread_var;
	thread_attack.friendpeople=&friend_people;
	thread_attack.rivalrypeople=&rivalry_people1;
	thread_attack.rivalrytwopeople=&rivalry_people2;
    memset(pla,0x00,sizeof(pool_attack)*100);
    memset(sk,0x00,sizeof(skill)*100);
	//线程ID
	pthread_t thread[6];
	
	
	
	//创建子线程
	  //boss移动线程
	pthread_create(thread,NULL,four_boss_print,&boss_var);
	//boss移动线程
	pthread_create(thread+5,NULL,four_boss_print,&boss_var1);
	  //时间打印线程
	pthread_create(thread+1,NULL,print_time,&xpthread_var);
	  //攻击冷却线程
	pthread_create(thread+2,NULL,thread_list_cooling,&thread_cooling);
	  //血量输出线程
	pthread_create(thread+3,NULL,two_print_blood,&thread_blood_mul);
	  //攻击输出线程
	pthread_create(thread+4,NULL,two_thread_list_attack,&thread_attack); 
	//玩家移动和攻击释放
	char move_char='0';
	while(xpthread_var.pthread_quit){
		move_char=_getch();
		move_char=command_person(&friend_people, move_char);
		switch(move_char){
			case 'w':
			case 's':
			case 'd':
			case 'a':
				pthread_mutex_lock(&xpthread_var.mutex_print);
				empty_shape(&friend_people.coord1, 2);
				move_person(&friend_people);
				pthread_mutex_unlock(&xpthread_var.mutex_print);
				break;
			case 'j':
				make_pool_attack(pla,&friend_people,friend_attack_cooling,friend_people.rudder);
				break;
			case 'k':
				make_skill_attack(sk,&friend_people,friend_attack_cooling,friend_people.rudder,3,'k',3,3);
				break;
			case 'l':
				make_skill_attack(sk,&friend_people,friend_attack_cooling,friend_people.rudder,3,'l',5,5);
				break;
			
			
		}
	} 
	
	//回收线程资源
	int i=0;
	for(i=0;i<6;++i){
		pthread_join(thread[i],NULL);
	} 
	
	Sleep(100);
	system("cls");
	//返回值判断 
	if(friend_people.blood){
		return time_game-xpthread_var.time_print;
	}else{
		return 0;
	}
}

//#ifdef __cplusplus
//}
//#endif
