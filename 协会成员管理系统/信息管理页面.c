#include <stdlib.h>
#include <Windows.h>

#include <stdio.h>
#include <conio.h>

#include <errno.h>
#include <string.h>
#include <time.h>

#pragma warning(disable : 4996)

typedef struct Student
{
	char name[20];
	unsigned int tel;
	int number;
	struct student *next;
} student;

student *create(int n) //创造链表
{
	int m = 1;
	student *head = NULL, *temp = NULL, *end = NULL;
	head = (student *)malloc(sizeof(student));
	if (!head)
	{
		printf("头指针分配内存失败");
		exit(0);
	}
	end = head;
	for (int i = 0; i < n; i++)
	{
		temp = (student *)malloc(sizeof(student));
		if (!temp)
		{
			printf("结点分配内存失败");
			exit(0);
		}
		printf("第%d名学生信息:\n", m++);
		printf("\n请输入名字:");
		scanf("%s", &temp->name);
		printf("\n请输入学号:");
		scanf("%d", &temp->number);
		printf("\n请输入电话号码:");
		scanf("%d", &temp->tel);
		end->next = temp;
		end = temp;
	}
	end->next = NULL;
	return head;
}

student *next_node(student *p);
student *nth_node(student *head, int n);

void show(student *p) //显示所有数据
{
	int i = 1;
	
	while (p = next_node(p))
	{
		printf(" %d.名字:%s\n", i++, p->name);
		printf("   学号:%d\n", p->number);
		printf("   电话号码:%d\n", p->tel);
		printf("\n");
	}
	system("pause");
}

void change(student *head, int n) //修改第n个结点
{
	student *p = nth_node(head, n);

	if (p == NULL)
	{
		puts("该学生信息不存在\n");
	}

	printf("\t\t\n\n		  你想修改哪个数值:		 ");
	printf("\n\n\t\t	      1.姓名       			");
	printf("\n\n\t\t	      2.学号      			");
	printf("\n\n\t\t	      3.电话号码      		 ");
	printf("\n\n\t\t	      0.退出修改界面      		 \n");

	while (1)
	{
		switch (getch())
		{
		case '1':
			printf("请输入新的名字:");
			scanf("%s", &p->name);
			puts("数据修改完毕\n");
			break;
		case '2':
			printf("请输入新的学号:");
			scanf("%d", &p->number);
			puts("数据修改完毕\n");
			break;
		case '3':
			printf("请输入新的电话号码:");
			scanf("%d", &p->tel);
			puts("数据修改完毕\n");
			break;
		default:
			return;
		}
		Sleep(1000);
	}
}

void delete(student *p, int n) //删除第n个结点
{
	int i = 0;
	student *temp;
	p = nth_node(p, n);

	if (p != NULL)
	{
		temp->next = p->next;
		free(temp);
		puts("已删除该学生信息\n");
		Sleep(1000);
	}
	else
	{
		puts("\n该学生信息不存在\n");
		system("pause");
	}
}

void add(student *p, int m, int n) //添加多少个结点,并且放在哪里
{
	int i = 0;
	student *temp;
	p = nth_node(p);
	if (p != NULL)
	{
		for (int i = 0; i < m; i++)
		{
			temp = (student *)malloc(sizeof(student));
			printf("\n请输入名字:");
			scanf("%s", &temp->name);
			printf("\n请输入学号:");
			scanf("%d", &temp->number);
			printf("\n请输入电话号码:");
			scanf("%d", &temp->tel);
			p->next = temp->next;
			p->next = temp;
		}
	}
	else
	{
		puts("该学生信息不存在\n");
		system("pause");
	}
}

void deletelist(student *p) //清空链表
{
	
	while(p = next_node(p)) {
		free(p);
	}
	
	puts("删除数据成功!\n");
	Sleep(1000);
}

