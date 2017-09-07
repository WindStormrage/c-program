#include<stdio.h>
#include<math.h>

int main()
{
 FILE *fp,*fw;
 int n,h[100000]={0},ans=0;
 int i,j,a;
 fp=fopen("block.in","r");
 fw=fopen("block.out","w");
 fscanf(fp,"%d",&n);
 for(i=0;i<n;i++)
    fscanf(fp,"%d",&h[i]);

 for(i=0;i<n;)
    {
     if(h[i]>0)
       {
        for(j=i+1;j<n;j++)
           {
            if(h[j]<=0)
              break;
           }
        for(a=i;a<j;a++)
           h[a]--;
        ans++;
       }
     else i++;
    }
 fprintf(fw,"%d",ans);

 fclose(fp);
 fclose(fw);
 return 0;
}
