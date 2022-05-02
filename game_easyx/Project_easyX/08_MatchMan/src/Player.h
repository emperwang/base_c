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
	// 要显示的图片
	IMAGE imShow;
	IMAGE standLeft, jumpLeft;
	IMAGE standRight, jumpRight;
	std::vector<IMAGE> runLeft;
	std::vector<IMAGE> runRight;
	int runIdx = 0;
	Player::PlayStatus playStatus = STANDRIGHT;

	//要显示的位置
	float leftX, buttomY;
	int width, height;
	// 移动速度
	float vx, vy;
	//重力加速度
	float gravity;
	//是否失败
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

	// 判断player是否在地面上
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

