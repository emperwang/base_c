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
	// Ҫ��ʾ��ͼƬ
	IMAGE imShow;
	IMAGE standLeft, jumpLeft;
	IMAGE standRight, jumpRight;
	std::vector<IMAGE> runLeft;
	std::vector<IMAGE> runRight;
	int runIdx = 0;
	PlayStatus playStatus = STANDLEFT;

	//Ҫ��ʾ��λ��
	int leftX, buttomY;
	int width, height;
	// �ƶ��ٶ�
	int vx, vy;
	//�������ٶ�
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

