#include <graphics.h>
#include <conio.h>
#include <cstdio>
#include <cmath>
#include "Needle.h"
#include <vector>
#include <iostream>

#define PI 3.1415926
#define LINELENGTH  120
#define ONE_ANGLE  PI/360
#define COLLISION  PI/80	// 两线夹角小于此角度,则认为是 碰撞了

const int width = 600;
const int height = 600;
// 总的线的数量
int linenum = 0;
// 每条线的 旋转角度
std::vector<float> angles;
// 总的得分
int scores = 0;
 //转动速度
float speed = ONE_ANGLE * 3;

bool isCollision = false;

void init()
{
	initgraph(width, height);
	BeginBatchDraw();
	setlinestyle(PS_SOLID, 3);
	changeTitle();
}

void sleep(int ms)
{
	static DWORD oldtime = GetTickCount();
	while ((GetTickCount() - oldtime) < ms)
	{
		Sleep(1);
	}
	oldtime = GetTickCount();
}

void show()
{
	setbkcolor(WHITE);
	cleardevice();
	//showTitle();
	// 显示所有线条
	//std::vector<float>::const_iterator iterator; // 迭代器遍历
	if (checkCollision())
	{
		isCollision = true;
		speed = 0;
		showFailed();
	}
	showCircle();
	showLine();
	showScore();
	sleep(10);
	FlushBatchDraw();
}

float convertIntToFloat(int a)
{
	float b = a;

	while (b >= 1.0)
	{
		b /= 10;
	}
	return b;
}

void debug(int x, int y, float val)
{
	settextcolor(RGB(1, 10, 167));
	settextstyle(20, 0, _T("Consolas"));
	TCHAR tmp[20] = { 0 };
	_stprintf_s(tmp, _T("debug: %f"), val);
	outtextxy(x, y, tmp);
}

void showCircle()
{
	setlinecolor(HSVtoRGB(0, 0.9, 0.8));
	// 填充颜色. 线条个数越多,颜色越亮
	setfillcolor(HSVtoRGB(0, linenum/80.0, 0.8));
	fillcircle(width / 2, height / 2, 60);
}

void showLine() 
{
	setlinecolor(BLACK);
	line(0, height / 2, LINELENGTH, height / 2);
	for (int i = 0; i < angles.size(); i++)
	{
		// 移动角度
		angles[i] += speed;
		if (angles[i] > 2 * PI)
		{
			angles[i] -= 2 * PI;
		}
		if (i == (angles.size() - 1))
		{
			setlinecolor(BLACK);
			line(width / 2, height / 2, width / 2 + LINELENGTH * cos(angles[i]), height / 2 + LINELENGTH * sin(angles[i]));
			break;
		}
		setlinecolor(BLUE);
		line(width / 2, height / 2, width / 2 + LINELENGTH * cos(angles[i]), height / 2 + LINELENGTH * sin(angles[i]));
	}
}

//  发生碰撞返回1,否则返回0
int checkCollision()
{
	if (angles.size() < 2) return 0;
	float lastLine = angles[angles.size() - 1];
	for (int i = 0; i < angles.size()-1; i++)
	{
		if (abs(lastLine - angles[i]) <= COLLISION)
		{
			return 1;
		}
	}
	return 0;
}

void showTitle()
{
	settextcolor(RGB(1, 10, 167));
	settextstyle(30, 0, _T("Consolas"));
	outtextxy(260, 20, _T("见缝插针"));
}

void showScore()
{
	settextcolor(RGB(1, 10, 167));
	settextstyle(20, 0, _T("Consolas"));
	TCHAR tmp[20] = { 0 };
	_stprintf_s(tmp, _T("score: %d"), scores);
	outtextxy(450, 20, tmp);
}

void showFailed()
{
	settextcolor(RGB(255, 0, 0));
	settextstyle(40, 0, _T("Consolas"),0,0, 30, false, false, false);
	outtextxy(260, 200, _T("游戏结束"));
	close();
}

void update()
{
	if (_kbhit() && !isCollision)
	{
		int ch = _getch();
		// 输入的是空格
		if (ch == ' ')
		{
			// 添加一个线条到圆中
			linenum++;
			angles.push_back(PI);
			scores++;
		}
	}
}

void close()
{
	int ch = _getch();
	if (ch == 'a') 
	{
		closegraph();
	}
}

void changeTitle()
{
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, _T("见缝插针"));
}