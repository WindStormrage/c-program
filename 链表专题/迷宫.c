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
			//�����������һ����0��������һ���Ͳ�����
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
			//�����������һ����0��������һ���Ͳ�����
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
			//�����������һ����0��������һ���Ͳ�����
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
			//�����������һ����0��������һ���Ͳ�����
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
		//�������Ҷ��������ˣ�����ֻ�ܻص���һ����
		if (map[x][y] == 5)
		{
			map[x][y] = 0;
			DelStack();//ջ��ɾ����ǰλ��
			newstack = tail;
			x = newstack -> x;
			y = newstack -> y;
		}
    }
    Traverse();
    system("pause");
    return 0;
}
//i==0��·
//i==1ʲô��û�߹���������
//i==2�߹��������������
//i==3�߹�����߽�������
//i==4�߹��������������
//i==5�߹����ұ�
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
//����·�λ���� 
