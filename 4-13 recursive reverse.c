#include <stdio.h>

void reverse(char s[]);
void reverseLen(char s[], int i, int len);
void swap(char s[], int i, int j);

int main()
{
	char s[] = "te";
	char s1[] = "racecar";
	char s2[] = "Reverse this";
	
	reverse(s);
	reverse(s1);
	reverse(s2);

	printf("s:%s\ns1:%s\ns2:%s\n", s, s1, s2);
}

void reverse(char s[])
{
	int len = 0;
	while (s[len++] != 0);
	--len;
	reverseLen(s, 0, len - 1);
}

// I used a helper, but I couldn't help it!
void reverseLen(char s[], int i, int j)
{
	if (j <= i)
		return;
	
	swap(s, i, j);
	reverseLen(s, i + 1, j - 1);
}

void swap(char s[], int i, int j)
{
	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}