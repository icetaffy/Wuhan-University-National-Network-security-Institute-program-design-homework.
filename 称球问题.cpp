#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int n, i, m, flag, fm;
	printf("���������С��ĸ�����\n");
	scanf_s("%d", &n);
	printf("Ԥ��ÿ��С���������������С��ı���Լ�������С�������:\n");
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
	if (sum1==sum2)//��һ�γƳ�����һ��͵ڶ���������ȣ�˵�������һ����������һ���������
	{
		int C1, C2;
		C1 = a[n - 5] + a[n - 4];
		C2 = a[n - 3] + a[n - 2] + a[n - 1];
		if (C2==sum1*3/4)//�ڶ�����C3�����������أ������˵��C1�������������⡣
		{
			if (a[n-5]==sum1/4)//�����γ�����9����Ϊ��׼������£�������������¾Ͳ��ܳƳ�10���������
			{
				printf("��%d��С�����������⣬����û�취��֪����\n",n-3);
			}
			else if(a[n-5]>sum1/4)
			{
				printf("��%d��С��ƫ��\n", n - 4);
			}
			else
			{
				printf("��%d��С��ƫ��\n", n - 4);
			}
		}
		else
		{
			if (C2 >sum1 * 3 / 4)
			{
				if (a[n - 1] == a[n - 2])
					printf("��%d����ƫ��\n",n-2);
				else if(a[n-1]>a[n-2])
				{
					printf("��%d��С��ƫ��\n", n);
				}
				else
				{
					printf("��%d��С��ƫ��\n", n - 1);
				}
			}
			else
			{
				if (a[n - 1] == a[n - 2])
					printf("��%d����ƫ��\n", n-2);
				else if (a[n - 1] > a[n - 2])
				{
					printf("��%d��С��ƫ��\n", n-1);
				}
				else
				{
					printf("��%d��С��ƫ��\n", n);
				}
			}
		}
	}
	else//�����һ�γƳ�����һ��͵ڶ����������ȵ�������������γ��ش���
	{
		if (sum1 > sum2)//���һ������ұ�����
		{
			int A1, A2, B1, B2;
			A1 = a[0];//��sum1���ٷ�Ϊ���飬ΪA1��A2,B1��B2�飬����A1��B1��1��С��A2��B2��3��С��
			A2 = a[1] + a[2] + a[3];
			B1 = a[4];
			B2 = a[5] + a[6] + a[7];
			sum1 = A1 + B2;
			sum2 = B1 + a[8] + a[9] + a[10];
			if (sum1 == sum2)//�ڶ��γ��أ�˵��A2��ƫ��
			{
				if (a[1] == a[3])//�����γ��أ���A2��ֻ��������С��ȽϾ���
					printf("��3��С��ƫ��\n");
				else if (a[1] < a[3])
				{
					printf("��4��С��ƫ��\n");
				}
				else
				{
					printf("��2��С��ƫ��\n");
				}
			}
			if (sum1 > sum2)//A1���ػ���B1��
			{
				if (A1 > a[10])
				{
					printf("��1��С����\n");
				}
				else if (A1 == a[10])
					printf("��5��С����\n");
			}
			if (sum1 < sum2)//B2����
			{
				if (a[6] == a[7])
					printf("��6��С��ƫ��\n");
				else if (a[6] < a[7])
				{
					printf("��7��С��ƫ��\n");
				}
				else
				{
					printf("��8��С��ƫ��\n");
				}
			}
		}
		else if(sum1 <sum2)
		{
			int A1, A2, B1, B2;
			A1 = a[0];//��sum1���ٷ�Ϊ���飬ΪA1��A2,B1��B2�飬����A1��B1��1��С��A2��B2��3��С��
			A2 = a[1] + a[2] + a[3];
			B1 = a[4];
			B2 = a[5] + a[6] + a[7];
			sum1 = A1 + B2;
			sum2 = B1 + a[8] + a[9] + a[10];
			
				if (sum1 == sum2)//A2��С��ƫ�ᣬ��A2��С���Ա���з���
				{
					if (a[2] == a[3])
						printf("��2��С��������,��ƫ��\n");
					else if (a[2] < a[3])
					{
						printf("��3��С�������⣬��ƫ��\n");
					}
					else
					{
						printf("��4��С�������⣬��ƫ��\n");
					}
				}
				if (sum1 < sum2)//A1�ػ���B1������������һ��С��͵����С��ıȽ����
				{
					if (A1 < a[10])
					{
						printf("��1��С��ƫ��\n");
					}
					else if (A1 == a[10])
					{
						printf("��5��С��ƫ��\n");
					}
				}
				if (sum1 > sum2)//B2С��ƫ�ᣬ��B2С���Ա���з���
				{
					if (a[6] == a[7])
						printf("��6��С��ƫ��\n");
					else if (a[6] > a[7])
					{
						printf("��7��С��ƫ��\n");
					}
					else
					{
						printf("��8��С��ƫ��\n");
					}
				}
		}
	}
	return 0;
}