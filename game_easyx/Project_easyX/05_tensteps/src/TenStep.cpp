#include "TenStep.h"
#include <graphics.h>
#include <time.h>
#include <cmath>
#include <cstdio>

int WIDTH = 600;
int HEIGHT = 700;

Round rounds[5][5];

// �ܵĲ���
int step = 10;
//��õķ���
int scores = 0;

void Init()
{
	srand((unsigned)time(NULL));
	// ��ʼ��Բ��Ϣ
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
			// ��Բ
			setlinecolor(RGB(200,200,200));
			circle(rounds[i][j].getX(), rounds[i][j].getY(), rounds[i][j].getRadious());

			// ��ָ��
			setlinecolor(RED);
			line(rounds[i][j].getX(), rounds[i][j].getY(),
				 rounds[i][j].getX() + rounds[i][j].getRadious()*(-cos(rounds[i][j].getAngleNum() * PI / 2)),
				 rounds[i][j].getY() + rounds[i][j].getRadious()*(-sin(rounds[i][j].getAngleNum() * PI / 2)));
			
			// debug
			/*settextcolor(RGB(200, 200, 200));
			sprintf_s(buf, "i=%d,j=%d,angle=%d",i,j, rounds[i][j].getAngleNum());
			setbkmode(TRANSPARENT);
			settextstyle(10, 0, _T("����"));
			outtextxy(20, 15*idx, buf);*/
		}
	}

	memset(buf, 0, sizeof(buf));
	settextcolor(RGB(200, 200, 200));
	sprintf_s(buf, "%d �� %d ��", step, scores);
	setbkmode(TRANSPARENT);
	settextstyle(40, 0, _T("����"));
	outtextxy(200, 10, buf);

	memset(buf, 0, sizeof(buf));
	settextcolor(RGB(0, 0, 200));
	settextstyle(20, 0, _T("����"));
	sprintf_s(buf, "%s", _T("���һ��ԲȦ,��ָ��˳ʱ����ת90��֮��,ָ���ָ��������ת"));
	outtextxy(15, 70, buf);
	FlushBatchDraw();
}

// ��ȡ�������
void updateWithInput()
{
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE, false) && step>0)
	{
		msg = getmessage(EM_MOUSE);

		//��ȡ���λ��,�Դ˻�ȡ��Ӧ��Բ
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
			// ��ȡ��һ��Ҫ��ת��Բ
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

// �����ϴθ��º��Բ��ָ��,����ȡ��һ��Ҫ��ת��Բ
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

// ���¶�ӦԲ�� ָ��λ��
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