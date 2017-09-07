#include <stdio.h>
#include <malloc.h>


typedef struct tree
{
	int data;
	int left,right,parent;
}tree;

void show_tree(int len,tree *new)
{
	int i = 0;
	for ( ; i < 2*len-1; i++)
		printf("%d\t%d\t%d\t%d\t\n", new[i].data,new[i].left,new[i].right,new[i].parent);
}

tree *new_tree(int len,int tree_data[])
{
	//new a tree
	int i;
	tree *new = malloc(sizeof(tree));
	for(i = 0;i < len ;i++)
	{
		new[i].data   = tree_data[i];
		new[i].left   = -1;
		new[i].right  = -1;
		new[i].parent = -1;
	}
	for(i=len;i < 2*len-1 ; i++)
	{
		new[i].data   = 9999;
		new[i].left   = -1;
		new[i].right  = -1;
		new[i].parent = -1;
	}
	return new;
}

tree *make_tree(int len,tree *new)
{
	int i,j;
	int min1,min2;
	int m = 0           ,n = 0 ;
	//only len - 1 times
	for (j = 0; j < len-1; j++)
	{
		min1=99999;
		min2=99999;
		//find two min data
		for ( i = 0 ; i < 2*len-1 ; i++)
		{
			//must use parent!=-1
			if ( new[i].parent != -1 )
				continue;
			if ( min1 > new[i].data )
			{
				min1 = new[i].data;
				m = i;
			}
		}
		for ( i = 0 ; i < 2*len ; i++)
		{
			if ( new[i].parent != -1 )
				continue;
			if (i == m)
				continue;
			if ( min2 > new[i].data )
			{
				min2 = new[i].data;
				n = i;
			}
		}
		printf("%d**%d**%d**%d**\n",min1,min2,m,n);
		//manage two son
		//len++;
		new[len+j].data  = new[m].data + new[n].data;
		new[len+j].right = m;
		new[len+j].left  = n;
		new[m].parent = len+j;
		new[n].parent = len+j;
	}
	return new;
}

int main()
{
	int tree_data[10];
	int len,i;
	tree *new;
	printf("Please write len:\n");
	scanf("%d",&len);
	printf("\nPlease write tree_data:\n");
	for (i = 0; i < len; i++)
		scanf("%d",&tree_data[i]);
	new = new_tree(len,tree_data);
	show_tree(len,new);
	new = make_tree(len,new);
	show_tree(len,new);
	return 0;
}
