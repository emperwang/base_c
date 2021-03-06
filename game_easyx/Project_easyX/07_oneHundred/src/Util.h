#ifndef _EAXYPNG_H
#define _EAXYPNG_H

#include <graphics.h>  
#include <math.h>
#define	 PI 3.14159

// 在当前设备上绘制带透明通道的png图片
// img_x	绘制位置的x坐标
// img_y	绘制位置的y坐标
// pSrcImg	要绘制的IMAGE对象指针
void putimagePng(int img_x, int img_y, IMAGE* pSrcImg);

void sleep(int ms);

void showMsg(int x, int y, COLORREF color, int fontHight, const TCHAR* msg);

#endif // _EAXYPNG_H