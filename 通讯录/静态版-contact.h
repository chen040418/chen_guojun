#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define MAX 100

//�˵���Ϣ
typedef struct peoinfo
{
	char name[20];
	int age;
	char sex[10];
	char tele[13];
	char addr[30];
}peoinfo;

//ͨѶ¼-��̬��
typedef struct contact
{
	peoinfo data[MAX];		//����˵���Ϣ
	int count;	//��¼��ǰͨѶ¼��ʵ�ʴ��ڵ�����
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

//�˵�
void menu();

//��ʼ��ͨѶ¼
void initcontact(contact* pc);

//���
void addcontact(contact* pc);

//��ӡͨѶ¼
void showcontact(const contact* pc);

//ɾ��
void deletcontact(contact* pc);