#include "pushbox.h"

// ��ʼ��������Ϊ��ͼ
// space=0 border=1   box=2  dest=3 playe=4 box+dest playe+dest
int maps[LEVEL][ROW][COL] =
{
	{
		{ 0,0,0,0,0,0,0,0,0,0},
		{ 0,0,0,1,1,1,0,0,0,0 },
		{ 0,0,0,1,3,1,1,1,1,0 },
		{ 0,1,1,1,2,0,2,3,1,0 },
		{ 0,1,3,2,4,0,1,1,1,0 },
		{ 0,1,1,1,1,2,1,0,0,0 },
		{ 0,0,0,0,1,3,1,0,0,0 },
		{ 0,0,0,0,1,1,1,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 }
	},
	{
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,1,1,0,0,1,1,0,0 },
		{ 0,1,0,3,1,1,3,0,1,0 },
		{ 1,0,0,0,2,0,0,0,0,1 },
		{ 1,0,0,0,0,0,2,0,0,1 },
		{ 1,0,0,0,0,4,0,0,0,1 },
		{ 0,1,0,0,2,0,0,0,1,0 },
		{ 0,0,1,0,0,0,0,1,0,0 },
		{ 0,0,0,1,3,0,1,0,0,0 },
		{ 0,0,0,0,1,1,0,0,0,0 }
	},

	{
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,1,0,0,0,0,0,1,0 },
		{ 0,1,0,1,0,0,0,1,3,1 },
		{ 1,0,0,1,0,0,0,1,0,1 },
		{ 1,0,0,0,1,1,1,0,0,1 },
		{ 1,0,0,0,0,4,0,0,2,1 },
		{ 1,0,0,2,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,1,0,3,0,3,2,0,1,0 },
		{ 0,0,1,1,1,1,1,1,0,0 }
	},
};
int level = 0;

enum BoxEnum
{
	SPACE=0,
	BORDER,
	BOX,
	DEST,
	PLAYE
};


void keyEvent() 
{
	// ���� ��ȡһ����ҵ�λ��
	int i = 0, k = 0;
	for (i = 0; i < 10; i++)
	{
		for (k = 0; k < 10; k++)
		{
			if (maps[level][i][k] == PLAYE || maps[level][i][k] == (PLAYE+DEST))	// got player address
				goto end;
		}
	}
end:;
	int ch = _getch();
	// up 72  down 80 left 75  right 77
	//printf("%d -- %c", ch, ch);
	switch (ch)
	{
	case 'w':
	case 'W':
	case 72:
		// �����ƶ�,����Ҫ�ж��Ƿ����ƶ�, ������ƶ�,��ô�Ͷ�����ֵ���в���
		// �����п�λ��
		if (maps[level][i-1][k] == SPACE || maps[level][i-1][k] == DEST) 
		{
			// �п�λ���ƶ�
			maps[level][i-1][k] += PLAYE;
			maps[level][i][k] -= PLAYE;
		}
		else if (maps[level][i - 1][k] == BOX)	// ����������
		{
			// �ǻ�Ҫ���box�ϵ�λ��,��ʲôλ��
			if (maps[level][i - 2][k] == SPACE || maps[level][i - 2][k] == DEST)
			{
				maps[level][i - 2][k] += BOX;
				maps[level][i - 1][k] -= BOX;
				maps[level][i - 1][k] += PLAYE;
				maps[level][i][k] -= PLAYE;
			}
		}
		break;
	case 's':
	case 'S':
	case 80:
		// �����ƶ�,ͬ���ȼ�������������ʲô
		if (maps[level][i + 1][k] == SPACE || maps[level][i + 1][k] == DEST)
		{
			// �п�λ���ƶ�
			maps[level][i + 1][k] += PLAYE;
			maps[level][i][k] -= PLAYE;
		}
		else if (maps[level][i + 1][k] == BOX)	// ������
		{
			// �ǻ�Ҫ���box�ϵ�λ��,��ʲôλ��
			if (maps[level][i + 2][k] == SPACE || maps[level][i + 2][k] == DEST)
			{
				maps[level][i + 2][k] += BOX;
				maps[level][i + 1][k] -= BOX;
				maps[level][i + 1][k] += PLAYE;
				maps[level][i][k] -= PLAYE;
			}
		}
		break;
	case 'a':
	case 'A':
	case 75:
		// �����ƶ�,ͬ���ȼ�������������ʲô
		if (maps[level][i][k-1] == SPACE || maps[level][i][k-1] == DEST)
		{
			// �п�λ���ƶ�
			maps[level][i][k-1] += PLAYE;
			maps[level][i][k] -= PLAYE;
		}
		else if (maps[level][i][k-1] == BOX)	// ������
		{
			// �ǻ�Ҫ���box�ϵ�λ��,��ʲôλ��
			if (maps[level][i][k-2] == SPACE || maps[level][i][k-2] == DEST)
			{
				maps[level][i][k-2] += BOX;
				maps[level][i][k-1] -= BOX;
				maps[level][i][k-1] += PLAYE;
				maps[level][i][k] -= PLAYE;
			}
		}
		break;
	case 'd':
	case 'D':
	case 77:
		// �����ƶ�,ͬ���ȼ�������������ʲô
		if (maps[level][i][k + 1] == SPACE || maps[level][i][k + 1] == DEST)
		{
			// �п�λ���ƶ�
			maps[level][i][k + 1] += PLAYE;
			maps[level][i][k] -= PLAYE;
		}
		else if (maps[level][i][k + 1] == BOX)	// ������
		{
			// �ǻ�Ҫ���box�ϵ�λ��,��ʲôλ��
			if (maps[level][i][k + 2] == SPACE || maps[level][i][k + 2] == DEST)
			{
				maps[level][i][k + 2] += BOX;
				maps[level][i][k + 1] -= BOX;
				maps[level][i][k + 1] += PLAYE;
				maps[level][i][k] -= PLAYE;
			}
		}
		break;
	default:
		break;
	}

}

bool checkAllPass()
{
	if (isPassed())
	{
		level++;
		if (level >= LEVEL)
		{
			return true;
		}
	}
	else
	{
		return false;
	}
	return false;
}

// ����Ƿ��Ѿ�ͨ��
// û�е��������Ӵ���,��ô�ͱ�ʾ�Ѿ�ͨ��
bool isPassed()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (maps[level][i][j] == BOX)
			{
				return false;
			}
		}
	}
	return true;
}

void drawBox()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			switch (maps[level][i][j])
			{
			case SPACE:
				printf("  ");
				break;
			case BORDER:
				printf("��");
				break;
			case BOX:
				printf("��");
				break;
			case DEST:
				printf("��");
				break;
			case PLAYE:
				printf("��");
				break;
			case BOX+DEST:
				printf("��");
				break;
			case PLAYE+DEST:
				printf("��");
				break;
			}
		}
		printf("\n");
	}

}





