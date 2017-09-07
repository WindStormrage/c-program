#include<stdio.h>
int main()
{
 float a,b,c,ans;
 scanf("%f",&a);
 if(a<=150.0)     ans=a*0.4463;
 else if(a<=400)  ans=150*0.4463+(a-150)*0.4663;
 else             ans=150*0.4463+250*0.4663+(a-400)*0.5663;
 printf("%.1f",ans);
 return 0;
}
