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
//��Ϸ��ͣ
bool gamePaused = false;
bool gameWin = false;
// �÷�
int scores = 0;
// snake�ƶ��ٶ�
int speed = 1;

// ��ǰ����
int level = 1;
// Ŀ��÷�
int goalScore = 1;

// ���ƶ�
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
	// �ҳ����λ��,���λ�þ�����β
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
	// �趨����ͷ��λ��
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
		// Ĭ�����ƶ�
		newHead_j = oldHeal_j + 1;
		break;
	}

	// ��ͷ���� ���� ��ͷ��������,��ʧ��
	if (newHead_i >= HEIGHT || newHead_i < 0 || newHead_j >= WIDTH || newHead_j < 0 ||
		Blocks[newHead_i][newHead_j] >0) 
	{
		isFailer = 1;
		return;
	}

	Blocks[newHead_i][newHead_j] = 1;
	// �Ƿ�Ե�ʳ��
	if (newHead_i == food_i && newHead_j == food_j)
	{
		// �����µ�ʳ��
		food_i = rand() % (HEIGHT - 5) + 2;
		food_j = rand() % (WIDTH - 5) + 2;
		scores++;
		checkSuccess();
	}
	else
	{
		// �Ե�ʳ��,��ȥ��β��
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
		showMessage(240, 200, "��ϲͨ��");
		FlushBatchDraw();
		ExMessage msg = getmessage(EM_KEY);
		reset();
	}
}

// ��Ϸͨ����,״̬��λ
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

// 1. ��ʼ�� ��λ��
// 2. ��ʼ�� graphics
// 3. ��ʼ�� ʳ�� λ��
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
				// ����任��ɫ
				setfillcolor(HSVtoRGB(Blocks[i][j] * 10, 0.9, 1));
			}
			else
			{
				setfillcolor(RGB(150, 150, 150));
			}
			fillrectangle(j*BLACKSIZE, i*BLACKSIZE,(j+1)*BLACKSIZE, (i + 1)*BLACKSIZE);
		}
	}

	// ����ʳ���λ��
	setfillcolor(RGB(0,255,0));
	fillrectangle(food_j*BLACKSIZE, food_i*BLACKSIZE, (food_j + 1)*BLACKSIZE, (food_i + 1)*BLACKSIZE);

	// ʧ�����
	if (isFailer)
	{
		showMessage(240, 200, "��Ϸʧ��");
	}

	if (gamePaused) 
	{
		showMessage(240, 200, "��Ϸ��ͣ");
	}

	if (gameWin)
	{
		showMessage(240, 200, "��ϲͨ��");
	}
	char score[20];
	sprintf_s(score, "%s%d", "�÷�:",scores);
	showScore(10,10,score);
	
	memset(score, 0, sizeof(score));
	sprintf_s(score, "%s%d", "Ŀ��:", goalScore);
	showScore(WIDTH*BLACKSIZE -120, 10, score);
	
	memset(score, 0, sizeof(score));
	sprintf_s(score, "%s%d", "�ؿ�:", level);
	showScore((WIDTH*BLACKSIZE)/2 - 120, 10, score);

	FlushBatchDraw();
}

void showScore(int x, int y, const char* score)
{
	setbkmode(TRANSPARENT);
	settextcolor(RGB(0, 0, 255));
	settextstyle(30, 0, _T("����"));
	outtextxy(x, y, _T(score));
}

void showMessage(int x, int y, const char* msg)
{
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 0, 0));
	settextstyle(80, 0, _T("Consolas"));
	outtextxy(x, y, _T(msg));
}

// �û�û������ʱ�� ����
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

// �����û�����
void updateWithoutInput() 
{
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE | EM_KEY, false) && !isFailer)
	{
		//char input = _getch();
		msg = getmessage(EM_MOUSE | EM_KEY);
		switch (msg.message)
		{
			// ��Ϸ��ͣ
		case WM_RBUTTONDOWN:
			gamePaused = true;
			break;
			// ��Ϸ����
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
		// 72 up ���ϼ�ͷ, 80 down, 75 left, 77 right
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
