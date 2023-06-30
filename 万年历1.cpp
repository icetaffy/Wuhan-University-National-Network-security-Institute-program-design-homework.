#include<stdio.h>
int weekday_judge(int, int, int);
int main(void)
{
	int year, k, i, days = 1;
	printf("请输入您要查询的万年历的年份:\n");
	scanf_s("%d", &year);
	if (year < 1900)
	{
		printf("年份日期输入错误!\n");
		return 0;
	}
	printf("%d年的万年历如下:\n", year);
	for (i = 1; i <= 12; i++)
	{
		printf("      %d年\n", year);
		printf("      %d月\n", i);
		printf("MON TUE WED THU FRI SAT SUN\n");
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
		{
			for (k = 0; k < weekday_judge(year, i, 1) - 1; k++)
				printf("    ");
			for (days = 1; days <= 31; days++)
			{
				printf("%-2d  ", days);
				if (weekday_judge(year, i, days) == 7)
					printf("\n");
			}
		}
		if (i == 4 || i == 6 || i == 9 || i == 11)
		{
			for (k = 0; k < weekday_judge(year, i, 1) - 1; k++)
				printf("    ");
			for (days = 1; days <= 30; days++)
			{
				printf("%-2d  ", days);
				if (weekday_judge(year, i, days) == 7)
					printf("\n");
			}
		}
		if (i == 2)
		{
			if (year % 400 == 0)
			{
				for (k = 0; k < weekday_judge(year, i, 1) - 1; k++)
					printf("    ");
				for (days = 1; days <= 29; days++)
				{
					printf("%-2d  ", days);
					if (weekday_judge(year, i, days) == 7)
						printf("\n");
				}
			}
			else
			{
				for (k = 0; k < weekday_judge(year, i, 1) - 1; k++)
					printf("    ");
				for (days = 1; days <= 28; days++)
				{
					printf("%-2d  ", days);
					if (weekday_judge(year, i, days) == 7)
						printf("\n");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
int weekday_judge(int year, int month, int day)
{
	int q = day, j, k, m;
	if (month == 1) {
		m = 13;
		year -= 1;
	}
	else if (month == 2) {
		m = 14;
		year -= 1;
	}
	else
		m = month;
	j = year / 100;
	k = year % 100;
	int weekday = (q + 26 * (m + 1) / 10 + k + k / 4 + j / 4 + 5 * j) % 7;
	if (weekday == 0)
		weekday = 6;
	else if (weekday == 1) {
		weekday = 7;
	}
	else
		weekday -= 1;
	return weekday;
}