#include<conio.h>
#include<stdio.h> 
#include<string.h>
#include<windows.h>
#include <stdlib.h>
#include <malloc.h>
int sum;

typedef struct user 
{
    char   name[20];//���֤ 
    char   use[20];//�˺� 
	char   password[20];//����
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
void  error();//��ʾ����
void  change(userp temp1,userp temp2);//���������ڵ������ 
void  pai(userp head);//���� 
void  maopao(userp head);//ð������ 

//��� 
userp insert_head(char a[],char b[],char c[],userp head,userp newnode)
{
//����һ���µ�������newnode��ʾ
	newnode = (userp)malloc(sizeof(user));
//����µ����� 
    strcpy(newnode->name,a);
    strcpy(newnode->use,b);
	strcpy(newnode->password,c); 
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
		printf("+================================+\n");
		printf("mane:%s \n",temp->name);
		printf("use:%s \n",temp->use);
		printf("password:%s \n",temp->password);
		printf("money:%f \n",temp->money);
		printf("+================================+\n");
		temp = temp->next;
	}
}

//ƥ���ʺ����� 
userp find(char a[],char b[],userp head)
{
	userp temp = head;
	while(temp)
	{
		if(strcmp(temp->use,a)==0&&strcmp(temp->password,b)==0) {sum=1;return temp;};
		temp = temp->next;
	}
	sum=0;
	return temp;
}

//����ר�� 
userp deldata(char a[],char b[],userp head)
{
	userp temp = head,temp0;
	if(strcmp(temp->use,a)==0&&strcmp(temp->password,b)==0)
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
			if(strcmp(temp->use,a)==0&&strcmp(temp->password,b)==0)
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

userp old_data(userp head)//������ǰ����
{	
	    FILE *fp;
    	userp newnode;
     	newnode = (userp)malloc(sizeof(user));
    	newnode->next=NULL;
		fp=fopen("data.txt","r");
    	while (!feof(fp))
    		{
			 	fscanf(fp,"%s%s%s%f",&newnode->name,&newnode->use,&newnode->password,&newnode->money); 
			 	head = newnode;	
     			newnode = (userp)malloc(sizeof(user));
			 	newnode->next = head;
			}
		fclose(fp);
		head = newnode;	
    	return head;  
}

void add(userp head)//�ѱ������ݷŵ��ļ��б���
{
		FILE *fp;
    	userp newnode=head;
		fp=fopen("data.txt","w");
    	while (newnode!=NULL)
	    	{
			   fprintf(fp,"%s %s %s %f\n",newnode->name,newnode->use,newnode->password,newnode->money); 
			   newnode=newnode->next;
			}
	    fclose(fp);
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
 head=old_data(head); //������ǰ�����ݣ���������
 for(;;)
    {
	 printf("+================================+\n");
	 printf("|                                |\n");
	 printf("|        1.����  2.��½          |\n");
	 printf("|        3.����  4.����          |\n");   
	 printf("|        5.�˳�                  |\n");
	 printf("|     ��������Ӧ�ķ�����       |\n");
	 printf("+================================+\n");
     scanf("%d",&i);
     system("cls"); 
	 if(i!=1&&i!=2&&i!=3&&i!=4&&i!=5)
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
		    case 4://���� 
		    pai(head);break;
		    case 5://�˳� 
		    goto qqq;
	 	}
    }
  qqq:
  add(head);//�ѱ������ݷŵ��ļ��б���
  output(head);	 
 }



userp open(userp head)//����
{
//newnode�Ǵ���һ���ձ���׼�����������µ������ 
	userp newnode=NULL;
	int abc,j=0;
	char a[20],b[20],c[20];
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
	     scanf("%s%s%s",&a,&b,&c);
         system("cls"); /////////////////////��Ҫ�ж������Ƿ�����ͬ�˺Ż����֤�������� 
		 head = insert_head(a,b,c,head,newnode);
	    }
	return head;
}

userp landing(userp head)//��½
{
	userp cookie_temp;
	int abc,i;
	char a[20],b[20];
	for(;;)
	   {
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|                                |\n");
		printf("|       �������˺ź�����         |\n");   
		printf("|                                |\n");
		printf("|                                |\n");
		printf("+================================+\n");
		scanf ("%s%s",&a,&b);
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
	char cookie_use[20],cookie_password[20]; 
	strcmp(cookie_use,a)==0; 
	strcmp(cookie_password,b)==0;	
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
	char a[20],b[20];
	int abc;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|    ������Ҫ�������˺ź�����    |\n");   
	printf("|                                |\n");
	printf("|                                |\n");
	printf("+================================+\n");
	scanf("%s%s",&a,&b);//////���������ʱ���������� 
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
	int abc;
	char password0[20],password1[20];
	again0:
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|         ������������           |\n"); 
	printf("|                                |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
    scanf ("%s",&password0); 
	system("cls");
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|       ���ٴ�����������         |\n"); 
	printf("|                                |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
    scanf ("%s",&password1); 
	system("cls");
	if(strcmp(password0,password1)!=0)
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
    strcpy(temp->password,password0);
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
	int abc,k;
	char use0[20];
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
    scanf ("%s",&use0);
	system("cls");
	while(temp0)
	{
		if(strcmp(temp0->use,use0)==0) {abc=0;break;}
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

void pai(userp head)
{
	int abc;
	char mima[10],mima0[10]={'0','0','0','0','0','0'}; 
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|      �����������ѯ����        |\n"); 
	printf("|                                |\n");
	printf("|       ��������Զ�����         |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
	scanf("%s",&mima);
    system("cls");
	if(strcmp(mima,mima0)==0)
	  maopao(head);
	else
	  {
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|           �������             |\n"); 
		printf("|                                |\n");
		printf("|      ����������������ҳ��      |\n"); 
		printf("|                                |\n");   
		printf("+================================+\n");
	    printf("\n");
        scanf("%d",&abc);  
	    system("cls");
	  } 
}

void maopao(userp head)//ð������ 
{
	int abc; 
	if(head==NULL)
	  printf("��ǰ��û���˻���\n");
	else
	  {  
		if(head->next!=NULL)
		  {		
			userp temp1,temp2,temp0;
			for(temp1=head;temp1!=NULL;temp1=temp1->next)
			   { 	
			    if(temp1==NULL) break;
				for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
				   {
				    if(temp2==NULL) break;
			        if(temp1->money<temp2->money)
				      { 
			  		   temp0=temp2;
			           change(temp0,temp1);
			          }
			       }
		       }
	      }
	      output(head);	
	   }
	  printf("������������������ҳ��\n");
      scanf("%d",&abc);  
	  system("cls");
}

void change(userp temp1,userp temp2)//���������ڵ������ 
{
	char a[20],b[20],c[20];
    float money0;
    strcpy(a,temp1->name); 
    strcpy(b,temp1->use);
	strcpy(c,temp1->password); 
	money0=temp1->money;  	
	
    strcpy(temp1->name,temp2->name); 
    strcpy(temp1->use,temp2->use);
	strcpy(temp1->password,temp2->password); 
	temp1->money=temp2->money; 
		
    strcpy(temp2->name,a); 
    strcpy(temp2->use,b);
	strcpy(temp2->password,c); 
	temp2->money=money0;  		
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
