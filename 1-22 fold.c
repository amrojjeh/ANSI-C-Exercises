#include <stdio.h>

#define NTHC 80 // Nth Coloumn

int main(int argc, char *argv[])
{
	int length = 0;
	for (int c; (c = getchar()) != EOF; length++)
	{
		if (length == NTHC)
		{
			length = 0;
			putchar('\n');
		}
		putchar(c);
	}
}
