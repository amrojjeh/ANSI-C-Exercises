#include <stdio.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

#define MAXLINE 1000

int main()
{
	char s[MAXLINE];
	itoa(130, s, 4); // 0130
	printf("%s", s);
	return 0;
}

void itoa(int n, char s[], int w)
{
	int i, sign;

	sign = n;
	i = 0;
	do
	{
		int rem = (n < 0 ? -1 : 1) * (n % 10);
		s[i++] = rem + '0';
	} while ((n /= 10) != 0);

	// Add padding
	while (i < w) s[i++] = '0';

	if (sign < 0)
		s[i++] = '-';
	s[i] = 0;
	reverse(s);
}

void reverse(char s[])
{
	// get length
	int length = 0;
	while (s[length] != 0) ++length;
	
	// reverse
	int x, j;
	for (x = 0, j = length - 1; x < length / 2; ++x, --j)
	{
		char temp = s[x];
		s[x] = s[j];
		s[j] = temp;
	}
}