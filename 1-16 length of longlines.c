#include <stdio.h>
#define MAXLINE 1000
#define LONGLINE 120 // An arbitrary chosen number that is used to classify long lines

int my_getline(char line[], int maxline);

int main()
{
	int len = 0; // Current length
	char currentLine[MAXLINE]; // The current line being read

	while ((len = my_getline(currentLine, MAXLINE)) > 0)
	{
		if (len >= LONGLINE)
		{
			printf("L%d : %s", len, currentLine);
		}
	}
	return 0;
}


// Gets the next line and returns its length
int my_getline(char line[], int maxline)
{
	char c;
	int length;

	for (length = 0; length < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++length) line[length] = c;
	
	if (c == '\n')
	{
		line[length] = c;
		++length;
	}

	line[length] = 0;
	return length;
}
