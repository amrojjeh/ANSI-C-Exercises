#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int* pmonth, int* pday);

int main()
{
	printf("%d\n", day_of_year(-123, 2, 29));
	printf("%d\n", day_of_year(123, -2, 29));
	printf("%d\n", day_of_year(123, 2, 31));
	printf("%d\n", day_of_year(2020, 2, 29));
	int month;
	int day;
	month_day(2000, 366, &month, &day);
	printf("%d %d\n", month, day);
	month_day(2000, 31 + 29, &month, &day);
	printf("%d %d\n", month, day);
	month_day(2001, 31 + 29, &month, &day);
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
	char *base = *daytab;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (leap) base += 13;

	if (month > 12 || month < 1 || year < 1 || day > *(base + month)|| day < 1) return -1;

	base += 1;

	while (--month > 0) day += *base++;
	return day;
}

void month_day(int year, int yearday, int* pmonth, int* pday)
{
	int i, leap;
	char* base = *daytab;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (leap) base += 13;

	if (year < 1 || yearday > 365 || yearday < 1)
	{
		*pmonth = -1;
		*pday = -1;
		return;
	}

	base += 1;
	while (yearday > *base)
		yearday -= *base++;

	*pmonth = base - *daytab - (leap ? 13 : 0);
	*pday = yearday;
}
