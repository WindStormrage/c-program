#include<stdio.h>
long int m[200000];
int fg(int left,int right)// fg(k,left,right)
{
 long int key=m[left];
 while(left<right) //left==right时退出循环 
    { 
     while(left<right&&m[right]>=key)//key在左，找比key小的数 
        right--;
     m[left]=m[right];
     while(left<right&&m[left]<=key) //key在右，找比key大的数 
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
    kp(left,i-1); //分开 
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

