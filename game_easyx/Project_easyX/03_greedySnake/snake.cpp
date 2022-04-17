#include "snake.h"
#include <time.h>
#define WIDTH 40
#define HEIGHT 40
#define BLACKSIZE 20

int Blocks[HEIGHT][WIDTH] = { 0 };
int moveDirection = 0;
int isFailer = 0;
int food_i, food_j;


// 蛇移动
void moveSnake()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (Blocks[i][j] > 0)
			{
				Blocks[i][j]+=1;
			}
		}
	}
	int oldTail_i=0, oldTail_j=0, oldHead_i=0, oldHeal_j=0;
	int max = 0;
	// 找出最大位置,最大位置就是蛇尾
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (max < Blocks[i][j])
			{
				max = Blocks[i][j];
				oldTail_i = i;
				oldTail_j = j;
			}
			if (Blocks[i][j] == 2)
			{
				oldHead_i = i;
				oldHeal_j = j;
			}
		}
	}
	
	// up 72  down 80 left 75  right 77
	// 设定新蛇头的位置
	int newHead_i = oldHead_i;
	int newHead_j = oldHeal_j;
	switch (moveDirection)
	{
	case 72:
	case 'w':
	case 'W':
		newHead_i = oldHead_i - 1;
		break;
	case 80:
	case 's':
	case 'S':
		newHead_i = oldHead_i + 1;
		break;
	case 75:
	case 'a':
	case 'A':
		newHead_j = oldHeal_j-1;
		break;
	case 77:
	case 'd':
	case 'D':
		newHead_j = oldHeal_j + 1;
		break;
	default:
		// 默认右移动
		newHead_j = oldHeal_j + 1;
		break;
	}

	// 蛇头出界 或者 蛇头碰到蛇身,则失败
	if (newHead_i >= HEIGHT || newHead_i < 0 || newHead_j >= WIDTH || newHead_j < 0 ||
		Blocks[newHead_i][newHead_j] >0) 
	{
		isFailer = 1;
		return;
	}

	Blocks[newHead_i][newHead_j] = 1;
	// 是否吃到食物
	if (newHead_i == food_i && newHead_j == food_j)
	{
		// 增加新的食物
		food_i = rand() % (HEIGHT - 5) + 2;
		food_j = rand() % (WIDTH - 5) + 2;
	}
	else
	{
		// 吃到食物,则不去除尾巴
		Blocks[oldTail_i][oldTail_j] = 0;
	}
}
// 1. 初始化 蛇位置
// 2. 初始化 graphics
// 3. 初始化 食物 位置
void Init()
{
	srand((unsigned int)time(NULL));
	//Blocks[WIDTH / 2][HEIGHT / 2] = 1;
	for (int i = 0; i < 5; i++)
	{
		Blocks[HEIGHT / 2][WIDTH / 2 - i] = i + 1;
	}
	moveDirection = 77;
	food_i = rand() % (HEIGHT - 5) + 2;
	food_j = rand() % (WIDTH - 5) + 2;
	initgraph(WIDTH*BLACKSIZE, HEIGHT*BLACKSIZE); // EW_SHOWCONSOLE
	setlinecolor(RGB(200, 200, 200));
	BeginBatchDraw();
}

void Show()
{
	// clear screen
	cleardevice();
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (Blocks[i][j]>0)
			{
				// 随机变换颜色
				setfillcolor(HSVtoRGB(Blocks[i][j] * 10, 0.9, 1));
			}
			else
			{
				setfillcolor(RGB(150, 150, 150));
			}
			fillrectangle(j*BLACKSIZE, i*BLACKSIZE,(j+1)*BLACKSIZE, (i + 1)*BLACKSIZE);
		}
	}

	// 设置食物的位置
	setfillcolor(RGB(0,255,0));
	fillrectangle(food_j*BLACKSIZE, food_i*BLACKSIZE, (food_j + 1)*BLACKSIZE, (food_i + 1)*BLACKSIZE);

	// 失败输出
	if (isFailer)
	{
		setbkmode(TRANSPARENT);
		settextcolor(RGB(255, 0, 0));
		settextstyle(80, 0, _T("宋体"));
		outtextxy(240, 200, _T("游戏失败"));
	}

	FlushBatchDraw();
}

// 用户没有输入时的 处理
void updateWithInput()
{
	if (isFailer)return;
	static int waitIndex = 1;
	waitIndex++;
	if (waitIndex == 10)
	{
		moveSnake();
		waitIndex = 1;
	}
}

// 处理用户输入
void updateWithoutInput() 
{
	if (_kbhit())
	{
		char input = _getch();
		if (input == 72 || input == 80 || input == 75 || input == 77 ||
			input == 'a' || input == 'w' || input == 's'|| input == 'd' ||
			input == 'A' || input == 'W' || input == 'S' || input == 'D')
		{
			moveDirection = input;
			moveSnake();
			Sleep(100);
		}
	}
}

