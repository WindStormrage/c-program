/*  01 2 3 4 5 6 7 8 9
  1        *
  2      *   * 
  3    *       * 
  4  *           * 
  5*               * 
  1  *           *  
  2    *       * 
  3      *   * 
  4        * 
 前五行： 
 行(i)                 *所在的列(j)
 1                      5      5 
 2                      4      6
 3                      3      7
 4                      2      8
 5                      1      9
 行列关系               6-i    4+i
 与n(边上*的个数)的关系 n+1-i  n-1+i 
 后四行： 
 行(i)                 *所在的列(j)
 1                      2      8
 2                      3      7
 3                      4      6
 4                      5      5
 行列关系               i+1    9-i 
 与n(边上*的个数)的关系        2*n-1-i    */ 

#include<stdio.h>
int main()
{
 int j,i; 
 for(i=1;i<=5;i++)            /* 前面有五行* */
    {                          
     for(j=1;j<=i+4;j++)      /* *所在位置最大为i+4 */
        {
         if(j==6-i||j==4+i)   /* 当j到对应位置时才输出* */
             {
              printf("*");
             }
         else                 /* 否则就输出空格 */
             {
              printf(" ");
             }
        } 
         printf("\n");        /* 循环了一行后就划行 */ 
    }
 for(i=1;i<=4;i++)            /* 以下同理 */ 
   {
    for(j=1;j<=9-i;j++)
       {
        if(j==i+1||j==9-i)
            {
             printf("*");
            }
        else
            {
             printf(" ");
            }
        }
        printf("\n");
   }
 system("pause");
 return 0;
}
