//#define _CRT_SECURE_NO_WARNINGS
//
//#include"��̬��-contact.h"
//
//
//
////�˵�
//void menu()
//{
//    printf("|============================================|\n");
//    printf("|         ��ӭʹ��ͨѶ¼                      |\n");
//    printf("|********************************************|\n");
//    printf("|             1�� add               |\n");
//    printf("|             2�� del               |\n");
//    printf("|             3�� search                   |\n");
//    printf("|             4�� modify                   |\n");
//    printf("|             5�� show               |\n");
//    printf("|             6�� sort             |\n");
//    printf("|********************************************|\n");
//    printf("|             0���˳�ͨѶ¼                   |\n");
//    printf("|********************************************|\n");
//    printf("|����������ѡ��(1,2,3,4,5,6,7,8,9,10,11,12,0)|\n");
//    printf("|============================================|\n");
//}
//
//
////��ʼ��ͨѶ¼
//void initcontact(contact* pc)
//{
//    assert(pc);
//	pc->count = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}
//
////���
//void addcontact(contact* pc)
//{
//    assert(pc);
//    //�ж��Ƿ����
//    if (pc->count == 100)
//    {
//        printf("ͨѶ¼�������޷���ӣ�\n");
//    }
//    //δ�������
//    printf("������������");
//    scanf("%s", pc->data[pc->count].name);      //���鲻��ȡ��ַ
//    printf("���������䣺");
//    scanf("%d", &pc->data[pc->count].age);
//    printf("�������Ա�");
//    scanf("%s", pc->data[pc->count].sex);
//    printf("������绰��");
//    scanf("%s", pc->data[pc->count].tele);
//    printf("�������ַ��");
//    scanf("%s", pc->data[pc->count].addr);
//
//    ++pc->count;
//}
//
////��ӡͨѶ¼
//void showcontact(const contact* pc)
//{
//    assert(pc);
//    int i = 0;
//    //-������ָ��������䷽ʽ
//    printf("%-20s\t%-5s\t%-5s\t%-13s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
//    for (i = 0; i < pc->count; i++)
//    {
//        printf("%-20s\t%-3d\t%-5s\t%-13s\t%-30s\n", pc->data[i].name,
//                                                pc->data[i].age,
//                                                pc->data[i].sex,
//                                                pc->data[i].tele,
//                                                pc->data[i].addr);
//    }
//}
//
//
////����
////static�ؼ��֣��øú���ֻ���ڸ�Դ�ļ���ʹ�ã�����Դ�ļ��޷�����
//static int find_name(const contact* pc, char name[])
//{
//    assert(pc);
//    int i = 0;
//    for (i = 0; i < pc->count; i++)
//    {
//        if (0 == strcmp(pc->data[i].name, name))
//        {
//            //����ҵ��������±�
//            return i;
//        }
//    }
//
//    //û���ҵ�
//    return -1;
//}
//
////ɾ��
//void deletcontact(contact* pc)
//{
//    assert(pc);
//    //ͨѶ¼Ϊ�գ�����ɾ��
//    if (pc->count == 0)
//    {
//        printf("ͨѶ¼Ϊ�գ�\n");
//        return;
//    }
//    char name[20] = { 0 };
//    scanf("��������Ҫɾ���˵����֣�");
//    scanf("%s", name);
//
//    //����
//    int pos = find_name(pc, name);
//    if (pos == -1)
//    {
//        printf("Ҫɾ�����˲����ڣ�\n");
//        return;
//    }
//    //ɾ��
//    int i = 0;
//    for (i = pos; i < pc->count - 1; i++)
//    {
//        pc->data[i] = pc->data[i + 1];
//    }
//    pc->count--;
//    printf("ɾ���ɹ���\n");
//}
//
//int main()
//{
//    contact con;
//    initcontact(&con);
//    int input = 0;
//    do
//    {
//        menu();
//        printf("��ѡ��>");
//        scanf("%d", &input);
//        switch (input)
//        {
//        case add:
//            addcontact(&con);
//            break;
//        case del:
//            deletcontact(&con);
//            break;
//        case search:
//        {
//            printf("������Ҫ�����˵�������");
//            char name[20];
//            scanf("%s", name);
//            find_name(&con, name);
//            break;
//        }
//        case modify:
//            break;
//        case show:
//            showcontact(&con);
//            break;
//        case EXIT:
//            exit(0);
//            break;
//        default:
//            printf("ѡ�����������ѡ��\n");
//            break;
//        }
//
//
//
//
//
//
//
//
//    } while (1);
//}