//#include "common.h"
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;

};
struct node *head = NULL;
struct node *tail = NULL;
void insertAtFirst(int item)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new ->data = item;
	new->data = item;
	new->next = NULL;
	new->prev = NULL;
	if (head == NULL)
	{
		head = new;
		tail = new;
		return;
	}

	new->next = head;
	head->prev = new;
	head = new;
}

void display()
{
	struct node *temp = head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data );
		temp = temp->next;

	}
}

void reverse()
{
	struct node *temp = head;
	struct node *flag;

	while(temp!= NULL)
	{
		flag = temp->next;
		temp->next = temp->prev;
		temp->prev = flag;
		temp = flag;

	}

	flag = head;
	head = tail;
	tail = flag;

}

int main()
{
	int n,i,data;
	printf("enter the length of list\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the data\n");
		scanf("%d",&data);
		insertAtFirst(data);

	}
	display();

	printf("after reverse\n");
	reverse();
	display();

}
