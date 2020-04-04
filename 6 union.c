#include <stdio.h>

int main()
{
	union test
	{
		int x;
		char y;
	} u;
	u.x = 3;
	u.y = 'a';
	printf("%d\n", u.x); // 97
}
