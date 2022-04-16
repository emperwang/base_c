#include <iostream>
//#include "pushbox.h"
#include "ui_pushbox.h"

void console_pushbox();

void ui_pushbox();

int main()
{
	system("mode con lines=10 cols=25");
	initgraph(10*64, 10*64);
	cleardevice();
	changeTitle("push Box");
	setbkcolor(WHITE);
	setfillcolor(WHITE);
	loadImg();
	ui_pushbox();
	_getch();
	return 0;
}


void ui_pushbox()
{
	while (1)
	{
		drawBox();
		if (checkAllPass())
		{
			outtextxy(300,300, "恭喜你,通关..");
			break;
		}
		keyEvent();
	}
	_getch();
	closegraph();
}

void console_pushbox() 
{
	while (1)
	{
		drawBox();
		if (checkAllPass())
		{
			printf("恭喜你,通关..");
			_getch();
			break;
		}
		keyEvent();
	}
}
