// �ϲ���������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node
{
	int data;
	struct Node* pnext;
}Node;

Node* Createlist()
{
	Node* phead = NULL, *ptail = NULL;
	int n;

	while (scanf("%d", &n) && n != -1)
	{
		Node* pnew = (Node*)malloc(sizeof(Node));
		if (pnew == NULL)
		{
			return phead;
		}
		else
		{
			pnew->data = n;
			pnew->pnext = NULL;
			if (phead == NULL)
			{
				phead = pnew;
				ptail = pnew;
			}
			else
			{
				ptail->pnext = pnew;
				ptail = pnew;
			}
		}
	}	
	return phead;
}

Node* combineList(int a, int b, Node* p1,Node* p2)
{
	Node* phead = p1;
	if (p1 == NULL)
	{
		return NULL;
	}
	
	Node* pprev = p1;
	p1 = p1->pnext;
	while (p1->data != a)
	{
		pprev = pprev->pnext;
		p1 = p1->pnext;
	}
	//��pprev->pnextָ��p2
	pprev->pnext = p2;
	while (p1->data != b)
	{
		Node* temp = p1;
		p1 = p1->pnext;
		free(temp);
		temp = NULL;
	}
	//p1����ָ���±�b,һ���ƶ�һ��ɾ��
	
	while (p2->pnext != NULL)
	{
		//pprev = pprev->pnext;
		p2 = p2->pnext;
	}
	p2->pnext = p1->pnext;
	//ʹlistĩβָ��b
	

	

	
	return phead;
}

void printList(Node* p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->pnext;
	}
	printf("\n");
}
int main()
{
	int input;
	Node* list1 = NULL, *list2 = NULL;
	// ����һ�ű�
	
	list1=Createlist();
	int a, b;
	scanf("%d %d", &a, &b);
	
	// ���ڶ��ű�
	
	list2 = Createlist();
	//printList(list1);
	//printList(list2);
	Node* newlist = combineList(a, b, list1, list2);
	printList(newlist);
	
	return 0;	
}

