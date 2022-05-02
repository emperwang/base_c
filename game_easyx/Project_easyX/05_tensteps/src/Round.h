#ifndef _ROUND_H
#define _ROUND_H
/*
1. ��ʾ��5*5 ��Բ
2. ��ʾÿ��Բ��ָ��
3. 

*/

class Round
{
private:
	int x, y;		//Բ�ĵ�λ��
	int r;			// Բ�İ뾶
	int angleNum;	//Ҫ��ת�Ķ���  pi/2 �ı���.Ϊ0-3
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



