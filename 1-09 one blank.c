#include <stdio.h>

int main()
{
	int prevC, c;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			if (prevC != ' ') putchar(c);
		if (c != ' ') putchar(c);
		prevC = c;
	}
}
