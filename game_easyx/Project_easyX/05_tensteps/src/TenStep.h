#ifndef _TEN_STEP_H
#define _TEN_STEP_H

#include "Round.h"
#define PI 3.1415926

// ��ʼ��Բ������
void Init();

// ��ʾ
void show();

// ��ȡ�û�����
void updateWithInput();

void changeTitle(const char*);

void roundRotate(int x, int y);

int getNextRound(int arr[2]);

#endif // _TEN_STEP_H
