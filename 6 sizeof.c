#include <stdio.h>

int main()
{
	struct yo
	{
		int test;
		char wow;
	};
	printf("%d\n", sizeof (struct yo));
}