#include "OneHundred.h"
#include "Rocket.h"
#include <vector>
#include <time.h>
#include "Bullet.h"
#include "Util.h"
#include "SmartUfo.h"

#pragma comment(lib, "winmm.lib")


// 全局图片资源
IMAGE bkimg, rocketimg, blowup, bullet, ufoImg;

// 背景图大小
const int width = 560;
const int height = 800;

Rocket rocket;
// 子弹
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

	changeTitle(_T("100秒"));
	rocket.setRocketImg(rocketimg).setExplode(blowup).setX(width / 2 - rocket.getRadious()).setY(height / 2);
	
	// 打开背景音乐
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
	// 显示游戏提示
	if (!rocket.checkAlive() && rocket.getLife() >= 0)
	{
		showMsg(200, 400, RED, 40, _T("鼠标右击继续"));
	}
	if (!rocket.checkAlive() && rocket.getLife() < 0)
	{
		showMsg(200, 400, RED, 40, _T("游戏结束."));
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
	// 更新生存时间
	rocket.setLiveSecond(newSecond);
	// 每两秒增加一个子弹
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
		// 检查是否碰撞
		if ((*iterator).checkCollision(rocket))
		{
			playMusicOnce(_T("explode.mp3"));
			rocket.die();
			// 把当前子弹移动到其他地方, 避免重复碰撞
			(*iterator).update(5, 5);
		}
		else 
		{
			(*iterator).update();
		}
	}
	for (int i = 0; i < ufos.size(); i++)
	{
		// 检查是否碰撞
		if (ufos[i].checkCollision(rocket))
		{
			playMusicOnce(_T("explode.mp3"));
			rocket.die();
			// 把当前子弹移动到其他地方, 避免重复碰撞
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

		// 鼠标右键,游戏继续
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


