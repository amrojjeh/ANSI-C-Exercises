/*
	When subtracting one from an integer, what was the right most 1 bit becomes 0. For example:
	1100 = C
	-1    -1
	1011 = B
	While there were two new bits created from the subtraction, what was the right most 1 bit is now 0.
	All that's left to do is to AND it with its previous self, which would remove the new 1 bits created.
	Therefore, x &= (x - 1) removes the right most 1 bit.
*/

#include <stdio.h>

int bitcount(unsigned int x);

int main()
{
	printf("0xB : 3 == %d\n", bitcount(0xB));
	printf("0xC : 2 == %d\n", bitcount(0xC));
	printf("0xA : 2 == %d\n", bitcount(0xA));
	printf("0xFF : 8 == %d\n", bitcount(0xFF));
	printf("-1 : 32 == %d\n", bitcount(-1));
}

int bitcount(unsigned int x)
{
	int b;

	for (b = 0; x != 0; x &= x - 1) ++b;
	return b;
}

/*
int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 1) ++b;
	return b;
}
*/
