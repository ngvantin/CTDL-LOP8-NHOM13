#include "graphics.h"
#include <iostream>
#include <conio.h>
#include <dos.h>
#pragma comment(lib, "graphics.lib")

using namespace std;

struct Record {
	char data;
	int key;
};

Record R[100];
int n;
int radius = 25;

void importArray(Record R[], int& n) {
	cin >> n;
	do {
		if (n <= 1) {
			cout << "Invalid value. Please re-enter." << endl;
			cin >> n;
		}
	} while (n <= 1);
	for (int i = 0; i < n; i++)
		cin >> R[i].key;
}

void exportArray(Record R[], int n) {
	for (int i = 0; i < n; i++)
		cout << R[i].key << " ";
	cout << endl;
}

void drawCircle(int x, int y, int color) {
	setcolor(color);
	circle(x, y, radius);
}

void writeText(int x, int y, int data, int color) {
	stringstream ss;
	ss << data;
	string s = ss.str();
	char* t = (char*)s.c_str();
	setcolor(color);
	outtextxy(x, y, t);
}

void drawBox(int x, int y, int data, int color) {
	drawCircle(x, y, color);
	writeText(x, y, data, color);
}

void drawMulticolorBox(int x, int y, int data, int colorCircle, int colorText) {
	drawCircle(x, y, colorCircle);
	writeText(x, y, data, colorText);
}

void glowBox(int x, int y, int data) {
	int j = 1;
	while (j != 50) {
		setcolor(j);
		j++;
		drawBox(x, y, data, j);
		delay(1);
	}
	drawBox(x, y, data, WHITE);
}

void drawArray(Record R[], int n, int x, int y, int color) {
	string index = "Index: ";
	char* indx = (char*)index.c_str();
	setcolor(color);
	outtextxy(50, y - 50, indx);
	//Write array indexes
	for (int i = 0; i < n; i++)
		writeText(x + 50 * i + 50, y - 50, i, color);
	//Draw array
	for (int i = 0; i < n; i++) {
		if (i == 0)
			drawBox(x + 50, y, R[i].key, color);
		else
			drawBox(x + 50 * i + 50, y, R[i].key, color);
	}
}

void comparison(int x, int y, int i, int j, int color, int colorNum) {
	char q1[] = "Key[ ";
	char q2[] = " ] < Key[ ";
	char q3[] = " ] ?";
	setcolor(color);
	outtextxy(x, y, q1);
	writeText(x + 40, y, i, colorNum);
	setcolor(color);
	outtextxy(x + 50, y, q2);
	writeText(x + 115, y, j, colorNum);
	setcolor(color);
	outtextxy(x + 125, y, q3);
}

void countingSortVisualize(Record R[], int n) {
	Record Count[100];
	Record Output[10];
	for (int i = 0; i < n; i++) {
		Count[i].key = 0;
		Output[i].key = 0;
	}

	setcolor(LIGHTGRAY);
	char array[] = "Unsorted Array: ";
	outtextxy(50, 0, array);
	drawArray(R, n, 100, 75, LIGHTGRAY);
	delay(100);
	
	char countArray[] = "Count Array with [n] Zero elements: ";
	outtextxy(50, 125, countArray);
	delay(100);
	drawArray(Count, n, 100, 200, LIGHTGRAY);
	delay(200);

	char outputArray[] = "Empty Output Array with [n] elements: ";
	outtextxy(50, 275, outputArray);
	drawArray(Output, n, 100, 350, LIGHTGRAY);
	delay(100);
	
	char plus[] = "+";
	char deleteOneChar[] = "  ";
	
	char countArr[] = "Count Array:                                      ";
	outtextxy(50, 125, countArr);
	for (int i = n - 1; i >= 1; i--) {
		for (int j = i - 1; j >= 0; j--) {
			comparison(350, 115, i, j, LIGHTGRAY, YELLOW);
			if (R[i].key < R[j].key) {
				glowBox(100 + 50 * i + 50, 75, R[i].key);
				delay(100);
				glowBox(100 + 50 * j + 50, 75, R[j].key);
				delay(100);
				comparison(350, 115, i, j, LIGHTGREEN, LIGHTGREEN);
				delay(100);
				glowBox(100 + 50 * j + 50, 200, Count[j].key);
				setcolor(LIGHTGREEN);
				outtextxy(100 + 50 * j + 50, 225, plus);
				delay(100);
				Count[j].key++;
				drawBox(100 + 50 * j + 50, 200, Count[j].key, LIGHTGREEN);
				delay(100);
				outtextxy(100 + 50 * j + 50, 225, deleteOneChar);
			}
			else {	
				glowBox(100 + 50 * i + 50, 75, R[i].key);
				delay(100);
				glowBox(100 + 50 * j + 50, 75, R[j].key);
				delay(100);
				comparison(350, 115, i, j, LIGHTRED, LIGHTRED);
				delay(100);
				glowBox(100 + 50 * i + 50, 200, Count[i].key);
				setcolor(LIGHTRED);
				outtextxy(100 + 50 * i + 50, 225, plus);
				delay(100);
				Count[i].key++;
				drawBox(100 + 50 * i + 50, 200, Count[i].key, LIGHTRED);
				delay(100);
				outtextxy(100 + 50 * i + 50, 225, deleteOneChar);
			}
		}
	}
	//Set everything back to normal
	drawArray(R, n, 100, 75, LIGHTGRAY);
	drawArray(Count, n, 100, 200, LIGHTGRAY);
	char noirSpace[] = "                                                                                                                                                                                         ";
	outtextxy(100, 115, noirSpace);

	char outputFinal[] = "Output Array:                                                              ";
	outtextxy(50, 275, outputFinal);
	delay(1000);
	//Form the Output array
	for (int i = 0; i < n; i++) {
		Output[Count[i].key].key = R[i].key;
		glowBox(100 + 50 * i + 50, 200, Count[i].key);
		delay(100);
		glowBox(100 + 50 * Count[i].key + 50, 350, 0);
		delay(100);
		glowBox(100 + 50 * i + 50, 75, R[i].key);
		delay(100);
		drawMulticolorBox(100 + 50 * Count[i].key + 50, 350, Output[Count[i].key].key, LIGHTGRAY, YELLOW);
		delay(100);
		//Export the array in Console
		exportArray(Output, n);
	}
	//Finish Stage
	drawArray(Output, n, 100, 350, YELLOW);
	int j = 1;
	char fin[] = "FINISH.";
	while (1) {
		setcolor(j);
		outtextxy(100 + n * 50 / 2, 450, fin);
		delay(10);
		j++;
	}
	system("pause");
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	importArray(R, n);
	initwindow(1200, 600);
	countingSortVisualize(R, n);
	closegraph();
	return 0;
}