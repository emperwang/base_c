#ifndef _TEN_STEP_H
#define _TEN_STEP_H

#include "Round.h"
#define PI 3.1415926

// 初始化圆的数组
void Init();

// 显示
void show();

// 获取用户输入
void updateWithInput();

void changeTitle(const char*);

void roundRotate(int x, int y);

int getNextRound(int arr[2]);

#endif // _TEN_STEP_H
