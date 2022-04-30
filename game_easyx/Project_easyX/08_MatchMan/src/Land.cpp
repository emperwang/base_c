#include "Land.h"
#include "Util.h"

void Land::initialize()
{
	// 加载图片
	loadimage(&imShow, _T("./assets/picture/land.png"));

	// 更新显示的坐标信息
	landWidht = imShow.getwidth();
	landHeight = imShow.getheight();

	leftX = WIDTH / 2;
	rightX = leftX + landWidht;
	topY = HEIGHT / 2;
}

void Land::draw()
{
	putimagePng(leftX, topY, &imShow);
}

void Land::draw(float px, float py)
{
	putimagePng(leftX-px, topY - py, &imShow);
}

float Land::getLeftX() const
{
	return leftX;
}

void Land::setLeftX(float leftx)
{
	this->leftX = leftx;
	this->rightX = leftX + landWidht;
}

float Land::getTopY() const
{
	return topY;
}

void Land::setTopY(float top)
{
	topY = top;
}

float Land::getLandWidht() const
{
	return landWidht;
}

float Land::getLandHeight() const
{
	return landHeight;
}

float Land::getRightX() const
{
	return this->rightX;
}
