#include <stdio.h>

void tprintcat(char* buffer, char* s, char* p, int n);
void tprintcopy(char* buffer, char* s, char* p, int n);
void tprintcompare(char* buffer, char* s, char* p, int n);


void strcat(char* s, char* p);
void strcpy(char* s, char* p);
int strcmp(char* s, char* p);

void strncat(char* s, char* p, int n);
void strncpy(char* s, char* p, int n);
int strncmp(char* s, char* p, int n);

int len(char* s);

#define MAX 1000

int main()
{
	char buffer[MAX];
	// cat
	tprintcat(buffer, "This is a ", "test", 1);
	tprintcat(buffer, "This i!!s a ", "wow", 3);
	tprintcat(buffer, "This is a ", "gg", 1);
	tprintcat(buffer, "", "wow", 1);
	tprintcat(buffer, "wow", "", 1);
	tprintcat(buffer, "test", "No test", 0);
	
	// copy
	tprintcopy(buffer, "Well this doesn't really matter", "Loooooooool", 4);
	tprintcopy(buffer, "", "test", 4);
	tprintcopy(buffer, "", "test", 10);

	// // compare
	tprintcompare(buffer, "test mate", "test", 4);
	tprintcompare(buffer, "no this isn't true", "it's definitely not!", 10);
	tprintcompare(buffer, "bcdef", "abcdef", 1);

	return 0;
}

// Test print
void tprintcat(char* buffer, char* s,  char* p, int n)
{
	strcpy(buffer, s);
	strncat(buffer, p, n);

	printf("%s\n", buffer);
}

void tprintcopy(char* buffer, char* s, char* p, int n)
{
	strcpy(buffer, s);
	strncpy(buffer, p, n);

	printf("%s\n", buffer);
}

void tprintcompare(char* buffer, char* s, char* p, int n)
{
	strcpy(buffer, s);
	int t = strncmp(buffer, p, n);

	printf("%d\n", t);
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

int strcmp(char* s, char* p)
{
	for (; *s == *p; ++s, ++p)
		if (*s == 0)
			return 0;
	return *s - *p;
}

void strncat(char* s, char* p, int n)
{
	while (*s++);
	--s;
	while (n-- > 0  && (*s++ = *p++));
	*s = 0;
}

void strncpy(char* s, char* p, int n)
{
	while (n-- > 0 && (*s++ = *p++));
	*s = 0;
}

int strncmp(char* s, char* p, int n)
{
	for (;*s == *p && --n > 0; ++s, ++p)
		if (*s == 0)
			return 0;
	return *s - *p;
}

int len(char* s)
{
	int l;
	for (l = 0; *s++; ++l);
	return l;
}
