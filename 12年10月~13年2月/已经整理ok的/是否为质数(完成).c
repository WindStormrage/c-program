#include<stdio.h>
int main()
{
    int m,k;
    printf("��������"); 
    scanf("%d",&k);
    if(k==1)
      goto remove;
    for(m=2;m<k;m++)
    {
     if(k%m==0)//���k��m���� 
       {
        remove:
        printf("��Ϊ����\n");
        goto to;
       }
    }
    printf("Ϊ����\n");
    to:
    system("pause");
    return 0;
}
/*#include<stdio.h>
#include <stdlib.h>
int main()
{
int m, k;
int flag = 1;
printf ("������һ��������"); 
while (scanf ("%d", &k) == 1)
{
for(m = 2; m <= k; m++)
if (k % m == 0)
break;
if (k == m)
printf ("%dΪ����\n", k);
else
printf ("%d��Ϊ����\n", k);
printf ("������һ������������q�˳�����");
}
system ("pause");
return 0;
}
*/
