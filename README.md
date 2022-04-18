#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<iostream>
using namespace std;
struct staff
{
	int num;
	char name[20];
	int product;
	int time;
};
struct staff sta[100], a[100];
int n = 1;
void enter(); //主菜单
void input(); //录入功能
void output(); //输出功能
void add(); //添加功能
void delet(); //删除功能
void search(); //查找功能
void end();
int main()
{
	printf("\n\n\t\t\t欢迎进入职工管理系统");
	enter();
}
void enter()
{
	int choice;
	int h;
	printf("\n\t\t1.录入\t2.显示\t3.添加\t4.删除\t5.查找\t6.退出");
	printf("\n输入序号执行相应功能\n");
	cin >> choice;
	switch (choice)
	{
	case 1:input(); break;
	case 2:output(); break;
	case 3:add(); break;
	case 4:delet(); break;
	case 5:search(); break;
	case 6:end(); break;
	default:h = 0;
	}
	if (h == 0)
	{
		printf("输入序号有误，请重新输入\n");
		enter();
	}
}
void input()

{
	int flag;
	char k;
	struct staff* p;
	p = sta;
	system("cls");
	do
	{
		cout << "职工工号:" << endl;
		cin >> p->num;
		cout << "职工姓名:" << endl;
		cin >> p->name;
		cout << "完成的产品数量:" << endl;
		cin >> p->product;
		cout << "完成时间:" << endl;
		cin >> p->time;
		cout << "是否继续输入职工信息,如果是请按Y,不是请按任意键" << endl;
		getchar();
		k = getchar();
		if (k == 'y' || k == 'Y')
		{
			flag = 1;
			n++;
			p++;
			system("cls");
		}
		else
		{
			getchar();
			system("cls");
			enter();
		}
	} while (flag == 1);
}
void output()
{
	int i, j, t;/*将对同一职工的多次输入叠加在一起*/
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
			if (sta[i].num == sta[j].num)
			{
				sta[i].product += sta[j].product;
				sta[j].product = -1;
				sta[i].time += sta[j].time;
				sta[j].time = -1;
			}
	}
	/*按产品数量将职工一一排序*/
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
			if (sta[i].product < sta[j].product)
			{
				strcpy_s(a[i].name, sta[i].name);
				strcpy_s(sta[i].name, sta[j].name);
				strcpy_s(sta[j].name, a[i].name);
				t = sta[i].num;
				sta[i].num = sta[j].num;
				sta[j].num = t;
				t = sta[i].product;
				sta[i].product = sta[j].product;
				sta[j].product = t;
				t = sta[i].time;
				sta[i].time = sta[j].time;
				sta[j].time = t;
			}
	}
	/*产品相同职工，按工号从小到大排序*/

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
			if ((sta[i].product == sta[j].product) && (sta[i].num > sta[j].num))
			{
				strcpy_s(a[i].name, sta[i].name);
				strcpy_s(sta[i].name, sta[j].name);
				strcpy_s(sta[j].name, a[i].name);
				t = sta[i].num;
				sta[i].num = sta[j].num;
				sta[j].num = t;
				t = sta[i].product;
				sta[i].product = sta[j].product;
				sta[j].product = t;
				t = sta[i].time;
				sta[i].time = sta[j].time;
				sta[j].time = t;
			}
	}
	cout << "输出如下:" << endl;
	for (i = 0; i < n; i++)
	{
		if (sta[i].product >= 0)
			printf("排名%d,职号%d,名字%s,工作量%d,完成时间%d\n", i + 1, sta[i].num, sta[i].name, sta[i].product, sta[i].time);
	}
	printf("已完成输出，请按任意键返回主菜单\n");
	_getch();
	system("cls");
	enter();
}
void add()
{
	struct staff* p;
	p = sta + n;
	cout << "职工工号:" << endl;
	cin >> p->num;
	cout << "职工姓名:" << endl;
	cin >> p->name;
	cout << "完成的产品数量:" << endl;
	cin >> p->product;
	cout << "完成时间:" << endl;
	cin >> p->time;
	n++;
	cout << "请按任意键返回主菜单" << endl;
	_getch();
	system("cls");
	enter();
}
void delet()
{
	int a = n;
	struct staff* p;
	char w[20];
	cout << "请输入需要删除的职工姓名:" << endl;
	cin >> w;
	for (p = sta; p < sta + n; p++)
	{
		if (strcmp(p->name, w) == 0)
			p->product = -1;
		else
			a--;
	}
	if (a == 0)
		cout << "你所输入的职工不存在" << endl;
	cout << "请按任意键返回主菜单" << endl;
	_getch();
	system("cls");
	enter();
}
void search()
{
	int a = n;
	struct staff* p;
	char w[20];
	cout << "请输入需要查找的职工姓名:" << endl;
	cin >> w;
	for (p = sta; p < sta + n; p++)
	{
		if (strcmp(p->name, w) == 0 && (p->product >= 0))
			printf("职号%d,名字%s,工作量%d,完成时间%d\n", p->num, p->name, p->product,p->time);
		else
			a--;
	}
	if (a == 0)
		cout << "你所输入的职工不存在" << endl;
	cout << "请按任意键返回主菜单" << endl;
	_getch();
	system("cls");
	enter();
}
void end()
{
	getchar();
	system("cls");
	printf("\n\n\n\t\t\t\t谢谢您的使用\n");
}
