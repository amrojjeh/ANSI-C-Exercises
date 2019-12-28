#include <stdio.h>

// Returns x with the n bits that begin at position p inverted, leaving others unchanged
unsigned int invert(unsigned int x, int p, int n);
unsigned int setbits(unsigned int x, int p, int n, int y);
unsigned int getbits(unsigned int x, int p, int n);

int main()
{
	printf("0xAB, 7, 8 == 0x54 : %x\n", invert(0xAB, 7, 8));
	printf("0xAB, 3, 2 == 0xA7 : %x\n", invert(0xAB, 3, 2));
	printf("5, 0, 1 == 4 : %x\n", invert(5, 0, 1));

	return 0;
}

unsigned int invert(unsigned int x, int p, int n)
{
	return setbits(x, p, n, ~getbits(x, p, n));
}

unsigned int setbits(unsigned int x, int p, int n, int y)
{
	int l = p - n + 1;
	return ((((x >> l) & (~0 << n)) | (y & ~(~0 << n))) << l) | (x & ~(~0 << l));
}

unsigned int getbits(unsigned int x, int p, int n)
{
	return (x >> (1 + p - n) ) & ~(~0 << n);
}