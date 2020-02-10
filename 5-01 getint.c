#include <stdio.h>
#include <ctype.h>

#define SIZE 1000

int getint(int*);
void printArray(int []);

int main()
{
	int n, array[SIZE];
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; ++n);
	array[n] = 0;

	printArray(array);
}

void printArray(int array[])
{
	printf("[%d", array[0]);
	for (int x = 1; x < SIZE && array[x] != 0; ++x)
	{
		printf(", %d", array[x]);
	}
	putchar(']');
}

int getch(void);
void ungetch(int);

int getint(int *pn)
{
	int c, sign;
	while (isspace(c = getch()));
	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);
		return 0;
	}

	sign = c == '-' ? -1 : 1;

	if (c == '+' || c == '-') c = getch();

	if (!isdigit(c))
	{
		ungetch(c);
		return 0;
	}

	for (*pn = 0; isdigit(c); c = getchar())
	{
		*pn *= 10;
		*pn += c - '0';
	}

	*pn *= sign;

	if (c != EOF) ungetch(c);
	return c;
}

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