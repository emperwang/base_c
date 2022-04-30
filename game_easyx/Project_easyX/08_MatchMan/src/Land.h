#pragma once

#include <graphics.h>

extern const int WIDTH;
extern const int HEIGHT;

class Land
{
private:
	IMAGE imShow;	// land��ͼƬ
	// ��ʾ������
	float leftX, rightX, topY;
	// ͼƬ��С
	float landWidht, landHeight;

public:
	void initialize();

	void draw();

	void draw(float px, float py);

	Land():leftX(0), rightX(0), topY(0), landWidht(0), landHeight(0){}

	~Land(){}

	float getLeftX() const;

	void setLeftX(float leftx);

	float getTopY() const;

	void setTopY(float topy);

	float getLandWidht() const;

	float getLandHeight() const; 

	float  getRightX() const;
};

