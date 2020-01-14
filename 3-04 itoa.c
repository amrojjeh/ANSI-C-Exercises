#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
	char s1[MAX_LINE] = "This ids a test";
	int test = -2147483648;
	itoa(test, s1);
	printf("%s", s1);
	return 0;
}

void itoa(int n, char s[])
{
	int i, sign;

	// The problem with this line is that it can't multiply -2^[wordsize] by -1, since there's no positive 2^[wordsize].
	if ((sign = n) < 0) n = -n - (-n == n ? 1 : 0);
	i = 0;
	do
	{
		s[i++] = n % 10 + '0' + (-n - 1== n + 1 ? 1 : 0); // The ternary fixes it.
	} while ((n /= 10) > 0);
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