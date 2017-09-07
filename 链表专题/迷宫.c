#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
       int x;
       int y;
       }*sqstack;

sqstack head = NULL,tail = NULL;

void InitStack(int x,int y){
  tail++; 
  sqstack newstack = tail;
  newstack -> x = x;
  newstack -> y = y;
}

void DelStack(){
    tail = tail-1;
}

void Traverse(){
  sqstack p = head;
  while(p != (tail+1)){
    printf("(%d,%d) -> ",p->x,p->y);
    p++;
  }
  printf("end\n");
}
//(1,1) -> (2,1) -> (3,1) -> (4,1) -> (4,2) -> (4,3) -> (5,3) -> (6,3) -> (6,2) -> (6,1) -> (7,1) -> (8,1) -> end
int main()
{
	int map[11][11]={{0,0,0,0,0,0,0,0,0,0},{0,1,0,1,0,0,0,0,0,0},{0,1,0,1,1,1,1,1,1,0},{0,1,0,0,0,1,0,0,1,0},{0,1,1,1,1,1,0,0,1,0},{0,0,0,1,0,1,0,0,1,0},{0,1,1,1,0,1,0,1,1,0},{0,1,0,0,0,1,0,0,0,0},{0,1,0,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0,0,0}};
	int x=1,y=1;
	sqstack newstack = (sqstack)malloc(sizeof(struct stack));
    head = newstack;
    tail = newstack;
    newstack -> x = x;
    newstack -> y = y;
    while(x!=8 || y!=8)
    {
    	Traverse();
		if (map[x][y] == 1)
		{
			//如果接下来的一步是0或者是上一步就不能走
			if(map[x-1][y]==0 || ((x-1)==(newstack-1)->x && y==(newstack-1)->y))
				map[x][y]++;
			else
			{
				map[x][y]++;
				InitStack(x-1,y);
				newstack = tail;
				x = newstack -> x;
				y = newstack -> y;
				continue;
			}
		}
		if (map[x][y] == 2)
		{
			//如果接下来的一步是0或者是上一步就不能走
			if(map[x][y-1]==0 || (x==(newstack-1)->x && (y-1)==(newstack-1)->y))
				map[x][y]++;
			else
			{
				map[x][y]++;
				InitStack(x,y-1);
				newstack = tail;
				x = newstack -> x;
				y = newstack -> y;
				continue;
			}
		}
		if (map[x][y] == 3)
		{
			//如果接下来的一步是0或者是上一步就不能走
			if(map[x+1][y]==0 || ((x+1)==(newstack-1)->x && y==(newstack-1)->y))
				map[x][y]++;
			else
			{
				map[x][y]++;
				InitStack(x+1,y);
				newstack = tail;
				x = newstack -> x;
				y = newstack -> y;
				continue;
			}
		}
		if (map[x][y] == 4)
		{
			//如果接下来的一步是0或者是上一步就不能走
			if(map[x][y+1]==0 || (x==(newstack-1)->x && (y+1)==(newstack-1)->y))
				map[x][y]++;
			else
			{
				map[x][y]++;
				InitStack(x,y+1);
				newstack = tail;
				x = newstack -> x;
				y = newstack -> y;
				continue;
			}
		}
		//上下左右都不能走了，所以只能回到上一个了
		if (map[x][y] == 5)
		{
			map[x][y] = 0;
			DelStack();//栈中删除当前位置
			newstack = tail;
			x = newstack -> x;
			y = newstack -> y;
		}
    }
    Traverse();
    system("pause");
    return 0;
}
//i==0死路
//i==1什么都没走过接下来上
//i==2走过了上面接下来左
//i==3走过了左边接下来下
//i==4走过了下面接下来右
//i==5走过了右边
/*
    0 1 2 3 4 5 6 7 8 9
    
0	0 0 0 0 0 0 0 0 0 0
1	0 1 0 1 0 0 0 0 0 0
2	0 1 0 1 1 1 1 1 1 0
3	0 1 0 0 0 1 0 0 1 0
4	0 1 1 1 1 1 0 0 1 0
5	0 0 0 1 0 1 0 0 1 0
6	0 1 1 1 0 1 0 1 1 0
7	0 1 0 0 0 1 0 0 0 0
8	0 1 0 1 1 1 1 1 1 0
9	0 0 0 0 0 0 0 0 0 0
*/
//环形路段会出错 
