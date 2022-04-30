#include "Player.h"
#include "Util.h"
#include <cstdio>
#include <iostream>

extern const int WIDTH;
extern const int HEIGHT;

// for debug
void Player::outputPostion()
{
	setbkmode(TRANSPARENT);
	settextcolor(RGB(10, 20, 120));
	settextstyle(20, 0, "宋体");
	TCHAR buf[20];
	_stprintf_s(buf, "X: %f", this->leftX);
	outtextxy(WIDTH - 100, 20, buf);
	memset(buf, 0, 20);
	_stprintf_s(buf, "Y: %f", this->buttomY);
	outtextxy(WIDTH - 100, 40, buf);
}

void Player::show()
{
	outputPostion();
	updateYCoordinate();
	putimagePng(leftX, buttomY - this->height, &this->imShow);
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
	update(WIDTH / 2, HEIGHT / 2 );

	// 初始化移动速度
	vx = 5;
	vy = 0;
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

void Player::runRightStatus(Scene& scene)
{
	leftX += vx;
	//奔跑相关处理
	/*if (playStatus == JUMPLEFT || playStatus == JUMPRIGHT)
	{
		imShow = jumpRight;
		return;
	}*/

	if (isNotOnAllLand(scene.getLands(), vy))
	{
		imShow = jumpRight;
		playStatus = RUNRIGHT;
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

void Player::runLeftStatus(Scene& scene)
{
	leftX -= vx;

	//奔跑相关处理
	/*if (playStatus == JUMPLEFT || playStatus == JUMPRIGHT)
	{
		imShow = jumpLeft;
		return;
	}*/

	if (isNotOnAllLand(scene.getLands(), vy))
	{
		imShow = jumpLeft;
		playStatus = RUNLEFT;
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

int Player::isOnLand(const Land& land, float speedy)
{
	float rightX = this->leftX + width;

	// y方向上小于0, 表示正在向上运动, 不需要考虑速度的影响
	if (speedy <= 0)
	{
		speedy = 0;
	}

	if ((land.getLeftX() - leftX) <= (width *0.6) && (rightX - land.getRightX()) <= (width * 0.6)
		&& abs(buttomY - land.getTopY()) <= (5 + speedy))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Player::isNotOnAllLand(const std::vector<Land>& lands, float speed)
{
	for (int i = 0; i < lands.size(); i++)
	{
		if (isOnLand(lands[i], speed))
			return 0;
	}
	return 1;
}

float Player::getLeftX()
{
	return this->leftX;
}

void Player::setLeftX(float left)
{
	this->leftX = left;
}

int Player::getButtonY()
{
	return this->buttomY;
}

void Player::setButtonY(float button)
{
	this->buttomY = button;
}

float Player::getVx()
{
	return this->vx;
}

void Player::setVx(float speedX)
{
	this->vx = speedX;
}

float Player::getVy()
{
	return this->vy;
}

void Player::setVy(float speedy)
{
	this->vy = speedy;
}
