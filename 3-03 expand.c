#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 1000

/* Expands abbreviations such as a-z, c-z, A-Z, and 0-9.
It will ignore abbreviations that logically don't make sense, leading or traing hyphens, and ranges like a-b-c.
The result will be copied to s1
*/
void expand(char s1[], char s2[]);

int main() 
{
	char s1[MAX_SIZE];

	// Testing correct statements
	expand(s1, "a-z");
	printf("'a-z' -> abcdef...z : %s\n", s1);

	expand(s1, "d-f");
	printf("'d-f' -> def : %s\n", s1);

	expand(s1, "0-9 A-Z a-z");
	printf("'0-9 A-Z a-z' -> 0123...9 ABC...Z abc..z : %s\n", s1);

	expand(s1, "A-z");
	printf("'A-z' -> ABC...z : %s\n", s1); // The list should skip all the symbols and just print out letters

	// Testing illogical statements
	expand(s1, "z-a");
	printf("'z-a' -> z-a : %s\n", s1);

	expand(s1, "4-3, B-C, z-x");
	printf("'4-3, B-C, z-x' -> 4-3, BC, z-x : %s\n", s1);


	// Testing weird formats
	expand(s1, "-a-b");
	printf("'-a-b' -> -ab : %s\n", s1);

	expand(s1, "------a-c");
	printf("'------a-c' -> ------abc : %s\n", s1);

	expand(s1, "a-b-c");
	printf("'a-b-c' -> ab-c : %s\n", s1);

	expand(s1, "a-z0-9A-Z");
	printf("'a-z0-9A-Z' -> abc...z012...9ABC...Z : %s\n", s1);
}

void expand(char s1[], char s2[])
{
	// x is the current index of s1, while j is the current index for s2
	// x will be either the same or larger than j at all times
	int x, j;
	
	s1[0] = s2[0]; // First character is always copied

	for (x = j = 1; s2[j] != 0; ++j)
	{
		char prevc = s2[j - 1];
		char nextc = s2[j + 1];
		
		if (s2[j] == '-' && prevc < nextc && ((isdigit(prevc) && isdigit(nextc)) || (isalpha(prevc) && isalpha(nextc))))
		{
			// Digit range?
			if (isdigit(prevc) && isdigit(nextc))
				// Skip the first and last character of the range since they will/already been copied
				for (int n = prevc + 1; n <= nextc - 1; ++n)
					s1[x++] = n;
			
			// Character range?
			else if (isalpha(prevc) && isalpha(nextc))
				for (int n = prevc + 1; n <= nextc - 1; ++n)
					if (isalpha(n)) s1[x++] = n;
		}
		else s1[x++] = s2[j];
	}
	s1[x] = 0;
}