
#include "graphics.h"
#include <iostream>
//#include <stdc++.h>
#pragma comment(lib, "graphics.lib")
using namespace std;
struct Data {
	int l;
	int r;
	Data* next;
};
struct Record {
	char data;
	int key;
};
void greenText(int x, int y, int a) {
	setcolor(GREEN);
	stringstream s1;
	s1 << a;
	string ss = s1.str();
	char* s = (char*)ss.c_str();
	outtextxy(x, y, s);
}
void blueText(int x, int y, int a) {
	setcolor(BLUE);
	stringstream s1;
	s1 << a;
	string ss = s1.str();
	char* s = (char*)ss.c_str();
	outtextxy(x, y, s);
}
void redText(int x, int y, int a) {
	setcolor(WHITE);
	stringstream s1;
	s1 << a;
	string ss = s1.str();
	char* s = (char*)ss.c_str();
	outtextxy(x, y, s);
}
void whiteText(int x, int y, int a) {
	setcolor(WHITE);
	stringstream s1;
	s1 << a;
	string ss = s1.str();
	char* s = (char*)ss.c_str();
	outtextxy(x, y, s);
}
void blackText(int x, int y, int a) {
	setcolor(BLACK);
	stringstream s1;
	s1 << a;
	string ss = s1.str();
	char* s = (char*)ss.c_str();
	outtextxy(x, y, s);
}
void whitetext(int x, int y, int a, int b) {
	setcolor(WHITE);
	stringstream s1, s2;
	s1 << a;
	s2 << b;
	string ss1 = s1.str();
	string ss2 = s2.str();
	char* s3 = (char*)ss1.c_str();
	char* s4 = (char*)ss2.c_str();
	outtextxy(x - 30, y, s3);
	outtextxy(x + 30, y, s4);
}
void whiterectangle(int x, int y, int x1, int y1, int a, int b) {
	setcolor(WHITE);
	rectangle(x, y, x1, y1);
	whitetext((x + x1) / 2, (y + y1) / 2, a, b);
}
void blacktext(int x, int y, int a, int b) {
	setcolor(BLACK);
	stringstream s1, s2;
	s1 << a;
	s2 << b;
	string ss1 = s1.str();
	string ss2 = s2.str();
	setcolor(BLACK);
	char* s3 = (char*)ss1.c_str();
	setcolor(BLACK);
	char* s4 = (char*)ss2.c_str();
	setcolor(BLACK);
	outtextxy(x - 30, y, s3);
	setcolor(BLACK);
	outtextxy(x + 30, y, s4);
}
void blackrectangle(int x, int y, int x1, int y1, int a, int b) {
	setcolor(BLACK);
	rectangle(x, y, x1, y1);
	setcolor(BLACK);
	blacktext((x + x1) / 2, (y + y1) / 2, a, b);
	setcolor(BLACK);
}
void yellowCircle(int x, int y, int R) {
	setcolor(YELLOW);
	circle(x, y, R);
}
void blueCircle(int x, int y, int R) {
	setcolor(BLUE);
	circle(x, y, R);
}
void greenCircle(int x, int y, int R) {
	setcolor(GREEN);
	circle(x, y, R);
}
void redCircle(int x, int y, int R) {
	setcolor(RED);
	circle(x, y, R);
}
void whiteCircle(int x, int y, int R) {
	setcolor(WHITE);
	circle(x, y, R);
}
void blackCircle(int x, int y, int R) {
	setcolor(BLACK);
	circle(x, y, R);
}
void blueBox(int x1, int x2, int y, int a1, int a2, int R)
{
	blueCircle(x1, y, R);
	blueText(x1, y, a1);
	blueCircle(x2, y, R);
	blueText(x2, y, a2);
}
void greenBox(int x1, int x2, int y, int a1, int a2, int R)
{
	greenCircle(x1, y, R);
	greenText(x1, y, a1);
	greenCircle(x2, y, R);
	greenText(x2, y, a2);
}
void redBox(int x1, int x2, int y, int a1, int a2, int R)
{
	redCircle(x1, y, R);
	redText(x1, y, a1);
	redCircle(x2, y, R);
	redText(x2, y, a2);
}
void blackBox(int x1, int x2, int& y, int a1, int a2, int R)
{
	blackCircle(x1, y, R);
	blackText(x1, y, a1);
	blackCircle(x2, y, R);
	blackText(x2, y, a2);
	//delay(5);
}
void whiteBox(int x1, int x2, int& y, int a1, int a2, int R)
{
	whiteCircle(x1, y, R);
	whiteText(x1, y, a1);
	whiteCircle(x2, y, R);
	whiteText(x2, y, a2);
	//delay(5);
}
void complete() {
	char s[] = "HOAN THANH VIEC SAP XEP!";
	outtextxy(500, 620, s);
}
void notice() {
	rectangle(30, 460, 400, 600);
	char s1[] = "Mau xanh la: phan tu da xep dung vi tri";
	char s2[] = "Mau do: phan tu sai vi tri can duoc xep dung";
	char s3[] = "Mau xanh bien: phan tu thu i xet tu trai qua";
	char s4[] = "Mau vang: phan tu thu j xet tu vi tri phai qua";
	char s5[] = "Quy uoc so -999 la so am vo cuc";
	char s6[] = "Quy uoc so 999 la so duong vo cuc";
	outtextxy(50, 480, s5);
	outtextxy(50, 500, s6);
	setcolor(GREEN);
	outtextxy(50, 520, s1);
	setcolor(RED);
	outtextxy(50, 540, s2);
	setcolor(BLUE);
	outtextxy(50, 560, s3);
	setcolor(YELLOW);
	outtextxy(50, 580, s4);
	setcolor(WHITE);
}
// transfer 2 value with circle 
void transferCircle(int x1, int x2, int& y, int a1, int a2, int R)
{
	//x1<x2
	for (int i = 0; i <= 100; i++) {
		blackBox(x1, x2, y, a1, a2, R);
		y = y++;
		whiteBox(x1, x2, y, a1, a2, R);
		//delay(1);
	}
	delay(50);
	//whiteCircle(x1, y, R);
	//whiteCircle(x2, y, R);
	int t1 = x1;
	while (x2 != t1) {
		blackBox(x1, x2, y, a1, a2, R);
		x1++;
		x2--;
		whiteBox(x1, x2, y, a1, a2, R);
		//delay(1);
	}
	delay(50);
	for (int i = 0; i <= 100; i++) {
		blackBox(x1, x2, y, a1, a2, R);
		y = y--;
		whiteBox(x1, x2, y, a1, a2, R);
		//delay(1);
	}
	delay(50);

}

