#include<stdio.h>
#include<time.h>
int main()
{  int x,a=1,b;
   long int y;
   y=time(0)%100;
   printf("���һ������(��ֻ����λ���):");
   for(;a<=5;a++)
   { 
    scanf("%d",&x);
    if(x>y)
      printf("\n�ף����ˣ�\n");
    else
        if(x<y)
          printf("�ף����ˣ�\n");
        else
            {
              printf("�ۣ���ϲ�㣡ͨ�أ�");
              a==7;
              break;
             }
    } 
    if(a==6)
        {
         printf("�Բ�����������ͣ�\n");
         printf("��ȷ��Ϊ��%d\n",y);
        }   
    system("pause");
    return 0;
               }
    
    
    
    
    
    
    
    

