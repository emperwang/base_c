#include "OneHundred.h"
#include "Rocket.h"
#include <vector>
#include <time.h>
#include "Bullet.h"
#include "Util.h"

#pragma comment(lib, "winmm.lib")


// 全局图片资源
IMAGE bkimg, rocketimg, blowup, bullet, ufo;

// 背景图大小
const int width = 560;
const int height = 800;

Rocket rocket;
// 子弹
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
	changeTitle(_T("100秒"));
	rocket.setRocketImg(rocketimg).setExplode(blowup).setX(width / 2 - rocket.getRadious()).setY(height / 2);
	
	// 打开背景音乐
	mciSendString(_T("open game_music.mp3 alias bk"), nullptr, 0, nullptr);
	mciSendString(_T("play bk repeat"),nullptr, 0, nullptr);
	BeginBatchDraw();
}

void display()
{
	cleardevice();
	putimage(0, 0, &bkimg);
	rocket.show();
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].show();
	}
	FlushBatchDraw();
	sleep(10);
}

void updateWithoutInput()
{
	static int lastOldTime = 0;
	static int newSecond = 0;
	static clock_t start = clock();
	clock_t now = clock();
	newSecond = (now - start) / CLOCKS_PER_SEC;
	// 更新生存时间
	rocket.setLiveSecond(newSecond);
	// 每两秒增加一个子弹
	if ((newSecond - lastOldTime) >= 2)
	{
		lastOldTime = newSecond;
		Bullet but(bullet);
		bullets.push_back(but);
	}
	std::vector<Bullet>::iterator iterator = bullets.begin();
	for (; iterator != bullets.end(); iterator++)
	{
		// 检查是否碰撞
		if ((*iterator).checkCollision(rocket))
		{
			rocket.updateWhenLostLife();
			playMusicOnce(_T("explode.mp3"));
			// 把当前子弹移动到其他地方, 避免重复碰撞
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

		// 鼠标右键,游戏继续
		switch (msg.message)
		{
		case WM_MOUSEMOVE:
			rocket.setX(msg.x);
			rocket.setY(msg.y);
			break;
		}
	}
}

void changeTitle(const TCHAR* title)
{
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, title);
}