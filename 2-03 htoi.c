#include <stdio.h>

int htoi(char string[]);

int main()
{
	printf("10 == 16: %d\n", htoi("10"));
	printf("0x10 == 16: %d\n", htoi("0x10"));
	printf("0X10 == 16: %d\n", htoi("0X10"));
	printf("1a == 26: %d\n", htoi("1a"));
	printf("1A == 26: %d\n", htoi("1A"));
	printf("0x1a == 26: %d\n", htoi("0x1a"));
	printf("0X1A == 26: %d\n", htoi("0X1A"));
	printf("0x01234567 == 19088743: %d\n", htoi("0x01234567"));
	printf("0x089ABCDEF == -1985229329: %d\n", htoi("0x089ABCDEF"));
	return 0;
}

int htoi(char string[])
{
	int num = 0;
	char c; // character
	for (int i = 0; (c = string[i]) != 0; ++i)
	{
		// Checking if it's a decimal digit
		if (c <= '9' && c >= '0') num = num * 16 + c - '0';
		// Checking if it's hex digit
		else if (c <= 'f' && c >= 'a') num = num * 16 + c - 'a' + 10;
		else if (c <= 'F' && c >= 'A') num = num * 16 + c - 'A' + 10;
	}
	return num;
}
