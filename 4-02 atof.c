#include <stdio.h>
#include <ctype.h>

float atof(char s[]);

int main()
{
	printf("430.23 : %f\n", atof("430.23"));
	printf("-43023e-2 : %f\n", atof("43023e-2"));
	printf("-1e8 : %f\n", atof("-1e8"));
	printf("    1000e0 : %f\n", atof("    1000e0"));
	printf("    1000e-0  : %f\n", atof("    1000e-0 "));
	printf("1.3e2 : %f\n", atof("1.3e2"));
	printf("132 : %f", atof("132"));
}

float atof(char s[])
{
	float val, power, powere;
	int i, sign, e, signe;

	for (i = 0; isspace(s[i]); ++i); // skip white space
	
	sign = (s[i] == '-' ? -1 : 1);
	if (s[i] == '-' || s[i] == '+') ++i;

	for (val = 0.0; isdigit(s[i]); ++i) // whole numbers
		val = val * 10 + s[i] - '0';

	if (s[i] == '.') ++i; // Skip decimal point, if it's something else second loop won't proceed

	for (power = 1.0; isdigit(s[i]); ++i) // fraction
	{
		val = val * 10 + s[i] - '0';
		power *= 10;
	}

	if (s[i] == 'e') ++i;

	signe = s[i] == '-' ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') ++i;

	for (e = 0; isdigit(s[i]); ++i) e = e * 10 + s[i] - '0'; // Calculate e
	for (powere = 1.0; e != 0; --e) powere *= 10; // Convert e to powere

	if (signe == 1) return sign * val * powere / power;

	return sign * val/ (power * powere);
}
