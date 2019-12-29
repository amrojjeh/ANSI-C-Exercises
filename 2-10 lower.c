#include <stdio.h>

char lower(char letter);

int main()
{
	printf("lower('A') == 'a' : %c\n", lower('A'));
	printf("lower('B') == 'b' : %c\n", lower('B'));
	printf("lower('c') == 'c' : %c\n", lower('c'));
	printf("lower('Z') == 'z' : %c\n", lower('Z'));
	return 0;
}

char lower(char letter)
{
	return (letter <= 'Z' && letter >= 'A') ? letter - 'A' + 'a' : letter;
}