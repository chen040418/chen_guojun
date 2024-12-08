#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define DEFAULT_SIZE 5
#define INC_SIZE 5
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 13
#define MAX_ADDR 30

//人的信息
typedef struct peoinfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}peoinfo;

//通讯录-动态版
typedef struct contact
{
	peoinfo* data;		//存放人的信息
	int count;	//记录当前通讯录中实际存在的人数
	int capacity;	//当前通讯录的容量
}contact;

enum option
{
	add = 1,
	del = 2,
	search = 3,
	modify = 4,
	show = 5,
	sort = 6,
	EXIT = 0
};

//菜单
void menu();

//初始化通讯录
int initcontact(contact* pc);

//加载通讯录已有信息
void load_contact(contact* pc);

//判断是否需要增容
void check_capacity(contact* pc);

//添加
void addcontact(contact* pc);

//打印通讯录
void showcontact(const contact* pc);

//删除
void deletcontact(contact* pc);

//释放内存
void destroy_contact(contact* pc);

//保存Contact信息到文件中
void save_contact(const contact* pc);

