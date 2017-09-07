#include<stdio.h>
#include<time.h>
int main()
{  int x,a=1,b;
   long int y;
   y=time(0)%100;
   printf("请猜一个数字(你只有五次机会):");
   for(;a<=5;a++)
   { 
    scanf("%d",&x);
    if(x>y)
      printf("\n亲，高了！\n");
    else
        if(x<y)
          printf("亲，低了！\n");
        else
            {
              printf("哇，恭喜你！通关！");
              a==7;
              break;
             }
    } 
    if(a==6)
        {
         printf("对不起，请继续加油！\n");
         printf("正确答案为：%d\n",y);
        }   
    system("pause");
    return 0;
               }
    
    
    
    
    
    
    
    

