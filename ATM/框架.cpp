#include<conio.h>
#include<stdio.h> 
#include<string.h>
#include<windows.h>

void  open();//����
int  landing();//��½
void  cancellation();//����
void  deposit();//��� 
void  draw();//ȡ�� 
void  change();//����
void  inquiry();//��ѯ  
void  transfer();//ת��  

void  old_data();//������ǰ����
void  error();//��ʾ����
void  add();//�ѱ������ݷŵ��ļ��б��� 


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
		    open(); break; 
		    case 2://��½ 
		    abc=landing();break; 
		    case 3://���� 
		    cancellation();break; 
		    case 4://�˳� 
		    goto qqq;
	 	}
    }
  qqq:
  add();//�ѱ������ݷŵ��ļ��б��� 
 }



void open()//����
{
	int abc;
 printf("��������\n");
     scanf ("%d",&abc);  
    system("cls"); 
}

int landing()//��½
{
	int abc,i;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|       �������˺ź�����         |\n");   
	printf("|                                |\n");
	printf("|                                |\n");
	printf("+================================+\n");
	scanf ("%d",&abc);  
    system("cls"); 
    for(;;)
    {
	printf("+================================+\n");
	printf("|      ��½�ɹ����������        |\n");
	printf("|   1.���  2.ȡ��  3.����       |\n");
	printf("|   4.��ѯ  5.ת��  6.�˳�       |\n");   
	printf("|                                |\n");
	printf("|                                |\n");
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
		    return 0;
	 	}
    }
}

void cancellation()//����
{
	int abc;
	printf("+================================+\n");
	printf("|                                |\n");
	printf("|                                |\n");
	printf("|    ������Ҫ�������˺ź�����    |\n");   
	printf("|                                |\n");
	printf("|                                |\n");
	printf("+================================+\n");
	    scanf ("%d",&abc);  
    system("cls"); 
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

