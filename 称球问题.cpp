#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int n, i, m, flag, fm;
	printf("请输入待称小球的个数：\n");
	scanf_s("%d", &n);
	printf("预设每个小球的质量和有问题小球的标号以及有问题小球的重量:\n");
	scanf_s("%d %d %d", &m, &flag,&fm);
	int* a = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		if (i == flag-1)
			a[i] = fm;
		else
			a[i] = m;
	}
	int sum1=0, sum2=0, sum3=0;
	for (i = 0; i < n / 3; i++)
	{
		sum1 = sum1 + a[i];
		sum2 = sum2 + a[i + 4];
		sum3 = sum3 + a[i + 8];
	}
	if (sum1==sum2)//第一次称出来第一组和第二组重量相等，说明在最后一组或者在最后一个球出问题
	{
		int C1, C2;
		C1 = a[n - 5] + a[n - 4];
		C2 = a[n - 3] + a[n - 2] + a[n - 1];
		if (C2==sum1*3/4)//第二次让C3组和正常组称重，相等则说明C1的两个球有问题。
		{
			if (a[n-5]==sum1/4)//第三次称重以9号球为基准的情况下，但是这种情况下就不能称出10号球的重量
			{
				printf("第%d个小球质量有问题，但是没办法得知轻重\n",n-3);
			}
			else if(a[n-5]>sum1/4)
			{
				printf("第%d个小球偏重\n", n - 4);
			}
			else
			{
				printf("第%d个小球偏轻\n", n - 4);
			}
		}
		else
		{
			if (C2 >sum1 * 3 / 4)
			{
				if (a[n - 1] == a[n - 2])
					printf("第%d个球偏重\n",n-2);
				else if(a[n-1]>a[n-2])
				{
					printf("第%d个小球偏重\n", n);
				}
				else
				{
					printf("第%d个小球偏重\n", n - 1);
				}
			}
			else
			{
				if (a[n - 1] == a[n - 2])
					printf("第%d个球偏轻\n", n-2);
				else if (a[n - 1] > a[n - 2])
				{
					printf("第%d个小球偏轻\n", n-1);
				}
				else
				{
					printf("第%d个小球偏轻\n", n);
				}
			}
		}
	}
	else//如果第一次称出来第一组和第二组质量不等的情况，还有两次称重次数
	{
		if (sum1 > sum2)//左边一组大于右边那组
		{
			int A1, A2, B1, B2;
			A1 = a[0];//把sum1组再分为四组，为A1和A2,B1和B2组，其中A1和B1分1个小球。A2和B2分3个小球
			A2 = a[1] + a[2] + a[3];
			B1 = a[4];
			B2 = a[5] + a[6] + a[7];
			sum1 = A1 + B2;
			sum2 = B1 + a[8] + a[9] + a[10];
			if (sum1 == sum2)//第二次称重，说明A2组偏重
			{
				if (a[1] == a[3])//第三次称重，在A2组只需找两个小球比较就行
					printf("第3个小球偏重\n");
				else if (a[1] < a[3])
				{
					printf("第4个小球偏重\n");
				}
				else
				{
					printf("第2个小球偏重\n");
				}
			}
			if (sum1 > sum2)//A1组重或者B1轻
			{
				if (A1 > a[10])
				{
					printf("第1个小球重\n");
				}
				else if (A1 == a[10])
					printf("第5个小球轻\n");
			}
			if (sum1 < sum2)//B2组轻
			{
				if (a[6] == a[7])
					printf("第6个小球偏轻\n");
				else if (a[6] < a[7])
				{
					printf("第7个小球偏轻\n");
				}
				else
				{
					printf("第8个小球偏轻\n");
				}
			}
		}
		else if(sum1 <sum2)
		{
			int A1, A2, B1, B2;
			A1 = a[0];//把sum1组再分为四组，为A1和A2,B1和B2组，其中A1和B1分1个小球。A2和B2分3个小球
			A2 = a[1] + a[2] + a[3];
			B1 = a[4];
			B2 = a[5] + a[6] + a[7];
			sum1 = A1 + B2;
			sum2 = B1 + a[8] + a[9] + a[10];
			
				if (sum1 == sum2)//A2组小球偏轻，对A2组小球成员进行分组
				{
					if (a[2] == a[3])
						printf("第2个小球有问题,且偏轻\n");
					else if (a[2] < a[3])
					{
						printf("第3个小球有问题，且偏轻\n");
					}
					else
					{
						printf("第4个小球有问题，且偏轻\n");
					}
				}
				if (sum1 < sum2)//A1重或者B1轻的情况，即第一个小球和第五个小球的比较情况
				{
					if (A1 < a[10])
					{
						printf("第1个小球偏轻\n");
					}
					else if (A1 == a[10])
					{
						printf("第5个小球偏重\n");
					}
				}
				if (sum1 > sum2)//B2小组偏轻，对B2小组成员进行分组
				{
					if (a[6] == a[7])
						printf("第6个小球偏重\n");
					else if (a[6] > a[7])
					{
						printf("第7个小球偏重\n");
					}
					else
					{
						printf("第8个小球偏重\n");
					}
				}
		}
	}
	return 0;
}