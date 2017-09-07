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

//向顺序表中添加数据 
void InitStack(int data){
  tail++; 
  tail -> data = data;
}


//输出顺序表中的数据 
void Traverse(){
  sqstack p = head;
  for(;p != tail+1;p++){
    printf("%d ",p -> data);
  }
  printf("\n"); 
}

//输入数据生成顺序表然后遍历查看 
//之前一直以为顺序表只要新建一个空间添加的时候用尾部向后移一个就可以了，
//但是实际上你开始要确定你顺序表的初始空间大小在你定义的空间之内才能往后移动尾节点
//如果你还想多加空间的话你需要用到realloc函数加 
void add_data()
{
	srand((unsigned) time(NULL));//用时间做种，每次产生随机数不一样
    int length,data;
    int i;
    printf("总共多少数据?\n");
    scanf("%d",&length);//确定好顺序表初始长度 
    head = (sqstack)malloc(length*sizeof(struct  stack));//新建一个长度为length的空间 
    tail = head;
   // printf("输入 %d 个数据:\n", length);
    //scanf("%d",&data);
    data = rand() % 101; //产生0-100的随机数
	head -> data = data;//先给他加第一个数据就进去 
    for (i = 1; i < length; i++)
    {
 	  data = rand() % 101; //产生0-100的随机数
      //scanf("%d",&data);
      InitStack(data);
    }
    printf("你现在输入了这些数据 :\n");
    Traverse();
}

//树的生成 
void insert(Tree &T,Tree S){//T为当前找到的根节点//S为要加入的节点 
	if(T == NULL)//如果当前节点是空的话S就变成当前叶子节点 
	{
		T = S;
		//printf("0-%d-0",T -> data);
	}
	else if(S -> data < T -> data)//要加的数据比当前节点数据小的话就继续向左遍历 
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

//遍历线性表为生成树做准备 
void create_bst(Tree &T){
	sqstack p = head;//遍历线性表 
  	for( ; p!=tail+1 ; p++ ){
	    Tree S = (Tree)malloc(sizeof(struct Bnode));//新建一个空间用来储存树的一个节点 
    	S -> data   = p -> data;//补充好节点的数据 
		S -> lchild = NULL;  
        S -> rchild = NULL;
        insert(T,S);  
  		//printf("**%d**",T -> data);
  }		
}

void inorderVisit(Tree T){     //中序遍历  
    if(T != NULL){  
        inorderVisit(T->lchild); 
		printf("%d  ",T->data);
        inorderVisit(T->rchild);  
    }  
}  

void Delete(Tree T,int x){  //删除节点  
    Tree f,p = T;  
    while(p && p->data !=x){  //去找到data为x的节点 //在为空或者找到就退出 
        if(p->data > x){  
            f = p;  //f记录的是p的双亲 //p为找到的节点 
            p = p->lchild;  
        }  
        else{  
            f = p;  
            p = p->rchild;  
        }  
    }  
    if(p == NULL)   return;  //表示没找到  
    
    if(p->lchild == NULL){  //只有右子树的话 
        if(f->lchild == p)  //直接把p的右孩子代替p 
            f->lchild = p->rchild;  
        else  
            f->rchild = p->rchild;  
    }  
    else{    //结点有左子树  
        Tree q = p->lchild;  
        Tree s = q;  
        while(q->rchild != NULL){  //q为p的左子树中最大的//s为q的双亲
            s = q;  
            q = q->rchild;  
        }  
        if(s == p->lchild){//p的左子树无左右孩子//如果上面循环没有动s也是p的左子树
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
	Tree T = NULL;//T为最上面的根节点开始为空 
    add_data();//用顺序表储存数据 
	create_bst(T);//建立二叉排序树
	//printf("!!!");
	printf("通过二叉排序树排序出来的数据列是：\n"); 
    inorderVisit(T);//中序遍历二叉排序树，从小到大输
    for(; i!=0 ;){
    	printf("\n插入数据输入1，删除数据输入2，结束输入0:\n");
    	scanf("%d",&i);
		if(i == 1){
			printf("请输入要插入的数据：\n");
			scanf("%d",&data);
		    Tree S = (Tree)malloc(sizeof(struct Bnode));
	    	S -> data   = data;
			S -> lchild = NULL;  
	        S -> rchild = NULL;
	        insert(T,S);  
            inorderVisit(T);
		} else if (i == 2){
			printf("请输入要删除的数据：\n");
			scanf("%d",&data);
			Delete(T,data); 
            inorderVisit(T);
		}
	}
    return 0;
}
