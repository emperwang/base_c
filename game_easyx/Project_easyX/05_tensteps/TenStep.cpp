#include "TenStep.h"
#include <graphics.h>
#include <time.h>
#include <cmath>
#include <cstdio>

int WIDTH = 600;
int HEIGHT = 700;

Round rounds[5][5];

// 总的步数
int step = 10;
//获得的分数
int scores = 0;

void Init()
{
	srand((unsigned)time(NULL));
	// 初始化圆信息
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Round r;
			r.setR(30);
			r.setX(100 + i * 100);
			r.setY(200 + j * 100);
			r.setAngleNum(rand()%3);
			rounds[i][j] = r;
		}
	}
	initgraph(WIDTH, HEIGHT);
	cleardevice();
	changeTitle("TenStep");
	setbkcolor(BLACK);
	BeginBatchDraw();
}


void show()
{
	cleardevice();
	TCHAR buf[100] = { 0 };
	//int idx = 1;		// debug
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//idx++;
			// 画圆
			setlinecolor(RGB(200,200,200));
			circle(rounds[i][j].getX(), rounds[i][j].getY(), rounds[i][j].getRadious());

			// 画指针
			setlinecolor(RED);
			line(rounds[i][j].getX(), rounds[i][j].getY(),
				 rounds[i][j].getX() + rounds[i][j].getRadious()*(-cos(rounds[i][j].getAngleNum() * PI / 2)),
				 rounds[i][j].getY() + rounds[i][j].getRadious()*(-sin(rounds[i][j].getAngleNum() * PI / 2)));
			
			// debug
			/*settextcolor(RGB(200, 200, 200));
			sprintf_s(buf, "i=%d,j=%d,angle=%d",i,j, rounds[i][j].getAngleNum());
			setbkmode(TRANSPARENT);
			settextstyle(10, 0, _T("宋体"));
			outtextxy(20, 15*idx, buf);*/
		}
	}

	memset(buf, 0, sizeof(buf));
	settextcolor(RGB(200, 200, 200));
	sprintf_s(buf, "%d 步 %d 度", step, scores);
	setbkmode(TRANSPARENT);
	settextstyle(40, 0, _T("宋体"));
	outtextxy(200, 10, buf);

	memset(buf, 0, sizeof(buf));
	settextcolor(RGB(0, 0, 200));
	settextstyle(20, 0, _T("宋体"));
	sprintf_s(buf, "%s", _T("点击一个圆圈,其指针顺时针旋转90度之后,指向的指针依次旋转"));
	outtextxy(15, 70, buf);
	FlushBatchDraw();
}

// 获取鼠标输入
void updateWithInput()
{
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE, false) && step>0)
	{
		msg = getmessage(EM_MOUSE);

		//获取鼠标位置,以此获取对应的圆
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			step--;
			int x = (msg.x - 50) / 100;
			int y = (msg.y - 150) / 100;
			roundRotate(x, y);
			show();
			Sleep(50);
			FlushBatchDraw();
			int checkXY[] = { x, y };
			/*getNextRound(checkXY);
			roundRotate(checkXY[0], checkXY[1]);
			show();
			Sleep(50);
			FlushBatchDraw();*/
			// 获取下一个要旋转的圆
			while (getNextRound(checkXY))
			{
				roundRotate(checkXY[0], checkXY[1]);
				show();
				Sleep(50);
				FlushBatchDraw();
			}
			break;
		}

	}
}

// 根据上次更新后的圆的指针,来获取下一个要旋转的圆
int getNextRound(int arr[2])
{
	int x = arr[0];
	int y = arr[1];
	if (x >= 0 && x < 5 && y >= 0 && y < 5)
	{
		int angleNum = rounds[x][y].getAngleNum();
		switch (angleNum)
		{
		case 0:
			arr[0]--;
			break;

		case 1:
			arr[1]--;
			break;
		case 2:
			arr[0]++;
			break;

		case 3:
			arr[1]++;
			break;
		}

		if (arr[0] >= 0 && arr[0] < 5 && arr[1] >= 0 && arr[1] < 5)
		{
			return 1;
		}
	}
	return 0;
}

// 更新对应圆的 指针位置
void roundRotate(int x, int y)
{
	if (x >= 0 && x < 5 && y >= 0 && y < 5)
	{
		rounds[x][y].SetAngleNumPlusOne();
		scores += 90;
	}
}

void changeTitle(const char* title)
{
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, title);
}