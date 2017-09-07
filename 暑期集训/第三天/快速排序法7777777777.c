#include<stdio.h>
int M=3;
int main()
{
 void qw(int k[],int right,int left);
 int k[M],key,right,left,a;
 for(a=0;a<=M;a++)
    scanf("%d",&k[a]); 
 key=k[0];
 for(right=M,left=0;;)
    { 
     right=key-1;
     left=key+1;
     if(right==left)
       break;
     qw(k[M],right,left);
    }
 for(a=0;a<=M;a++)
    printf("%d ",k[a]);
 system("pause");
 return 0;
}

void qw(int k[],int right,int left)
{ 
 int key=k[left]; 
 for(;right==left;right--,left++)
    {
     if(k[right]<key)
       {
        k[left]=k[right];
        k[right]=key; 
       }
     else 
       {
        for(;k[right]<key;right--)
           break;
        k[left]=k[right];
        k[right]=key; 
       }
     if(k[left]>key)
       { 
        k[right]=k[left];
        k[left]=key;
       }
     else
       {
        for(;k[left]<key;left++)
           break;
        k[right]=k[left];
        k[left]=key; 
       }
    }
}
