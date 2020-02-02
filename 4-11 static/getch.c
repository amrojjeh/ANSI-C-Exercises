#include <stdio.h>

char buffer = 0;

int getch(void)
{
	if (!buffer) return getchar();
	char temp = buffer;
	buffer = 0;
	return temp;
}

void ungetch(int c)
{
	buffer = c;
}