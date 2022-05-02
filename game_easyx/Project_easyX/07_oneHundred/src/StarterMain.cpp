#include "OneHundred.h"

int main(int argc, char** argv)
{
	init();
	while (1)
	{
		display();
		updateWithoutInput();
		updateWithInput();
	}
	return 0;
}
