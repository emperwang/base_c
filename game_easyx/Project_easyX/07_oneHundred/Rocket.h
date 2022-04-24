#pragma once
#include <graphics.h>

class Rocket
{
private:
	IMAGE rocketiImg;
	IMAGE explode;
	//  坐标
	int x;
	int y;

	// 大小
	int width;
	int height;
	int radious;

	int life = 3;

	//生存时间
	int liveSeconds = 0;
	// 是否存活
	bool isAlive = true;
public:
	Rocket(){}
	Rocket(IMAGE rc, IMAGE bom) : rocketiImg(rc), explode(bom)
	{
		this->width = rocketiImg.getwidth();
		this->height = rocketiImg.getheight();
		this->radious = this->width / 2;
		this->x = 0;
		this->y = 0;
	}
	// 显示
	void show();

	int getX()
	{
		return x;
	}

	Rocket& setX(int x)
	{
		this->x = x;
		return *this;
	}

	Rocket& setY(int y)
	{
		this->y = y;
		return *this;
	}

	int getY()
	{
		return y;
	}

	void updatePostion(int x, int y)
	{
		if (isAlive)
		{
			this->x = x;
			this->y = y;
		}
	}

	bool checkAlive()
	{
		return this->isAlive;
	}

	void resetAlive()
	{
		if (this->getLife() >= 0)
		{
			this->isAlive = true;
		}
	}

	void die()
	{
		this->isAlive = false;
	}

	int getWidth()
	{
		return this->width;
	}

	int getRadious()
	{
		return this->radious;
	}

	int getHeight()
	{
		return this->height;
	}

	int getLiveSecond()
	{
		return this->liveSeconds;
	}

	void setLiveSecond(int sec)
	{
		this->liveSeconds = sec;
	}

	void liveSecondPlus()
	{
		this->liveSeconds++;
	}

	void updateWhenLostLife()
	{
		this->life--;
	}

	int getLife()
	{
		return this->life;
	}

	Rocket& setRocketImg(IMAGE& img)
	{
		this->rocketiImg = img;
		this->width = img.getwidth();
		this->height = img.getheight();
		return *this;
	}

	Rocket& setExplode(IMAGE& img)
	{
		this->explode = img;
		return *this;
	}
};

