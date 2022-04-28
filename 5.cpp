#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;
void f(int amount, int oper, int max, int kuohao, int xiaoshu) {
	int range;
	if (max == 1)range = 10;
	else if (max == 2)range = 100;
	else range = 1000;
	for (int i = 0;i < amount;i++) {
		double firstone = 0;
		int changdu=rand()%5+1;
		int kuohaochangdu = changdu - rand()%changdu;
		int youmeiyoukuohao = 0;
		int youkuohaojiewei = 0;
		srand((unsigned)time(0)+(unsigned)rand());
		firstone = (double)rand() / RAND_MAX * range+1;
		if (xiaoshu == 1)cout << firstone;
		else cout << int(firstone);
		for (int j = 0;j <= changdu;j++) {
			if (oper == 1) {
				int fuhao = rand() % 2;
				if (fuhao == 0)cout << "+";
				else cout << "-";
			}
			else if (oper == 2) {
				int fuhao = rand() % 2;
				if (fuhao == 0)cout << "*";
				else cout << "/";
			}
			else {
				int fuhao = rand() % 4;
				switch (fuhao) {
				case 0:
					cout << "+";
					break;
				case 1:
					cout << "-";
					break;
				case 2:
					cout << "*";
					break;
				case 3:
					cout << "/";
					break;
				}
			}
			if (kuohao == 1) {
				if (youmeiyoukuohao == 0) {
					cout << "(";
					youmeiyoukuohao++;
				}
			}
			if (xiaoshu == 1)cout << (double)rand() / RAND_MAX * range+1;
			else cout << int((double)rand() / RAND_MAX * range)+1;
			if (kuohao == 1) {
				if (kuohaochangdu == 0 && youkuohaojiewei == 0) {
					cout << ")";
					youkuohaojiewei++;
				}
				else kuohaochangdu--;
			}			
		}
		cout <<"="<< endl;
	}
}
int main() {
	int oper;
	int amount;
	int max;
	int kuohao;
	int xiaoshu;
	printf("输入生成数量：");
	cin >> amount;
	printf("输入运算符（输入1代表加减，2代表乘除，3代表混合）：\n");
	oper = _getch();
	oper -= 48;
	printf("输入最大数（输入1代表10以内，2代表100以内，3代表1000以内）：\n");
	max = _getch();
	max -= 48;
	printf("输入是否带括号（输入1代表加带，2代表不带）：\n");
	kuohao = _getch();
	kuohao -= 48;
	printf("输入是否带小数（输入1代表加带，2代表不带）：\n");
	xiaoshu = _getch();
	xiaoshu -= 48;
	printf("输入是否输出到文件（输入1代表否，2代表是）：\n");
	int x = _getch();
	f(amount, oper, max, kuohao, xiaoshu);
	return 0;
}