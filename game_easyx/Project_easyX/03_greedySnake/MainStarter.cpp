#include "snake.h"


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