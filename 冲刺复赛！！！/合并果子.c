#include<stdio.h>
int main()
{
 int a[20000],b[20000]={0},n,ans=0;
 int i,j,k,min,min2,c,d;
 freopen("guozi.txt","r",stdin);
 freopen("ans.txt","w",stdout);
 scanf("%d",&n);
 
 for(i=0;i<n;i++)
    scanf("%d",&a[i]);

 for(d=0;d<n;d++)
    {
     min=ans;
     for(j=0;j<n;j++)
        {
         if(b[j]==0)
           if(min>a[j])
             {
              min=a[j];
              c=j;
             }
        }
     b[c]=1;
     min2=10000;
     for(i=0;i<n;i++)
        {
         if(b[i]==0)
           if(min2>a[i])
             {
              min2=a[i];
              c=j;
             }
        }
     b[c]=1;
     if(min!=ans)
       if(ans<min2)
         {
          min2=ans;
          b[c]=0;
         }
     ans=ans+min+min2;
    }
 printf("%d",ans);
 return 0;
}
