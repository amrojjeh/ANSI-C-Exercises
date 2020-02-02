#include <stdio.h>
#include <stdlib.h> // for atof
#include <math.h>
#include "calc.h"

#define MAXOP 1000
#define VARIABLES 100


int main()
{
	int type;
	double op2;
	char s[MAXOP];
	double vars[VARIABLES];

	for (int i = 0; i < VARIABLES; ++i) vars[i] = 0;

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
		case 'p': // Seeks and stores last printed double
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
