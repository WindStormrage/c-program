#include <stdio.h> 
int main() 
{ 
int a,b; 
freopen("in1.txt","r",stdin); //�����ض����������ݽ���in.txt�ļ��ж�ȡ 
freopen("out.txt","w",stdout); //����ض���������ݽ�������out.txt�ļ��� 
scanf("%d %d",&a,&b);
printf("%d\n",a+b); 
fclose(stdin);//�ر��ļ� 
fclose(stdout);//�ر��ļ� 
return 0; 
} 
