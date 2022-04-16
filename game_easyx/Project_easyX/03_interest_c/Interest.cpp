#include "interest.h"

void fallBall()
{
	int height = 600;
	int width = 600;
	initgraph(width, height);

	// С���ֱ���Լ�λ��
	int ballX = 300;
	int ballY = 200;
	int ballR = 20;
	// ÿ������ľ���
	int step = 10;
	//ģ����ٶ�
	int g = 1.5;
	while (1)
	{
		step *= g;
		cleardevice();
		// ��ֹС�򴩹� ����
		if (ballY >= (height - ballR))
		{
			ballY = (height - ballR);
		}
		fillcircle(ballX, ballY, ballR);
		Sleep(1000);
		ballY += step;
	}
	closegraph();
}


void donotTouchBar()
{
	//  �����ĸ߶� �� �������ٶ�
	int height = 600, width = 600;
	float gravity = 0.9;
	// С���λ�� �뾶
	int ballR = 20;
	int ballX = width / 3;
	float ballY = (float)(height - ballR);
	float vy = 15;

	// ����Ŀ� �� �Լ�x�����ƶ��ٶ�
	int rectWidth = 20, rectHeight = 100;
	float rectVx = 3;
	// �����λ����Ϣ
	int rectX = width / 4 * 3, rectY = height - rectHeight;

	initgraph(width, height);
	int scores = 0;
	BeginBatchDraw();
	while (1)
	{
		if (_kbhit()) 
		{
			// �ո�: 32
			int ch = _getch();
			//printf("%d--%c\n", ch, ch);
			// ���������ǿո�, ��ô�͸�С��һ�����ϵ��ٶ�
			if (ch == 32)
			{
				vy = -16;
			}
		}
		// С����ƶ�
		vy += gravity;
		ballY += vy;
		// ������ƶ�
		rectX -= rectVx;

		// ʹ����ѭ���ƶ�
		if (rectX <= -rectWidth)
		{
			rectX = width - rectWidth;
		}

		// ��ֹС���ܳ�����
		if (ballY >= (height - ballR))
		{
			ballY = (height - ballR);
		}
		if (ballY <= ballR)
		{
			ballY = ballR;
		}
		// clear screen
		cleardevice();
		fillrectangle(rectX, rectY, rectX + rectWidth, height);
		fillcircle(ballX, ballY, ballR);

		// �ж�С��ͷ�����û����ײ
		// 1.С���ұߺͷ������ x�����Ȼ�С�� & С���Y����<= �����Y���� 
		// 2.С����� �� �����ұ� x��� ��Ȼ�С�� & С�� Y ���� <= �����Y����
		// 3.С����±� �� ������ϱ� ���
		if (((ballX+ballR)>= rectX) && 
			((rectX + rectWidth) >= (ballX - ballR)) && 
			(rectY <= (ballY+ballR)))
		{
			Sleep(100);
			scores = 0;
			//outtextxy(300, 300, "Failed...");
		}
		if (rectX <= 0)
		{
			scores++;
		}
		TCHAR s[20];
		sprintf_s(s, "%d", scores);
		settextstyle(40, 0, _T("����"));
		outtextxy(30, 30, s);
		FlushBatchDraw();
		Sleep(10);
	}
	_getch();
	closegraph();
}

// 
void snakeRotate()
{
	float PI = 3.1415926;
	int width = 1200, height = 800;
	initgraph(width, height);
	int centerX = 300, centerY = 300, radius = 200;
	// ������ɫ
	setbkcolor(RGB(128,128,128)); // ����ɫ
	//setlinecolor(RED); // ������ɫ
	//setfillcolor(GREEN); // .���������ɫ
	cleardevice();
	float offset = 0;
	float totaloffset = 0;
	for (centerX = 200; centerX < 1200; centerX = centerX + 400)
	{
		for (centerY = 200; centerY < 800; centerY = centerY + 400)
		{
			for (radius = 200; radius > 0; radius = radius - 50)
			{
				// ����
				int left = centerX - radius;
				int top = centerY - radius;
				int right = centerX + radius;
				int bottom = centerY + radius;
				for (int i = 0; i < 20; i++)
				{
					offset = i*PI / 10 + totaloffset;
					setfillcolor(RGB(0, 240, 220)); //��ɫ
					solidpie(left, top, right, bottom, offset, 2 * PI / 60 + offset);

					setfillcolor(RGB(255, 255, 255));//		��ɫ
					solidpie(left, top, right, bottom, 2 * PI / 60 + offset, 3 * PI / 60 + offset);
					// ���Բ
					//circle(centerX, centerY, radius);
					setfillcolor(RGB(200, 0, 0)); // ��ɫ
					solidpie(left, top, right, bottom, 3 * PI / 60 + offset, 5 * PI / 60 + offset);

					setfillcolor(RGB(0, 0, 0)); // ��ɫ
					solidpie(left, top, right, bottom, 5 * PI / 60 + offset, 6 * PI / 60 + offset);
				}
				totaloffset = totaloffset + PI / 20;
			}
		}
	}
	_getch();
	closegraph();
}



