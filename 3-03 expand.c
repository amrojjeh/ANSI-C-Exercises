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
	printf("'a-z' -> abcdef...z : %s", s1);

	expand(s1, "d-f");
	printf("'d-f' -> df : %s", s1);

	expand(s1, "0-9 A-Z a-z");
	printf("'0-9 A-Z a-z' -> 0123...9 ABC...Z abc..z : %s", s1);

	expand(s1, "A-z");
	printf("'A-z' -> ABC...z : %s", s1); // The list should skip all the symbols and just print out letters

	// Testing illogical statements
	expand(s1, "z-a");
	printf("'z-a' -> z-a : %s", s1);

	expand(s1, "4-3, B-C, z-x");
	printf("'4-3, B-C, z-x' -> 4-3, BC, z-x : %s", s1);


	// Testing weird formats
	expand(s1, "-a-b");
	printf("'-a-b' -> -ab : %s", s1);

	expand(s1, "a-b-c");
	printf("'a-b-c' -> ab-c : %s", s1);

	expand(s1, "a-z0-9A-Z");
	printf("'a-z0-9A-Z' -> abc...z012...9ABC...Z : %s", s1);
}

void expand(char s1[], char s2[])
{
	
}