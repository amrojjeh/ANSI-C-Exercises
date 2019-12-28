#include <stdio.h>

int any(char s1[], char s2[]); // Returns the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2

int main()
{
	printf("This is a test | it == 2 : %d\n", any("This is a test", "it"));
	printf("This is a test | ti == 2 : %d\n", any("This is a test", "ti"));
	printf("This is a test | Tt == 0 : %d\n", any("This is a test", "Tt"));
	printf("This is a test | z == -1 : %d\n", any("This is a test", "z"));
	printf("This is a test | ' ' == 4 : %d\n", any("This is a test", " "));

	return 0;
}


int any(char s1[], char s2[])
{
	for (int i = 0; s1[i] != 0; ++i)
		for (int x = 0; s2[x] != 0; ++x)
			if (s1[i] == s2[x]) return i;
	return -1;
}