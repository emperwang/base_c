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
	// ����ufo���ٶ�, ʹ�䳯��rocket
	void updateSpeedForRocket(Rocket& rocket);
};

