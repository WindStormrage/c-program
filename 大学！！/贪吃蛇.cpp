//贪吃蛇简易版 
//2016/7/26 20:54
//运行环境：windows
//编译器：Dev-C++ 5.11 
//初次尝试，写的不太好，请见谅 
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
char map[10][20];//地图 
char snake[2][200]={-1};//蛇的坐标0为行1为列 
int  snake_long=1;//蛇的长度 
int  now;//当前蛇的移动方向 
int  over=0;//判断是否结束
int  direction[2][81];//判断四个方向
int  head_x,head_y;//新的头的坐标 
int  end_x,end_y;//旧的尾部坐标，当吃到了食物就不删除尾部 
int  food_x,food_y;//食物坐标 
int main ()
{
	int i,j;
	//把上下左右的位置定义一下 
	direction[0][75]=0;  direction[1][75]=-1;  //左 x-1 y+0
	direction[0][77]=0;  direction[1][77]=1;  //右 x+1 y+0
	direction[0][72]=-1; direction[1][72]=0; //上 x+0 y-1
	direction[0][80]=1;  direction[1][80]=0;  //下 x+0 y+1
 	system("title 贪吃蛇V1.0");  //控制台的标题  
	initial();//先地图全部变成+
	srand(time(0));   //随机数  
	snake[0][0]=rand()%10;//把蛇头的坐标储存 
	snake[1][0]=rand()%20;
    map[snake[0][0]][snake[1][0]]='@';//显示出蛇头的坐标
	food();//随机产生食物 
	show();//展示地图 
	//以上是游戏开始前的所以准备，接下来就是游戏开始了！
	now=getch();//开始第一个键
	while(1)
	{
		Sleep(500);//每隔500ms 
		if(kbhit())//确认当前有没有检测到输入 
			now=getch();//如果检测到就接收数据
		if(now==224)//在切换的时候会中间多出来一个224 
			now=getch();
		//这样可以得到新的头的位置 
		head_x=snake[0][0]+direction[0][now];
		head_y=snake[1][0]+direction[1][now];
		//判断是否碰墙 
		if(head_x<0||head_y<0||head_x>9||head_y>19)
			over=1;
		//判断是否吃自己 
		for(i=0;i<snake_long-1;i++)
			if(head_x==snake[0][i]&&head_y==snake[1][i])
				over=1;
		if(over)//判断有没有over 
			break;
		end_x=snake[0][snake_long-1];
		end_y=snake[1][snake_long-1];
		move(); 
		initial();//先地图全部变成+ 
		fill();
		if(head_x==food_x&&head_y==food_y)//如果吃到了食物
		{
			snake_long++;//长度增加1 
			snake[0][snake_long-1]=end_x;//最后加一位 
			snake[1][snake_long-1]=end_y;
			map[end_x][end_y]='@';//把最后的补上 
			food();//分配一个新的食物//函数里面会吧食物补上 
		} 
		else
			map[food_x][food_y]='#';
		system("cls");//清除上次的屏幕 
		show();//展现当前地图 
	}
	gameOver();
}

void gameOver()
{
	printf("GAME OVER >_<\n");
	printf("最终得分：%d\n",snake_long);
	printf("制作人：谢大帅哥\n");
	printf("All rights reserved.Copyright reserved.");
}

void fill()//把蛇填充上去 
{
	int i;
	for(i=0;i<snake_long;i++)
		map[snake[0][i]][snake[1][i]]='@';
}
 
void move()//移动蛇的位置 
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

void show()//展现当前地图 
{
	printf("贪吃蛇V1.0之谢大帅哥呕心沥血之作\n\n"); 
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<20;j++)
			printf("%c",map[i][j]);
		printf("\n");
	}
}

void food()//产生食物 
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

void initial()//先地图全部变成+
{
	int i,j;
	for(i=0;i<10;i++) 
		for(j=0;j<20;j++)
			map[i][j]='+';
	
} 
