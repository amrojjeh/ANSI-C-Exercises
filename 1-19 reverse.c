#include <stdio.h>
#define MAX_LINE 1000

void reverse(char s[], int length);
int mgetline(char s[], int maxLength);

int main()
{
	char line[MAX_LINE];
	int length;
	while(length = mgetline(line, MAX_LINE))
	{
		reverse(line, length);
		printf("%s", line);
	}
}

void reverse(char s[], int length)
{
	char old[MAX_LINE];
	for (int x = 0; x <= length; x++) // copy string
	{
		old[x] = s[x];
	}
	
	for (int x = length - 2; x >= 0; --x) // We subtract two because we don't want to touch the zero and the newline
	{
		s[-x + length - 2] = old[x]; // Also, we can do that without causing any bugs because the reversed string should still remain the same size
	}
}

int mgetline(char s[], int maxLength)
{
	int c;
	int length;
	for (length = 0; length < maxLength && (c = getchar()) != '\n' && c != EOF; ++length) s[length] = c;
	
	if (c == '\n')
	{
		s[length] = '\n';
		++length;
	}
	
	s[length] = 0;
	return length;
}
