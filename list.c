#include <stdio.h>
#include "list.h"

int max(int a,int b)
{
	return a>b ? a:b;
}

List *list_create()
{
	List *newlist = (List*)malloc(sizeof(List));
	newlist->size = 0;
	newlist->data = (Node*)malloc(sizeof(Node));
	newlist->data->elem = barrier_elem;
	newlist->data->next = NULL;
	return newlist;
}

Node *nodebyidx(List* l,int idx)
{
	Node *cur = l->data;
	while(idx--)
		cur = cur->next;
	return  cur;
}

void list_insert(List* l,Item e,int idx)
{
	Node *newelem = (Node*)malloc(sizeof(Node));
	newelem->elem = e;
	if(idx==0)
	{
		newelem->next = l->data;
		l->data = newelem;
	}
	else
	{
		Node *prev = nodebyidx(l,idx-1);
		newelem->next = prev->next;
		prev->next = newelem;
	}
	l->size++;
}

Item list_get(List* l,int idx)
{
	return nodebyidx(l,idx)->elem;
}

void list_push(List* l,Item e)
{
	list_insert(l,e,l->size);
}

void list_remove(List* l,int idx)
{
	if(idx==0)
	{
		Node *head = l->data;
		l->data = l->data->next;
		free(head);
	}
	else
	{
		Node *prev = nodebyidx(l,idx-1);
		Node *del = prev->next;
		prev->next = prev->next->next;
		free(del);
	}
	l->size--;
}

int idxbyvalue(List* l,Item e)
{
	Node *cur = l->data;
	int cidx = 0;
	while(cur->elem!=barrier_elem)
	{
		if(cur->elem==e)
			return cidx;
		cur = cur->next;
		cidx++;
	}
	return -1;
}

void list_delete(List* l,Item e)
{
	list_remove(l,idxbyvalue(l,e));
}

void list_print(List* l,char** nms)
{
	Node *cur = l->data;
	while(cur->elem!=barrier_elem)
	{
		printf("%s; ",nms[cur->elem]);
		cur = cur->next;
	}
	/*for(int i=0;i<=l->size;i++)
	{
		printf("%d ",cur->elem);
		cur = cur->next;
	}*/
	printf("\n");
}

void list_destroy_internal(Node* n)
{
	if(n==NULL)
		return;
	list_destroy_internal(n->next);
	free(n);
}

void list_destroy(List* l)
{
	list_destroy_internal(l->data);
}

void list_reverse(List* l)
{
	Node *last = nodebyidx(l,l->size);
	for(int i = 0; i < l->size; i++)
	{
		Node *old = last->next;
		last->next = l->data;
		l->data = l->data->next;
		last->next->next = old;
	}
	list_remove(l,0);
	l->size++;
	list_push(l,barrier_elem);
	l->size--;
}

