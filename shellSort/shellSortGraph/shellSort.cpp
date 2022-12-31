#include "graphics.h"
#include <iostream>
//#include <stdc++.h>
#pragma comment(lib, "graphics.lib")
using namespace std;

void greenText(int x, int y, int a) {
	setcolor(GREEN);
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
void blackBox(int x1, int x2, int &y, int a1, int a2, int R)
{
	blackCircle(x1, y, R);
	blackText(x1, y, a1);
	blackCircle(x2, y, R);
	blackText(x2, y, a2);
	//delay(5);
}
void whiteBox(int x1, int x2, int &y, int a1, int a2, int R)
{
	whiteCircle(x1, y, R);
	whiteText(x1, y, a1);
	whiteCircle(x2, y, R);
	whiteText(x2, y, a2);
	//delay(5);
}
void complete() {
	char s[] = "SORTING DONE!";
	outtextxy(250, 500, s);
}
void notice() {
	rectangle(1080, 570, 1300, 620);
	char s1[] = "Mau xanh: phan tu dang xet";
	char s2[] = "Mau do: phan tu sai vi tri";
	setcolor(GREEN);
	outtextxy(1100, 580, s1);
	setcolor(RED);
	outtextxy(1100, 600, s2);
	setcolor(WHITE);
}
struct Record
{
	char data;
	int key;
};
void inPut(Record M[], int &n) {
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	cout << "Nhap phan tu: \n";
	for (int i = 0; i < n; i++) {
		cin >> M[i].key;
	}
}
void outPut(Record M[], int n) {
	for (int i = 0; i < n; i++) {
		cout << M[i].key << " ";
	}
	cout << endl;
}
// transfer 2 value with circle 
void transferCircle(int x1, int x2, int &y, int a1,int a2, int R)
{	
	//x1<x2
	for (int i = 0; i <= 100; i++) {
		blackBox(x1, x2, y, a1, a2, R);
		y = y ++;
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
void draw(Record M[], int n, int gap, int &y, int R) {
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
		s2 << M[i].key;
		ss = s2.str();
		s = (char*)ss.c_str();
		outtextxy((i + 2) * 100, y, s);
		gap += 100;
	}
	notice();
	//int x1 = 200, x2 = 400;
	//transferCircle(x1, x2,y,a[0], a[2], R);
}


void shellSort(Record M[], int n, int y, int R)
{
	outPut(M, n);
	char s[] = "Shell Sort: ";
	outtextxy(50, 10, s);
	char s2[] = "GAP:";
	outtextxy(50, y + 200, s2);
	circle(200, y + 200, R);
	int y1 = y + 200;
	for (int i = n / 2; i > 0; i /= 2)
	{
		delay(1000);
		whiteText(200, y1, i);
		for (int j = i; j < n; j++)
		{
			Record r = M[j];
			int k = j;
			greenBox((k - i + 2) * 100, (k + 2) * 100, y, M[k - i].key, r.key , R);
			
			delay(1000);
			for (k; k >= i && M[k - i].key > r.key; k -= i)
			{
				greenBox((k - i + 2) * 100, (k + 2) * 100, y, M[k - i].key, r.key, R);
				delay(100);
				redBox((k - i + 2) * 100, (k + 2) * 100, y, M[k - i].key , r.key, R);
				delay(1000);
				transferCircle((k-i + 2) * 100, (k + 2) * 100, y, M[k-i].key, r.key, R);
				M[k] = M[k - i];
			}
			if(k-i>=0)
				whiteBox((k-i + 2) * 100, (k + 2) * 100, y, M[k - i].key, r.key, R);
			M[k] = r;
			
		}
	}
	whiteText(200, y1, 0);
	for (int i = 0; i < n; i++) {
		greenCircle((i + 2) * 100, y, R);
		greenText((i + 2) * 100, y, M[i].key);
		delay(100);
	}
	outPut(M, n);
	setcolor(WHITE);
	complete();
}
int* Incresments(int& t, int N) {
	int* H = new int[N];
	for (int j = 0; j < N; j++)
		H[j] = 0;
	H[0] = 1;
	while (3 * H[t] <= N) {
		t++;
		H[t] = 3 * H[t - 1] + 1;
	}
	return H;
}

//void shellSort(int* M, int N) {
//	//outPut(M, n);
//	int t = 0;
//	int* H = new int[N];
//	H = Incresments(t, N);
//
//	for (int s = t - 1; s >= 0; s--) {                                               // D1
//		int h = H[s];					          //D2
//
//		for (int j = h ; j <= N; j++) {
//			int i = j - h, K = M[j];		             //D3			
//			int R = M[j];				//D3
//
//			while (i >= 0) {				//D5
//				if (K >=  M[i]) {			//D4
//					M[i + h] = R;		            //D6
//					break;
//				}
//				else {
//					swap(M[i + h], M[i]);	             //D5
//					i = i - h;			
//				}
//			}
//		}
//	}
//	outPut(M, N);
//	//PrintRecord(M,0, N);
//}

int main()
{
	int gap = 200;
	int y = 100;
	int R = 45;
	int n = 5;
	Record M[100];
	inPut(M, n);
	//int a[] = { 15,50,17,1,2};
	initwindow(1500, 700, "install_graphics_h");

	draw(M, n, gap,y, R);
	shellSort(M, n, y, R);
	//delay(10000);
	getch();
	closegraph();
	return 0;
}