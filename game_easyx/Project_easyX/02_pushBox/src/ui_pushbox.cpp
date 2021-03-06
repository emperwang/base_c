#include <conio.h>
#include <cstdio>
#include <graphics.h>
#include "ui_pushbox.h"
#include "common.h"

namespace uibox {
	// 初始化数组作为地图
	// space=0 border=1   box=2  dest=3 playe=4 box+dest playe+dest
	int maps[LEVEL][ROW][COL] =
	{
		{
			{ 0,0,0,0,0,0,0,0,0,0 },
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
		SPACE = 0,
		BORDER,
		BOX,
		DEST,
		PLAYE
	};

	IMAGE imgs[IMAGES];

	void ui_loadImg()
	{
		for (int i = 0; i < IMAGES; i++)
		{
			char files[50];
			sprintf_s(files, "assets/picture/%d.png", i);
			loadimage(imgs + i, files, 64, 64);
			//putimage(i * 64 + 5, 0, imgs + i);
		}
	}

	void ui_keyEvent()
	{
		// 首先 获取一下玩家的位置
		int i = 0, k = 0;
		for (i = 0; i < 10; i++)
		{
			for (k = 0; k < 10; k++)
			{
				if (maps[level][i][k] == PLAYE || maps[level][i][k] == (PLAYE + DEST))	// got player address
					goto end;
			}
		}
	end:
		int ch = _getch();
		// up 72  down 80 left 75  right 77
		//printf("%d -- %c", ch, ch);
		switch (ch)
		{
		case 'w':
		case 'W':
		case 72:
			// 向上移动,首先要判断是否能移动, 如果能移动,那么就对数组值进行操作
			// 向上有空位置
			if (maps[level][i - 1][k] == SPACE || maps[level][i - 1][k] == DEST)
			{
				// 有空位则移动
				maps[level][i - 1][k] += PLAYE;
				maps[level][i][k] -= PLAYE;
			}
			else if (maps[level][i - 1][k] == BOX)	// 上面是箱子
			{
				// 那还要检测box上的位置,是什么位置
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
			// 向下移动,同样先检测下面的内容是什么
			if (maps[level][i + 1][k] == SPACE || maps[level][i + 1][k] == DEST)
			{
				// 有空位则移动
				maps[level][i + 1][k] += PLAYE;
				maps[level][i][k] -= PLAYE;
			}
			else if (maps[level][i + 1][k] == BOX)	// 是箱子
			{
				// 那还要检测box上的位置,是什么位置
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
			// 向左移动,同样先检测下面的内容是什么
			if (maps[level][i][k - 1] == SPACE || maps[level][i][k - 1] == DEST)
			{
				// 有空位则移动
				maps[level][i][k - 1] += PLAYE;
				maps[level][i][k] -= PLAYE;
			}
			else if (maps[level][i][k - 1] == BOX)	// 是箱子
			{
				// 那还要检测box上的位置,是什么位置
				if (maps[level][i][k - 2] == SPACE || maps[level][i][k - 2] == DEST)
				{
					maps[level][i][k - 2] += BOX;
					maps[level][i][k - 1] -= BOX;
					maps[level][i][k - 1] += PLAYE;
					maps[level][i][k] -= PLAYE;
				}
			}
			break;
		case 'd':
		case 'D':
		case 77:
			// 向右移动,同样先检测下面的内容是什么
			if (maps[level][i][k + 1] == SPACE || maps[level][i][k + 1] == DEST)
			{
				// 有空位则移动
				maps[level][i][k + 1] += PLAYE;
				maps[level][i][k] -= PLAYE;
			}
			else if (maps[level][i][k + 1] == BOX)	// 是箱子
			{
				// 那还要检测box上的位置,是什么位置
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

	bool ui_checkAllPass()
	{
		if (ui_isPassed())
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

	// 检查是否已经通关
	// 没有单独的箱子存在,那么就表示已经通关
	bool ui_isPassed()
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

	void ui_drawBox()
	{

		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				int x = j * 64;
				int y = i * 64;

				switch (maps[level][i][j])
				{
				case SPACE:
					//printf("  ");
					putimage(x, y, imgs);
					break;
				case BORDER:
					//printf("▓");
					putimage(x, y, imgs + 1);
					break;
				case BOX:
					putimage(x, y, imgs + 2);
					break;
				case DEST:
					putimage(x, y, imgs + 3);
					break;
				case PLAYE:
					putimage(x, y, imgs + 4);
					break;
				case BOX + DEST:
					putimage(x, y, imgs + 5);
					break;
				case PLAYE + DEST:
					putimage(x, y, imgs + 6);
					break;
				}
			}
			//printf("\n");
		}

	}

	void ui_changeTitle(const char* title)
	{
		HWND hwnd = GetHWnd();
		SetWindowText(hwnd, title);
	}

}

