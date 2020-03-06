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
	int starting = 0;
	int N = 4;
	
	char line[MAXLINE];
	int length = 0;
	int spacesLeft = 0;
	
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
					printf("Usage: detab -m +n");
					return -1;
			}	
	
	while (starting-- > 0) line[length++] = getchar();

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
