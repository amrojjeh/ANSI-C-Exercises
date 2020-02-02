#define MAXVAL 100

static int sp = 0;
static double val[MAXVAL];

double seek(void)
{
	if (sp > 0)
		return val[sp - 1];
	printf("seek: stack is empty, couldn't seek\n");
	return 0.0;
}

void push(double n)
{
	sp < MAXVAL ? val[sp++] = n : printf("error: stack is full, can't push %g", n);
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
