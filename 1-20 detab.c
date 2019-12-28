/* Input and Output:
This	is	a	test
This    is  a   test
*/

#include <stdio.h>

#define N 4
#define MAXLINE 1000

int mgetline(char s[], int maxLine);

int main()
{
	char line[MAXLINE];
	int length = 0;
	int spacesLeft = 0;
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
		if (spacesLeft == 4) spacesLeft = 0;
	}
	line[length] = 0;
	printf("%s", line);
}