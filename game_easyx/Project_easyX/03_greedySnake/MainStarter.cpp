#include "snake.h"

extern bool gamePaused;
int main()
{
	Init();
	while (1)
	{
		Show();
		updateWithInput();
		updateWithoutInput();
	}
	return 0;
}