#include<conio.h>
#include<stdio.h> 
#include<string.h>
#include<windows.h>
#include <stdlib.h>
#include <malloc.h>
int sum;

typedef struct user 
{
    char   name[20];//身份证 
    char   use[20];//账号 
	char   password[20];//密码
	float  money;//余额 
	struct user *next;
}*userp;

userp open(userp head);//开户
userp landing(userp head);//登陆
userp  cancellation(userp head);//销户
void  deposit(userp temp);//存款 
void  draw(userp temp);//取款 
void  change(userp temp);//改密
void  inquiry(userp temp);//查询  
void  transfer(userp temp,userp head);//转账  
void  error();//提示错误
void  change(userp temp1,userp temp2);//交换连个节点的数据 
void  pai(userp head);//排序 
void  maopao(userp head);//冒泡排序 

//添加 
userp insert_head(char a[],char b[],char c[],userp head,userp newnode)
{
//创建一个新的链表用newnode表示
	newnode = (userp)malloc(sizeof(user));
//填充新的数据 
    strcpy(newnode->name,a);
    strcpy(newnode->use,b);
	strcpy(newnode->password,c); 
	newnode->money=0;  
//新的的next指向之前的头 
	newnode->next = head;
//之前deep头指向新的 
	head = newnode;	
	return head;
}

//输出 
void output(userp head)
{
	//temp从头开始一直到null 
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

//匹配帐号密码 
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

//销户专用 
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

userp old_data(userp head)//导入以前数据
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

void add(userp head)//把本次数据放到文件中保存
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
 printf("|         欢迎使用本ATM          |\n");
 printf("|                                |\n");   
 printf("|          请输入1登陆           |\n");
 printf("|                                |\n");
 printf("+================================+\n");
 scanf("%d",&abc);
 system("cls");
 head=old_data(head); //导入以前的数据！！！！！
 for(;;)
    {
	 printf("+================================+\n");
	 printf("|                                |\n");
	 printf("|        1.开户  2.登陆          |\n");
	 printf("|        3.销户  4.排序          |\n");   
	 printf("|        5.退出                  |\n");
	 printf("|     请输入相应的服务编号       |\n");
	 printf("+================================+\n");
     scanf("%d",&i);
     system("cls"); 
	 if(i!=1&&i!=2&&i!=3&&i!=4&&i!=5)
	   {
			error();//提示错误
	   }
	 else switch(i)
	 	{
		    case 1://开户 
		    head=open(head); break; 
		    case 2://登陆 
		    head=landing(head);break; 
		    case 3://销户 
		    head=cancellation(head);break; 
		    case 4://排序 
		    pai(head);break;
		    case 5://退出 
		    goto qqq;
	 	}
    }
  qqq:
  add(head);//把本次数据放到文件中保存
  output(head);	 
 }



userp open(userp head)//开户
{
//newnode是创造一个空变量准备用来当做新的链表的 
	userp newnode=NULL;
	int abc,j=0;
	char a[20],b[20],c[20];
    for(j=0;;)
	    {
		 printf("+================================+\n");
		 printf("|                                |\n");
		 printf("|        继续开户请输入1         |\n");
		 printf("|       返回上一层请输入2        |\n");   
		 printf("|                                |\n");
		 printf("|     请输入相应的服务编号       |\n");
		 printf("+================================+\n");
 	     scanf("%d",&j);  
		 system("cls");
		 if(j==2) break;
		 printf("+================================+\n");
		 printf("|                                |\n");
		 printf("|        请输入相应数据          |\n");
		 printf("|                                |\n");   
		 printf("|      身份证号，账号，密码      |\n");
		 printf("|                                |\n");
		 printf("+================================+\n"); 
	     scanf("%s%s%s",&a,&b,&c);
         system("cls"); /////////////////////需要判断里面是否有相同账号或身份证！！！！ 
		 head = insert_head(a,b,c,head,newnode);
	    }
	return head;
}

userp landing(userp head)//登陆
{
	userp cookie_temp;
	int abc,i;
	char a[20],b[20];
	for(;;)
	   {
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|                                |\n");
		printf("|       请输入账号和密码         |\n");   
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
			printf("|            输入错误            |\n");   
			printf("|                                |\n");
			printf("|输入1返回首页，输入其他重新输入 |\n");
			printf("|                                |\n");
			printf("+================================+\n");
			scanf ("%d",&abc);  
		    system("cls");
			if(abc==1) return head; 
		   }
	   }
	//登陆成功了！
	char cookie_use[20],cookie_password[20]; 
	strcmp(cookie_use,a)==0; 
	strcmp(cookie_password,b)==0;	
    for(;;)
    {
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|      登陆成功请继续操作        |\n");
	printf("|                                |\n");
	printf("|   1.存款  2.取款  3.改密       |\n");
	printf("|   4.查询  5.转账  6.退出       |\n");   
	printf("+================================+\n");
     scanf("%d",&i);
     system("cls"); 
	 if(i!=1&&i!=2&&i!=3&&i!=4&&i!=5&&i!=6)
	   {
			error();//提示错误
	   }
	 else switch(i)
	 	{
		    case 1://存款 
		    deposit(cookie_temp); break; 
		    case 2://取款 
		    draw(cookie_temp);break; 
		    case 3://改密 
		    change(cookie_temp);break;  
		    case 4://查询 
		    inquiry(cookie_temp);break;  
		    case 5://转账 
		    transfer(cookie_temp,head);break; 
		    case 6://退出 
		    return head;
	 	}
    }
}

