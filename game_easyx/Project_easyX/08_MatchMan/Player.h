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
	PlayStatus status = STANDLEFT;

	//Ҫ��ʾ��λ��
	int leftX, buttomY;
	int width, height;
	// �ƶ��ٶ�
	int vx, vy;
public:
	Player()
	{
	}
	void show();

	void initialize();
	

};

