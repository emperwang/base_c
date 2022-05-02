#pragma once
#include <graphics.h>
#include <vector>
#include "Land.h"
#include "Scene.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

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
	Player::PlayStatus playStatus = STANDRIGHT;

	//Ҫ��ʾ��λ��
	float leftX, buttomY;
	int width, height;
	// �ƶ��ٶ�
	float vx, vy;
	//�������ٶ�
	float gravity;
	//�Ƿ�ʧ��
	bool fail = false;
	
	// logger
	std::shared_ptr<spdlog::logger> logger = spdlog::stdout_color_mt("console");

	//file logger
	// 1048576 * 5 = 5M
	std::shared_ptr<spdlog::logger> filelog = spdlog::rotating_logger_mt("route", "logs/rotating.txt",1048576 * 5, 3);
public:
	Player(): leftX(0), buttomY(0),width(0), height(0), vx(0), vy(0), gravity(0)
	{
	}

	~Player(){}
	void show();

	void initialize();
	
	void update(int leftx, int buttony);

	void standStill();

	void setStatus(PlayStatus status);

	void updateJumpStatus();

	void runRightStatus(Scene& scene);

	void runLeftStatus(Scene& scene);

	void updateYCoordinate(Scene& scene);

	void checkSuccess(Scene& scene);

	// �ж�player�Ƿ��ڵ�����
	int isOnLand(const Land& land, float speed);

	int isNotOnAllLand(const std::vector<Land>& lands, float speed);

	float getLeftX();

	void setLeftX(float left);

	int getButtonY();

	void setButtonY(float button);

	float getVx();

	void setVx(float speedX);

	float getVy();

	void setVy(float speedy);

private:
	void outputPostion();
};

