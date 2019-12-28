// Horizontal Histogram

#include <stdio.h>

#define IN 1
#define OUT 0

#define MAX_WORD_SIZE 50
#define INTERVAL 5
#define BARS (MAX_WORD_SIZE/INTERVAL)

// This program is assuming that MAX_WORD_SIZE is dividing evenly with INTERVAL
// If they don't divide evenly, then the histogram will be one bar short
// (Example : 51/5 = 10 bars, 11 is needed), (49/5 = 9 bars, 10 is needed)
int main()
{
	int length_by_interval[BARS], state, currentLength;
	currentLength = 0;
	state = OUT;

	// Clear the list
	for (int x = 0; x < BARS; x++) length_by_interval[x] = 0;

	// Get lengths of words
	for (int c; (c = getchar()) != EOF;)
	{
		if (state == IN && (c == '\t' || c == '\n' || c == ' '))
		{
			state = OUT;
			++length_by_interval[(currentLength - 1)/INTERVAL];
			currentLength = 0;
		}
		else
		{
			state = IN;
			++currentLength;
		}
	}

	// Print horizontal histogram
	printf("The interval is %d\n", INTERVAL);
	for (int x = 0; x < BARS; x++)
	{
		printf("%d-%d\t", INTERVAL*x + 1, x*INTERVAL + INTERVAL);
		for (int y = 0; y < length_by_interval[x]; ++y) putchar('#');
		putchar('\n');
	}
}
