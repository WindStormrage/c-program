#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct linklist
{
	int data;
	int data2;
	struct linklist *next;
}*linklistp;


linklistp insert_head(int i,int i2,linklistp head,linklistp newnode)
{
//����һ���µ�������newnode��ʾ 
	newnode = (linklistp)malloc(sizeof(linklistp));
//����µ����� 
    newnode->data = i; 
    newnode->data2= i2;   
//�µĵ�nextָ��֮ǰ��ͷ 
	newnode->next = head;
//֮ǰdeepͷָ���µ� 
	head = newnode;	
	return head;
}

linklistp deldata(int i,linklistp head)
{
	linklistp temp = head,temp0;int a;
	if(temp->data == i)
		{
			head=head->next;
			free(temp);
			return head;
		}
	else
	{
		temp0= head;
		temp = temp->next;
		while(temp)
		{
			if(temp->data==i)
			  {
				temp0->next=temp->next;	
			    free(temp);
				return head;
			  } 
			temp0= temp0->next;
			temp = temp->next;
		}
    }
    printf("û�ҵ���");
    return head;
}

void output(linklistp head)
{
	//temp��ͷ��ʼһֱ��null 
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
//newnode�Ǵ���һ���ձ���׼�����������µ������ 
	linklistp newnode;
	int j,i,i2;
    for(j=1;;)
	    {
		    printf("1Ҫ0��Ҫ"); 
		    scanf("%d",&j);
		    if(j==0) break;
		    printf("������1:"); 
		    scanf("%d",&i);
		    printf("������2:"); 
		    scanf("%d",&i2);
			head = insert_head(i,i2,head,newnode);
	    }
	printf("Ҫɾ����1���ڶ��ٵ�"); 
	scanf("%d",&i);
	
	if(head == NULL)
	  printf("û����");
	else 
	  head=deldata(i,head);
	
	output(head);	
}

