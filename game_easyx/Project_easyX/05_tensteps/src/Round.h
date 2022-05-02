#ifndef _ROUND_H
#define _ROUND_H
/*
1. 显示出5*5 个圆
2. 显示每个圆的指针
3. 

*/

class Round
{
private:
	int x, y;		//圆心的位置
	int r;			// 圆的半径
	int angleNum;	//要翻转的度数  pi/2 的倍数.为0-3
public:

	int getRadious()
	{
		return r;
	}

	void setR(int r)
	{
		this->r = r;
	}

	int getX()
	{
		return x;
	}

	void setX(int x)
	{
		this->x = x;
	}

	int getY()
	{
		return this->y;
	}

	void setY(int y)
	{
		this->y = y;
	}

	int getAngleNum()
	{
		return this->angleNum;
	}

	void setAngleNum(int angle)
	{
		if (angle > 3)
		{
			this->angleNum = 1;
			return;
		}
		this->angleNum = angle;
	}

	void SetAngleNumPlusOne()
	{
		this->angleNum += 1;
		if (this->angleNum > 3)
		{
			this->angleNum = 0;
		}
	}
};


#endif // _ROUND_H



