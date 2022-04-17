#include "snake.h"
#include <time.h>
#include <iostream>
#define WIDTH 40
#define HEIGHT 40
#define BLACKSIZE 20

int Blocks[HEIGHT][WIDTH] = { 0 };
DIRECTION moveDirection = RIGHT;
int isFailer = 0;
int food_i, food_j;
//游戏暂停
bool gamePaused = false;
bool gameWin = false;
// 得分
int scores = 0;
// snake移动速度
int speed = 1;

// 当前关数
int level = 1;
// 目标得分
int goalScore = 1;

// 蛇移动
void moveSnake()
{
	if (gamePaused || gameWin)
	{
		return;
	}
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
	case UP:
		newHead_i = oldHead_i - 1;
		break;
	case DOWN:
		newHead_i = oldHead_i + 1;
		break;
	case LEFT:
		newHead_j = oldHeal_j-1;
		break;
	case RIGHT:
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
		scores++;
		checkSuccess();
	}
	else
	{
		// 吃到食物,则不去除尾巴
		Blocks[oldTail_i][oldTail_j] = 0;
	}
}

void checkSuccess()
{
	if (scores >= goalScore)
	{
		scores = 0;
		goalScore *= 2;
		level += 1;
		speed += 1;
		gameWin = true;
		showMessage(240, 200, "恭喜通关");
		FlushBatchDraw();
		ExMessage msg = getmessage(EM_KEY);
		reset();
	}
}

// 游戏通过后,状态复位
void reset()
{
	gameWin = false;
	memset(Blocks, 0, sizeof(Blocks));
	srand((unsigned int)time(NULL));
	//Blocks[WIDTH / 2][HEIGHT / 2] = 1;
	for (int i = 0; i < 5; i++)
	{
		Blocks[HEIGHT / 2][WIDTH / 2 - i] = i + 1;
	}
	moveDirection = RIGHT;
	food_i = rand() % (HEIGHT - 5) + 2;
	food_j = rand() % (WIDTH - 5) + 2;
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
	moveDirection = RIGHT;
	food_i = rand() % (HEIGHT - 5) + 2;
	food_j = rand() % (WIDTH - 5) + 2;
	initgraph(WIDTH*BLACKSIZE, HEIGHT*BLACKSIZE); // EW_SHOWCONSOLE
	setlinecolor(RGB(200, 200, 200));
	changeTitle("Snake");
	BeginBatchDraw();
}

void changeTitle(const char* title)
{
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, title);
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
		showMessage(240, 200, "游戏失败");
	}

	if (gamePaused) 
	{
		showMessage(240, 200, "游戏暂停");
	}

	if (gameWin)
	{
		showMessage(240, 200, "恭喜通关");
	}
	char score[20];
	sprintf_s(score, "%s%d", "得分:",scores);
	showScore(10,10,score);
	
	memset(score, 0, sizeof(score));
	sprintf_s(score, "%s%d", "目标:", goalScore);
	showScore(WIDTH*BLACKSIZE -120, 10, score);
	
	memset(score, 0, sizeof(score));
	sprintf_s(score, "%s%d", "关卡:", level);
	showScore((WIDTH*BLACKSIZE)/2 - 120, 10, score);

	FlushBatchDraw();
}

void showScore(int x, int y, const char* score)
{
	setbkmode(TRANSPARENT);
	settextcolor(RGB(0, 0, 255));
	settextstyle(30, 0, _T("宋体"));
	outtextxy(x, y, _T(score));
}

void showMessage(int x, int y, const char* msg)
{
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 0, 0));
	settextstyle(80, 0, _T("Consolas"));
	outtextxy(x, y, _T(msg));
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
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE | EM_KEY, false) && !isFailer)
	{
		//char input = _getch();
		msg = getmessage(EM_MOUSE | EM_KEY);
		switch (msg.message)
		{
			// 游戏暂停
		case WM_RBUTTONDOWN:
			gamePaused = true;
			break;
			// 游戏继续
		case WM_LBUTTONDOWN:
			//reset();
			gamePaused = false;
			break;
		case WM_KEYUP: 
			BYTE scanCode = msg.scancode;
			updateDirection(scanCode);
			moveSnake();
			Sleep(100);
			break;
		}
	}
}


void updateDirection(int input)
{
	switch (input)
	{
		// 72 up 向上箭头, 80 down, 75 left, 77 right
	case  72:
	case 'w':
	case 'W':
		moveDirection = UP;
		break;
	case  80:
	case 's':
	case 'S':
		moveDirection = DOWN;
		break;
	case  75:
	case 'a':
	case 'A':
		moveDirection = LEFT;
		break;
	case  77:
	case 'd':
	case 'D':
		moveDirection = RIGHT;
		break;
	}
}
