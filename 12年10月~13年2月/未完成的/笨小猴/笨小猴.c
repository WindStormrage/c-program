//3����С��
/*#include<stdio.h>
int main()
{
    int n,c,d,maxn=0*�����ĸ�ĸ���*,min=0*������ĸ�ĸ���*;
    char i[100][24]*��Ϊͬ���ַ�,��Ϊ������ĸ*,word[100]*a����������ĸ/,b�������ٵ���ĸ*,out*���;
    printf("������Ҫ���ĵ���");
     gets(word);
    word[n];
    i[c][d];
    for(n=0;n<=strlen(word)/*������*;n++)
       {
        word[n]=a;
        for(c=0,d=0;;)
           {
            i[c][d]=a
           } 
       } 
    printf("%s\n",);
    system("pause");
    return 0;
}*/



//������Ҫ�����ĸ��
//��һ��һά�������ÿһ����ĸ�Ĵ����������ǣ�
//��ÿ����ĸѭ��һ�Σ�����˵��a����a���롾a-97��=��0����i[a-97]++.��b��into��b-97��=��1��i[b-97]++�� 
//Ȼ����������С�ģ�Ȼ�󡣡��� 
#include<stdio.h>
#include<string.h>
int main()
{
    int m,k,n,a,b,maxn/*�����ĸ�ĸ���*/,min/*������ĸ�ĸ���*/;
    char i[23],word[100];
    printf("�������ⵥ��"); 
     gets(word);
    word[n];
    for(n=0;n<=strlen(word)/*������*/;n++)
       {
        word[n]=b;
        i[b-97]++;
       }
    for(i[a],a=0,maxn=i[0];a<24;a++)
       {
        if(i[a]>maxn)
          maxn=i[a];
       }
    for(i[a],a=0,min=i[0];a<24;a++)
       {
        if(i[a]<min)
          min=i[a];
       } 
    
   // �������ֳ������������ǳ���1��������û���������ӵ�������
   // ע��1����������
   k==maxn-min;
    if(k==1)
      goto remove;
    for(m=2;m<k;m++)
    {
     if(k%m==0)//���k��m���� 
       {
        remove:
        printf("No Answer\n0");//��Ϊ����
        goto to;
       }
    }
    printf("Lucky Work\nk,");//Ϊ����
    to:
    return 0;
}
