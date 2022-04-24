#include "Rocket.h"
#include "Util.h"
#include <cstdio>

void Rocket::show()
{
	// 显示生命数量
	for (int i = 0; i < life; i++)
	{
		putimagePng(i * this->width * 0.7, 0, &this->rocketiImg);
	}
	if (this->isAlive)
	{
		putimagePng(this->x, this->y, &this->rocketiImg);
	}
	else 
	{
		putimagePng(this->x, this->y, &this->explode);
	}

	// 显示生存时间
	TCHAR buf[20];
	setbkmode(TRANSPARENT);
	sprintf_s(buf, "%d秒", this->liveSeconds);
	settextcolor(WHITE);
	settextstyle(20, 0, _T("宋体"));
	outtextxy(500, 5, buf);
}