int decide()
{
	int n;
	while (1)
	{
		scanf("%ld", &n);
		while (getchar() != '\n')
			;
		if (n >= 1 && n <= 50 && n != 0)
		{
			break;
		}
		puts("请输入一个有效的值!\n");
	}
	return n;
}

void SaveData(student *p)
{
	FILE *fp = NULL;
	fp = fopen("C:/Users/Administrator/Desktop/users.txt", "a");

	if (!fp) {
		eprintf("file open failed!\n %s (OS %d)", strerror(errno), errno);
		return;
	}
	
	if (p == NULL) 
	{
		puts("学生信息不存在,保存失败\n");
		system("pause");
	}

 	while(p = next_node(p)) {
		fprintf(fp, "姓名: %s\n", p->name);
		fprintf(fp, "电话号码: %d\n", p->tel);
		fprintf(fp, "学号: %d\n", p->number);
		fprintf(fp, "\n");
	};

	system("pause");
}

int main()
{
	student *x = NULL;
	while (1)
	{
		printf("\n\n\t\t	= = =欢迎使用该系统= = =");
		printf("\n\n\t\t	      1.录入学生信息        ");
		printf("\n\n\t\t	      2.修改学生信息        ");
		printf("\n\n\t\t	      3.查看学生信息        ");
		printf("\n\n\t\t	      4.删除单个学生信息        ");
		printf("\n\n\t\t	      5.添加学生信息        ");
		printf("\n\n\t\t	      6.删除所有学生信息        ");
		printf("\n\n\t\t	      0.退出        ");
		printf("\n\n\t\t	= = = = = = = = = = = =\n");
		int m, j;
		char input = getch();
		if (input == '1')
		{
			if (x != NULL)
			{
				puts("\n学生信息已存在,请按5添加学生信息\n");
				Sleep(1000);
			}
			else if (x == NULL)
			{
				puts("你要录入几位学生信息(最多录入50名学生信息),请输入:");
				m = decide();
				x = create(m);
				puts("\n学生信息录入完毕");
				Sleep(1000);
			}
		}
		else if (input == '2')
		{
			if (x == NULL)
			{
				puts("学生信息不存在\n");
				system("pause");
			}
			else
			{
				puts("你要修改第几名学生的信息,请输入:");
				m = decide();
				change(x, m);
			}
		}
		else if (input == '3')
		{
			if (x == NULL)
			{
				puts("学生信息不存在\n");
				system("pause");
			}
			else
			{
				show(x);
			}
		}
		else if (input == '4')
		{
			if (x == NULL)
			{
				puts("学生信息不存在\n");
				system("pause");
			}
			else
			{
				puts("你要删除第几名学生信息，请输入:");
				m = decide();
				delete (x, m);
			}
		}
		else if (input == '5')
		{
			if (x == NULL)
			{
				puts("学生信息不存在\n");
				system("pause");
			}
			else
			{
				puts("添加几位学生信息，请输入:");
				m = decide();
				puts("添加在哪位学生后，请输入:");
				j = decide();
				add(x, j, m);
				puts("\n学生信息录入完毕");
				Sleep(1000);
			}
		}
		else if (input == '6')
		{
			if (x == NULL)
			{
				puts("学生信息不存在\n");
				system("pause");
			}
			else
			{
				deletelist(x);
			}
		}
		else if (input == '0')
		{
			break;
		}
		else if (input == ' ')
		{
			puts("该系统有诸多bug\n如发现bug，可以发给我继续去修bug\nQQ:513815062\n");
			system("pause");
		}
		else
		{
			puts("不要乱按其他键啦,没啥用的\n");
			Sleep(500);
		}
		system("cls");
	}
	return 0;
}

student *next_node(student *p)
{
	if (p && p->next)
	{
		return p->next;
	}
	else
	{
		return NULL;
	}
}

student *nth_node(student *head, int n)
{
	if (n <= 0)
	{
		return NULL;
	}
	student *p = head;

	for (int i = 0; i < n && p; i++)
	{
		p = next_node(p);
	}
}
