#include "Rocket.h"
#include "Util.h"
#include <cstdio>

void Rocket::show()
{
	// ��ʾ��������
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

	// ��ʾ����ʱ��
	TCHAR buf[20];
	setbkmode(TRANSPARENT);
	sprintf_s(buf, "%d��", this->liveSeconds);
	settextcolor(WHITE);
	settextstyle(20, 0, _T("����"));
	outtextxy(500, 5, buf);
}