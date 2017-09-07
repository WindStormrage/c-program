#include<stdio.h>
#include<stdlib.h>


typedef struct stack{
       int data;
       }*sqstack;
       
sqstack head = NULL,tail = NULL;

void InitStack(int data){
  tail++; 
  sqstack newstack = tail;
  newstack -> data = data;
}

void DelStack(){
  sqstack p = head;
  if(head == tail){
    printf("error\n");
  }
  else{
    p = tail;
    tail = tail-1;
  }
}

void Traverse(){
  sqstack p = head;
  while(p != (tail+1)){
    printf("%d \n",p -> data);
    p++;
  }
  printf("!end!\n");
}

int main()
{
    int length=0,data;
    int t;
    sqstack newstack = (sqstack)malloc(sizeof(struct stack));
    head = newstack;
    tail = newstack;
    newstack -> data = 0;
    while(1)
    {
      printf("����1������,2ȡ��һ������:\n");
      scanf("%d",&t); 
      if (t == 1)
      {
        printf("����һ�����ݣ�\n");
        scanf("%d",&data);
        InitStack(data);
        length++;
      }
      if (t == 2)
      {
        DelStack();
        length--;
      }
      printf("�������ݣ�\n");
      Traverse();
    }
    system("pause");
    return 0;
    }
