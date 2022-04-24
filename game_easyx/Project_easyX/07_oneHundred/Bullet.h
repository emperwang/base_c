#pragma once
#include <graphics.h>
#include <time.h>
#include "Rocket.h"
#include <cmath>

#define  PI 3.1415926

class Bullet
{
private:
	IMAGE bulletImg;
	//  λ����Ϣ
	int x=0;
	int y=0;
	// x ��y�����ϵ��ٶ�
	int vx=0;
	int vy=0;

	// ��С
	int width=0;
	int height=0;

	int screenWidth = 560;
	int screenHeight = 800;

	// �ӵ��뾶
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
		//this->vx = 1;
		//this->vy = 1;
		// Ϊ�ӵ�����һ�����������ٶ�
		float angle = (rand() / double(RAND_MAX) - 0.5) * 0.9 * PI;
		float scalar = 2 * rand() / double(RAND_MAX) + 2;
		this->vx = scalar * cos(angle);
		this->vy = scalar * sin(angle);
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

