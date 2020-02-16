#include <stdio.h>
#include <stdlib.h>

void push(double n);
double pop();

int main(int argc, char* argv[])
{
	if (argc == 1)
		printf("Usage: expr expression\n");
	while ((*++argv) != 0)
	{
		int c = (*argv)[0];
		double n1;
		double num;
		switch(c)
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				num = atof(*argv);
				push(num);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				n1 = pop();
				push(pop() - n1);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				n1 = pop();
				push(pop() / n1);
				break;
			default:
				printf("Illegal: unkown operator");
				return;
		}
	}
	printf("%g\n", pop());
}

#define MAXBUF 1000

double stack[MAXBUF];
double* stackptr = stack; // First available space

void push(double n)
{
	*stackptr++ = n;
}

double pop()
{
	return *--stackptr;
}
