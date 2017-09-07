#include<stdio.h>
int main()
{
 int k[500][500]={0},w[500],z[500][500]={0},n,min,max;
 int a,b,c,d,e,f;
 scanf("%d",&n);
 for(a=0;a<n;a++)
    scanf("%d",&w[a]);
 for(a=6,b=0;a<2*n-1;a++,b++)
    w[a]=w[b];
 for(a=0;a<2*n;a++)
    k[a][a]=0;
 for(a=1;a<2*n-1;a++)    //min
    for(b=0,c=a,min=20000;b<2*n-1;b++,c++)
       {
        if(k[b+1][c]<k[b][c-1])
          min=k[b+1][c];
        else
          min=k[b][c-1];
        for(d=1;d<n;d++)//d为下面还有的个数 
           if(k[b+d][c]==0)
             {
              for(e=2;e<d;e++)
                 if(k[b+d-e+1][c]+k[b][c-e]<min)
                   min=k[b+d-e+1][c]+k[b][c-e];
              break;
             }
        k[b][c]=min;
        for(f=b;f<=c;f++)
           k[b][c]=k[b][c]+w[f];
       }

 for(a=1;a<2*n-1;a++)    //max
    for(b=0,c=a,max=0;b<2*n-1;b++,c++)
       {
        if(z[b+1][c]>z[b][c-1])
          max=z[b+1][c];
        else
          max=z[b][c-1];
        for(d=1;d<n;d++)//d为下面还有的个数 
           if(z[b+d][c]==0)
             {
              for(e=2;e<d;e++)
                 if(z[b+d-e+1][c]+z[b][c-e]>max)
                   max=z[b+d-e+1][c]+z[b][c-e];
              break;
             }
        z[b][c]=max;
        for(f=b;f<=c;f++)
           z[b][c]=z[b][c]+w[f];
       }

for(a=0;a<2*n;a++)
 {   for(b=0;b<2*n;b++)
       printf("%d  ",k[a][b]);
    printf("\n");
}
    printf("\n");
    
for(a=0;a<2*n;a++)
 {   for(b=0;b<2*n;b++)
       printf("%d  ",z[a][b]);
    printf("\n");
}
    printf("\n"); 

 min=100000;
 max=0;
 for(b=0,a=n-1;a<2*n-1;b++,a++)
    {
     if(z[b][a]>max)
       max=z[b][a];
     if(k[b][a]<min)
       min=k[b][a];
    }
 printf("%d\n%d",min,max);
 system("pause");
 return 0; 
} 
