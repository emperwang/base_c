#include "SmartUfo.h"

void SmartUfo::updateSpeedForRocket(Rocket& rocket)
{
	float scalar = 1 * rand() / double(RAND_MAX) + 1;
	if (rocket.getX() >= this->x)
	{
		this->vx = scalar;
	}
	else
	{
		this->vx = -scalar;
	}

	if (rocket.getY() >= this->y)
	{
		vy = scalar;
	}
	else
	{
		vy = -scalar;
	}
}
