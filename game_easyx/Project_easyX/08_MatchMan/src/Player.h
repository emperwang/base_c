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
	PlayStatus playStatus = STANDLEFT;

	//要显示的位置
	int leftX, buttomY;
	int width, height;
	// 移动速度
	int vx, vy;
	//重力加速度
	int gravity;
public:
	Player(): leftX(0), buttomY(0),width(0), height(0), vx(0), vy(0), gravity(0)
	{
	}
	void show();

	void initialize();
	
	void update(int leftx, int buttony);

	void standStill();

	void setStatus(PlayStatus status);

	void updateJumpStatus();

	void runRightStatus();

	void runLeftStatus();

	void updateYCoordinate();

	int getLeftX();

	void setLeftX(int left);

	int getButtonY();

	void setButtonY(int button);

	int getVx();

	void setVx(int speedX);

	int getVy();

	void setVy(int speedy);

private:

};

