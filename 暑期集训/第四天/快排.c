#include<stdio.h>
#define M 12
int fg(int k[],int left,int right)// fg(k,left,right)
{
 int key=k[left];
 while(left<right) //left==rightʱ�˳�ѭ�� 
    { 
     while(left<right&&k[right]>=key)//key�����ұ�keyС���� 
        --right;
     k[left]=k[right];
     while(left<right&&k[left]<=key) //key���ң��ұ�key����� 
        ++left;
     k[right]=k[left]; 
    } 
 k[left]=key;
 return left; 
} 

kp(int k[],int left,int right) //kp(k,0,a-1); 
{ 
 int i; 
 int a;
 if(left<right)
   {
    i=fg(k,left,right);
    kp(k,left,i-1); //�ֿ� 
    kp(k,i+1,right); 
   } 
} 

int main()
{
 int k[M],a;
 for(a=0;a<M;a++)
    scanf("%d",&k[a]);  
 kp(k,0,M-1);
 for(a=0;a<M;a++)
    printf("%d ",k[a]);
 system("pause");
 return 0;
}

