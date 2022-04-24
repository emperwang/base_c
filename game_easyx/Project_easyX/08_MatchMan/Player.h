#pragma once
#include <graphics.h>
#include <vector>

class Player
{
public:
	enum PlayStatus 
	{
		STANDLEFT,
		STANDRIGHT,
		RUNLEFT,
		RUNRIGHT,
		JUMPLEFT,
		JUMPRIGHT,
		DIE
	};
private:
	// 要显示的图片
	IMAGE imShow;
	IMAGE standLeft, jumpLeft;
	IMAGE standRight, jumpRight;
	std::vector<IMAGE> runLeft;
	std::vector<IMAGE> runRight;
	int runIdx = 0;
	PlayStatus status = STANDLEFT;

	//要显示的位置
	int leftX, buttomY;
	int width, height;
	// 移动速度
	int vx, vy;
public:
	Player()
	{
	}
	void show();

	void initialize();
	

};

