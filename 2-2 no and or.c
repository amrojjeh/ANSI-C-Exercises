#include <stdio.h>

int main()
{
	int lim;
	int c;
	for (int i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {/* Do stuff here */}
	// is equivelent to
	for (int i = 0; i < lim - 1; ++i)
		if ((c = getchar()) != '\n')
			if (c != EOF) {/* Do stuff here */}
	return 0;
}