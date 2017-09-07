#include<stdio.h>  
int main()
{
 char z[101][101]={1}/*图*//*标记防止重复*/;
 int x[4]={-1,0,1,0},y[4]={0,1,0,-1},w[2][10001]/*队列当前位置*/,l[10000]={0}/*路程*/;
 int n,m;
 int a,b=1,c=0,d,e,f,g;
 freopen("wow.in","r",stdin);
 freopen("ans.out","w",stdout);
 scanf("%d%d\n",&n,&m);
 for(a=1;a<=n;a++)
    {
     for(d=1;d<=m;d++)
        scanf("%c",&z[a][d]);
     scanf("\n");
    }

 z[1][1]=1;
 w[0][0]=1;
 w[1][0]=1;
 while(b>c)
    {
     for(a=0;a<4;a++)
        {
              if(z[ w[0][c]+x[a] ] [ w[1][c]+y[a] ] == '0')//可以走 
                {
                 z [ w[0][b] ] [ w[1][b] ] = '1';
                 w[0][b]=w[0][c]+x[a];
                 w[1][b]=w[1][c]+y[a];
                 l[b]=l[c]++;
                // z [ w[0][b] ] [ w[1][b] ] = 1;//变成小怪就不会重复走了 
                }
              else //考虑瞬移 
                if(z[w[0][c]+x[a]][w[1][c]+y[a]]>='A'&&z[w[0][c]+x[a]][w[1][c]+y[a]]<='Z')
                   for(d=1;d<=n;d++)
                      for(e=1;e<=m;e++)
                         if(z[w[0][c]+x[a]][w[1][c]+y[a]]==z[d][e]&&((w[0][c]+x[a])!=d||(w[1][c]+y[a])!=e))
                           {//字母相同                              不是原来的那个 
                            w[0][b]=d;
                            w[1][b]=e;
                            l[b]=l[c]++;
                            z[ w[0][c] ] [ w[1][c] ]=1;
                            //z[d][e]=1;
                           }
              if(w[0][b]==n&&w[1][b]==m)
                {
                 printf("%d",l[b]);
                 return 0;
                }
              b++;
        }
     c++;
    }
 printf("No Solution.");
 return 0;
}
