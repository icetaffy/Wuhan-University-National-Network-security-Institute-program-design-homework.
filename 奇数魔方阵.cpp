#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n;
	printf("����������ħ����Ľ�����\n");
	scanf_s("%d", &n);
	if (n % 2 == 0)
	{
		printf("����������\n");
		return 0;
	}
	int a[50][50] = { 0 }, i;
	int q = 0, p = 0, j, q2, p2;
	p = (n + 1) / 2 - 1;
	a[q][p] = 1;	//�ȴ�1��ʼ����1�������м��λ��
	for (i = 2; i <= n * n; i++)
	{
		q2 = q;
		p2 = p;
		//�ԽǴ���
		if (q == 0 && p == n - 1)
		{
			q = n - 1;
			p = 0;
		}
		//��һ�б߽紦��
		else if (q == 0)
		{
			q = n - 1;
			p = p + 1;
		}
		//���һ�б߽紦��
		else if (p == n - 1)
		{
			q = q - 1;
			p = 0;
		}
		else {
			q--;
			p++;
		}
		//�������Ϸ���ռ��������
		if (a[q][p] != 0 && q == n - 2)
		{
			q = 0;
			p = p2;
		}
		else if (a[q][p] != 0) 
		{
			q = q2 + 1;
			p = p2;
		}
		a[q][p] = i;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

