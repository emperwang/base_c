#include "Bullet.h"
#include "Util.h"
#include <cmath>

void Bullet::show()
{
	putimagePng(this->x - this->width/2, this->y, &this->bulletImg);
}

void Bullet::update()
{
	this->x += vx;
	this->y += vy;

	if (this->x < 0 || this->x >= screenWidth)
	{
		this->vx = -this->vx;
	}

	if (this->y < 0 || this->y >= screenHeight)
	{
		this->vy = -this->vy;
	}
}

int Bullet::checkCollision(Rocket& rocket)
{
	float distanceX = abs(rocket.getX() - this->x);
	float distanceY = abs(rocket.getY() - this->y);

	if (distanceX <= rocket.getWidth() / 2 && distanceY <= rocket.getHeight() / 2)
	{
		return 1;
	}

	return 0;
}