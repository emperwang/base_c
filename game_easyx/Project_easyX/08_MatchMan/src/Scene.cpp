#include "Scene.h"
#include "Util.h"

void Scene::show()
{
	putimagePng(-100, -100, &imgBak);
	for (int i = 0; i < lands.size(); i++)
	{
		lands[i].draw();
	}
}

void Scene::initialize()
{
	loadimage(&imgBak, _T("assets/picture/landscape1.png"));
	for (int i = 1; i <= 6; i++)
	{
		Land land;
		land.initialize();
		land.setLeftX(i * land.getLandWidht());
		float val = (float(i) - 1) / 6 * HEIGHT; // / 2 + HEIGHT / 2;
		land.setTopY(val);
		lands.push_back(land);
	}
}

const std::vector<Land>& Scene::getLands()const 
{
	return this->lands;
}

