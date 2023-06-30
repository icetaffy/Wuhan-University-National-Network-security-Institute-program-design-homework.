#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int number;
	struct node* next;
}CycList;
CycList* initLink(int n) {
	int i = 0;
	CycList* head = NULL, * cyclic = NULL;
	head = (CycList*)malloc(sizeof(CycList));
	head->number = 1;
	head->next = NULL;
	cyclic = head;
	for (i = 2; i <= n; i++) {
		CycList* body = (CycList*)malloc(sizeof(CycList));
		body->number = i;
		body->next = NULL;
		cyclic->next = body;
		cyclic = cyclic->next;
	}
	cyclic->next = head;//首尾相连
	return head;
}
void function(CycList* head, int k, int m)
{
	CycList* p = NULL;
	CycList* tail = head;

	while (tail->next != head) 
	{
		tail = tail->next;
	}
	p = head;
	while (p->number != k)
	{
		tail = p;
		p = p->next;
	}
	while (p->next != p) 
	{
		int i = 0;
	
		for (i = 1; i < m; i++) 
		{
			tail = p;
			p = p->next;
		}
		tail->next = p->next;
		printf("出列人的编号为:%d\n", p->number);
		free(p);
		p = tail->next;
	}
	if (p->next==p)
	{
		printf("最后一人的编号为:%d\n", p->number);
	}
	
	free(p);
}
int main(void)
{
	int n = 0, k = 1, m = 0;
	CycList* head = NULL;
	printf("输入人数:");
	scanf_s("%d", &n);
	head = initLink(n);
	printf("输入标定序号m(即需要出列的号码)：");
	scanf_s("%d", &m);
	printf("从第1个人开始报数：");
	function(head, k, m);
	return 0;
}

