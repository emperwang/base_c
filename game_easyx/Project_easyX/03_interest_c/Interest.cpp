#include "interest.h"
#include <iostream>

void fallBall()
{
	int height = 600;
	int width = 600;
	initgraph(width, height);

	// С���ֱ���Լ�λ��
	int ballX = 300;
	int ballY = 200;
	int ballR = 20;
	// С���ʼ���ٶ�
	double step = 0;
	//ģ����ٶ�
	double g = 1.5;
	while (1)
	{
		step += g;
		ballY += step;
		std::cout << "y = " << ballY << std::endl;
		cleardevice();
		// ��ֹС�򴩹� ����
		if (ballY >= (height - ballR))
		{
			ballY = (height - ballR);
			// ������ٶ�
			step *= -0.9;
		}
		fillcircle(ballX, ballY, ballR);
		Sleep(10);
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
	// ��ͣ
	bool pause = false;
	// �Ƿ���ײ
	bool collision = false;
	ExMessage msg;
	LPCTSTR str = "��Ϸ��ͣ";
	int fontWidth = textwidth(str);
	// �Ƿ�ӷ�
	bool isPlused = false;
	while (1)
	{
		if (peekmessage(&msg, EM_MOUSE | EM_KEY,false))
		{
			// ��ȡ��Ϣ
			msg = getmessage(EM_MOUSE | EM_KEY);
			switch (msg.message)
			{
				// �Ҽ�����, ��ͣ��Ϸ
			case WM_RBUTTONDOWN:
				settextstyle(40, 0, _T("����"));
				settextcolor(BLUE);
				outtextxy((width - fontWidth) / 2,height/2, str);
				FlushBatchDraw();
				pause = true;
				break;
				// �������, ��Ϸ����
			case WM_LBUTTONDOWN:
				clearrectangle((width - fontWidth) / 2, height / 2-40, (width - fontWidth) / 2+fontWidth, height / 2 + 40);
				FlushBatchDraw();
				pause = false;
				break;
			case WM_KEYDOWN:
				// �ո�: 32
				int ch = _getch();
				//printf("%d--%c\n", ch, ch);
				// ���������ǿո�, ��ô�͸�С��һ�����ϵ��ٶ�
				if (ch == 32)
				{
					vy = -16;
				}
				break;
			}
	
		}
		if (pause)
		{
			continue;
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
			isPlused = false;
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
			scores = 0;
			displayScore(scores);
			Sleep(100);
			collision = true;
			isPlused = true;
			//outtextxy(300, 300, "Failed...");
		}
		if (!collision && rectX <= ballX && !isPlused)
		{
			isPlused = true;
			scores++;
		}
		displayScore(scores);
		collision = false;
		FlushBatchDraw();
		Sleep(10);
	}
	_getch();
	closegraph();
}

void displayScore(int scores)
{
	TCHAR s[20];
	sprintf_s(s, "%d", scores);
	settextstyle(40, 0, _T("����"));
	outtextxy(30, 30, s);
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



