/* Input and Output:
This	is	a	test
This    is  a   test
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINE 1000

int mgetline(char s[], int maxLine);

int main(int argc, char* argv[])
{
	int N = 4;
	char line[MAXLINE];
	int length = 0;
	int spacesLeft = 0;
	
	if (argc > 1 && isdigit(argv[1][0]))
		N = atoi(argv[1]);
	
	for (int c; (c = getchar()) != EOF;)
	{
		if (c != '\t')
		{
			line[length++] = c;
			++spacesLeft;
		}
		else
		{
			for (; spacesLeft < N; ++spacesLeft)
				line[length++] = ' ';
			spacesLeft = 0;
		}
		if (spacesLeft == N) spacesLeft = 0;
	}
	line[length] = 0;
	printf("%s", line);
}
