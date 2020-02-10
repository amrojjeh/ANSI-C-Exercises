#include <stdio.h>
#include <ctype.h>

#define SIZE 1000

int getfloat(float*);
void printArray(float []);

int main()
{
	int n;
	float array[SIZE];
	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; ++n);
	array[n] = 0;

	printArray(array);
}

void printArray(float array[])
{
	printf("[%f", array[0]);
	for (int x = 1; x < SIZE && array[x] != 0; ++x)
	{
		printf(", %f", array[x]);
	}
	putchar(']');
}

int getch(void);
void ungetch(int);

int getfloat(float *pn)
{
	int c, sign;
	while (isspace(c = getch()));
	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
	{
		ungetch(c);
		return 0;
	}

	sign = c == '-' ? -1 : 1;

	if (c == '+' || c == '-') c = getch();

	if (!isdigit(c) && c != '.')
	{
		ungetch(c);
		return 0;
	}

	for (*pn = 0; isdigit(c); c = getchar())
	{
		*pn *= 10;
		*pn += c - '0';
	}

	if (c == '.') c = getchar();

	for (float position = 10.0; isdigit(c); position *= 10)
	{
		*pn += (c - '0') / position;
		c = getchar();
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