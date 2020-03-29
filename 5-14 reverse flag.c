#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLINES 5000

int readlines(char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines);

void mqsort(char** lineptr, int left, int right, int reverse, int (*comp)(void*, void*));
int numcmp(char*, char *);

int printHelp(char* programName, int return_code);

int main(int argc, char* argv[])
{
	char* lineptr[MAXLINES];
	int nlines;
	int numeric = 0;
	int reverse = 0;

	while (argc-- > 1)
	{
		if (strcmp(argv[argc], "-n") == 0)
			numeric = 1;
		else if (strcmp(argv[argc], "-r") == 0)
			reverse = 1;
		else if (strcmp(argv[argc], "-h") == 0)
			return printHelp(argv[0], EXIT_SUCCESS);
		else return printHelp(argv[0], EXIT_FAILURE);
	}
	
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		mqsort((void*) lineptr, 0, nlines - 1, reverse, (int (*)(void*,void*))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return EXIT_SUCCESS;
	}

	printf("Input too big to sort\n");
	return EXIT_FAILURE;
}

int numcmp(char *s1, char *s2)
{
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void mqsort(char** v, int left, int right, int reverse, int (*comp)(void*, void*))
{
	int i, last;
	void swap(void *v[], int, int);
	if (left >= right) // Do nothing if array contains fewer than two elements
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; ++i)
		if (reverse)
		{
			if ((*comp)(v[i], v[left]) < 0)
				swap(v, ++last, i);
		}
		else
			if ((*comp)(v[i], v[left]) > 0)
				swap(v, ++last, i);
	swap(v, left, last);
	mqsort(v, left, last - 1, reverse, comp);
	mqsort(v, left, last - 1, reverse, comp);
}

void swap(void *v[], int x, int y)
{
	void* temp = v[x];
	v[x] = v[y];
	v[y] = temp;
}

int printHelp(char* programName, int return_code)
{
	printf("Sorts lines.\n\n");
	printf("\t%s [-n] [-r] [-h]\n\n", programName);
	printf("\t-n\t\tSort based on the first character, numerically\n");
	printf("\t-r\t\tReverse sort\n");
	printf("\t-h\t\tGive this help menu\n");

	return return_code;
}

char buffer[MAXLINES];
char* nextAvailableCharacter = buffer;

int readlines(char* lineptr[], int nlines)
{
	int x;
	for (x = 0; x < nlines && nextAvailableCharacter < buffer + MAXLINES; ++x)
	{
		int c;
		lineptr[x] = nextAvailableCharacter;
		while ((c = getchar()) != '\n' && c != EOF && nextAvailableCharacter < buffer + MAXLINES)
			*nextAvailableCharacter++ = c;
		*nextAvailableCharacter++ = 0;

		if (c == EOF) break;
	}
	return x;
}

void writelines(char* lineptr[], int nlines)
{
	while (nlines-- > 0) printf("%s\n", lineptr[nlines]);
}
