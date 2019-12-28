#include <stdio.h>
#include <limits.h>
#include <float.h>

// Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned.

int main()
{
	printf("SIGNED CHAR RANGE: %d - %d\n", CHAR_MIN, CHAR_MAX);
	printf("UNSIGNED CHAR RANGE: %d - %d\n\n", 0, UCHAR_MAX);

	printf("SIGNED SHORT RANGE: %d - %d\n", SHRT_MIN, SHRT_MAX);
	printf("UNSIGNED SHORT RANGE: %d - %d\n\n", 0, USHRT_MAX);

	printf("SIGNED INT RANGE: %d - %d\n", INT_MIN, INT_MAX);
	printf("UNSIGNED INT RANGE: %d - %u\n\n", 0, UINT_MAX);

	printf("SIGNED LONG RANGE: %lld - %lld\n", LLONG_MIN, LLONG_MAX);
	printf("UNSIGNED LONG RANGE: %d - %llu\n", 0, ULLONG_MAX);

	return 0;
}