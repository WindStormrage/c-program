#include<stdio.h>
int main() 
{
    float x=0,y=0,z=0,max=0;
    scanf("%f%f%f",&x,&y,&z);
    if(x>y){
        max=x;
        if(max<z)
           max=z;        
        }
    else{
        max=y;
        printf("max=%f",max);
     }
    system ("pause");
    return 0;
} 
