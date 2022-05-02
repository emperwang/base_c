#pragma once
#include <tchar.h>
#include <graphics.h>

void init();

void display();

void updateWithoutInput();

void updateWithInput();

void changeTitle(const TCHAR* title);

void addUfo();