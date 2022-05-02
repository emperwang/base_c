#include <iostream>
#include "pushbox.h"
#include "ui_pushbox.h"
#include <graphics.h>
#include <conio.h>

void console_pushbox();

void ui_pushbox();

int main()
{
	system("mode con lines=10 cols=25");
	initgraph(10*64, 10*64);
	uibox::ui_changeTitle("push Box");
	setbkcolor(WHITE);
	setfillcolor(WHITE);
	cleardevice();
	uibox::ui_loadImg();
	ui_pushbox();
	_getch();
	return 0;
}


void ui_pushbox()
{
	while (1)
	{
		uibox::ui_drawBox();
		if (uibox::ui_checkAllPass())
		{
			outtextxy(300,300, "恭喜你,通关..");
			break;
		}
		uibox::ui_keyEvent();
		uibox::ui_keyEvent();
	}
	_getch();
	closegraph();
}

void console_pushbox() 
{
	while (1)
	{
		consolebox::drawBox();
		if (consolebox::checkAllPass())
		{
			printf("恭喜你,通关..");
			_getch();
			break;
		}
		consolebox::keyEvent();
	}
}
