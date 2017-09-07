#include<stdio.h>  0
int main()
{
 char z[101][101]={1}/*图*//*标记防止重复*/;
 int x[4]={-1,0,1,0},y[4]={0,1,0,-1},w[2][10001]={0}/*队列当前位置*/,l[101]={0}/*路程*/;
 int n,m;
 int a,b=1,c=0,d,e,f,g;
 freopen("wow.in","r",stdin);
 freopen("ans.out","w",stdout);
 scanf("%d%d\n",&n,&m);
 for(a=0;a<n;a++)
     scanf("%s",&z[a]);

 z[0][0]=1;
 w[0][0]=0;
 w[1][0]=0;
 
 while(b>c)
    {
     for(a=0;a<4;a++)
        {
         f=w[0][c]+x[a];
         g=w[1][c]+y[a];
              if(z[f][g]=='0')//可以走 
                {
                 z[ w[0][b] ] [ w[1][b] ] ='1';//变成小怪就不会重复走了 
                 w[0][b]=f;
                 w[1][b]=g;
                 l[b]=l[c]+1;
                }
              else //考虑瞬移 
                if(z[f][g]>='A'&&z[f][g]<='Z')
                   for(d=0;d<n;d++)
                      for(e=0;e<m;e++)
                         if(z[f][g]==z[d][e]&&(f!=d||g!=e))
                           {//字母相同         不是原来的那个 
                            w[0][b]=d;
                            w[1][b]=e;
                            l[b]=l[c]+1;
                            z[ w[0][c] ] [ w[1][c] ]='1';
                           }
              if(w[0][b]==n-1&&w[1][b]==m-1)
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
