#include <stdio.h>

void tprint(char* buffer, char* s, char* p);
void strcat(char* s, char* p);
void strcpy(char* s, char* p);

#define MAX 1000

int main()
{
	char buffer[MAX];
	tprint(buffer, "This is a ", "test");
	tprint(buffer, "This i!!s a ", "wow");
	tprint(buffer, "This is a ", "gg");
	tprint(buffer, "", "wow");
	tprint(buffer, "wow", "");

	return 0;
}

// Test print
void tprint(char* buffer, char* s,  char* p)
{
	strcpy(buffer, s);
	strcat(buffer, p);

	printf("%s\n", buffer);
}


// Assumes s is large enough to hold len(s) + len(p) + 0
void strcat(char* s, char* p)
{
	while (*s++);
	--s;
	while (*s++ = *p++);
}

// Assumes s is large enough to hold len(s) + len(p) + 0
void strcpy(char* s, char* p)
{
	while (*s++ = *p++);
}
