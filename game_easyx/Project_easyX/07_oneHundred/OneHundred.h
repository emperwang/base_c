#pragma once
#include <tchar.h>
#include <graphics.h>

void init();

void display();

void updateWithoutInput();

void updateWithInput();

void showMsg(int x, int y, COLORREF color, int fontHight, const TCHAR* msg);

void changeTitle(const TCHAR* title);
