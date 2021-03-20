//学生成绩管理
#include <iostream>
using namespace std;

/*
        定义结构体student用于表示学生的基本信息，采用链表结构
*/
struct student
{
    int no;                  //  学号
    char name[20], sex;      //  姓名以及性别,  请思考如果将name[20]修改为*name，结果将会怎样，还适合本题的处理方式吗？
    int age;                 //  年龄
    float chinese, computer; //  表示两门课程的成绩
    student *next;
    bool operator<(const student &another) const //  重载运算符  <  (小于)，用于结构体对象之间的比较，在LinkSort中比较链表的两个节点大小
    {
        return this->chinese+this->computer<another.chinese+another.computer;
    }
};

student *ReadFile(FILE *fp, student *head, int &n); //  从二进制文件(文件指针为fp)中将所有数据读入，存储于以head为头指针的链表中
void display(student *head);                        //  用于显示链表的内容
void WriteFile(FILE *fp, student *head);            //  将以head为头指针的链表中的数据写入二进制文件(文件指针为fp)
student *input(student *head, int &n);              //  输入新的数据，将新数据连接到链表末尾
student *LinkSort(student *head, const int &n);     //  实现对链表的排序，按总成绩从大到小排列，冒泡排序
void swapNode(student *s, student *q);              //  实现对链表节点的数据交换，用于排序,  在函数LinkSort中调用

int main()
{
    int n = 0;            //  定义变量n，用于存储学生人数
    student *head = NULL; //  链表头指针
    FILE *fp;

    fp = fopen("grade.bin","wb"); //  打开二进制文件，用于读写以及添加记录
    head = ReadFile(fp,head,n);
    display(head);
    fclose(fp);

    head = input(head, n);
    head = LinkSort(head, n);

    fp = fopen("grade.bin", "wb");
    WriteFile(fp, head);
    fclose(fp);

    return 0;
}

student *ReadFile(FILE *fp, student *head, int &n) //本函数将调用fread函数读数据块，这个函数非常有用
{
    student *q = head;
    if (head)
        while (q->next)
            q = q->next;

    while (1)
    {
        student *p = new student; //  用于存储读入的数据块
        if (!fread(p,1,sizeof(student),fp))             //  从文件fp中读入大小为sizeof(student)的数据块，保存于内存缓冲区p之中,  fread将返回读入的字节数，如果为0，则结束读文件
        {
            delete p;
            break;
        }
        p->next = NULL;
        if (!head)
            head = p;
        else
            q->next = p;

        q = p;
        n++;
    }

    return head;
}

void WriteFile(FILE *fp,student *head) //本函数将调用fwrite函数写数据块，这个函数非常有用
{
    while (head)
    {
        fwrite(head,sizeof(student),sizeof(student),fp); //  将缓冲区head中的内容(数据块)写入文件中
        head = head->next;
    }
}

void display(student *head)
{
    student *p = head;
    while (p)
    {
        cout<<"No: "<<p->no<<"\nName: "<<p->name<<"\nSex: "<<p->sex<<"\nAge: "<<p->age;
        cout.precision(6);
        cout<<"\nScores: "<<p->chinese;
        cout.precision(6);
        cout<<' '<<p->computer<<"\n\n";
        p=p->next;
        //  输出链表节点内容
    }
}

student *input(student *head, int &n)
{

    student *q = head;

    if (head)
        while (q->next)
            q = q->next;

    while (1)
    {
        printf("Input  continue(y/n)?");
        if (getchar() != 'y')
            break;

        student *p = new student;

        printf("No:  ");
        scanf("%d", &p->no);
        getchar();
        printf("Name:  ");
        gets(p->name);
        printf("Sex(M/F):  ");
        p->sex = getchar();
        printf("Age:  ");
        scanf("%d", &p->age);
        printf("Chinese  score:  ");
        scanf("%f", &p->chinese);
        printf("Computer  score:  ");
        scanf("%f", &p->computer);
        p->next = NULL;
        getchar();

        if (!head)
            head = p;
        else
            q->next = p;

        q = p;
        n++;
    }

    return head;
}

student *LinkSort(student *head, const int &n)
{
    student *p;
    for (int i = 1; i <= n - 1; i++)
    {
        p = head;
        for (int j = 1; j <= n - i; j++)
        {
            if (*p < *p->next)
            {
                swapNode(p,p->next); //  交换节点值
            }
            p = p->next;
        }
    }

    return head;
}

void swapNode(student *s, student *q)
{
    student *snext = s->next, *qnext = q->next, tmp;
    tmp = *s;
    *s = *q;
    *q = tmp;
    s->next = snext;
    q->next = qnext;
}