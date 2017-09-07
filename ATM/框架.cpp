#include<conio.h>
#include<stdio.h> 
#include<string.h>
#include<windows.h>

void  open();//开户
int  landing();//登陆
void  cancellation();//销户
void  deposit();//存款 
void  draw();//取款 
void  change();//改密
void  inquiry();//查询  
void  transfer();//转账  

void  old_data();//导入以前数据
void  error();//提示错误
void  add();//把本次数据放到文件中保存 


typedef struct users  
{  
    int use;
	int password;
	int money;
    struct users *next;  
}users;  

int  main()
{
 int i,abc,n;
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
		    open(); break; 
		    case 2://登陆 
		    abc=landing();break; 
		    case 3://销户 
		    cancellation();break; 
		    case 4://退出 
		    goto qqq;
	 	}
    }
  qqq:
  add();//把本次数据放到文件中保存 
 }



void open()//开户
{
	int abc;
 printf("开户函数\n");
     scanf ("%d",&abc);  
    system("cls"); 
}

int landing()//登陆
{
	int abc,i;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|       请输入账号和密码         |\n");   
	printf("|                                |\n");
	printf("|                                |\n");
	printf("+================================+\n");
	scanf ("%d",&abc);  
    system("cls"); 
    for(;;)
    {
	printf("+================================+\n");
	printf("|      登陆成功请继续操作        |\n");
	printf("|   1.存款  2.取款  3.改密       |\n");
	printf("|   4.查询  5.转账  6.退出       |\n");   
	printf("|                                |\n");
	printf("|                                |\n");
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
		    return 0;
	 	}
    }
}

void cancellation()//销户
{
	int abc;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|    请输入要销户的账号和密码    |\n");   
	printf("|                                |\n");
	printf("|                                |\n");
	printf("+================================+\n");
	    scanf ("%d",&abc);  
    system("cls"); 
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

