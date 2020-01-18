#include <stdio.h>
#include <stdlib.h> // for atof
#include <ctype.h>

#define MAXOP 1000
#define NUMBER '0'

int getop(char []); // Gets next number or operator and returns the type
void push(double);
double pop(void);

int main()
{
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF)
		switch (type)
		{
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			push(pop() - op2);
			break;
		case '%': // Adding mod
			op2 = pop();
			push((int)pop() - (int)op2);
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	printf("%g", pop());
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double n)
{
	sp < MAXVAL ? val[sp++] = n : printf("error: stack is full, can't push %g", n);
}

double pop(void)
{
	if (sp == 0)
	{
		printf("error: stack is empty, can't pop");
		return 0.0;
	}
	return val[--sp];
}


int getch(void);
void ungetch(int);

// Negative sign is ~
int getop(char s[])
{
	int i, c, sign;

	while ((s[0] = c = getch()) == ' ' || c == '\t'); // Trim whitespace
	s[1] = 0;

	if (!isdigit(c) && c != '.' && c != '~') return c; // not a number
	
	i = 0;

	if (c == '~')
	{
		s[i] = '-';
		s[++i] = c = getchar();
	}
	
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()));

	if (c == '.')
		while (isdigit(s[++i] = c = getch()));
	
	s[i] = 0;

	if (c != EOF) ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buffer[BUFSIZE];
int bp = 0; // Next free position

int getch(void)
{
	return bp > 0 ? buffer[--bp] : getchar();
}

void ungetch(int c)
{
	if (bp < BUFSIZE) buffer[bp++] = c;
	else printf("ungetch: too many characters\n");
}