#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

char* lineptr[MAXLINES];

void qsort(char* v[], int left, int right);
int readlines(char* lineptr[], int maxlines, char buffer[], int size);
void writelines(char* lineptr[], int nlines);

int main()
{
	int nlines;
	char buffer[MAXLINES];
	if ((nlines = readlines(lineptr, MAXLINES, buffer, MAXLINES)) >= 0)
	{
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else 
	{
		printf("error: input too big to sort\n");
		return 1;
	}

	return 0;
}

int getline(char*, int max);
char* alloc(int);

int readlines(char* lineptr[], int maxlines, char buffer[], int size)
{
	int len, nlines;
	char *p, line[MAXLEN];
	p = buffer;

	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0)
	{
		if (nlines >= maxlines && p + len < buffer + size)
			return -1;
		line[len] = 0;
		strcpy(p, line);
		lineptr[nlines++] = p;
		p += len + 1;
	}
	return nlines;
}

void writelines(char* lineptr[], int nlines)
{
	while (nlines-- > 0) printf("%s\n", *lineptr++);
}

void qsort(char* v[], int left, int right)
{
	int i, last;
	void swap(char* v[], int i, int j);

	if (left >= right) return;

	swap(v, left, (left + right) / 2);
	last = left;
	for (int i = left + 1; i <= right; ++i)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}


int getline(char* s, int max)
{
	int length = 0, c;
	for (c = 0; (c = getchar()) != EOF && c != '\n' && c != 0 && length <= max; *s++ = c) ++length;
	*s = 0;
	return length;
}


void swap(char* v[], int i, int j)
{
	char* temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
