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
 int count()
{
	int length = 0;

	if (head == NULL)
	{
		return -1 ;
		
	}

	struct node *temp = head;
	while(temp != NULL)
	{

		temp = temp->next;
		length++;

	}
	return length;

}
void deletefirst()
{
	if (head==NULL)
	{
		return;
		/* code */
	}
	head = head->next;
	head->prev = NULL;

}

void deleteLast()
{
	if (head == NULL)
	{
		return;
		/* code */
	}
	tail = tail->prev;
	tail->next = NULL;
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

void reversedisplay()
{
	if(head==NULL)
	{
		return;
	}

	struct node *temp = tail;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->prev;
	}


}

void delete(int item)
{
	struct node *temp = head;
	if (temp->data == item)
	{
		deletefirst();
		return;
	}
	if (tail->data == item)
	{
		deleteLast();
		return;
	}
	while(temp->data != item )
	{
		if (temp==NULL)
		{
			return;
		}
		temp = temp->next;
	}

	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
}


void search( int item)
{
	if (head == NULL)
	{
		return;
		/* code */
	}

	struct node *temp = head;
	while(temp != NULL)
	{
		if (temp->data == item)
		{
			printf("item found\n");
			/* code */
			return;
		}
		temp = temp->next;

	}

}



void main()
{
	int data,c = 1;
	
	while(c !=-1)
	{
		printf("enter:\n 1 to insert\n 2 to delete at first\n 3 to delete at last\n 4 to search an element\n 5 t0 find length of list\n6 to delete element with given keyn\n7 to display\n8 to reversedisplay");

	scanf("%d",&c);

	switch(c)
	{
		case 1:
		     printf("enter data\n");
		     scanf("%d",&data);
			 insertAtFirst(data);
			break;
		case 2:
			deletefirst();
			break;
		case 3:
			deleteLast();
			break;
		case 4:
		     printf("enter data to be searched\n");
		    scanf("%d",data);
		    search(data);
			break;
		case 5:
			printf("length is %d\n",count() );
			break;
		case 6:
			 printf("enter data to be deleted\n");
		     scanf("%d",data);
			 insertAtFirst(data);
			 break;
		case 7:
			display();
			break;
		case 8:
			reversedisplay();
			break;
		default:
			printf("fuck off\n");

}

}
}

