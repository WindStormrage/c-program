#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct linklist
{
	int data;
	int data2;
	struct linklist *next;
}*linklistp;


linklistp insert_head(int i,int i2,linklistp head,linklistp newnode)
{
//创建一个新的链表用newnode表示 
	newnode = (linklistp)malloc(sizeof(linklistp));
//填充新的数据 
    newnode->data = i; 
    newnode->data2= i2;   
//新的的next指向之前的头 
	newnode->next = head;
//之前deep头指向新的 
	head = newnode;	
	return head;
}


void output(linklistp head)
{
	//temp从头开始一直到null 
	linklistp temp = head;
	while(temp)
	{
	//	if(temp->data==0)printf("ok\n"); 
		printf("%d %d\n",temp->data,temp->data2);
		temp = temp->next;
	}printf("end");
}


int main()
{
	linklistp head = NULL;
//newnode是创造一个空变量准备用来当做新的链表的 
	linklistp newnode;
	int j,i,i2;
    for(j=1;;)
	    {
		    printf("1要0不要"); 
		    scanf("%d",&j);
		    if(j==0) break;
		    printf("加数据1:"); 
		    scanf("%d",&i);
		    printf("加数据2:"); 
		    scanf("%d",&i2);
			head = insert_head(i,i2,head,newnode);
	    }
	output(head);	
}

