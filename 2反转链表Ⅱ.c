//反转链表Ⅱ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node
{
	int data;
	struct Node* pnext;
	struct Node* pprev;
}Node;

Node* CreateList()
{
	Node* phead = NULL, * ptail = NULL;
	int n;
	while (scanf("%d", &n) && n != -1)
	{
		Node* pnew = (Node*)malloc(sizeof(Node));
		if (pnew == NULL)
		{
			return NULL;
		}
		else//分配成功
		{
			pnew->data = n;
			pnew->pnext = NULL;
			pnew->pprev = NULL;
			if (phead == NULL)
			{
				phead = pnew;
				ptail = pnew;

			}
			else
			{
				ptail->pnext = pnew;
				pnew->pprev = ptail;
				ptail = pnew;
			}
		}

	}
	return phead;
}

Node* reverse(Node* phead, int l, int r)
{
	if (phead == NULL)
	{
		return NULL;
	}
	else
	{
		Node* p = phead;
		while (p->data != l && p->pnext != NULL)
		{
			printf("%d ", p->data);
			p = p->pnext;
		}
		while (p->data != r && p->pnext != NULL)
		{
			p = p->pnext;
		}
		while (p->data != l && p->pprev != NULL)
		{
			printf("%d ", p->data);
			p = p->pprev;
			
		}
		if (p != NULL)
		{
			printf("%d ", p->data);
		}

		while (p->data != r && p->pnext != NULL)
		{
			p = p->pnext;

		}
		while (p->pnext != NULL)
		{
			p = p->pnext;
			printf("%d ", p->data);
		}
		printf("\n");
	}
	return phead;
}


int main()
{
	Node* list = NULL;
	list = CreateList();
	int l = 0, r = 0;
	scanf("%d %d", &l, &r);
	reverse(list, l, r);
	return 0;
}