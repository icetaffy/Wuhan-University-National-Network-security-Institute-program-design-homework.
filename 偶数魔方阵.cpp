#include <stdio.h>
#define N 8 //定义阶数为8，可以修改为其他4的倍数
int main(void)
{
	int a[N][N]; //定义一个N*N的二维数组
	int i, j; //定义循环变量
	int tmp1 = 1; //定义从小到大填充的临时变量
	int tmp2 = N * N; //定义从大到小填充的临时变量
	for (i = 0; i < N; i++) //遍历每一行
	{
		for (j = 0; j < N; j++) //遍历每一列
		{
			if (i % 4 == j % 4 || (i + j) % 4 == 3) //判断是否在对角线上，根据规律可知，对角线上满足i%4 == j%4或者(i+j)%4 == 3
			{
				a[i][j] = tmp2; //对角线上从大到小填充
			}
			else
			{
				a[i][j] = tmp1; //非对角线上从小到大填充
			}
			tmp2--; //每填充一个数，tmp2减一
			tmp1++; //每填充一个数，tmp1加一
		}
	}
	for (i = 0; i < N; i++) //输出魔方阵
	{
		for (j = 0; j < N; j++)
		{
			printf("%-5d", a[i][j]); //按照格式输出每个元素，-5表示左对齐，占5个字符宽度
		}
		printf("\n"); //换行
	}
	return 0;
}