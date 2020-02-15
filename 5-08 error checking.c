#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int* pmonth, int* pday);

int main()
{
	printf("%d\n", day_of_year(-123, 2, 29));
	printf("%d\n", day_of_year(123, -2, 29));
	printf("%d\n", day_of_year(123, 2, 31));
	int month;
	int day;
	month_day(2000, 366, &month, &day);
	printf("%d %d\n", month, day);
	return 0;
}

static char daytab[2][13] = 
{
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	if (month > 12 || month < 1 || year < 1 || day > daytab[leap][month] || day < 1) return -1;

	for (i = 1; i < month; ++i)
		day += daytab[leap][i];
	return day;
}

void month_day(int year, int yearday, int* pmonth, int* pday)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	if (year < 1 || yearday > 365 || yearday < 1)
	{
		*pmonth = -1;
		*pday = -1;
		return;
	}

	for (i = 1; yearday > daytab[leap][i]; ++i)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
