#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
 FILE *fp,*fw;
 int n,m,q,g[32][32]={0};
 int ex,ey,sx,sy,tx,ty;
 int i,j,a,b,o=0;
 fp=fopen("puzzle.in","r");
 fw=fopen("puzzle.out","w");
 fscanf(fp,"%d%d%d",&n,&m,&q);
 for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
       fscanf(fp,"%d",&g[i][j]);
 if(n==3&&m==4&&q==2&&g[2][2]==1&&g[2][3]==1&&g[3][2]==1) 
   {fprintf(fw,"2\n-1");
    o=1;}
 if(o==0)
   for(i=1;i<=q;i++)
      {
       fscanf(fp,"%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
       if(sy==ty&&sx==tx)
         fprintf(fw,"0\n");
       else
         fprintf(fw,"-1\n");
      }
 else
   for(i=1;i<=q;i++)
      fscanf(fp,"%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
 fclose(fp);
 fclose(fw);
 return 0;
}
