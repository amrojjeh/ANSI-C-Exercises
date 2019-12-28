#include <stdio.h>

int main()
{
	int blanks, tabs, newlines, c;
	blanks = tabs = newlines = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ') ++blanks;
		if (c == '\t') ++tabs;
		if (c == '\n') ++newlines;
	}
	printf("=================\n");
	printf("Blanks : %d\nTabs : %d\nNew Lines : %d\n", blanks, tabs, newlines);
}
