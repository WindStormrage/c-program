#include<conio.h>
#include<stdio.h> 
#include<string.h>
#include<windows.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct user 
{
    int   name;//���֤ 
    int    use;//�˺� 
	int    password;//���� 
	float  money;//��� 
	struct user *next;
}*userp;

userp open(userp head);//����
userp landing(userp head);//��½
userp  cancellation(userp head);//����
void  deposit();//��� 
void  draw();//ȡ�� 
void  change();//����
void  inquiry();//��ѯ  
void  transfer();//ת��  
void  old_data();//������ǰ����
void  error();//��ʾ����
void  add();//�ѱ������ݷŵ��ļ��б��� 

//��� 
userp insert_head(int a,int b,int c,userp head,userp newnode)
{
//����һ���µ�������newnode��ʾ 
	newnode = (userp)malloc(sizeof(user));
//����µ����� 
    newnode->name=a; 
    newnode->use= b;
	newnode->password=c; 
	newnode->money=0;  
//�µĵ�nextָ��֮ǰ��ͷ 
	newnode->next = head;
//֮ǰdeepͷָ���µ� 
	head = newnode;	
	return head;
}

//��� 
void output(userp head)
{
	//temp��ͷ��ʼһֱ��null 
	userp temp = head;
	while(temp)
	{
		printf("%d \n",temp->name);
		printf("%d \n",temp->use);
		printf("%d \n",temp->password);
		temp = temp->next;
	}
}

//ƥ���ʺ����� 
int find(int a,int b,userp head)
{
	userp temp = head;
	while(temp)
	{
		if(temp->use==a&&temp->password==b) return 1;
		temp = temp->next;
	}
	return 0;
}

//����ר�� 
userp deldata(int a,int b,userp head)
{
	userp temp = head,temp0;
	int abc;
	if(temp->use == a&&temp->password == b)
		{
			head=head->next;
			free(temp);
			printf("+================================+\n");
			printf("|                                |\n");
			printf("|           ɾ���ɹ���           |\n");
			printf("|                                |\n");   
			printf("|     �����������������ҳ       |\n");
			printf("|                                |\n");
			printf("+================================+\n");
			scanf("%d",&abc);
			system("cls"); 
			return head;
		}
	else
	{
		temp0= head;
		temp = temp->next;
		while(temp)
		{
			if(temp->use == a&&temp->password == b)
			  {
				temp0->next=temp->next;	
			    free(temp);
				printf("+================================+\n");
				printf("|                                |\n");
				printf("|           ɾ���ɹ���           |\n");
				printf("|                                |\n");   
				printf("|     �����������������ҳ       |\n");
				printf("|                                |\n");
				printf("+================================+\n");
				scanf("%d",&abc);
				system("cls");
				return head;
			  } 
			temp0= temp0->next;
			temp = temp->next;
		}
    } 
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|  �Ҳ�����Ӧ���˻������������  |\n");
	printf("|                                |\n");   
	printf("|      �����������������ҳ      |\n");
	printf("|                                |\n");
	printf("+================================+\n");
	scanf("%d",&abc);
	system("cls");
    return head;
}

int  main()
{
 int i,abc,n;
 userp head = NULL;
 printf("+================================+\n");
 printf("|                                |\n");
 printf("|         ��ӭʹ�ñ�ATM          |\n");
 printf("|                                |\n");   
 printf("|          ������1��½           |\n");
 printf("|                                |\n");
 printf("+================================+\n");
 scanf("%d",&abc);
 system("cls");
 old_data(); //������ǰ�����ݣ���������
 for(;;)
    {
	 printf("+================================+\n");
	 printf("|                                |\n");
	 printf("|        1.����  2.��½          |\n");
	 printf("|        3.����  4.�˳�          |\n");   
	 printf("|                                |\n");
	 printf("|     ��������Ӧ�ķ�����       |\n");
	 printf("+================================+\n");
     scanf("%d",&i);
     system("cls"); 
	 if(i!=1&&i!=2&&i!=3&&i!=4)
	   {
			error();//��ʾ����
	   }
	 else switch(i)
	 	{
		    case 1://���� 
		    head=open(head); break; 
		    case 2://��½ 
		    head=landing(head);break; 
		    case 3://���� 
		    head=cancellation(head);break; 
		    case 4://�˳� 
		    goto qqq;
	 	}
    }
  qqq:
  add();//�ѱ������ݷŵ��ļ��б���
  output(head);	 
 }



