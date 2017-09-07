#include<stdio.h> 
#include <windows.h>

	int withdrawal(int ye);
	int deposit(int ye);
	int query(int ye);
	int CTP(char mm);


int main()
{

	char zh/*账号*/,mm/*密码*/;
	int  a=1,x/*代号*/,ye=0/*余额*/;
	printf("+====================+\n");
	printf("|   欢迎使用本ATM    |\n");
	printf("|                    |\n");    
	printf("|     请按1登陆      |\n");
    printf("+====================+\n");
scanf("%d");
    system("cls");
	printf("+====================+\n");
	printf("|   请输入账号密码   |\n");
	printf("|                    |\n"); 
    printf("|    以回车键间隔    |\n");
    printf("+====================+\n");
    scanf("%s%s",&zh,&mm);    
	system("cls"); 
    //ye=ye-51;//不知道为什么？？！！！！！！！！！！！！！！！ 
	for(;;) 
   	   {
	    printf("+====================+\n");
	    printf("|1.取款 2.存款 3.查询|\n");
        printf("|4.改密 5.结束服务   |\n");
        printf("|请输入相应的服务编号|\n");    
        printf("+====================+\n");
        scanf ("%d",&x);
        system("cls"); 
		switch(x)
	      {
	       case 1://取款 
	           ye=withdrawal(ye);
 	   	       break; 
	       case 2://存款 
	           ye=deposit(ye);
		       break; 
    	   case 3://查询 
	           query(ye);
		       break; 
	       case 4://改密 
	           mm=CTP(mm);
		       break; 
	       case 5:
	           a=0;
			   break; 
	      }
	    if(a==0)  break;
       }
    return 0;
}
//取款 
int withdrawal(int ye)
{
 int a,b; 
 printf("请输入取款金额");
 for(;;)
    {
	 scanf ("%d",&a);
     if(a<=ye) 
       { 
    	ye=ye-a;
        b=1;
       }
     else      
       {
        printf("对不起，您的余额不足，请重新输入:"); 
        b=0;
       }
     if(b==1) 
       { 
		printf("取款成功，请按1返回"); 
        scanf("%d"); 
        system("cls");
		break;
       }
	}
 return(ye);
}
//存款 
int deposit(int ye)
{
 int a;
 printf("请输入存款金额: ");
 scanf ("%d",&a);
 ye=ye+a;
 printf("存款成功，请输入1返回。");
 scanf("%d"); 
 system("cls"); 
 return(ye);
}
//查询 
int query(int ye)
{
 printf("+====================+\n"   );
 printf("|   账号余额: %d元   |\n",ye);
 printf("|                    |\n"   );    
 printf("|     返回请按1      |\n"   );
 printf("+====================+\n"   );
 scanf ("%d");
 system("cls"); 
 return(0);
}
//改密 
int CTP(char mm)
{
 printf("请输入更改后的密码: ");
 scanf("%s",&mm);
 printf("改密成功，请输入1返回。");
 scanf("%d"); 
 system("cls"); 
 return(mm);
}
