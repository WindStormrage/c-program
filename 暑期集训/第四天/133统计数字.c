#include<stdio.h>
long int m[200000];
int fg(int left,int right)// fg(k,left,right)
{
 long int key=m[left];
 while(left<right) //left==rightʱ�˳�ѭ�� 
    { 
     while(left<right&&m[right]>=key)//key�����ұ�keyС���� 
        right--;
     m[left]=m[right];
     while(left<right&&m[left]<=key) //key���ң��ұ�key����� 
        left++;
     m[right]=m[left]; 
    } 
 m[left]=key;
 return left; 
} 
int kp(int left,int right) //kp(k,0,a-1); 
{ 
 int i; 
 if(left<right)
   {
    i=fg(left,right);
    kp(left,i-1); //�ֿ� 
    kp(i+1,right); 
   } 
} 



int main()
{
 int q,p,c;
 scanf("%d",&p);
 for(q=0;q<p;q++) 
    scanf("%ld",&m[q]);
 kp(0,p-1);
 for(q=0,c=1;q<p;q++)
    {
     printf("%ld ",m[q]); 
     while(m[q]==m[q+1])
       {
        c++;
        q++;
       }
     printf("%d\n",c); 
     c=1;
    } 
 system("pause");
 return 0;
}

