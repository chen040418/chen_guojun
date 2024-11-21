//#ifdef __cplusplus
//extern "C"{
//#endif
#include <stdio.h>
#include "variate.h"

//时间冷却初始化函数
void attack_cooling_init(attack_cooling* cooling,int num){//写死 
	if(cooling==NULL) return;
	int i=0;
	cooling->attack_char='j';
	cooling->time_cooling=1;
	(cooling+1)->attack_char='k';
	(cooling+1)->time_cooling=1;
	if(num==3){
		(cooling+2)->attack_char='l';
		(cooling+2)->time_cooling=1;
	}
	return;
}


//墙壁坐标获取函数 
xy_coord* get_rudder(char rudder_char) {//输入对应字符获取对应的墙壁坐标地址,否则返回NULL;
	int i = 0;
	for (i = 0; i < 4; ++i) {
		if (rudder_char == rudder_coord.coord_arr[i].rudder) {
			return &(rudder_coord.coord_arr[i].coord1);
		}
	}
	return NULL;

}

//地图界面输出
void print_1(int num1, int num2) {//num1是地图的高//num2是地图的宽
	int i = 0, j = 0;
	printf("\033[1;33m");
	for (i = 0; i < num1; ++i) {
		for (j = 0; j < num2; ++j) {
			if (i > 0 && i < num1 - 1 && j>0 && j < num2 - 1) {
				printf(" ");
				continue;
			}
			printf("%c", '*');
		}
		printf("\n");
	}
	printf("\033[0m");
	rudder_coord.coord_arr[0].rudder = 'w';
	rudder_coord.coord_arr[0].coord1.x = num2 / 2;
	rudder_coord.coord_arr[0].coord1.y = 3;

	rudder_coord.coord_arr[1].rudder = 's';
	rudder_coord.coord_arr[1].coord1.x = num2 / 2;
	rudder_coord.coord_arr[1].coord1.y = num1-2;

	rudder_coord.coord_arr[2].rudder = 'a';
	rudder_coord.coord_arr[2].coord1.x = 3;
	rudder_coord.coord_arr[2].coord1.y = num1/2;

	rudder_coord.coord_arr[3].rudder = 'd';
	rudder_coord.coord_arr[3].coord1.x = num2-2;
	rudder_coord.coord_arr[3].coord1.y = num1/2;
} 

//#ifdef __cplusplus
//}
//#endif
