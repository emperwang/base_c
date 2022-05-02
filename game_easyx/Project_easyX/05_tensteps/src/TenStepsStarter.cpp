#include "TenStep.h"

int main (void)
{
	Init();
	while (1)
	{
		show();
		updateWithInput();
	}

	return 0;
}
