#include <stdio.h>
#include <stdlib.h> // for atof
#include <ctype.h>
#include <math.h>

// Well, I don't think there's anything wrong.

#define MAXOP 1000
#define NUMBER '0'
#define VARIABLES 100
int getop(char []); // Gets next number or operator and returns the type
void push(double);
double pop(void);
double seek(void); // Seeks the top element without popping it
void duplicate(void); // Duplicates the top two elements
void clear(void); // Clears the stack
void swap(void);

int main()
{
	int type;
	double op2;
	char s[MAXOP];
	double vars[VARIABLES];
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
		case '\n': // Seeks and stores last printed double
			double val = seek();
			printf("%g\n", val);
			vars[0] = val;
			break;
		case '!': // Duplicate
			duplicate();
			break;
		case 'w': // Swaps
			swap();
			break;
		case 'c':
			clear();
			break;
		case 's': // sin
			push(sin(pop()));
			break;
		case 'e': // exp
			push(exp(pop()));
			break;
		case '^': // power
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case 'v': // Reads a variable
			push(vars[(int)pop()]);
			break;
		case 'a': // Assign
			int i = pop();
			// 0 is restricted
			if (i >= VARIABLES || i < 1)
			{
				printf("error: variable index is too high or too low\n");
				break;
			}
			vars[i] = pop();
			push(vars[i]);
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

double seek(void)
{
	if (sp > 0)
		return val[sp - 1];
	printf("seek: stack is empty, couldn't seek\n");
	return 0.0;
}

void duplicate(void)
{
	if (sp > 0)
		push(seek());
	else
		printf("duplicate: stack is empty, couldn't duplicate");
}

void clear(void)
{
	sp = 0;
}

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


void swap(void)
{
	if (sp > 1)
	{
		double second = pop();
		double first= pop();
		push(second);
		push(first);
	}
	else printf("swap: couldn't swap, there are less than two elements\n");
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

char buffer = 0;

int getch(void)
{
	if (!buffer) return getchar();
	char temp = buffer;
	buffer = 0;
	return temp;
}

void ungetch(int c)
{
	buffer = c;
}