userp cancellation(userp head)//销户
{
	char a[20],b[20];
	int abc;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|    请输入要销户的账号和密码    |\n");   
	printf("|                                |\n");
	printf("|                                |\n");
	printf("+================================+\n");
	scanf("%s%s",&a,&b);//////输入密码的时候隐藏密码 
    system("cls"); 
	if(head == NULL) sum=0;
	else head=deldata(a,b,head);
	
	if(sum==1)
	 {
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|           删除成功！           |\n");
		printf("|                                |\n");   
		printf("|     请输入任意键返回首页       |\n");
		printf("|                                |\n");
		printf("+================================+\n");
		scanf("%d",&abc);
		system("cls"); 
     }
	else
	   {
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|  找不到对应的账户或者密码错误  |\n");
		printf("|                                |\n");   
		printf("|      请输入任意键返回首页      |\n");
		printf("|                                |\n");
		printf("+================================+\n");
		scanf("%d",&abc);
		system("cls");
	   }
        return head;
}

void deposit(userp temp)//存款 
{
	int abc;
	float money0;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|        请输入存款金额          |\n"); 
	printf("|                                |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
    scanf ("%f",&money0); 
	system("cls");
    temp->money=temp->money+money0;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|            存款成功            |\n");
	printf("|已存入%f元，余额%f元|\n",money0,temp->money); 
	printf("|        输入任意键返回首页      |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
	scanf ("%d",&abc);  
	system("cls");
}

void draw(userp temp)//取款 
{
	int abc;
	float money0;
	again:
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|        请输入取款金额          |\n"); 
	printf("|                                |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
    scanf ("%f",&money0); 
	system("cls");
	if(temp->money<money0)  
	{ 
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|           余额不足             |\n");
		printf("|                                |\n"); 
		printf("|   按0登陆界面按其他重新输入    |\n"); 
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
	printf("|            取款成功            |\n");
	printf("|已取出%f元，余额%f元|\n",money0,temp->money); 
	printf("|        输入任意键返回首页      |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
	scanf ("%d",&abc);  
	system("cls");
	end:
		; 
}

void change(userp temp)//改密
{
	int abc;
	char password0[20],password1[20];
	again0:
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|         请输入新密码           |\n"); 
	printf("|                                |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
    scanf ("%s",&password0); 
	system("cls");
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|       请再次输入新密码         |\n"); 
	printf("|                                |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
    scanf ("%s",&password1); 
	system("cls");
	if(strcmp(password0,password1)!=0)
	{ 
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|        两次密码不相等          |\n"); 
		printf("|                                |\n");
		printf("|  按1重新输入，按0返回登陆界面  |\n"); 
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
	printf("|            改密成功            |\n");
	printf("|                                |\n"); 
	printf("|     输入任意键返回登陆界面     |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
	scanf ("%d",&abc);  
	system("cls");
	end0: ;
}

void inquiry(userp temp)//查询  
{
	int abc;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|         余额%f元       |\n",temp->money); 
	printf("|                                |\n");
	printf("|        输入任意键返回首页      |\n"); 
	printf("|                                |\n");   
	printf("+================================+\n");
	scanf ("%d",&abc);  
	system("cls");
}

void transfer(userp temp,userp head)//转账 
{
	int abc,k;
	char use0[20];
	float  money0;
	again1:
	userp temp0=head;		
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|        请输入转账人账号        |\n"); 
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
		printf("|         找不到当前账号         |\n"); 
		printf("|                                |\n");
		printf("|  按0重新输入，按1返回登陆页面  |\n"); 
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
	printf("|         请输入转入金额         |\n"); 
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
		printf("|           余额不足             |\n");
		printf("|                                |\n"); 
		printf("|         返回登陆界面           |\n"); 
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
		printf("|            转账成功            |\n"); 
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
	printf("|      请输入排序查询密码        |\n"); 
	printf("|                                |\n");
	printf("|       输入错误自动返回         |\n"); 
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
		printf("|           密码错误             |\n"); 
		printf("|                                |\n");
		printf("|      输入任意数返回首页！      |\n"); 
		printf("|                                |\n");   
		printf("+================================+\n");
	    printf("\n");
        scanf("%d",&abc);  
	    system("cls");
	  } 
}

void maopao(userp head)//冒泡排序 
{
	int abc; 
	if(head==NULL)
	  printf("当前还没有账户！\n");
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
	  printf("请输入任意数返回首页！\n");
      scanf("%d",&abc);  
	  system("cls");
}

void change(userp temp1,userp temp2)//交换连个节点的数据 
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

void error()//提示错误
{		 	 
    int abc;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|          输入错误！            |\n");
    printf("|                                |\n");
    printf("|        重新输入请按 1          |\n");
    printf("|                                |\n");    
    printf("+================================+\n");
    scanf ("%d",&abc);  
    system("cls"); 
}
