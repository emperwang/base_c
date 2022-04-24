#pragma once
#include <graphics.h>
#include <time.h>
#include "Rocket.h"

class Bullet
{
private:
	IMAGE bulletImg;
	//  位置信息
	int x=0;
	int y=0;
	// x 和y方向上的速度
	int vx=0;
	int vy=0;

	// 大小
	int width=0;
	int height=0;

	int screenWidth = 560;
	int screenHeight = 800;

	// 子弹半径
	int radius =0;

public :
	Bullet()
	{
		generatePosition();
	}
	Bullet(IMAGE& img) : bulletImg(img)
	{
		this->width = img.getwidth();
		this->height = img.getheight();
		this->radius = img.getwidth() / 2;
		generatePosition();
	}

	void generatePosition()
	{
		srand(time(nullptr));
		this->x = rand() % screenWidth;
		this->y = rand() % screenHeight;
		this->vx = 1;
		this->vy = 1;
	}

	void setBulletImg(IMAGE& img)
	{
		this->bulletImg = img;
		this->width = img.getwidth();
		this->height = img.getheight();
		this->radius = img.getwidth() / 2;
	}

	int checkCollision(Rocket& rocket);

	void show();

	void update();

	void update(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

