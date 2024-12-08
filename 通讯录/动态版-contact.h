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

//�˵���Ϣ
typedef struct peoinfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}peoinfo;

//ͨѶ¼-��̬��
typedef struct contact
{
	peoinfo* data;		//����˵���Ϣ
	int count;	//��¼��ǰͨѶ¼��ʵ�ʴ��ڵ�����
	int capacity;	//��ǰͨѶ¼������
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
int initcontact(contact* pc);

//����ͨѶ¼������Ϣ
void load_contact(contact* pc);

//�ж��Ƿ���Ҫ����
void check_capacity(contact* pc);

//���
void addcontact(contact* pc);

//��ӡͨѶ¼
void showcontact(const contact* pc);

//ɾ��
void deletcontact(contact* pc);

//�ͷ��ڴ�
void destroy_contact(contact* pc);

//����Contact��Ϣ���ļ���
void save_contact(const contact* pc);

