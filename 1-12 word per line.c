#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
	int c, state;
	state = OUT;
	while ((c = getchar()) != EOF)
	{
		if (state == IN && c == '\n' || c == ' ' || c == '\t')
		{
			putchar('\n');
			state = OUT;
		}
		else if (state == OUT)
		{
			putchar(c);
			state = IN;
		}
		else putchar(c);
	}
}
