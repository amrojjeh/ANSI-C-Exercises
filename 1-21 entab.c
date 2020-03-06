/* Example input and output
              
			  
*/

#include <stdio.h>

#define MAXLINE 1000
#define N 4

int mgetline(char line[], int max);

int main()
{
	char line[MAXLINE];
	char newline[MAXLINE];
	int index = 0;
	int length = mgetline(line, MAXLINE);
	while (length != 0)
	{
		if (length >= N)
		{
			newline[index++] = '\t';
			length -= N;
		}
		else
		{
			newline[index++] = ' ';
			--length;
		}
	}
	newline[index] = 0;
	printf("%s\n", newline);
}

int mgetline(char line[], int max) // gets line without newline
{
	int i = 0;
	for (int c = 0; (c = getchar()) != EOF && c != '\n' && i < MAXLINE; ++i) line[i] = c;
	return i;
}
