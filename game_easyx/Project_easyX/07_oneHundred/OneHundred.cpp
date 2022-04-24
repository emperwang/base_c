#include "OneHundred.h"
#include "Rocket.h"
#include <vector>
#include <time.h>
#include "Bullet.h"
#include "Util.h"

#pragma comment(lib, "winmm.lib")


// ȫ��ͼƬ��Դ
IMAGE bkimg, rocketimg, blowup, bullet, ufo;

// ����ͼ��С
const int width = 560;
const int height = 800;

Rocket rocket;
// �ӵ�
std::vector<Bullet> bullets;

void playMusicOnce(const TCHAR* filename)
{
	TCHAR cmdbuf[100];
	sprintf_s(cmdbuf, "open %s alias tmpmusic", filename);
	mciSendString(_T("close tmpmusic"), nullptr, 0, nullptr);
	mciSendString(cmdbuf, nullptr, 0, nullptr);
	mciSendString(_T("play tmpmusic"), nullptr, 0, nullptr);
}

void init()
{
	srand(time(nullptr));
	initgraph(width, height);
	loadimage(&bkimg, _T("background.png"));
	loadimage(&rocketimg, _T("rocket.png"));
	loadimage(&blowup, _T("blowup.png"));
	loadimage(&bullet, _T("bullet.png"));
	loadimage(&ufo, _T("ufo.png"));
	changeTitle(_T("100��"));
	rocket.setRocketImg(rocketimg).setExplode(blowup).setX(width / 2 - rocket.getRadious()).setY(height / 2);
	
	// �򿪱�������
	mciSendString(_T("open game_music.mp3 alias bk"), nullptr, 0, nullptr);
	mciSendString(_T("play bk repeat"),nullptr, 0, nullptr);
	BeginBatchDraw();
}

void display()
{
	cleardevice();
	putimage(0, 0, &bkimg);
	rocket.show();
	// ��ʾ��Ϸ��ʾ
	if (!rocket.checkAlive() && rocket.getLife() >= 0)
	{
		showMsg(200, 400, RED, 40, _T("����һ�����"));
	}
	if (!rocket.checkAlive() && rocket.getLife() < 0)
	{
		showMsg(200, 400, RED, 40, _T("��Ϸ����."));
	}
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].show();
	}
	FlushBatchDraw();
	sleep(10);
}

void updateWithoutInput()
{
	if (!rocket.checkAlive())
	{
		return;
	}
	static int lastOldTime = 0;
	static int newSecond = 0;
	static clock_t start = clock();
	clock_t now = clock();
	newSecond = (now - start) / CLOCKS_PER_SEC;
	// ��������ʱ��
	rocket.setLiveSecond(newSecond);
	// ÿ��������һ���ӵ�
	if ((newSecond - lastOldTime) >= 2)
	{
		lastOldTime = newSecond;
		Bullet but(bullet);
		bullets.push_back(but);
	}
	std::vector<Bullet>::iterator iterator = bullets.begin();
	for (; iterator != bullets.end(); iterator++)
	{
		// ����Ƿ���ײ
		if ((*iterator).checkCollision(rocket))
		{
			playMusicOnce(_T("explode.mp3"));
			rocket.die();
			// �ѵ�ǰ�ӵ��ƶ��������ط�, �����ظ���ײ
			(*iterator).update(5, 5);
		}
		else 
		{
			(*iterator).update();
		}
	}

}

void updateWithInput()
{
	ExMessage msg;
	while (peekmessage(&msg, EM_MOUSE, false))
	{
		msg = getmessage(EM_MOUSE);

		// ����Ҽ�,��Ϸ����
		switch (msg.message)
		{
		case WM_MOUSEMOVE:
			rocket.updatePostion(msg.x, msg.y);
			break;

		case WM_RBUTTONDOWN:
			rocket.updateWhenLostLife();
			rocket.resetAlive();
			break;
		}
	}
}

void changeTitle(const TCHAR* title)
{
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, title);
}


void showMsg(int x, int y, COLORREF color,int fontHight, const TCHAR* msg)
{
	if (msg != nullptr)
	{
		setbkmode(TRANSPARENT);
		settextcolor(color);
		settextstyle(fontHight, 0, _T("����"));
		outtextxy(x, y, msg);
	}
}

