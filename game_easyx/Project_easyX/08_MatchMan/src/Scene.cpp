#include "Scene.h"
#include "Util.h"

void Scene::show()
{
	putimagePng(-100, -100, &imgBak);
	for (int i = 0; i < lands.size(); i++)
	{
		lands[i].draw();
	}
	float rightx = (*lands.cend()).getRightX();
	float top = (*lands.cend()).getTopY();
	putimagePng(rightx - star.getwidth() / 2, top, &star);
}


void Scene::show(float px, float py)
{
	putimagePng(-px/20, -100-py/20, &imgBak);
	showLevel();
	for (int i = 0; i < lands.size(); i++)
	{
		lands[i].draw(px, py);
	}
	float rightx = (lands.end()-1)->getRightX();
	float top = (lands.end() - 1)->getTopY();
	putimagePng(rightx - star.getwidth() -px, top - star.getheight()-py, &star);
}

void Scene::showLevel()
{
	//show level
	TCHAR buf[40];
	_stprintf_s(buf, "Level: %d", level);
	//showMsg(WIDTH - 100, 40, RGB(10, 20, 120), 20, buf);
	setbkmode(TRANSPARENT);
	settextcolor(RGB(10, 20, 120));
	settextstyle(20, 0, "����");
	outtextxy(WIDTH - 100, 40, buf);
}

void Scene::initialize()
{
	bkimgs.clear();
	lands.clear();
	TCHAR buf[50];
	IMAGE tmp;
	for (int i = 1; i <= 9; i++)
	{
		sprintf_s(buf, "assets/picture/landscape%d.png", i);
		loadimage(&tmp, buf);
		bkimgs.push_back(tmp);
	}
	loadimage(&star, _T("assets/picture/star.png"));
	for (int i = 1; i <= 6; i++)
	{
		Land land;
		land.initialize();
		land.setLeftX(i * land.getLandWidht());
		float val = (float(i) - 1) / 6 * HEIGHT; // / 2 + HEIGHT / 2;
		land.setTopY(val);
		lands.push_back(land);
	}
	imgBak = bkimgs[1];
}

int Scene::getLevel()
{
	return level;
}

void Scene::nextLevel()
{
	level++;
}

const std::vector<Land>& Scene::getLands()const 
{
	return this->lands;
}

