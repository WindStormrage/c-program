#include<stdio.h> 
#include <windows.h>

	int withdrawal(int ye);
	int deposit(int ye);
	int query(int ye);
	int CTP(char mm);


int main()
{

	char zh/*�˺�*/,mm/*����*/;
	int  a=1,x/*����*/,ye=0/*���*/;
	printf("+====================+\n");
	printf("|   ��ӭʹ�ñ�ATM    |\n");
	printf("|                    |\n");    
	printf("|     �밴1��½      |\n");
    printf("+====================+\n");
scanf("%d");
    system("cls");
	printf("+====================+\n");
	printf("|   �������˺�����   |\n");
	printf("|                    |\n"); 
    printf("|    �Իس������    |\n");
    printf("+====================+\n");
    scanf("%s%s",&zh,&mm);    
	system("cls"); 
    //ye=ye-51;//��֪��Ϊʲô���������������������������������� 
	for(;;) 
   	   {
	    printf("+====================+\n");
	    printf("|1.ȡ�� 2.��� 3.��ѯ|\n");
        printf("|4.���� 5.��������   |\n");
        printf("|��������Ӧ�ķ�����|\n");    
        printf("+====================+\n");
        scanf ("%d",&x);
        system("cls"); 
		switch(x)
	      {
	       case 1://ȡ�� 
	           ye=withdrawal(ye);
 	   	       break; 
	       case 2://��� 
	           ye=deposit(ye);
		       break; 
    	   case 3://��ѯ 
	           query(ye);
		       break; 
	       case 4://���� 
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
//ȡ�� 
int withdrawal(int ye)
{
 int a,b; 
 printf("������ȡ����");
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
        printf("�Բ����������㣬����������:"); 
        b=0;
       }
     if(b==1) 
       { 
		printf("ȡ��ɹ����밴1����"); 
        scanf("%d"); 
        system("cls");
		break;
       }
	}
 return(ye);
}
//��� 
int deposit(int ye)
{
 int a;
 printf("����������: ");
 scanf ("%d",&a);
 ye=ye+a;
 printf("���ɹ���������1���ء�");
 scanf("%d"); 
 system("cls"); 
 return(ye);
}
//��ѯ 
int query(int ye)
{
 printf("+====================+\n"   );
 printf("|   �˺����: %dԪ   |\n",ye);
 printf("|                    |\n"   );    
 printf("|     �����밴1      |\n"   );
 printf("+====================+\n"   );
 scanf ("%d");
 system("cls"); 
 return(0);
}
//���� 
int CTP(char mm)
{
 printf("��������ĺ������: ");
 scanf("%s",&mm);
 printf("���ܳɹ���������1���ء�");
 scanf("%d"); 
 system("cls"); 
 return(mm);
}
