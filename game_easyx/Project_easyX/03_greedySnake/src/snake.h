#pragma once
#include <conio.h>
#include <stdio.h>
#include <graphics.h>

enum DIRECTION 
{
	UP=0,
	DOWN,
	LEFT,
	RIGHT
};

void Init();

void Show();

void updateWithInput();

void updateWithoutInput();

void changeTitle(const char* title);

void updateDirection(int input);

void showMessage(int x, int y, const char* msg);

void showScore(int x, int y, const char* score);

void checkSuccess();

// ”Œœ∑∏¥Œª
void reset();