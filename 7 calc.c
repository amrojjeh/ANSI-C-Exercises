#include <stdio.h>

int main(int argc, char* argv[])
{
	double sum = 0, v;
	while (scanf("%lf", &v) == 1)
		printf("\t%.2f\n", sum += v);
	return 0;
}
