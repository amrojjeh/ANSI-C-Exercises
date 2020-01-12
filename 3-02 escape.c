#include <stdio.h>
#define MAXLINE 1000

// Converts newline characters and such to their equivelent escape characters, then copies it to s.
void escape(char s[], char t[]);

// Converts escape characters to their equivelent characters, then copies it to s
void real(char s[], char t[]);


int main()
{
	char s[MAXLINE];
	char t[MAXLINE];

	// testing escape
	int c;
	int x = 0;
	while ((c = getchar()) != EOF && c != 0)
		t[x++] = c;
	t[x] = 0;

	escape(s, t);
	printf("%s\n", s);

	// testing real
	x = 0;
	while ((c = getchar()) != EOF && c != 0)
		t[x++] = c;
	t[x] = 0;
	
	real(s, t);
	printf("%s\n", s);
}

void escape(char s[], char t[])
{
	// x is index for s, while j is index for t
	// x will be larger or the same as j, but never less
	int x, j;
	for (x = j = 0; t[j] != 0; ++j)
	{
		switch (t[j])
		{
		case '\n':
			s[x++] = '\\';
			s[x++] = 'n';
			break;
		case '\t':
			s[x++] = '\\';
			s[x++] = 't';
			break;
		case '\\':
			s[x++] = '\\';
			s[x++] = '\\';
			break;
		default:
			s[x++] = t[j];
			break;
		}
	}
	s[x] = 0;
}

void real(char s[], char t[])
{
	int x, j;
	for (x = j = 0; t[j] != 0; ++j)
	{
		switch (t[j])
		{
		case '\\':
			switch (t[j + 1])
			{
			case 't':
				s[x++] = '\t';
				++j;
				break;
			case 'n':
				s[x++]= '\n';
				++j;
				break;
			case '\\':
				s[x++] = '\\';
				++j;
				break;
			default:
				s[x++] = t[j];
				break;
			}
			break;
		
		default:
			s[x++] = t[j];
			break;
		}
	}
	s[x] = 0;
}