#include <stdio.h>

unsigned int getbits(unsigned int x, int p, int n); // Best explained with an example. getbits(0xB0, 4, 3) 10110000 -> 100

int main()
{
	printf("0xB0, 4, 3 == 4 : %x", getbits(0xB0, 4, 3));
	return 0;
}

unsigned int getbits(unsigned int x, int p, int n)
{
	return (x >> (1 + p - n) ) & ~(~0 << n);
}