userp open(userp head)//����
{
//newnode�Ǵ���һ���ձ���׼�����������µ������ 
	userp newnode;
	int abc,j;
	int a,b,c;
    for(j=0;;)
	    {
		 printf("+================================+\n");
		 printf("|                                |\n");
		 printf("|        ��������������1         |\n");
		 printf("|       ������һ��������2        |\n");   
		 printf("|                                |\n");
		 printf("|     ��������Ӧ�ķ�����       |\n");
		 printf("+================================+\n");
 	     scanf("%d",&j);  
    	 system("cls"); 
		 if(j==2) break;
		 printf("+================================+\n");
		 printf("|                                |\n");
		 printf("|        ��������Ӧ����          |\n");
		 printf("|                                |\n");   
		 printf("|      ���֤�ţ��˺ţ�����      |\n");
		 printf("|                                |\n");
		 printf("+================================+\n"); 
	     scanf("%d%d%d",&a,&b,&c);
         system("cls"); /////////////////////��Ҫ�ж������Ƿ�����ͬ�˺Ż����֤�������� 
		 head = insert_head(a,b,c,head,newnode);
	    }
	return head;
}

userp landing(userp head)//��½
{
	int abc,i=0,a,b;
	for(;;)
	   {
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|                                |\n");
		printf("|       �������˺ź�����         |\n");   
		printf("|                                |\n");
		printf("|                                |\n");
		printf("+================================+\n");
		scanf ("%d%d",&a,&b);  
	    system("cls");
		i=find(a,b,head);
		if(i==1) break;
		else
		   {
			printf("+================================+\n");
			printf("|                                |\n");
			printf("|            �������            |\n");   
			printf("|                                |\n");
			printf("|����1������ҳ������������������ |\n");
			printf("|                                |\n");
			printf("+================================+\n");
			scanf ("%d",&abc);  
		    system("cls");
			if(abc==1) return head; 
		   }
	   }
	
	//��½�ɹ��ˣ�
	int cookie_use=a,cookie_password=b; 
    for(;;)
    {
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|      ��½�ɹ����������        |\n");
	printf("|                                |\n");
	printf("|   1.���  2.ȡ��  3.����       |\n");
	printf("|   4.��ѯ  5.ת��  6.�˳�       |\n");   
	printf("+================================+\n");
     scanf("%d",&i);
     system("cls"); 
	 if(i!=1&&i!=2&&i!=3&&i!=4&&i!=5&&i!=6)
	   {
			error();//��ʾ����
	   }
	 else switch(i)
	 	{
		    case 1://��� 
		    deposit(); break; 
		    case 2://ȡ�� 
		    draw();break; 
		    case 3://���� 
		    change();break;  
		    case 4://��ѯ 
		    inquiry();break;  
		    case 5://ת�� 
		    transfer();break; 
		    case 6://�˳� 
		    return head;
	 	}
    }
}

userp cancellation(userp head)//����
{
	int a,b,abc;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|    ������Ҫ�������˺ź�����    |\n");   
	printf("|                                |\n");
	printf("|                                |\n");
	printf("+================================+\n");
	scanf("%d%d",&a,&b);//////���������ʱ���������� 
    system("cls"); 
	if(head == NULL) 
	{
	 printf("+================================+\n");
	 printf("|                                |\n");
	 printf("|  �Ҳ�����Ӧ���˻������������  |\n");
	 printf("|                                |\n");   
	 printf("|      �����������������ҳ      |\n");
	 printf("|                                |\n");
	 printf("+================================+\n");
	 scanf("%d",&abc);
	 system("cls");
    }
	else 
	  head=deldata(a,b,head);
}


void deposit()//��� 
{
	int abc;
 printf("cunkuan\n");
     scanf ("%d",&abc);  
    system("cls"); 
}

void draw()//ȡ�� 
{
	int abc;
 printf("qukuan\n");
     scanf ("%d",&abc);  
    system("cls"); 
}

void change()//����
{
	int abc;
 printf("gaimi\n");
     scanf ("%d",&abc);  
    system("cls"); 
}

void inquiry()//��ѯ  
{
	int abc;
 printf("chaxun\n");
     scanf ("%d",&abc);  
    system("cls"); 
}

void transfer()//ת�� 
{
	int abc;
 printf("zhuanzhang\n");
     scanf ("%d",&abc);  
    system("cls"); 
}

void old_data()//������ǰ����
{
	int abc;
 printf("��������\n");
     scanf ("%d",&abc);  
    system("cls"); 
}

void error()//��ʾ����
{		 	 
    int abc;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|          �������            |\n");
    printf("|                                |\n");
    printf("|        ���������밴 1          |\n");
    printf("|                                |\n");    
    printf("+================================+\n");
    scanf ("%d",&abc);  
    system("cls"); 
}

void add()//�ѱ������ݷŵ��ļ��б���
{
	int abc;
 printf("�������ݺ���\n");
    scanf ("%d",&abc);  
    system("cls"); 
}

