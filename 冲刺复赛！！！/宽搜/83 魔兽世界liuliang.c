#include<stdio.h>  0
int main()
{
 char z[101][101]={1}/*ͼ*//*��Ƿ�ֹ�ظ�*/;
 int x[4]={-1,0,1,0},y[4]={0,1,0,-1},w[2][10001]={0}/*���е�ǰλ��*/,l[101]={0}/*·��*/;
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
              if(z[f][g]=='0')//������ 
                {
                 z[ w[0][b] ] [ w[1][b] ] ='1';//���С�־Ͳ����ظ����� 
                 w[0][b]=f;
                 w[1][b]=g;
                 l[b]=l[c]+1;
                }
              else //����˲�� 
                if(z[f][g]>='A'&&z[f][g]<='Z')
                   for(d=0;d<n;d++)
                      for(e=0;e<m;e++)
                         if(z[f][g]==z[d][e]&&(f!=d||g!=e))
                           {//��ĸ��ͬ         ����ԭ�����Ǹ� 
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
