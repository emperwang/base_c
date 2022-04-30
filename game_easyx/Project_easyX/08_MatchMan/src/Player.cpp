#include "Player.h"
#include "Util.h"
#include <cstdio>

extern const int WIDTH;
extern const int HEIGHT;

void Player::show()
{
	putimagePng(leftX, buttomY, &this->imShow);
}

void Player::initialize()
{
	loadimage(&this->standLeft, _T("./assets/picture/standleft.png"));
	loadimage(&this->standRight, _T("./assets/picture/standright.png"));
	loadimage(&this->jumpLeft, _T("./assets/picture/jumpleft.png"));
	loadimage(&this->jumpRight, _T("./assets/picture/jumpright.png"));
	TCHAR filename[80];
	for (int i = 0; i <= 7; i++)
	{
		IMAGE img;
		_stprintf_s(filename, _T("./assets/picture/runleft%d.png"), i);
		loadimage(&img, filename);
		runLeft.push_back(img);

		memset(filename, 0, sizeof(filename));
		_stprintf_s(filename, _T("runright%d.png"), i);
		loadimage(&img, filename);
		runRight.push_back(img);
	}

	this->imShow = this->standRight;
	this->width = imShow.getwidth();
	this->height = imShow.getheight();
	this->leftX = WIDTH / 2 - this->width / 2;
	this->buttomY = HEIGHT / 2 - this->height;

}