#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct linklist
{
	int data;
	struct linklist *next;
}linknode,*linklistp;

linklistp insert_head(linklistp head,linklistp newnode)
{
	newnode->next = head;
	head = newnode;	
	return head;
}

void output(linklistp head)
{
	linklistp temp = head;
	while(temp)
	{
		printf("%d  ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}


int main()
{
	linklistp head = NULL;
	int i=0;
	for(;i<10;i++)
	{
		linklistp newnode = (linklistp)malloc(sizeof(linknode));
	    newnode->data = i;
	    newnode->next = NULL;
		head = insert_head(head,newnode);
		output(head);	
	}
}

