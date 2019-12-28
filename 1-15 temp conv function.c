// Fahrenhite -> Celcius
#include <stdio.h>

#define LOWER 0.0
#define STEP 20.0
#define UPPER 300.0

float FtoC(float F);

int main()
{
	printf("Far Celsius\n=== =======\n");
	for (float far = LOWER; far <= UPPER; far += STEP)
	{
		float c = FtoC(far);
		printf("%3.0f %6.1f\n", far, c);
	}
}

float FtoC(float F)
{
	return 5.0/9.0 * (F - 32);
}
