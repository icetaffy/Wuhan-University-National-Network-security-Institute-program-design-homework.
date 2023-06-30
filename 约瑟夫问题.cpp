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
	cyclic->next = head;//��β����
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
		printf("�����˵ı��Ϊ:%d\n", p->number);
		free(p);
		p = tail->next;
	}
	if (p->next==p)
	{
		printf("���һ�˵ı��Ϊ:%d\n", p->number);
	}
	
	free(p);
}
int main(void)
{
	int n = 0, k = 1, m = 0;
	CycList* head = NULL;
	printf("��������:");
	scanf_s("%d", &n);
	head = initLink(n);
	printf("����궨���m(����Ҫ���еĺ���)��");
	scanf_s("%d", &m);
	printf("�ӵ�1���˿�ʼ������");
	function(head, k, m);
	return 0;
}

