#include<stdio.h>
int x[3][3];
int jh()
 { 
  int a,b,k;
  for(b=0;b<3;b++)
     for(a=b+1;a<3;a++)
        {
         k=x[a][b];
         x[a][b]=x[b][a];
         x[b][a]=k;
        }
  return(x);
 }
int main()
{ 
    int a,b;
    for(a=0;a<3;a++)
     for(b=0;b<3;b++)
        scanf("%d",&x[a][b]);
    jh();
     for(a=0;a<3;a++)
        for(b=0;b<3;b++)
           printf("%d ",x[a][b]);
     system("pause");
     return 0;
}
