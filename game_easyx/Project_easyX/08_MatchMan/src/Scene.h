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

public:

	void show();

	// 背景相对运动
	void show(float px, float py);

	void initialize();

	const std::vector<Land>& getLands() const;
};

