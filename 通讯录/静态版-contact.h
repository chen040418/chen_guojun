#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define MAX 100

//人的信息
typedef struct peoinfo
{
	char name[20];
	int age;
	char sex[10];
	char tele[13];
	char addr[30];
}peoinfo;

//通讯录-静态版
typedef struct contact
{
	peoinfo data[MAX];		//存放人的信息
	int count;	//记录当前通讯录中实际存在的人数
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
void initcontact(contact* pc);

//添加
void addcontact(contact* pc);

//打印通讯录
void showcontact(const contact* pc);

//删除
void deletcontact(contact* pc);