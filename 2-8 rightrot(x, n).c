#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);

int main()
{
	printf("4, 0 == 4 : %x\n", rightrot(4, 0));
	printf("4, 2 == 1 : %x\n", rightrot(4, 2));
	printf("5, 2 == 0x40000001 : %x\n", rightrot(5, 2));
	printf("0xFF, 16 == 0xFF0000 : %x\n", rightrot(0xFF, 16));
	printf("0xFFFFFFFF, 23 == 0xFFFFFFFF : %x\n", rightrot(0xFFFFFFFF, 23));
	return 0;
}

unsigned int rightrot(unsigned int x, int n)
{
	// 0111 1111 -> ROTATE ONCE RIGHT -> 1011 1111
	return ((x & ~(~0 << n)) << (32 - n)) | (x >> n);
}