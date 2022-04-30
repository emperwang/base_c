#include "Player.h"
#include "Util.h"
#include <cstdio>

extern const int WIDTH;
extern const int HEIGHT;

void Player::show()
{
	updateYCoordinate();
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
		_stprintf_s(filename, _T("./assets/picture/runright%d.png"), i);
		loadimage(&img, filename);
		runRight.push_back(img);
	}

	this->imShow = this->standRight;
	this->width = imShow.getwidth();
	this->height = imShow.getheight();
	update(WIDTH / 2 - this->width / 2, HEIGHT / 2 - this->height);

	// 初始化移动速度
	vx = 5;
	vy = 5;
	gravity = 2;
}

void Player::update(int leftx, int buttony)
{
	this->leftX = leftx;
	this->buttomY = buttony;
}

void Player::standStill()
{
	if (this->playStatus == STANDLEFT)
	{
		imShow = standLeft;
	}
	else if (playStatus == STANDRIGHT)
	{
		imShow = standRight;
	}
}

void Player::setStatus(PlayStatus status)
{
	this->playStatus = status;
}

void Player::updateJumpStatus()
{
	if (this->playStatus != JUMPLEFT && this->playStatus != JUMPRIGHT)
	{
		if (this->playStatus == RUNLEFT || this->playStatus == STANDLEFT)
		{
			this->playStatus = JUMPLEFT;
			imShow = jumpLeft;
		}
		else if (this->playStatus == RUNRIGHT || this->playStatus == STANDRIGHT)
		{
			this->playStatus = JUMPRIGHT;
			imShow = jumpRight;
		}
		vy = -30;
	}
}

void Player::runRightStatus()
{
	leftX += vx;
	//奔跑相关处理
	if (playStatus == JUMPLEFT || playStatus == JUMPRIGHT)
	{
		imShow = jumpRight;
		return;
	}

	if (playStatus != RUNRIGHT)
	{
		playStatus = RUNRIGHT;
		runIdx = 0;
	}
	else
	{
		runIdx++;
		if (runIdx >= runRight.size())
		{
			runIdx = 0;
		}
	}
	imShow = runRight[runIdx];
}

void Player::runLeftStatus()
{
	leftX -= vx;

	//奔跑相关处理
	if (playStatus == JUMPLEFT || playStatus == JUMPRIGHT)
	{
		imShow = jumpLeft;
		return;
	}

	if (playStatus != RUNLEFT)
	{
		playStatus = RUNLEFT;
		runIdx = 0;
	}
	else
	{
		runIdx++;
		if (runIdx >= runLeft.size())
		{
			runIdx = 0;
		}
	}
	imShow = runLeft[runIdx];
}

void Player::updateYCoordinate()
{
	if (playStatus == JUMPLEFT || playStatus == JUMPRIGHT)
	{
		vy += gravity;
		buttomY += vy;
		if (buttomY > (HEIGHT / 2 - this->height))
		{
			buttomY = HEIGHT / 2 - this->height;
			if (playStatus == JUMPRIGHT)
			{
				playStatus = STANDRIGHT;
			}
			else if (playStatus == JUMPLEFT)
			{
				playStatus = STANDLEFT;
			}
		}
	}
}

int Player::getLeftX()
{
	return this->leftX;
}

void Player::setLeftX(int left)
{
	this->leftX = left;
}

int Player::getButtonY()
{
	return this->buttomY;
}

void Player::setButtonY(int button)
{
	this->buttomY = button;
}

int Player::getVx()
{
	return this->vx;
}

void Player::setVx(int speedX)
{
	this->vx = speedX;
}

int Player::getVy()
{
	return this->vy;
}

void Player::setVy(int speedy)
{
	this->vy = speedy;
}
