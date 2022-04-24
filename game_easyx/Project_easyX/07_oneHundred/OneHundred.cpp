#include "OneHundred.h"
#include "Rocket.h"
#include <vector>
#include <time.h>
#include "Bullet.h"
#include "Util.h"
#include "SmartUfo.h"

#pragma comment(lib, "winmm.lib")


// ȫ��ͼƬ��Դ
IMAGE bkimg, rocketimg, blowup, bullet, ufoImg;

// ����ͼ��С
const int width = 560;
const int height = 800;

Rocket rocket;
// �ӵ�
std::vector<Bullet> bullets;
std::vector<SmartUfo> ufos;

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
	loadimage(&ufoImg, _T("ufo.png"));
	
	addUfo();

	changeTitle(_T("100��"));
	rocket.setRocketImg(rocketimg).setExplode(blowup).setX(width / 2 - rocket.getRadious()).setY(height / 2);
	
	// �򿪱�������
	mciSendString(_T("open game_music.mp3 alias bk"), nullptr, 0, nullptr);
	mciSendString(_T("play bk repeat"),nullptr, 0, nullptr);
	BeginBatchDraw();
}

void addUfo()
{
	SmartUfo ufo(ufoImg);
	ufos.push_back(ufo);
}

void addBullet()
{
	Bullet but(bullet);
	bullets.push_back(but);
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
	for (int i = 0; i < ufos.size(); i++)
	{
		ufos[i].show();
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
	static int lastOldTimeForBullet = 0;
	static int lastOldTimeForUfo = 0;
	static int newSecond = 0;
	static clock_t start = clock();
	clock_t now = clock();
	newSecond = (now - start) / CLOCKS_PER_SEC;
	// ��������ʱ��
	rocket.setLiveSecond(newSecond);
	// ÿ��������һ���ӵ�
	if ((newSecond - lastOldTimeForBullet) >= 2)
	{
		lastOldTimeForBullet = newSecond;
		addBullet();
	}
	if ((newSecond - lastOldTimeForUfo) >= 10)
	{
		lastOldTimeForUfo = newSecond;
		addUfo();
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
	for (int i = 0; i < ufos.size(); i++)
	{
		// ����Ƿ���ײ
		if (ufos[i].checkCollision(rocket))
		{
			playMusicOnce(_T("explode.mp3"));
			rocket.die();
			// �ѵ�ǰ�ӵ��ƶ��������ط�, �����ظ���ײ
			ufos[i].update(5, 5);
		}
		else
		{
			ufos[i].update();
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
			for (int i = 0; i < ufos.size(); i++)
			{
				ufos[i].updateSpeedForRocket(rocket);
			}
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


