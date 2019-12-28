#include <stdio.h>

int main()
{
	for (int c; (c = getchar()) != EOF;)
	{
		if (c == ' ') printf("\\b");
		else if (c == '\t') printf("\\t");
		else if (c == '\\') printf("\\\\");
		else putchar(c);
	}
}