// draw first array
void draw(Record a[], int n, int gap, int& y, int R) {
	char s1[] = "ARRAY:";
	outtextxy(50, y, s1);
	int i;
	for (i = 0; i < n + 2; i++) {
		stringstream s1, s2;
		s1 << i;
		string ss = s1.str();
		char* s = (char*)ss.c_str();
		outtextxy(gap, 25, s);
		circle((i + 2) * 100, y, R);
		s2 << a[i].key;
		ss = s2.str();
		s = (char*)ss.c_str();
		outtextxy((i + 2) * 100, y, s);
		gap += 100;
	}
	line(600, 300, 600, 600);
	line(600, 600, 800, 600);
	line(800, 300, 800, 600);
	notice();

	//int x1 = 200, x2 = 400;
	//transferCircle(x1, x2,y,a[0], a[2], R);
}

struct Stack {
	Data* top;
	void init() {
		top = nullptr;
	}
	bool Insert(Data* Y) {
		if (top == nullptr) {
			top = Y;
			top->next = nullptr;
			return true;
		}
		Y->next = top;
		top = Y;
		return true;
	}
	bool insertNode(int l, int r) {
		Data* data = (Data*)malloc(sizeof(Data));
		data->l = l; data->r = r;
		return this->Insert(data);
	}
	bool isEmpty() {
		return top == nullptr;
	}
	Data* deleteStack() {
		if (this->isEmpty() == true)
			return nullptr;
		Data* result;
		result = (Data*)calloc(1, sizeof(Data));
		result->l = top->l;
		result->r = top->r;
		Data* next = top->next;
		delete(top);
		top = next;
		return result;
	}
};
//selection sort
void quickSort(Record a[], int n, int y, int R)
{
	char s[] = "Quick Sort: ";
	outtextxy(50, 10, s);
	int l, r;
	delay(15000);
	int K;
	l = 1; r = n;
	K = a[l].key;
	Stack stack;
	stack.init();
	stack.insertNode(l, r);

	int Yrectangle = 600;
	whiterectangle(620, Yrectangle - 40, 780, Yrectangle - 20, 1, n);
	delay(5000);
	blackrectangle(620, Yrectangle - 40, 780, Yrectangle - 20, 1, n);
	int i, j;
	Record T;
	int slstack = 1;
	while (stack.isEmpty() == false) {
		Data* temp = stack.deleteStack();
		l = temp->l;
		r = temp->r;
		delay(5000);
		blackrectangle(620, Yrectangle - slstack * 40, 780, Yrectangle - 40 * (slstack - 1) - 20, l, r);
		slstack--;
		delay(1000);
		//i = l; j = r + 1;
		i = l + 1;
		j = r;
		K = a[l].key;
		redCircle((l + 2) * 100, y, R);
		delay(2000);
		blueCircle((i + 2) * 100, y, R);
		delay(3000);
		yellowCircle((j + 2) * 100, y, R);
		delay(3000);
		while (j > i) {
			while (K >= a[i].key && i <= j) {
				whiteCircle((i + 2) * 100, y, R);
				i++;
				blueCircle((i + 2) * 100, y, R);
				delay(2500);
			}

			while (K <= a[j].key && i <= j) {
				whiteCircle((j + 2) * 100, y, R);
				j--;
				yellowCircle((j + 2) * 100, y, R);
				if (i > j) {
					blueCircle((i + 2) * 100, y, R);
				}
				delay(2500);
			}
			// doi vi tri cho nhau
			if (j >= i) {
				transferCircle((i + 2) * 100, (j + 2) * 100, y, a[i].key, a[j].key, R);
				T = a[j];
				a[j] = a[i];
				a[i] = T;
				blueCircle((i + 2) * 100, y, R);
				delay(1000);
				yellowCircle((j + 2) * 100, y, R);
				delay(1000);

			}
		}
		// doi vi tri l va j
		if (j <= i) {
			// phan tu co 2 ptu tro len
			if (K > a[j].key) {
				delay(3000);
				transferCircle((l + 2) * 100, (j + 2) * 100, y, a[l].key, a[j].key, R);
				greenCircle((j + 2) * 100, y, R);
				delay(1000);
				greenText((j + 2) * 100, 25, j);
				whiteCircle((j + 2) * 100, y, R);
				whiteCircle((l + 2) * 100, y, R);
				whiteCircle((i + 2) * 100, y, R);
				delay(1000);
				T = a[j];
				a[j] = a[l];
				a[l] = T;
			}
			//chi co 1 phan tu
			else {
				greenCircle((j + 2) * 100, y, R);
				delay(1000);
				greenText((j + 2) * 100, 25, j);
				whiteCircle((j + 2) * 100, y, R);
				whiteCircle((i + 2) * 100, y, R);
			}
		}
		//them vao stack phia ben phai con dang xet
		if (r > j) {
			slstack++;
			whiterectangle(620, Yrectangle - slstack * 40, 780, Yrectangle - 40 * (slstack - 1) - 20, j + 1, r);
			delay(3000);

			stack.insertNode(j + 1, r);
		}
		//them vao stack phia ben phai con dang xet
		if (j > l) {
			slstack++;
			whiterectangle(620, Yrectangle - slstack * 40, 780, Yrectangle - 40 * (slstack - 1) - 20, l, j - 1);
			delay(3000);

			stack.insertNode(l, j - 1);
		}

	}
	// hoan thanh cong viec
	complete();
}
int main()
{
	int gap = 200;
	int y = 100;
	int R = 45;
	int n;
	cout << "nhap so luong phan tu: ";
	cin >> n;
	Record a[100];
	a[0].key = -999;
	a[n + 1].key = 999;
	cout << "nhap lan luot tung phan tu" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].key;
	}
	initwindow(1500, 700, "install_graphics_h");

	draw(a, n, gap, y, R);
	quickSort(a, n, y, R);

	delay(10000);
	getch();
	closegraph();
	return 0;
}