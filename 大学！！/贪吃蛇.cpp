//̰���߼��װ� 
//2016/7/26 20:54
//���л�����windows
//��������Dev-C++ 5.11 
//���γ��ԣ�д�Ĳ�̫�ã������ 
#include <stdio.h>  
#include <stdlib.h>  
#include <conio.h>  
#include <string.h>  
#include <time.h> 
#include <windows.h> 
void gameOver();
void fill();
void initial();
void food(); 
void show();
void move(); 
char map[10][20];//��ͼ 
char snake[2][200]={-1};//�ߵ�����0Ϊ��1Ϊ�� 
int  snake_long=1;//�ߵĳ��� 
int  now;//��ǰ�ߵ��ƶ����� 
int  over=0;//�ж��Ƿ����
int  direction[2][81];//�ж��ĸ�����
int  head_x,head_y;//�µ�ͷ������ 
int  end_x,end_y;//�ɵ�β�����꣬���Ե���ʳ��Ͳ�ɾ��β�� 
int  food_x,food_y;//ʳ������ 
int main ()
{
	int i,j;
	//���������ҵ�λ�ö���һ�� 
	direction[0][75]=0;  direction[1][75]=-1;  //�� x-1 y+0
	direction[0][77]=0;  direction[1][77]=1;  //�� x+1 y+0
	direction[0][72]=-1; direction[1][72]=0; //�� x+0 y-1
	direction[0][80]=1;  direction[1][80]=0;  //�� x+0 y+1
 	system("title ̰����V1.0");  //����̨�ı���  
	initial();//�ȵ�ͼȫ�����+
	srand(time(0));   //�����  
	snake[0][0]=rand()%10;//����ͷ�����괢�� 
	snake[1][0]=rand()%20;
    map[snake[0][0]][snake[1][0]]='@';//��ʾ����ͷ������
	food();//�������ʳ�� 
	show();//չʾ��ͼ 
	//��������Ϸ��ʼǰ������׼����������������Ϸ��ʼ�ˣ�
	now=getch();//��ʼ��һ����
	while(1)
	{
		Sleep(500);//ÿ��500ms 
		if(kbhit())//ȷ�ϵ�ǰ��û�м�⵽���� 
			now=getch();//�����⵽�ͽ�������
		if(now==224)//���л���ʱ����м�����һ��224 
			now=getch();
		//�������Եõ��µ�ͷ��λ�� 
		head_x=snake[0][0]+direction[0][now];
		head_y=snake[1][0]+direction[1][now];
		//�ж��Ƿ���ǽ 
		if(head_x<0||head_y<0||head_x>9||head_y>19)
			over=1;
		//�ж��Ƿ���Լ� 
		for(i=0;i<snake_long-1;i++)
			if(head_x==snake[0][i]&&head_y==snake[1][i])
				over=1;
		if(over)//�ж���û��over 
			break;
		end_x=snake[0][snake_long-1];
		end_y=snake[1][snake_long-1];
		move(); 
		initial();//�ȵ�ͼȫ�����+ 
		fill();
		if(head_x==food_x&&head_y==food_y)//����Ե���ʳ��
		{
			snake_long++;//��������1 
			snake[0][snake_long-1]=end_x;//����һλ 
			snake[1][snake_long-1]=end_y;
			map[end_x][end_y]='@';//�����Ĳ��� 
			food();//����һ���µ�ʳ��//����������ʳ�ﲹ�� 
		} 
		else
			map[food_x][food_y]='#';
		system("cls");//����ϴε���Ļ 
		show();//չ�ֵ�ǰ��ͼ 
	}
	gameOver();
}

void gameOver()
{
	printf("GAME OVER >_<\n");
	printf("���յ÷֣�%d\n",snake_long);
	printf("�����ˣ�л��˧��\n");
	printf("All rights reserved.Copyright reserved.");
}

void fill()//���������ȥ 
{
	int i;
	for(i=0;i<snake_long;i++)
		map[snake[0][i]][snake[1][i]]='@';
}
 
void move()//�ƶ��ߵ�λ�� 
{
	int i;
	for(i=snake_long-1;i>0;i--)
	{
		snake[0][i]=snake[0][i-1];
		snake[1][i]=snake[1][i-1];
	}
	snake[0][0]=head_x;
	snake[1][0]=head_y;
}

void show()//չ�ֵ�ǰ��ͼ 
{
	printf("̰����V1.0֮л��˧��Ż����Ѫ֮��\n\n"); 
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<20;j++)
			printf("%c",map[i][j]);
		printf("\n");
	}
}

void food()//����ʳ�� 
{
	int i,j=1; 
	srand(time(0));
	while(1)
	{
		food_x=rand()%10;
		food_y=rand()%20;
		if(map[food_x][food_y]=='+')
	    	break;
	}
	map[food_x][food_y]='#';
} 

void initial()//�ȵ�ͼȫ�����+
{
	int i,j;
	for(i=0;i<10;i++) 
		for(j=0;j<20;j++)
			map[i][j]='+';
	
} 
