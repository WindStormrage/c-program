/*1����дһ������ɾ���ַ�����������ָ���ַ���ͬ���ַ���
2����дһ���ж�һ�ַ����Ƿ�����һ�ַ����Ӵ��ĳ���
3����С��*/
#include<stdio.h>
int main()
{
    int n,a;
    char str[50],i/*��ɾ�����ַ�*/;
    printf("��ʼ�ַ���:");
     gets(str);
    printf("����ɾ�����ַ�:");
     scanf("%c",&i);
    str[n];
    for(n=0;n<=strlen(str)/*������*/;n++)
       {
        if(i==str[n])
          {
           for(a=1;a<=strlen(str)-n;a++)
              str[n+a-1]=str[n+a];        
           n==n--;
          }
       } 
    printf("%s\n",str);
    system("pause");
    return 0;
}
