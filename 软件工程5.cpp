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
void enter(); //���˵�
void input(); //¼�빦��
void output(); //�������
void add(); //��ӹ���
void delet(); //ɾ������
void search(); //���ҹ���
void end();
int main()
{
	printf("\n\n\t\t\t��ӭ����ְ������ϵͳ");
	enter();
}
void enter()
{
	int choice;
	int h;
	printf("\n\t\t1.¼��\t2.��ʾ\t3.���\t4.ɾ��\t5.����\t6.�˳�");
	printf("\n�������ִ����Ӧ����\n");
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
		printf("���������������������\n");
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
		cout << "ְ������:" << endl;
		cin >> p->num;
		cout << "ְ������:" << endl;
		cin >> p->name;
		cout << "��ɵĲ�Ʒ����:" << endl;
		cin >> p->product;
		cout << "���ʱ��:" << endl;
		cin >> p->time;
		cout << "�Ƿ��������ְ����Ϣ,������밴Y,�����밴�����" << endl;
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
	int i, j, t;/*����ͬһְ���Ķ�����������һ��*/
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
	/*����Ʒ������ְ��һһ����*/
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
	/*��Ʒ��ְͬ���������Ŵ�С��������*/

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
	cout << "�������:" << endl;
	for (i = 0; i < n; i++)
	{
		if (sta[i].product >= 0)
			printf("����%d,ְ��%d,����%s,������%d,���ʱ��%d\n", i + 1, sta[i].num, sta[i].name, sta[i].product, sta[i].time);
	}
	printf("�����������밴������������˵�\n");
	_getch();
	system("cls");
	enter();
}
void add()
{
	struct staff* p;
	p = sta + n;
	cout << "ְ������:" << endl;
	cin >> p->num;
	cout << "ְ������:" << endl;
	cin >> p->name;
	cout << "��ɵĲ�Ʒ����:" << endl;
	cin >> p->product;
	cout << "���ʱ��:" << endl;
	cin >> p->time;
	n++;
	cout << "�밴������������˵�" << endl;
	_getch();
	system("cls");
	enter();
}
void delet()
{
	int a = n;
	struct staff* p;
	char w[20];
	cout << "��������Ҫɾ����ְ������:" << endl;
	cin >> w;
	for (p = sta; p < sta + n; p++)
	{
		if (strcmp(p->name, w) == 0)
			p->product = -1;
		else
			a--;
	}
	if (a == 0)
		cout << "���������ְ��������" << endl;
	cout << "�밴������������˵�" << endl;
	_getch();
	system("cls");
	enter();
}
void search()
{
	int a = n;
	struct staff* p;
	char w[20];
	cout << "��������Ҫ���ҵ�ְ������:" << endl;
	cin >> w;
	for (p = sta; p < sta + n; p++)
	{
		if (strcmp(p->name, w) == 0 && (p->product >= 0))
			printf("ְ��%d,����%s,������%d,���ʱ��%d\n", p->num, p->name, p->product, p->time);
		else
			a--;
	}
	if (a == 0)
		cout << "���������ְ��������" << endl;
	cout << "�밴������������˵�" << endl;
	_getch();
	system("cls");
	enter();
}
void end()
{
	getchar();
	system("cls");
	printf("\n\n\n\t\t\t\tлл����ʹ��\n");
}