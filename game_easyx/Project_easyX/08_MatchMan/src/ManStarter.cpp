#include "MatchMan.h"

int main(int argc, char** argv)
{
	init();
	while (1)
	{
		show();
		updateWithInput();
		updateWithoutInput();
	}
	return 0;
}
