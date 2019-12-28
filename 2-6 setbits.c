#include <stdio.h>

// returns x with the n bits that begin at position p set to the right most n bits of y, leaving other bits unchanged.
// Example : setbits(0xB0, 4, 3, 0xC0) : 101 100 00 | 1100 0000 -> 101 000 00
unsigned int setbits(unsigned int x, int p, int n, int y);

int main()
{
	printf("0xB0, 4, 3, 0xC0 == 0xA0 : %x\n", setbits(0xB0, 4, 3, 0xC0));
	printf("0xB0, 7, 3, 0x3 == 0x70 : %x\n", setbits(0xB0, 7, 3, 0x3));
	printf("0xABCD, 10, 5, 0xCD == 0xAB4D : %x\n", setbits(0xABCD, 10, 5, 0xCD));
	printf("0x0, 0, 1, 0xB == 0x1 : %x\n", setbits(0x0, 0, 1, 0xB));
	return 0;
}

unsigned int setbits(unsigned int x, int p, int n, int y)
{
	// 0xCB, 5, 3, 0x25: 1100 1011 | 0010 0101 -> 1110 1011 (0xEB)
	// 1100 1011 >> 3(l) = 0001 1001
	// 0001 1001 & (~0 << 3(n)) = 0001 1000
	// 0001 1000 | (0010 0101 & ~(~0 << 3(n))) = 0001 1101
	// 0001 1101 << 3(l) = 1110 1000
	// 1110 1000 | (1100 1011 & ~(~0 << 3)) = 1110 1011
	// 1110 1011
	
	int l = p - n + 1; // Location of first bit
	return ((((x >> l) & (~0 << n)) | (y & ~(~0 << n))) << l) | (x & ~(~0 << l));
	// This isn't a neat solution. I think the neater solution would be to clear the bitfield with the AND operator then OR it to set the new bits.

}