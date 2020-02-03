#include <stdio.h>
#include <string.h> // for strcpy

#define MAX 1000

void itoa(int n, char s[]);

int main()
{
	char s[MAX];
	itoa(-12412, s);
	printf("%s\n", s);
	return 0;
}

void append(char c, char s[]);

/*
	I can represent the largest negative number by adding to s[i] instead of assiging it, however, that means that for the function to work, 
	the user has to make sure s[] is clear, which isn't a good idea.

	After some thinking, there's no choice but to either remove support for the largest negative number or just hard code. I guess I'll hard code it.
*/
void itoa(int n, char s[])
{
	if (n == -2147483648)
	{
		strcpy(s, "-2147483648");
		return;
	}

	if (n < 0)
	{
		s[0] = '-';
		s[1] = 0;
		n *= -1;
		s += 1;
	}
	
	if (n / 10) // more than one digit
		itoa(n / 10, s);
	else
		s[0] = 0;
	append((n % 10) + '0', s);
}

void append(char c, char s[])
{
	int i = 0;
	while (s[i] != '\0') ++i;
	s[i] = c;
	s[i + 1] = '\0';
}