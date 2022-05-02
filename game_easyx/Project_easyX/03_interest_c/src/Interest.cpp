#include "interest.h"
#include <iostream>

void fallBall()
{
	int height = 600;
	int width = 600;
	initgraph(width, height);

	// 小球的直径以及位置
	int ballX = 300;
	int ballY = 200;
	int ballR = 20;
	// 小球初始加速度
	double step = 0;
	//模拟加速度
	double g = 1.5;
	while (1)
	{
		step += g;
		ballY += step;
		std::cout << "y = " << ballY << std::endl;
		cleardevice();
		// 防止小球穿过 地面
		if (ballY >= (height - ballR))
		{
			ballY = (height - ballR);
			// 反向加速度
			step *= -0.9;
		}
		fillcircle(ballX, ballY, ballR);
		Sleep(10);
	}
	closegraph();
}


void donotTouchBar()
{
	//  动画的高度 和 重力加速度
	int height = 600, width = 600;
	float gravity = 0.9;
	// 小球的位置 半径
	int ballR = 20;
	int ballX = width / 3;
	float ballY = (float)(height - ballR);
	float vy = 15;

	// 方块的宽 高 以及x方向移动速度
	int rectWidth = 20, rectHeight = 100;
	float rectVx = 3;
	// 方块的位置信息
	int rectX = width / 4 * 3, rectY = height - rectHeight;

	initgraph(width, height);
	int scores = 0;
	BeginBatchDraw();
	// 暂停
	bool pause = false;
	// 是否碰撞
	bool collision = false;
	ExMessage msg;
	LPCTSTR str = "游戏暂停";
	int fontWidth = textwidth(str);
	// 是否加分
	bool isPlused = false;
	while (1)
	{
		if (peekmessage(&msg, EM_MOUSE | EM_KEY,false))
		{
			// 获取消息
			msg = getmessage(EM_MOUSE | EM_KEY);
			switch (msg.message)
			{
				// 右键按下, 暂停游戏
			case WM_RBUTTONDOWN:
				settextstyle(40, 0, _T("宋体"));
				settextcolor(BLUE);
				outtextxy((width - fontWidth) / 2,height/2, str);
				FlushBatchDraw();
				pause = true;
				break;
				// 左键按下, 游戏继续
			case WM_LBUTTONDOWN:
				clearrectangle((width - fontWidth) / 2, height / 2-40, (width - fontWidth) / 2+fontWidth, height / 2 + 40);
				FlushBatchDraw();
				pause = false;
				break;
			case WM_KEYDOWN:
				// 空格: 32
				int ch = _getch();
				//printf("%d--%c\n", ch, ch);
				// 如果输入的是空格, 那么就给小球一个向上的速度
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
		// 小球的移动
		vy += gravity;
		ballY += vy;
		// 方块的移动
		rectX -= rectVx;

		// 使方块循环移动
		if (rectX <= -rectWidth)
		{
			rectX = width - rectWidth;
			isPlused = false;
		}

		// 防止小球跑出画面
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

		// 判断小球和方块有没有碰撞
		// 1.小球右边和方块左边 x左边相等或小于 & 小球的Y坐标<= 方块的Y坐标 
		// 2.小球左边 和 方块右边 x左边 相等或小于 & 小球 Y 坐标 <= 方块的Y坐标
		// 3.小球的下边 和 方框的上边 相逢
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
	settextstyle(40, 0, _T("宋体"));
	outtextxy(30, 30, s);
}


// 
void snakeRotate()
{
	float PI = 3.1415926;
	int width = 1200, height = 800;
	initgraph(width, height);
	int centerX = 300, centerY = 300, radius = 200;
	// 设置颜色
	setbkcolor(RGB(128,128,128)); // 背景色
	//setlinecolor(RED); // 线条颜色
	//setfillcolor(GREEN); // .设置填充颜色
	cleardevice();
	float offset = 0;
	float totaloffset = 0;
	for (centerX = 200; centerX < 1200; centerX = centerX + 400)
	{
		for (centerY = 200; centerY < 800; centerY = centerY + 400)
		{
			for (radius = 200; radius > 0; radius = radius - 50)
			{
				// 扇形
				int left = centerX - radius;
				int top = centerY - radius;
				int right = centerX + radius;
				int bottom = centerY + radius;
				for (int i = 0; i < 20; i++)
				{
					offset = i*PI / 10 + totaloffset;
					setfillcolor(RGB(0, 240, 220)); //青色
					solidpie(left, top, right, bottom, offset, 2 * PI / 60 + offset);

					setfillcolor(RGB(255, 255, 255));//		白色
					solidpie(left, top, right, bottom, 2 * PI / 60 + offset, 3 * PI / 60 + offset);
					// 外边圆
					//circle(centerX, centerY, radius);
					setfillcolor(RGB(200, 0, 0)); // 红色
					solidpie(left, top, right, bottom, 3 * PI / 60 + offset, 5 * PI / 60 + offset);

					setfillcolor(RGB(0, 0, 0)); // 黑色
					solidpie(left, top, right, bottom, 5 * PI / 60 + offset, 6 * PI / 60 + offset);
				}
				totaloffset = totaloffset + PI / 20;
			}
		}
	}
	_getch();
	closegraph();
}



