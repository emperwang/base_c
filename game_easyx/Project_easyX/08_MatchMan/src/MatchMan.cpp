#include "MatchMan.h"
#include "Util.h"
#include "Player.h"
#include <conio.h>
#include "Scene.h"

extern const int WIDTH = 800;
extern const int HEIGHT = 600;

//IMAGE bk, land;
Player player;
Scene scene;

void init()
{
	initgraph(WIDTH, HEIGHT);
	player.initialize();
	scene.initialize();
	changeTitle(_T("»ð²ñÈË"));
	//loadimage(&bk, _T("assets/picture/landscape1.png"));
	//loadimage(&land, _T("assets/picture/land.png"));
	BeginBatchDraw();
}
void show()
{
	cleardevice();
	//putimagePng(0, 0, &bk);
	//putimagePng(WIDTH /2 - land.getwidth()/2, HEIGHT / 2, &land);
	scene.show();
	player.show();
	FlushBatchDraw();
	sleep(10);
}

void updateWithInput()
{
	player.standStill();
	if (_kbhit())
	{
		if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
		{
			player.runLeftStatus(scene);
		}
		if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
		{
			player.runRightStatus(scene);
		}
		if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
		{
			player.updateJumpStatus();
		}
		if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
		{
			//player.setButtonY(player.getButtonY() + player.getVy());
		}
	}
}

void updateWithoutInput()
{
	player.updateYCoordinate();
}

void changeTitle(const TCHAR* title)
{
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, title);
}