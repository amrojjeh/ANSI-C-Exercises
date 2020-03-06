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
	int starting = 0;
	
	if (argc > 1)
		while (--argc != 0)
			switch (argv[argc][0])
			{
				case '+':
					N = atoi(argv[argc] + 1);
					break;
				case '-':
					starting = atoi(argv[argc] + 1);
					break;
				default:
					printf("Usage: entab -m +n");
					return -1;
			}	
		
	int padding = 0;
	int spaces = 0; // consecutive spaces

	while (starting-- > 0) getchar();

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
