#ifndef _EAXYPNG_H
#define _EAXYPNG_H

#include <graphics.h>  
#include <math.h>
#define	 PI 3.14159

// �ڵ�ǰ�豸�ϻ��ƴ�͸��ͨ����pngͼƬ
// img_x	����λ�õ�x����
// img_y	����λ�õ�y����
// pSrcImg	Ҫ���Ƶ�IMAGE����ָ��
void putimagePng(int img_x, int img_y, IMAGE* pSrcImg);

void sleep(int ms);

#endif // _EAXYPNG_H