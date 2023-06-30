#include <stdio.h>
#define N 10 //定义阶数为10，可以修改为其他形如4k+2的偶数
int main(void)
{
	int a[N][N]; //定义一个N*N的二维数组
	int i, j, k; //定义循环变量
	int x, y; //定义交换时的临时变量
	k = (N - 2) / 4; //根据规律可知，k为(N-2)/4，用于确定交换范围
	for (i = 0; i < N; i++) //遍历每一行
	{
		for (j = 0; j < N; j++) //遍历每一列
		{
			a[i][j] = i * N + j + 1; //按照顺序填充数组，从1到N*N
		}
	}
	for (i = 0; i < N / 2; i++) //交换右半边大于k+1的列，注意只交换上半部分，下半部分会自动交换
	{
		for (j = N / 2 + k + 1; j < N; j++)
		{
			x = a[i][j]; //用x保存右上角的元素值
			y = a[i + N / 2][j - N / 2]; //用y保存左下角的元素值
			a[i][j] = y; //将左下角的值赋给右上角
			a[i + N / 2][j - N / 2] = x; //将右上角的值赋给左下角
		}
	}
	for (i = N / 4; i <= N / 4 + k; i++) //交换左半边，上下两个块最中心的点，注意只交换一行
	{
		x = a[i][N / 4]; //用x保存上方的元素值
		y = a[i + N / 2][N / 4]; //用y保存下方的元素值
		a[i][N / 4] = y; //将下方的值赋给上方
		a[i + N / 2][N / 4] = x; //将上方的值赋给下方
	}
	for (i = 0; i < N / 2; i++) //交换左半边小于中心列的列，除了上下半边最中心的行的第一列的那个值不用交换，注意只交换上半部分，下半部分会自动交换
	{
		for (j = 1; j < N / 4; j++)
		{
			if (i == N / 4 && j == 1) //跳过上下半边最中心的行的第一列的那个值
				continue;
			x = a[i][j]; //用x保存右上角的元素值
			y = a[i + N / 2][j + N / 2]; //用y保存左下角的元素值
			a[i][j] = y; //将左下角的值赋给右上角
			a[i + N / 2][j + N / 2] = x; //将右上角的值赋给左下角
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