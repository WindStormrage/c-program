#include<conio.h>
#include<stdio.h> 
#include<string.h>
#include<windows.h>
#include <stdlib.h>
#include <malloc.h>
int sum;

typedef struct user 
{
    int   name;//���֤ 
    int    use;//�˺� 
	int    password;//���� ////////////��Ϊchar�ε� 
	float  money;//��� 
	struct user *next;
}*userp;

userp open(userp head);//����
userp landing(userp head);//��½
userp  cancellation(userp head);//����
void  deposit(userp temp);//��� 
void  draw(userp temp);//ȡ�� 
void  change(userp temp);//����
void  inquiry(userp temp);//��ѯ  
void  transfer(userp temp,userp head);//ת��  
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
userp find(int a,int b,userp head)
{
	userp temp = head;
	while(temp)
	{
		if(temp->use==a&&temp->password==b) {sum=1;return temp;};
		temp = temp->next;
	}
	sum=0;
	return temp;
}

//����ר�� 
userp deldata(int a,int b,userp head)
{
	userp temp = head,temp0;
	if(temp->use == a&&temp->password == b)
		{
			head=head->next;
			free(temp);
			sum=1;
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
			    sum=1;
				return head;
			  } 
			temp0= temp0->next;
			temp = temp->next;
		}
    } 
    sum=0;
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
	userp cookie_temp;
	int abc,a,b,i;
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
		cookie_temp=find(a,b,head);
		if(sum==1) break;
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
		    deposit(cookie_temp); break; 
		    case 2://ȡ�� 
		    draw(cookie_temp);break; 
		    case 3://���� 
		    change(cookie_temp);break;  
		    case 4://��ѯ 
		    inquiry(cookie_temp);break;  
		    case 5://ת�� 
		    transfer(cookie_temp,head);break; 
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
	if(head == NULL) sum=0;
	else head=deldata(a,b,head);
	
	if(sum==1)
	 {
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|           ɾ���ɹ���           |\n");
		printf("|                                |\n");   
		printf("|     �����������������ҳ       |\n");
		printf("|                                |\n");
		printf("+================================+\n");
		scanf("%d",&abc);
		system("cls"); 
     }
	else
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
        return head;
}

void deposit(userp temp)//��� 
{
	int abc;
	float money0;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|        ����������          |\n"); 
	printf("|                                |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
    scanf ("%f",&money0); 
	system("cls");
    temp->money=temp->money+money0;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|            ���ɹ�            |\n");
	printf("|�Ѵ���%fԪ�����%fԪ|\n",money0,temp->money); 
	printf("|        ���������������ҳ      |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
	scanf ("%d",&abc);  
	system("cls");
}

void draw(userp temp)//ȡ�� 
{
	int abc;
	float money0;
	again:
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|        ������ȡ����          |\n"); 
	printf("|                                |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
    scanf ("%f",&money0); 
	system("cls");
	if(temp->money<money0)  
	{ 
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|           ����             |\n");
		printf("|                                |\n"); 
		printf("|   ��0��½���水������������    |\n"); 
		printf("|                                |\n");   
		printf("+================================+\n");
		scanf ("%d",&abc);  
		system("cls");
		if(abc==0) goto end;
		else goto again;
    }
    temp->money=temp->money-money0;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|            ȡ��ɹ�            |\n");
	printf("|��ȡ��%fԪ�����%fԪ|\n",money0,temp->money); 
	printf("|        ���������������ҳ      |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
	scanf ("%d",&abc);  
	system("cls");
	end:
		; 
}

void change(userp temp)//����
{
	int abc,password0,password1;
	again0:
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|         ������������           |\n"); 
	printf("|                                |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
    scanf ("%d",&password0); 
	system("cls");
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|       ���ٴ�����������         |\n"); 
	printf("|                                |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
    scanf ("%d",&password1); 
	system("cls");
	if(password0!=password1)
	{ 
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|        �������벻���          |\n"); 
		printf("|                                |\n");
		printf("|  ��1�������룬��0���ص�½����  |\n"); 
		printf("|                                |\n");   
		printf("+================================+\n");
	    scanf ("%d",&abc); 
		system("cls");
		if(abc==1) goto again0;
		else       goto end0;		
    }
    temp->password=password0;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|            ���ܳɹ�            |\n");
	printf("|                                |\n"); 
	printf("|     ������������ص�½����     |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
	scanf ("%d",&abc);  
	system("cls");
	end0: ;
}

void inquiry(userp temp)//��ѯ  
{
	int abc;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|         ���%fԪ       |\n",temp->money); 
	printf("|                                |\n");
	printf("|        ���������������ҳ      |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
	scanf ("%d",&abc);  
	system("cls");
}

void transfer(userp temp,userp head)//ת�� 
{
	int abc,use0,k;
	float  money0;
	again1:
	userp temp0=head;		
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|        ������ת�����˺�        |\n"); 
	printf("|                                |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
    scanf ("%d",&use0);
	system("cls");
	while(temp0)
	{
		if(temp0->use==use0) {abc=0;break;}
		temp0 = temp0->next;
		abc=1;
	}
	if(abc==1) 
	{
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|         �Ҳ�����ǰ�˺�         |\n"); 
		printf("|                                |\n");
		printf("|  ��0�������룬��1���ص�½ҳ��  |\n"); 
		printf("|                                |\n");   
		printf("+================================+\n");
	    scanf ("%d",&abc);
		system("cls");
        if(abc==0) goto again1;
        else goto end1;
	}

	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|         ������ת����         |\n"); 
	printf("|                                |\n");
	printf("|                                |\n");   
	printf("+================================+\n");
	scanf("%f",&money0);
	system("cls");
	k=1;
	if(money0>temp->money)
	{		
	    printf("+================================+\n");
		printf("|                                |\n");
		printf("|           ����             |\n");
		printf("|                                |\n"); 
		printf("|         ���ص�½����           |\n"); 
		printf("|                                |\n");   
		printf("+================================+\n");
		scanf ("%d",&abc);  
		system("cls");
		k=0; 
	}
	if(k==1)
	   {
		temp0->money=temp0->money+money0;
		temp ->money=temp ->money-money0;
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|                                |\n");
		printf("|            ת�˳ɹ�            |\n"); 
		printf("|                                |\n"); 
		printf("|                                |\n");   
		printf("+================================+\n");
		scanf("%f",&abc);
		system("cls");
		end1: ;
       }
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

