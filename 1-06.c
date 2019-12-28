#include <stdio.h>

int main()
{
	printf("%d\t%d\n", (EOF != 0), (EOF != EOF));
	/* If the values outputed are 1 and 0, then that verifies that 
		getchar() != EOF is either 0 or 1*/
}
