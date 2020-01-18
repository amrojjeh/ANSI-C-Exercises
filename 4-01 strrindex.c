#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int strrindex(char s[], char t[]);

int main()
{
	char str[MAXLINE] = "test This is a test, yoooo!";
	
	printf("%d\n", strrindex(str, "test")); // Expected: 15
	return 0;
}

int strrindex(char s[], char t[])
{
	int x, j, k;

	int tlength = strlen(t);

	if (tlength == 0) return -1;

	for (x = strlen(s) - 1; x >= 0; --x)
	{
		for (j = x, k = tlength - 1; k >= 0 && t[k] == s[j]; --j, --k);
		if (k == -1)
			return x - tlength + 1;
	}
	return -1;
}