#define _CRT_SECURE_NO_WARNINGS

#include"动态版-contact.h"



//菜单
void menu()
{
    printf("|============================================|\n");
    printf("|              欢迎使用通讯录                 |\n");
    printf("|********************************************|\n");
    printf("|             1、 add                        |\n");
    printf("|             2、 del                        |\n");
    printf("|             3、 search                     |\n");
    printf("|             4、 modify                     |\n");
    printf("|             5、 show                       |\n");
    printf("|             6、 sort                       |\n");
    printf("|********************************************|\n");
    printf("|             0、退出通讯录                   |\n");
    printf("|********************************************|\n");
    printf("|请输入您的选择(1,2,3,4,5,6,7,8,9,10,11,12,0) |\n");
    printf("|============================================|\n");
}


//初始化通讯录-动态版
int initcontact(contact* pc)
{
    assert(pc);
    pc->count = 0;
    pc->data = (peoinfo*) calloc(DEFAULT_SIZE, sizeof(peoinfo));
    if (pc->data == NULL)
    {
        printf("initcontact::%s\n", strerror(errno));
        return 1;
    }
    pc->capacity = DEFAULT_SIZE;
    
    //加载通讯录已有信息
    load_contact(pc);

    return 0;
}

//判断是否需要增容
void check_capacity(contact* pc)
{
    if (pc->count == pc->capacity)
    {
        peoinfo* ptr = (peoinfo*)realloc(pc->data, (pc->capacity + INC_SIZE) * sizeof(peoinfo));
        if (ptr == NULL)
        {
            printf("addcontact::%s\n", strerror(errno));
            return;
        }
        else
        {
            pc->data = ptr;
            ptr = NULL;     //将ptr置空，防止成为野指针
            pc->capacity += INC_SIZE;
            printf("增容成功！\n");
        }
    }
}

//加载通讯录已有信息
void load_contact(contact* pc)
{
    FILE* pfread = fopen("contact.txt", "rb");
    if (pfread == NULL)
    {
        perror("load_contact");
        return;
    }

    peoinfo tmp = { 0 };

    //如果pfread成功读取一个，就为真
    while (fread(&tmp, sizeof(peoinfo), 1, pfread) == 1)
    {
        check_capacity(pc);
        pc->data[pc->count] = tmp;
        pc->count++;
    }

    fclose(pfread);
    pfread = NULL;
    return;
}

//添加
void addcontact(contact* pc)
{
    assert(pc);
    //判断是否存满,存满就增容
    check_capacity(pc);

    //未满，添加
    printf("请输入姓名：");
    scanf("%s", pc->data[pc->count].name);      //数组不用取地址
    printf("请输入年龄：");
    scanf("%d", &pc->data[pc->count].age);
    printf("请输入性别：");
    scanf("%s", pc->data[pc->count].sex);
    printf("请输入电话：");
    scanf("%s", pc->data[pc->count].tele);
    printf("请输入地址：");
    scanf("%s", pc->data[pc->count].addr);

    ++pc->count;
}

//打印通讯录
void showcontact(const contact* pc)
{
    assert(pc);
    int i = 0;
    //-负号是指采用左对其方式
    printf("%-20s\t%-5s\t%-5s\t%-13s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
    for (i = 0; i < pc->count; i++)
    {
        printf("%-20s\t%-3d\t%-5s\t%-13s\t%-30s\n", pc->data[i].name,
            pc->data[i].age,
            pc->data[i].sex,
            pc->data[i].tele,
            pc->data[i].addr);
    }
}


//查找
//static关键字，让该函数只能在该源文件里使用，其他源文件无法访问
static int find_name(const contact* pc, char name[])
{
    assert(pc);
    int i = 0;
    for (i = 0; i < pc->count; i++)
    {
        if (0 == strcmp(pc->data[i].name, name))
        {
            //如果找到，返回下标
            return i;
        }
    }

    //没有找到
    return -1;
}

//删除
void deletcontact(contact* pc)
{
    assert(pc);
    //通讯录为空，不用删除
    if (pc->count == 0)
    {
        printf("通讯录为空！\n");
        return;
    }
    char name[20] = { 0 };
    scanf("请输入你要删除人的名字：");
    scanf("%s", name);

    //查找
    int pos = find_name(pc, name);
    if (pos == -1)
    {
        printf("要删除的人不存在！\n");
        return;
    }
    //删除
    int i = 0;
    for (i = pos; i < pc->count - 1; i++)
    {
        pc->data[i] = pc->data[i + 1];
    }
    pc->count--;
    printf("删除成功！\n");
}

//保存Contact信息到文件中
void save_contact(const contact* pc)
{
    assert(pc);
    FILE* pfwrite = fopen("contact.txt", "wb");
    if (pfwrite == NULL)
    {
        perror("save_contact");
        return;
    }

    //以二进制形式写入
    int i = 0;
    for (i = 0; i < pc->count; i++)
    {
        fwrite(pc->data + i, sizeof(peoinfo), 1, pfwrite);
    }

    fclose(pfwrite);
    pfwrite = NULL;
    return;
}

//释放内存
void destroy_contact(contact* pc)
{
    assert(pc);
    free(pc->data);
    pc->data = NULL;
    return;
}

int main()
{
    contact con;
    initcontact(&con);
    int input = 0;
    do
    {
        menu();
        printf("请选择：>");
        scanf("%d", &input);
        switch (input)
        {
        case add:
            addcontact(&con);
            break;
        case del:
            deletcontact(&con);
            break;
        case search:
        {
            printf("请输入要查找人的姓名：");
            char name[20];
            scanf("%s", name);
            find_name(&con, name);
            break;
        }
        case modify:
            break;
        case show:
            showcontact(&con);
            break;
        case EXIT:
            save_contact(&con);
            destroy_contact(&con);
            exit(0);
            break;
        default:
            printf("选择错误，请重新选择！\n");
            break;
        }








    } while (1);
}