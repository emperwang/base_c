#include "MatchMan.h"
#include "Util.h"
#include "Player.h"
extern const int WIDTH = 800;
extern const int HEIGHT = 600;

IMAGE bk, land;
Player player;

void init()
{
	initgraph(WIDTH, HEIGHT);
	player.initialize();
	changeTitle(_T("»ð²ñÈË"));
	loadimage(&bk, _T("assets/picture/landscape1.png"));
	loadimage(&land, _T("assets/picture/land.png"));
	BeginBatchDraw();
}
void show()
{
	cleardevice();
	putimagePng(0, 0, &bk);
	putimagePng(WIDTH /2 - land.getwidth()/2, HEIGHT / 2, &land);
	player.show();
	FlushBatchDraw();
	sleep(10);
}

void changeTitle(const TCHAR* title)
{
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, title);
}