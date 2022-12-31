#include "graphics.h"
#include <iostream>
//#include <stdc++.h>
#pragma comment(lib, "graphics.lib")
using namespace std;
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
	char s[] = "HOAN THANH SAP XEP!";
	outtextxy(60, 350, s);
}
void notice() {
	rectangle(50, 250, 450, 330);
	char s1[] = "Mau xanh la: phan tu da xep dung vi tri";
	char s2[] = "Mau do: phan tu sai vi tri";
	char s3[] = "Mau xanh bien: phan tu max so voi phan tu sai vi tri";
	setcolor(GREEN);
	outtextxy(60, 270, s1);
	setcolor(RED);
	outtextxy(60, 290, s2);
	setcolor(BLUE);
	outtextxy(60, 310, s3);
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
	for (i = 0; i < n; i++) {
		stringstream s1, s2;
		s1 << i ;
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
	notice();
	//int x1 = 200, x2 = 400;
	//transferCircle(x1, x2,y,a[0], a[2], R);
}

//selection sort
void selectionSort(Record a[], int n, int y, int R)
{
	char s[] = "Selection Sort: ";
	outtextxy(50, 10, s);
	int i, j, max;
	Record temp;
	delay(8000);
	for (i = n-1; i >0; i--)
	{
		int sl = 0;
		max = i;
		redCircle((max + 2) * 100, y, R);
		delay(2000);
		for (j = i - 1; j >=0; j--) {
			redCircle((j + 2) * 100, y, R);
			delay(2000);
			if (a[j].key > a[max].key) {
				blueCircle((j + 2) * 100, y, R);
				delay(2000);
				sl++;
				if (sl >= 2) {
					whiteCircle((max + 2) * 100, y, R);
					delay(1000);
				}
				max = j;
			}
			else {
				whiteCircle((j + 2) * 100, y, R);
				delay(2000);
			}

		}

		if (max != i) {
			temp = a[max];
			a[max] = a[i];
			a[i] = temp;
			transferCircle( (max + 2) * 100, (i + 2) * 100, y, a[i].key, a[max].key, R);
			greenCircle((i + 2) * 100, y, R);
			delay(2000);
			whiteCircle((max + 2) * 100, y, R);
			delay(1000);
		}
		else {
			greenCircle((i + 2) * 100, y, R);
			delay(2000);
		}
	}
	greenCircle((2) * 100, y, R);
	delay(2000);
	complete();
}

int main()
{
	int gap = 200;
	int y = 100;
	int R = 45;
	int n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	Record a[100];
	cout << "Nhap lan luot tung phan tu :";
	for (int i = 0; i < n; i++) {
		cin >> a[i].key;
	}
	initwindow(1500, 700, "install_graphics_h");
	draw(a, n, gap, y, R);
	selectionSort(a, n, y, R);
	//greenText(gap, y, a[1]);
	delay(10000);
	getch();
	closegraph();
	return 0;
}