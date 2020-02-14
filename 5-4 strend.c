#include <stdio.h>

void tprint(char* s, char* p, int expected);
int strend(char* s, char* t);
int len(char *s);
void reverse(char* s);

#define MAX 1000

int main()
{
	tprint("This is a test", "test", 1);
	tprint("This test is a", "test", 0);
	tprint("", "", 1);
	tprint("Cool", "ol", 1);
	tprint("baba", "ba", 1);
	tprint("baabaaba", "baaba", 1);
	tprint("test", "test", 1);
	tprint("te", "test", 0);
	tprint("Hell", "no", 0);

	return 0;
}

// Test print
void tprint(char* s,  char* p, int expected)
{
	printf("%s, %s, %d : %d\n", s, p, expected, strend(s, p));
}

int strend(char* s, char* t)
{
	int ls = len(s);
	int lt = len(t);
	while(lt > -1 && ls > -1 && s[ls-- - 1] == t[lt-- - 1]);
	if (lt < 0) return 1;
	return 0;
}

int len(char* s)
{
	int l;
	for (l = 0; *s++; ++l);
	return l;
}