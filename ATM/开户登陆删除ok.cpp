#include<conio.h>
#include<stdio.h> 
#include<string.h>
#include<windows.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct user 
{
    int   name;//身份证 
    int    use;//账号 
	int    password;//密码 
	float  money;//余额 
	struct user *next;
}*userp;

userp open(userp head);//开户
userp landing(userp head);//登陆
userp  cancellation(userp head);//销户
void  deposit();//存款 
void  draw();//取款 
void  change();//改密
void  inquiry();//查询  
void  transfer();//转账  
void  old_data();//导入以前数据
void  error();//提示错误
void  add();//把本次数据放到文件中保存 

//添加 
userp insert_head(int a,int b,int c,userp head,userp newnode)
{
//创建一个新的链表用newnode表示 
	newnode = (userp)malloc(sizeof(user));
//填充新的数据 
    newnode->name=a; 
    newnode->use= b;
	newnode->password=c; 
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
		printf("%d \n",temp->name);
		printf("%d \n",temp->use);
		printf("%d \n",temp->password);
		temp = temp->next;
	}
}

//匹配帐号密码 
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

//销户专用 
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
			printf("|           删除成功！           |\n");
			printf("|                                |\n");   
			printf("|     请输入任意键返回首页       |\n");
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
				printf("|           删除成功！           |\n");
				printf("|                                |\n");   
				printf("|     请输入任意键返回首页       |\n");
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
	printf("|  找不到对应的账户或者密码错误  |\n");
	printf("|                                |\n");   
	printf("|      请输入任意键返回首页      |\n");
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
 printf("|         欢迎使用本ATM          |\n");
 printf("|                                |\n");   
 printf("|          请输入1登陆           |\n");
 printf("|                                |\n");
 printf("+================================+\n");
 scanf("%d",&abc);
 system("cls");
 old_data(); //导入以前的数据！！！！！
 for(;;)
    {
	 printf("+================================+\n");
	 printf("|                                |\n");
	 printf("|        1.开户  2.登陆          |\n");
	 printf("|        3.销户  4.退出          |\n");   
	 printf("|                                |\n");
	 printf("|     请输入相应的服务编号       |\n");
	 printf("+================================+\n");
     scanf("%d",&i);
     system("cls"); 
	 if(i!=1&&i!=2&&i!=3&&i!=4)
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
		    case 4://退出 
		    goto qqq;
	 	}
    }
  qqq:
  add();//把本次数据放到文件中保存
  output(head);	 
 }



userp open(userp head)//开户
{
//newnode是创造一个空变量准备用来当做新的链表的 
	userp newnode;
	int abc,j;
	int a,b,c;
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
	     scanf("%d%d%d",&a,&b,&c);
         system("cls"); /////////////////////需要判断里面是否有相同账号或身份证！！！！ 
		 head = insert_head(a,b,c,head,newnode);
	    }
	return head;
}

userp landing(userp head)//登陆
{
	int abc,i=0,a,b;
	for(;;)
	   {
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|                                |\n");
		printf("|       请输入账号和密码         |\n");   
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
	int cookie_use=a,cookie_password=b; 
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
		    deposit(); break; 
		    case 2://取款 
		    draw();break; 
		    case 3://改密 
		    change();break;  
		    case 4://查询 
		    inquiry();break;  
		    case 5://转账 
		    transfer();break; 
		    case 6://退出 
		    return head;
	 	}
    }
}

userp cancellation(userp head)//销户
{
	int a,b,abc;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|    请输入要销户的账号和密码    |\n");   
	printf("|                                |\n");
	printf("|                                |\n");
	printf("+================================+\n");
	scanf("%d%d",&a,&b);//////输入密码的时候隐藏密码 
    system("cls"); 
	if(head == NULL) 
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
	else 
	  head=deldata(a,b,head);
}


void deposit()//存款 
{
	int abc;
 printf("cunkuan\n");
     scanf ("%d",&abc);  
    system("cls"); 
}

void draw()//取款 
{
	int abc;
 printf("qukuan\n");
     scanf ("%d",&abc);  
    system("cls"); 
}

void change()//改密
{
	int abc;
 printf("gaimi\n");
     scanf ("%d",&abc);  
    system("cls"); 
}

void inquiry()//查询  
{
	int abc;
 printf("chaxun\n");
     scanf ("%d",&abc);  
    system("cls"); 
}

void transfer()//转账 
{
	int abc;
 printf("zhuanzhang\n");
     scanf ("%d",&abc);  
    system("cls"); 
}

void old_data()//导入以前数据
{
	int abc;
 printf("导入数据\n");
     scanf ("%d",&abc);  
    system("cls"); 
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

void add()//把本次数据放到文件中保存
{
	int abc;
 printf("导出数据函数\n");
    scanf ("%d",&abc);  
    system("cls"); 
}

