#include<stdio.h>  
int main()
{
 char z[101][101]={1}/*ͼ*//*��Ƿ�ֹ�ظ�*/;
 int x[4]={-1,0,1,0},y[4]={0,1,0,-1},w[2][10001]/*���е�ǰλ��*/,l[10000]={0}/*·��*/;
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
              if(z[ w[0][c]+x[a] ] [ w[1][c]+y[a] ] == '0')//������ 
                {
                 z [ w[0][b] ] [ w[1][b] ] = '1';
                 w[0][b]=w[0][c]+x[a];
                 w[1][b]=w[1][c]+y[a];
                 l[b]=l[c]++;
                // z [ w[0][b] ] [ w[1][b] ] = 1;//���С�־Ͳ����ظ����� 
                }
              else //����˲�� 
                if(z[w[0][c]+x[a]][w[1][c]+y[a]]>='A'&&z[w[0][c]+x[a]][w[1][c]+y[a]]<='Z')
                   for(d=1;d<=n;d++)
                      for(e=1;e<=m;e++)
                         if(z[w[0][c]+x[a]][w[1][c]+y[a]]==z[d][e]&&((w[0][c]+x[a])!=d||(w[1][c]+y[a])!=e))
                           {//��ĸ��ͬ                              ����ԭ�����Ǹ� 
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
