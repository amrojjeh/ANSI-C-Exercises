#include <stdio.h>

#define MAX_LINE 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
	char s1[MAX_LINE];
	int test = 0xFFF32;
	itob(test, s1, 16);
	printf("%s", s1);
	return 0;
}

void itob(int n, char s[], int b)
{
	int i, sign;

	sign = n;
	i = 0;
	do
	{
		int rem = (n < 0 ? -1 : 1) * (n % b);
		printf("%x ", rem);
		s[i++] = rem + (rem >= 10 ? -10 + 'a' : '0');
	} while ((n /= b) != 0);
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