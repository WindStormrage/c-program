#include<stdio.h>
#include<stdlib.h>


typedef struct stack{
       int data;
       struct stack *next;
       }*sqstack;
       
sqstack head = NULL,tail = NULL;

void InitStack(int data){
  sqstack newstack = (sqstack)malloc(sizeof(struct stack));
  if(head == NULL)
    head = newstack;
  else 
    tail -> next = newstack;
  tail = newstack;
  newstack -> data = data;
  newstack -> next = NULL;
}

void DelStack(){
  sqstack p = head;
  if(head == tail){
    head = NULL;
    tail = NULL;
  }
  else{
    while(1){
      if (p -> next == tail)
      {
        tail = p;
        free(p->next);
        tail -> next = NULL;
        break;
      }
      p = p -> next;
    }
  }
}

void Traverse(){
  sqstack p = head;
  while(p){
    printf("%d \n",p -> data);
    p = p -> next;
  }
  printf("!end!\n");
}

int main()
{
    int length=0,data;
    int t;
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
