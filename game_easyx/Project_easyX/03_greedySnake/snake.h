#pragma once
#include <conio.h>
#include <stdio.h>
#include <graphics.h>

enum direction 
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




