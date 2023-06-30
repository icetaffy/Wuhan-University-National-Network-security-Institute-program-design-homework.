#include<stdio.h>
int weekday_judge(int,int,int);
int main(void)
{
	int year, month, k,days = 1;
	printf("请输入您要查询几年几月的万年历:\n");
	scanf_s("%d %d", &year, &month);
	if (year < 1900 || month < 1 || month>12)
	{
		printf("年份日期输入错误!\n");
		return 0;
	}
	printf("%d年%d月的万年历如下:\n", year, month);
	printf("                %d年%d月\n",year,month);
	printf("MON TUE WED THU FRI SAT SUN\n");
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			{
				for (k = 0; k < weekday_judge(year, month, 1) - 1; k++)
					printf("    ");
				for (days = 1; days <= 31; days++)
				{
					printf("%-2d  ", days);
					if (weekday_judge(year, month, days) == 7)
						printf("\n");
				}
			}
			if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				for (k = 0; k < weekday_judge(year, month, 1) - 1; k++)
					printf("    ");
				for (days = 1; days <= 30; days++)
				{
					printf("%-2d  ", days);
					if (weekday_judge(year, month, days) == 7)
						printf("\n");
				}
			}
			if (month == 2)
			{
				if (year%400==0)
				{
					for (k = 0; k < weekday_judge(year, month, 1) - 1; k++)
						printf("    ");
					for (days = 1; days <= 29; days++)
					{
						printf("%-2d  ", days);
						if (weekday_judge(year, month, days) == 7)
							printf("\n");
					}
				}
				else
				{
					for (k = 0; k < weekday_judge(year, month, 1) - 1; k++)
						printf("    ");
					for (days = 1; days <= 28; days++)
					{
						printf("%-2d  ", days);
						if (weekday_judge(year, month, days) == 7)
							printf("\n");
					}
				}
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
	else if (weekday== 1) {
		weekday = 7;
	}
	else
		weekday -= 1;
	return weekday;
}