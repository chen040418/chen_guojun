//#define _CRT_SECURE_NO_WARNINGS
//
//#include"静态版-contact.h"
//
//
//
////菜单
//void menu()
//{
//    printf("|============================================|\n");
//    printf("|         欢迎使用通讯录                      |\n");
//    printf("|********************************************|\n");
//    printf("|             1、 add               |\n");
//    printf("|             2、 del               |\n");
//    printf("|             3、 search                   |\n");
//    printf("|             4、 modify                   |\n");
//    printf("|             5、 show               |\n");
//    printf("|             6、 sort             |\n");
//    printf("|********************************************|\n");
//    printf("|             0、退出通讯录                   |\n");
//    printf("|********************************************|\n");
//    printf("|请输入您的选择(1,2,3,4,5,6,7,8,9,10,11,12,0)|\n");
//    printf("|============================================|\n");
//}
//
//
////初始化通讯录
//void initcontact(contact* pc)
//{
//    assert(pc);
//	pc->count = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}
//
////添加
//void addcontact(contact* pc)
//{
//    assert(pc);
//    //判断是否存满
//    if (pc->count == 100)
//    {
//        printf("通讯录已满，无法添加！\n");
//    }
//    //未满，添加
//    printf("请输入姓名：");
//    scanf("%s", pc->data[pc->count].name);      //数组不用取地址
//    printf("请输入年龄：");
//    scanf("%d", &pc->data[pc->count].age);
//    printf("请输入性别：");
//    scanf("%s", pc->data[pc->count].sex);
//    printf("请输入电话：");
//    scanf("%s", pc->data[pc->count].tele);
//    printf("请输入地址：");
//    scanf("%s", pc->data[pc->count].addr);
//
//    ++pc->count;
//}
//
////打印通讯录
//void showcontact(const contact* pc)
//{
//    assert(pc);
//    int i = 0;
//    //-负号是指采用左对其方式
//    printf("%-20s\t%-5s\t%-5s\t%-13s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
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
////查找
////static关键字，让该函数只能在该源文件里使用，其他源文件无法访问
//static int find_name(const contact* pc, char name[])
//{
//    assert(pc);
//    int i = 0;
//    for (i = 0; i < pc->count; i++)
//    {
//        if (0 == strcmp(pc->data[i].name, name))
//        {
//            //如果找到，返回下标
//            return i;
//        }
//    }
//
//    //没有找到
//    return -1;
//}
//
////删除
//void deletcontact(contact* pc)
//{
//    assert(pc);
//    //通讯录为空，不用删除
//    if (pc->count == 0)
//    {
//        printf("通讯录为空！\n");
//        return;
//    }
//    char name[20] = { 0 };
//    scanf("请输入你要删除人的名字：");
//    scanf("%s", name);
//
//    //查找
//    int pos = find_name(pc, name);
//    if (pos == -1)
//    {
//        printf("要删除的人不存在！\n");
//        return;
//    }
//    //删除
//    int i = 0;
//    for (i = pos; i < pc->count - 1; i++)
//    {
//        pc->data[i] = pc->data[i + 1];
//    }
//    pc->count--;
//    printf("删除成功！\n");
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
//        printf("请选择：>");
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
//            printf("请输入要查找人的姓名：");
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
//            printf("选择错误，请重新选择！\n");
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