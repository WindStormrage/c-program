#include<stdio.h>  
int main()
{
 char z[102][102]={-1}/*图*/;
 int x[4]={-1,0,1,0},y[4]={0,1,0,-1},k[101][101]={0}/*标记防止重复*/,w[2][10001]/*队列*/,l[10000]={0}/*路程*/;
 int n,m;
 int a,b=1,c=0,d,e,f,g;
 freopen("wow.in","r",stdin);
 freopen("ans.out","w",stdout);
 scanf("%d%d\n",&n,&m);
 for(a=1;a<=n;a++)
    for(d=1;d<=m;d++)
       {
        scanf("%c",&z[a][d]);
        scanf("\n");
       }

 k[1][1]=1;
 w[0][0]=1;
 w[1][0]=1;
 while(b!=c)
    {
     for(a=0;a<4;a++)
        {
        // if(w[0][c]+x[a]>0&&w[0][c]+x[a]<=m&&w[1][c]+y[a]>0&&w[1][c]+y[a]<=n)
           if(k[ w[0][c]+x[a] ] [ w[1][c]+y[a] ] == 0)
             {
              if(z[ w[0][c]+x[a] ] [ w[1][c]+y[a] ]== 0)
                {
                 w[0][b]=w[0][c]+x[a];
                 w[1][b]=w[1][c]+y[a];
                 l[b]=l[c]+1;
                 k [ w[0][b] ] [ w[1][b] ] = 1;
                }
              else 
                if(z[ w[0][c]+x[a] ] [ w[1][c]+y[a] ] >= 'A'&&z[ w[0][c]+x[a] ] [ w[1][c]+y[a] ] <= 'z')
                  {
                   for(d=1;d<=n;d++)
                      for(e=1;e<=m;e++)
                         if(z[ w[0][c]+x[a] ] [ w[1][c]+y[a] ]==z[d][e]&&(w[0][c]+x[a])!=d&&(w[1][c]+y[a])!=e)
                           {
                            w[0][b]=d;
                            w[1][b]=e;
                            l[b]=l[c]+1;
                            k [d][e]=1;
                           }
                  }   
              if(w[0][b]==n&&w[1][b]==m)
                {
                 printf("%d",l[b]);
                 return 0;
                }
              b++;
             }
        }
     c++;
    }
 printf("No Solution.");
 return 0;
}
