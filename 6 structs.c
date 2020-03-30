#include <stdio.h>

struct test
{
	int wow;
	char amazing;
};

int main()
{
	struct test thing = {4, 'a'};
	// thing is not a pointer, but when printed it prints 4, even though it's also of not type int.
	// Hmmmmmm

	// SOLVED: With vardiac arguments, structures are broken down into their members
	printf("%d %c\n", thing, *(((char*)&thing) + 4));
}
