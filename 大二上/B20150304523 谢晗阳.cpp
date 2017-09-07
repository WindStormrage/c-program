#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Bnode{  
    int data;  
    struct Bnode *lchild;  
    struct Bnode *rchild;  
}Bnode,*Tree;  

typedef struct stack{
       int data;
       }*sqstack;
       
sqstack head = NULL,tail = NULL;

//��˳������������ 
void InitStack(int data){
  tail++; 
  tail -> data = data;
}


//���˳����е����� 
void Traverse(){
  sqstack p = head;
  for(;p != tail+1;p++){
    printf("%d ",p -> data);
  }
  printf("\n"); 
}

//������������˳���Ȼ������鿴 
//֮ǰһֱ��Ϊ˳���ֻҪ�½�һ���ռ���ӵ�ʱ����β�������һ���Ϳ����ˣ�
//����ʵ�����㿪ʼҪȷ����˳���ĳ�ʼ�ռ��С���㶨��Ŀռ�֮�ڲ��������ƶ�β�ڵ�
//����㻹���ӿռ�Ļ�����Ҫ�õ�realloc������ 
void add_data()
{
	srand((unsigned) time(NULL));//��ʱ�����֣�ÿ�β����������һ��
    int length,data;
    int i;
    printf("�ܹ���������?\n");
    scanf("%d",&length);//ȷ����˳����ʼ���� 
    head = (sqstack)malloc(length*sizeof(struct  stack));//�½�һ������Ϊlength�Ŀռ� 
    tail = head;
   // printf("���� %d ������:\n", length);
    //scanf("%d",&data);
    data = rand() % 101; //����0-100�������
	head -> data = data;//�ȸ����ӵ�һ�����ݾͽ�ȥ 
    for (i = 1; i < length; i++)
    {
 	  data = rand() % 101; //����0-100�������
      //scanf("%d",&data);
      InitStack(data);
    }
    printf("��������������Щ���� :\n");
    Traverse();
}

//�������� 
void insert(Tree &T,Tree S){//TΪ��ǰ�ҵ��ĸ��ڵ�//SΪҪ����Ľڵ� 
	if(T == NULL)//�����ǰ�ڵ��ǿյĻ�S�ͱ�ɵ�ǰҶ�ӽڵ� 
	{
		T = S;
		//printf("0-%d-0",T -> data);
	}
	else if(S -> data < T -> data)//Ҫ�ӵ����ݱȵ�ǰ�ڵ�����С�Ļ��ͼ���������� 
	{
		insert(T -> lchild,S);
		//printf("L");
	}
	else
	{
		insert(T -> rchild,S);
		//printf("R");
	}
}

//�������Ա�Ϊ��������׼�� 
void create_bst(Tree &T){
	sqstack p = head;//�������Ա� 
  	for( ; p!=tail+1 ; p++ ){
	    Tree S = (Tree)malloc(sizeof(struct Bnode));//�½�һ���ռ�������������һ���ڵ� 
    	S -> data   = p -> data;//����ýڵ������ 
		S -> lchild = NULL;  
        S -> rchild = NULL;
        insert(T,S);  
  		//printf("**%d**",T -> data);
  }		
}

void inorderVisit(Tree T){     //�������  
    if(T != NULL){  
        inorderVisit(T->lchild); 
		printf("%d  ",T->data);
        inorderVisit(T->rchild);  
    }  
}  

void Delete(Tree T,int x){  //ɾ���ڵ�  
    Tree f,p = T;  
    while(p && p->data !=x){  //ȥ�ҵ�dataΪx�Ľڵ� //��Ϊ�ջ����ҵ����˳� 
        if(p->data > x){  
            f = p;  //f��¼����p��˫�� //pΪ�ҵ��Ľڵ� 
            p = p->lchild;  
        }  
        else{  
            f = p;  
            p = p->rchild;  
        }  
    }  
    if(p == NULL)   return;  //��ʾû�ҵ�  
    
    if(p->lchild == NULL){  //ֻ���������Ļ� 
        if(f->lchild == p)  //ֱ�Ӱ�p���Һ��Ӵ���p 
            f->lchild = p->rchild;  
        else  
            f->rchild = p->rchild;  
    }  
    else{    //�����������  
        Tree q = p->lchild;  
        Tree s = q;  
        while(q->rchild != NULL){  //qΪp��������������//sΪq��˫��
            s = q;  
            q = q->rchild;  
        }  
        if(s == p->lchild){//p�������������Һ���//�������ѭ��û�ж�sҲ��p��������
            p->lchild = s->lchild;  
            p->data = s -> data;  
            free(s);  
        }  
        else{  
            p->data = q->data;  
            s->rchild = q->lchild;  
            free(q);  
        }  
    }  
      
}  


int main()
{
	int i = -1,data;
	Tree T = NULL;//TΪ������ĸ��ڵ㿪ʼΪ�� 
    add_data();//��˳��������� 
	create_bst(T);//��������������
	//printf("!!!");
	printf("ͨ����������������������������ǣ�\n"); 
    inorderVisit(T);//���������������������С������
    for(; i!=0 ;){
    	printf("\n������������1��ɾ����������2����������0:\n");
    	scanf("%d",&i);
		if(i == 1){
			printf("������Ҫ��������ݣ�\n");
			scanf("%d",&data);
		    Tree S = (Tree)malloc(sizeof(struct Bnode));
	    	S -> data   = data;
			S -> lchild = NULL;  
	        S -> rchild = NULL;
	        insert(T,S);  
            inorderVisit(T);
		} else if (i == 2){
			printf("������Ҫɾ�������ݣ�\n");
			scanf("%d",&data);
			Delete(T,data); 
            inorderVisit(T);
		}
	}
    return 0;
}
