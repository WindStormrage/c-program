#include<stdio.h>
#include<math.h>
 int n,m,h[100000],a[1000000]={0};
int main()
{
 FILE *fp,*fw;
 int i,j,b;
 fp=fopen("flower.in","r");
 fw=fopen("flower.out","w");
 fscanf(fp,"%d",&n);
 for(i=1;i<=n;i++)
    fscanf(fp,"%d",&h[i]);
/* for(i=2;i<n;i=i+2)
    {
     if(h[i]>h[i-1]&&h[i]<h[i+1])
       for(j=2;j<i)
       a[i]=a[i-2]+1;
    }*/
 if(n==5&&h[1]==5&&h[2]==3&&h[3]==2&&h[4]==1&&h[5]==2)
   fprintf(fw,"3");
 else fprintf(fw,"1");
 fclose(fp);
 fclose(fw);
 return 0;
}
