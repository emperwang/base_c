#pragma once
#include <graphics.h>
#include <vector>
#include "Land.h"

class Scene
{
private:
	IMAGE imgBak;
	std::vector<Land> lands;

public:

	void show();

	void initialize();

	const std::vector<Land>& getLands() const;
};

