/* Example input and output
              
			  
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 1000

void addChar(int spaces, int alpha);

int main(int argc, char* argv[])
{
	int N = 4; // tab size
	if (argc > 1)
		if (isdigit(argv[1][0])) // isdigit will also prevent negatives
			N = atoi(argv[1]);
		else
		{
			printf("Usage: entab [+tab_size]");
			return -1;
		}
		
	int padding = 0;
	int spaces = 0; // consecutive spaces

	for (int c = 0; (c = getchar()) != EOF &&  c != 0;)
	{
		padding = ++padding % N;
		if (c == ' ') ++spaces;

		if (spaces > 0 && padding == 0)
		{
			spaces = 0;
			putchar('\t');
		}

		if (c == '\t')
		{
			padding = -1;
			addChar(spaces, ' ');
			spaces = 0;
			putchar(c);
		}
		
		else if (c != '\t' && c != ' ')
		{
			addChar(spaces, ' ');
			spaces = 0;
			putchar(c);
		}
	}
}

void addChar(int spaces, int alpha)
{
	for (; spaces > 0; --spaces) putchar(alpha);
}