
#include "easyxdemo.h"

#define MAXSTAR 200

struct STAR
{
	double x;
	int y;
	double step;
	int color;
};

STAR stars[MAXSTAR];

// Initialize the stars
void InitStar(int index)
{
	stars[index].x = 0;
	stars[index].y = rand() % 480;
	stars[index].step = (rand() % 5000) / 1000 + 1;
	stars[index].color = (int)(stars[index].step * 255 / 6 + 0.5);
	stars[index].color = RGB(stars[index].color, stars[index].color, stars[index].color);
}

// moving stars
void MoveStar(int index)
{
	// wipe the original star
	putpixel((int)stars[index].x, stars[index].y, 0);

	// calculate new location
	stars[index].x += stars[index].step;
	if (stars[index].x > 640) InitStar(index);

	// draw the new star
	putpixel((int)stars[index].x, stars[index].y, stars[index].color);
}

void PrintStars()
{
	srand((unsigned)time(NULL));
	initgraph(640, 480);
	changetitle();
	// initialize all stars
	for (int i = 0; i < MAXSTAR; i++)
	{
		InitStar(i);
		stars[i].x = rand() % 640;
	}

	while (!_kbhit())
	{
		for (int i = 0; i < MAXSTAR; i++)
		{
			MoveStar(i);
		}
		Sleep(20);
	}

	_getch();
	closegraph();
}

void matrix()
{
	srand((unsigned)time(NULL));
	initgraph(640, 800);

	int x, y;
	char c;

	settextstyle(16, 8, _T("Courier"));
	settextcolor(GREEN);
	setlinecolor(BLACK);

	for (int i = 0; i <= 479; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			x = (rand() % 80) * 8;
			y = (rand() % 20) * 24;
			c = (rand() % 26) + 65;
			outtextxy(x, y, c);
		}
		line(0, i, 639, i);
		Sleep(10);
		if (i >= 479) i = -1;
		if (_kbhit()) break;
	}
	_getch();
}

void firstCircle()
{
	initgraph(600, 800);

	// display ball
	fillcircle(300, 300, 100);

	_getch();
	closegraph();
}

// example 4
void MouseOperation()
{
	initgraph(640, 480);

	ExMessage m;

	while (true)
	{
		m = getmessage(EM_MOUSE | EM_KEY);

		switch (m.message)
		{
		case WM_MOUSEMOVE:
			// draw a red pixel then mouse move
			putpixel(m.x, m.y, RED);
			break;
		case WM_LBUTTONDOWN:
			// if the left button is clicked while pressing the ctrl key
			if (m.ctrl)
				rectangle(m.x - 10, m.y - 10, m.x + 10, m.y + 10);
			else
				rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
			break;

		case WM_KEYDOWN:
			// press ESC key to exit
			if (m.vkcode == VK_ESCAPE)
				return;
		}
	}

	closegraph();
}


// example 5
void RainBow()
{
	initgraph(640, 480);

	// draw a gradual sky
	float H = 190;
	float S = 1;
	float L = 0.7f;

	for (int y = 0; y < 480; y++)
	{
		L += 0.0005f;
		setlinecolor(HSLtoRGB(H, S, L));
		line(0, y, 639, y);
	}

	H = 0;
	S = 1;
	L = 0.05f;

	setlinestyle(PS_SOLID, 2);
	for (int r = 400; r > 344; r--)
	{
		H += 5;
		setlinestyle(HSLtoRGB(H, S, L));
		circle(500, 480, r);
	}

	_getch();
	closegraph();
}

//修改窗口标题
void changetitle()
{
	HWND hnd = GetHWnd();
	SetWindowText(hnd, "GamePlus");
}

/*void playMp3()
{
	mciSendString("open ./ThatGirl.mp3 alias BGM", 0, 0, 0);
	//mciSendString("play ./ThatGirl.mp3", 0, 0, 0);
	mciSendString("play BGM repeat", 0, 0, 0);
	mciSendString("close BGM",0,0,0);
}*/



void changeCmdMode()
{
	system("mode con lines=20 cols=50");
	_getch();
}