#pragma once
#include <graphics.h>
#include <vector>
#include "Land.h"

class Scene
{
private:
	IMAGE imgBak;
	IMAGE star;
	std::vector<Land> lands;
	std::vector<IMAGE> bkimgs;

	// 关卡
	int level = 1;
public:

	void show();

	// 背景相对运动
	void show(float px, float py);

	void showLevel();

	void initialize();

	int getLevel();

	void nextLevel();

	const std::vector<Land>& getLands() const;
};

