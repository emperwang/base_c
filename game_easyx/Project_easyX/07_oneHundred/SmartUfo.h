#pragma once
#include "Bullet.h"

class SmartUfo: public Bullet
{
public:
	SmartUfo() :Bullet()
	{
	}
	SmartUfo(IMAGE& img):Bullet(img)
	{

	}
	// 更新ufo的速度, 使其朝向rocket
	void updateSpeedForRocket(Rocket& rocket);
};

