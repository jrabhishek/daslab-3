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

void insertAtfirst(int item)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new ->data = item;
	new->data = item;
	new->next = NULL;
	new->prev = NULL;
	if(head == NULL)
	{
		head = new;
		tail = new;
		tail->next = new;
		return;


	}

	new->next = head;
	head->prev = new;
	tail->next = new;
	head = new;

}

void display()
{
	if (head== NULL)
	{
		return;
	}

	struct node *temp = head;

	while(temp->next != head)
	{
		printf("%d\n",temp->data);
		temp = temp->next;
	}
	printf("%d\n",temp->data );
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
		insertAtfirst(data);

	}
	display();

}