#include <stdio.h>

#define NUM_OF_PRINTABLE_CHARACTERS 96 // Including the SPACE key, which is the first printable character in the list
#define NUM_OF_SPECIAL_CHARACTERS 2
#define NEWLINE 0
#define TAB 1

int main()
{
	int total_letters, letters[NUM_OF_PRINTABLE_CHARACTERS + NUM_OF_SPECIAL_CHARACTERS];
	total_letters = 0;

	// Clear array
	for (int x = 0; x < NUM_OF_PRINTABLE_CHARACTERS + NUM_OF_SPECIAL_CHARACTERS; ++x) letters[x] = 0;

	for (int c; (c = getchar()) != EOF;)
	{
		if (c == '\n') ++letters[NEWLINE];
		else if (c == '\t') ++letters[TAB];
		else ++letters[c - '!' + NUM_OF_SPECIAL_CHARACTERS];
		++total_letters;
	}

	// Print histogram
	for (int x = 0; x < NUM_OF_PRINTABLE_CHARACTERS + NUM_OF_SPECIAL_CHARACTERS; ++x)
	{
		if (x == TAB) printf("Tab:\t");
		else if (x == NEWLINE) printf("NL :\t");
		else  printf("%c :\t", x + 30);
		for (int y = 0; y < letters[x] * (100/total_letters); ++y) putchar('#');
		putchar('\n');
	}
}
