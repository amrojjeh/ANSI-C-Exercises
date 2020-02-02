#include <stdio.h>
#include <ctype.h>
#include "calc.h"

static int next = 0;

// Negative sign is ~
int getop(char s[])
{
	int i, c, sign;

	if (next == ' ' || next == '\t' || next == '\n' || next == 0)
		while ((s[0] = c = getch()) == ' ' || c == '\t' || c == '\n'); // Trim whitespace
	else s[0] = c = next;
	s[1] = 0;

	if (!isdigit(c) && c != '.' && c != '~')
	{
		next = 0;
		return c;
	}
		
	
	i = 0;

	if (c == '~')
	{
		s[i] = '-';
		s[++i] = c = getchar();
	}
	
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()));

	if (c == '.')
		while (isdigit(s[++i] = c = getch()));
	
	s[i] = 0;

	if (c != EOF) next = c;
	else next = 0;
	return NUMBER;
}