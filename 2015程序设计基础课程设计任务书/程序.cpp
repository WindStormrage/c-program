#include<conio.h>
#include<stdio.h> 
#include<string.h>
#include<windows.h>
	int validate(char zh[],char mm[]);//��½ϵͳ(���ô����˺��ļ�����ƥ��)
	int validate_stu(int count,char zh[],char mm[]);
	int entering(int count);//��������(��Ϣ¼��:����,������ɼ����ܷ�,ѧ��) 
	int payment(int count);//�ɷѹ���(��5000,��ʾǷ�Ѻ��ѽ���) 	 
	int payment_stu(int count,char sum_number[]);//�ɷѹ���(��5000,��ʾǷ�Ѻ��ѽ���) 
//	int payment2(char );//��������(��5000,��ʾǷ�Ѻ��ѽ���) 
    int query(int count);//��ѯ����(�������ɼ���ѧ��Ƿ�����)
    int sort(int count);//������(�ɼ���ѧ��Ƿ�ɷֱ�����)     
    int ex(int i,int j);//����
    int old_data(int count);//���ļ��ж�ȡԭ����Ϣ 
    int add(int count);//�ѱ������ݷŵ��ļ��б��� 
	void gaim();//���� 
	int gaim_stu(int count,char zh[]);

    struct student
    {
    	char name[20];
    	int  math;
    	int  english;
    	int  chinese;
    	int  all;
    	int  money;
    	char number[20];//������� 
    	char mm[20];
	}stu[100000];


	int main()
	{
     int  a=0/*�˳�ϵͳ��־*/,x/*����*/,t=0;
	 int  count=0/*����*/;
	 char zh[20],mm[20]; 
	 int  i,abc;
	 int  man;
	 printf("+================================+\n");
	 printf("|                                |\n");
	 printf("|        ��ӭʹ�ñ���ϵͳ        |\n");
	 printf("|                                |\n");   
	 printf("|          ������1��½           |\n");
	 printf("|                                |\n");
	 printf("+================================+\n");
	 scanf("%d",&abc);
	 system("cls");
	 count=old_data(count); 
	 for(;;)
	   {
		 printf("+================================+\n");
		 printf("|                                |\n");
		 printf("|        ѧ����½�밴 1          |\n");
		 printf("|      ������Ա��½�밴 2        |\n");   
		 printf("|        �˳�ϵͳ�밴 0          |\n");
		 printf("|                                |\n");
		 printf("+================================+\n");
		 scanf("%d",&man);
		 system("cls");
	     if(man!=1&&man!=2&&man!=0)
	        {
		 	 printf("+================================+\n");
			 printf("|                                |\n");
		     printf("|          �������            |\n");
		     printf("|                                |\n");
		     printf("|        ���������밴 1          |\n");
		     printf("|                                |\n");    
		     printf("+================================+\n");
		     scanf ("%d",&abc);  
		     system("cls"); 
	        }	
		 else if(man==2)
		   {
			printf("+================================+\n");
			printf("|                                |\n");
			printf("|         �������˺�����         |\n");
			printf("|                                |\n"); 
		    printf("|          �Իس�������          |\n");
			printf("|                                |\n");
		    printf("+================================+\n");
		    for(t=0;t==0;)
		       {	       	
			    scanf("%s",zh);
		       	for(i=0;;i++)
		       	   { 
		       	    mm[i]=getch();
		       	    putchar('*');
		       	    if(mm[i]==13) break;
				   }
				 mm[i]='\0';
		         t=validate(zh,mm); 
		         if(t==0) 
		           {
				    system("cls");
					printf("+================================+\n");
					printf("|                                |\n");
					printf("|          �˺��������          |\n");
					printf("|       �����������˺�����       |\n"); 
				    printf("|          �Իس������          |\n");
					printf("|                                |\n");
				    printf("+================================+\n");
		           }
			   }
			system("cls");  
			for(a=0;a==0;) 
		   	   {
			    printf("+================================+\n");
			    printf("|1.�������� 2.�ɷѷ��� 3.��ѯ����|\n");
		     	printf("|                                |\n");
		        printf("|4.������� 5.�����ϲ� 6.�޸�����|\n");
		    	printf("|                                |\n");
		        printf("|      ��������Ӧ�ķ�����      |\n");    
		        printf("+================================+\n");
		        scanf ("%d",&x); 
		        system("cls"); 
		        if(x!=1&&x!=2&&x!=3&&x!=4&&x!=5&&x!=6)
		           {
					printf("+================================+\n");
				    printf("|                                |\n");
			     	printf("|          �������            |\n");
			        printf("|                                |\n");
			    	printf("|        ���������밴 1          |\n");
			        printf("|                                |\n");    
			        printf("+================================+\n");
			        scanf ("%d",&abc);  
			        system("cls"); 
		           }	    
				else switch(x)
			      {
			       case 1://���� 
		 	   	       count=entering(count);break; 
			       case 2://���� 
				       count=payment(count);break; 
			       case 3://��ѯ 
				       count=query(count);break; 
				   case 4://���� 
				       count=sort(count);break;
			       case 5:
				       a=1;break; 
			       case 6://���� 
				       gaim();break; 
				  }
		       }
	        }
	     else if(man==1)
	       { 
			printf("+================================+\n");
			printf("|                                |\n");
			printf("|         �������˺�����         |\n");
			printf("|     (��ʼ�˺������Ϊѧ��)     |\n"); 
		    printf("|          �Իس�������          |\n");
			printf("|                                |\n");
		    printf("+================================+\n");
		    for(t=0;t==0;)
		       {	       	
			    scanf("%s",zh);
		       	for(i=0;;i++)
		       	   { 
		       	    mm[i]=getch();
		       	    putchar('*');
		       	    if(mm[i]==13) break;
				   }
				 mm[i]='\0';
		         t=validate_stu(count,zh,mm); 
		         if(t==0) 
		           {
				    system("cls");
					printf("+================================+\n");
					printf("|                                |\n");
					printf("|          �˺��������          |\n");
					printf("|       �����������˺�����       |\n"); 
				    printf("|          �Իس������          |\n");
					printf("|                                |\n");
				    printf("+================================+\n");
		           }
			   }
			system("cls");  
			printf("+================================+\n");
			printf("|                                |\n");
			printf("|            ��½�ɹ�            |\n");
		    printf("|                                |\n"); 
			printf("|            ����1����           |\n");
			printf("|                                |\n");
			printf("+================================+\n");
			scanf("%d",&abc);
			system("cls");			
			printf("+================================+\n");
			printf("|                                |\n");
			printf("|     1.����ѧ��  2.��������     |\n");
		    printf("|                                |\n"); 
			printf("|           ������Ӧ����         |\n");
			printf("|                                |\n");
			printf("+================================+\n");		
			scanf("%d",&abc);
			system("cls");
			if(abc==1) count=payment_stu(count,zh);			
	        else       count=gaim_stu(count,zh);
		   }
	     if(man==0) {count=add(count); return 0;}
       }
	}    
	
	int gaim_stu(int count,char zh[])
	{
     int i,abc;
	 for(i=0;i<count;i++)
 		if(strcmp(zh,stu[i].number)==0) break;
	 printf("+================================+\n");
	 printf("|                                |\n");
	 printf("|         �������µ�����         |\n");
	 printf("|                                |\n"); 
	 printf("|                                |\n");
 	 printf("|                                |\n");
	 printf("+================================+\n");
	 scanf("%s",stu[i].mm);
	 system("cls");
	 printf("+================================+\n");
	 printf("|                                |\n");
	 printf("|            �޸ĳɹ�            |\n");
	 printf("|                                |\n"); 
	 printf("|            ����0����           |\n");
 	 printf("|                                |\n");
	 printf("+================================+\n");
	 scanf("%d",&abc);
	 system("cls"); 
 	 return count;
    } 
	

	void gaim()//����
	{
		char zh[20],mm[20];
		int abc; 
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|      �������µ��˺ź�����      |\n");
		printf("|                                |\n"); 
		printf("|                                |\n");
		printf("|                                |\n");
		printf("+================================+\n");
		scanf("%s%s",zh,mm);
		system("cls");
	    FILE *fp;
    	fp=fopen("mima.in","w");
	    fprintf(fp,"%s\n%s",zh,mm); 
		fclose(fp);  
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|           �޸ĳɹ���           |\n");
		printf("|                                |\n"); 
		printf("|         ����0�����ϲ�          |\n");
		printf("|                                |\n");
		printf("+================================+\n");
		scanf("%d",&abc);
		system("cls");		
	} 
	
	
    int add(int count)
	{
		FILE *fp;
		fp=fopen("old.data","w");
		fprintf(fp,"%d\n",count);
		for(int i=0;i<count;i++)
		   fprintf(fp,"%s %s %d %d  %d %d %d %s\n",stu[i].name,stu[i].number,stu[i].math,stu[i].english,stu[i].chinese,stu[i].all,stu[i].money,stu[i].mm); 
	    fclose(fp);
		return count;
	}


    int old_data(int count)
    {
	    FILE *fp; 
	    int i;
		fp=fopen("old.data","r");
    	fscanf(fp,"%d",&count);
    	for(i=0;i<count;i++)
     		fscanf(fp,"%s%s%d%d%d%d%d%s",stu[i].name,stu[i].number,&stu[i].math,&stu[i].english,&stu[i].chinese,&stu[i].all,&stu[i].money,stu[i].mm); 
		fclose(fp);
    	return count;    	
	}
   
   
    int sort(int count)//������(�ɼ���ѧ��Ƿ�ɷֱ�����) 
    {
     int sum_x,i,j,abc;
     for(;;)
     	{ 
		    printf("+================================+\n");
	     	printf("|   1.�����ĳɼ�  2.����ѧ�ɼ�   |\n");
	        printf("|   3.��Ӣ��ɼ�  4.��Ƿ�����   |\n");
	    	printf("|   5.�������˵�                 |\n");
	        printf("|      �������ѯ����ı��      |\n"); 
		    printf("|         (��С��������)         |\n");   
	        printf("+================================+\n");
	        scanf ("%d",&sum_x);
	        system("cls");       
	        if(sum_x!=1&&sum_x!=2&&sum_x!=3&&sum_x!=4&&sum_x!=5)
	           {
				printf("+================================+\n");
			    printf("|                                |\n");
		     	printf("|          �������            |\n");
		        printf("|                                |\n");
		    	printf("|        ���������밴 1          |\n");
		        printf("|                                |\n");    
		        printf("+================================+\n");
		        scanf ("%d",&abc);  
		        system("cls"); 
	           }	     
			else switch(sum_x)
		      {
		       case 1://���ĳɼ�
		       		for(i=0;i<(count-1);i++)
		       			for(j=i+1;j<count;j++)
		       		   	   if(stu[i].chinese>stu[j].chinese) 
		       		   	   	 ex(i,j);
		            printf("+================================+\n");
		       		for(i=0;i<count;i++)
					   {	
						printf("|    ������%s     ѧ�ţ�%s    |\n",stu[i].name,stu[i].number);
						printf("|                                |\n"); 
						printf("|    ���ĳɼ�:%d   ��ѧ�ɼ�:%d   |\n",stu[i].chinese,stu[i].math);
						printf("|    Ӣ��ɼ�:%d    �ܳɼ� :%d   |\n",stu[i].english,stu[i].all);
						printf("|    ��ǰǷ��:%dԪ               |\n",5000-stu[i].money); 
						printf("|                                |\n");
				        printf("|                                |\n");
         		       }
					printf("|          �����������          |\n");
					printf("|                                |\n"); 
					printf("|            ����1����           |\n");
					printf("|                                |\n");    
					printf("+================================+\n");
					scanf ("%d",&abc);
					system("cls"); 
                    break;
		       case 2://��ѧ�ɼ�
		       		for(i=0;i<(count-1);i++)
		       			for(j=i+1;j<count;j++)
		       		   	   if(stu[i].math>stu[j].math) 
		       		   	   	 ex(i,j);
		            printf("+================================+\n");
		       		for(i=0;i<count;i++)
					   {	
						printf("|    ������%s     ѧ�ţ�%s    |\n",stu[i].name,stu[i].number);
						printf("|                                |\n"); 
						printf("|    ���ĳɼ�:%d   ��ѧ�ɼ�:%d   |\n",stu[i].chinese,stu[i].math);
						printf("|    Ӣ��ɼ�:%d    �ܳɼ� :%d   |\n",stu[i].english,stu[i].all);
						printf("|    ��ǰǷ��:%dԪ               |\n",5000-stu[i].money); 
						printf("|                                |\n");
				        printf("|                                |\n");
         		       }
					printf("|          �����������          |\n");
					printf("|                                |\n"); 
					printf("|            ����1����           |\n");
					printf("|                                |\n");    
					printf("+================================+\n");
					scanf ("%d",&abc);
					system("cls"); 
                    break;
	    	   case 3://Ӣ��ɼ� 
		       		for(i=0;i<(count-1);i++)
		       			for(j=i+1;j<count;j++)
		       		   	   if(stu[i].english>stu[j].english) 
		       		   	   	 ex(i,j);
		            printf("+================================+\n");
		       		for(i=0;i<count;i++)
					   {	
						printf("|    ������%s     ѧ�ţ�%s    |\n",stu[i].name,stu[i].number);
						printf("|                                |\n"); 
						printf("|    ���ĳɼ�:%d   ��ѧ�ɼ�:%d   |\n",stu[i].chinese,stu[i].math);
						printf("|    Ӣ��ɼ�:%d    �ܳɼ� :%d   |\n",stu[i].english,stu[i].all);
						printf("|    ��ǰǷ��:%dԪ               |\n",5000-stu[i].money); 
						printf("|                                |\n");
				        printf("|                                |\n");
         		       }
					printf("|          �����������          |\n");
					printf("|                                |\n"); 
					printf("|            ����1����           |\n");
					printf("|                                |\n");    
					printf("+================================+\n");
					scanf ("%d",&abc);
					system("cls"); 
                    break;
		       case 4://Ƿ�����
		       		for(i=0;i<(count-1);i++)
		       			for(j=i+1;j<count;j++)
		       		   	   if(stu[i].money<stu[j].money) 
		       		   	   	 ex(i,j);
		            printf("+================================+\n");
		       		for(i=0;i<count;i++)
					   {	
						printf("|    ������%s     ѧ�ţ�%s    |\n",stu[i].name,stu[i].number);
						printf("|                                |\n"); 
						printf("|    ���ĳɼ�:%d   ��ѧ�ɼ�:%d   |\n",stu[i].chinese,stu[i].math);
						printf("|    Ӣ��ɼ�:%d    �ܳɼ� :%d   |\n",stu[i].english,stu[i].all);
						printf("|    ��ǰǷ��:%dԪ               |\n",5000-stu[i].money); 
						printf("|                                |\n");
				        printf("|                                |\n");
         		       }
					printf("|          �����������          |\n");
					printf("|                                |\n");
					printf("|            ����1����           |\n");
					printf("|                                |\n");    
					printf("+================================+\n");
					scanf ("%d",&abc);
					system("cls"); 
                    break;
			   case 5://���˵� 
		            return count; 
		      }
     	}
    }


    int ex(int i,int j)//����
    {
    	int t;
    	char sum;
		for(t=0;t<strlen(stu[j].name);t++)
		   {
		    sum=stu[i].name[t];
		    stu[i].name[t]=stu[j].name[t];
		    stu[j].name[t]=sum;
		   }
		t=stu[i].math;
		stu[i].math=stu[j].math;
		stu[j].math=t;

		t=stu[i].chinese;
		stu[i].chinese=stu[j].chinese;
		stu[j].chinese=t;

		t=stu[i].english;
		stu[i].english=stu[j].english;
		stu[j].english=t;

		t=stu[i].all;
		stu[i].all=stu[j].all;
		stu[j].all=t;

		t=stu[i].money;
		stu[i].money=stu[j].money;
		stu[j].money=t;
    }


    int query(int count)//��ѯ����(�������ɼ���ѧ��Ƿ�����)
    {
    	int sum_x,i,abc,sum_y,sum_man;
    	char sum_name[20];
    	int sum_a,sum_b,sum_c;
    	for(;;)
    	   {
		    printf("+================================+\n");
		    printf("|        1.��������ѯ            |\n");
	     	printf("|        2.���ɼ���ѯ            |\n");
	        printf("|        3.��ѧ�������ѯ        |\n");
	    	printf("|        4.�������˵�            |\n");
	        printf("|       �������ѯ������       |\n");    
	        printf("+================================+\n");
	        scanf ("%d",&sum_x);
	        system("cls"); 
	        if(sum_x!=3&&sum_x!=1&&sum_x!=2&&sum_x!=4)
	           {
				printf("+================================+\n");
			    printf("|                                |\n");
		     	printf("|          �������            |\n");
		        printf("|                                |\n");
		    	printf("|        ���������밴 1          |\n");
		        printf("|                                |\n");    
		        printf("+================================+\n");
		        scanf ("%d",&abc);  
		        system("cls"); 
	           }	    
			else switch(sum_x)
		      {
		       case 1://��������ѯ
		            for(sum_y=0;;) 
				       {
				       	sum_y=0;
						printf("+================================+\n");
					    printf("|                                |\n");
				     	printf("|      �����뱻��ѯ������        |\n");
				        printf("|                                |\n");
				    	printf("|       ����0������һ�˵�        |\n");
				        printf("|                                |\n");    
				        printf("+================================+\n");
				        scanf ("%s",sum_name); 
				        system("cls"); 
				        if(sum_name[0]=='0') break; 
				        else
				          for(i=0;i<count;i++)
				             if(strcmp(stu[i].name,sum_name)==0) 
				               {sum_y=1;break;}
				        if(sum_y==1)
						  {
							printf("+================================+\n");
							printf("|    ������%s     ѧ�ţ�%s    |\n",stu[i].name,stu[i].number);
					        printf("|    ���ĳɼ�:%d   ��ѧ�ɼ�:%d   |\n",stu[i].chinese,stu[i].math);
					    	printf("|    Ӣ��ɼ�:%d    �ܳɼ� :%d   |\n",stu[i].english,stu[i].all);
					        printf("|    ��ǰǷ��:%dԪ               |\n",5000-stu[i].money); 
						    printf("|            ����0����           |\n");   
					        printf("+================================+\n");
				          }
				        else
						  {
							printf("+================================+\n");
							printf("|                                |\n");
					        printf("|         �޷�������ѧ����       |\n");
					    	printf("|                                |\n");
					        printf("|            ����0����           |\n"); 
						    printf("|                                |\n");   
					        printf("+================================+\n");
				          }
						scanf ("%d",&abc);
				        system("cls"); 
				       }
				       break; 
		       case 2://���ɼ���ѯ
			    	for(;;)
			    	   {
			    	   	sum_man=0;
					    printf("+================================+\n");
					    printf("|    ���ĳɼ�-1   ��ѧ�ɼ�-2     |\n");
				     	printf("|    Ӣ��ɼ�-3    �ܳɼ� -4     |\n");
				        printf("| �������ѯ��Ӧ�ĳɼ��ͷ�����Χ |\n");
				    	printf("| ��:��ѯ����50��60�ֵ�ͬѧ����Ϣ|\n");
				        printf("| ����:1 50 60  ����0 0 0�����ϲ�|\n");    
				        printf("+================================+\n");
				        scanf ("%d%d%d",&sum_a,&sum_b,&sum_c); 
				        system("cls"); 
				        if(sum_a==0) break; 
				        else 
				          {
					       printf("+================================+\n");
				           if(sum_a==1)//���� 
				             for(i=0;i<count;i++)
							    if(stu[i].chinese>=sum_b&&stu[i].chinese<=sum_c)
								  {	
					            	printf("|    ������%s     ѧ�ţ�%s    |\n",stu[i].name,stu[i].number);
								    printf("|                                |\n"); 
							        printf("|    ���ĳɼ�:%d   ��ѧ�ɼ�:%d   |\n",stu[i].chinese,stu[i].math);
							    	printf("|    Ӣ��ɼ�:%d    �ܳɼ� :%d   |\n",stu[i].english,stu[i].all);
							        printf("|    ��ǰǷ��:%dԪ               |\n",5000-stu[i].money); 
					                printf("|                                |\n");
			           		        printf("|                                |\n");
			           		        sum_man++;
							      }      
				           if(sum_a==2)
				             for(i=0;i<count;i++)
							    if(stu[i].math>=sum_b&&stu[i].math<=sum_c)
								  {	
						            printf("|    ������%s     ѧ�ţ�%s    |\n",stu[i].name,stu[i].number);
								    printf("|                                |\n"); 
							        printf("|    ���ĳɼ�:%d   ��ѧ�ɼ�:%d   |\n",stu[i].chinese,stu[i].math);
							    	printf("|    Ӣ��ɼ�:%d    �ܳɼ� :%d   |\n",stu[i].english,stu[i].all);
							        printf("|    ��ǰǷ��:%dԪ               |\n",5000-stu[i].money);
							        printf("|                                |\n");
							        printf("|                                |\n"); 
			           		        sum_man++; 
							      }
				           if(sum_a==3)
				             for(i=0;i<count;i++)
							    if(stu[i].english>=sum_b&&stu[i].english<=sum_c)
								  {	
					            	printf("|    ������%s     ѧ�ţ�%s    |\n",stu[i].name,stu[i].number);
								    printf("|                                |\n"); 
							        printf("|    ���ĳɼ�:%d   ��ѧ�ɼ�:%d   |\n",stu[i].chinese,stu[i].math);
							    	printf("|    Ӣ��ɼ�:%d    �ܳɼ� :%d   |\n",stu[i].english,stu[i].all);
							        printf("|    ��ǰǷ��:%dԪ               |\n",5000-stu[i].money); 
							        printf("|                                |\n");
							        printf("|                                |\n");
			           		        sum_man++;
							      }				           
				           if(sum_a==4)
				             for(i=0;i<count;i++)
							    if(stu[i].all>=sum_b&&stu[i].all<=sum_c)
								  {	
						            printf("|    ������%s     ѧ�ţ�%s    |\n",stu[i].name,stu[i].number);
								    printf("|                                |\n"); 
							        printf("|    ���ĳɼ�:%d   ��ѧ�ɼ�:%d   |\n",stu[i].chinese,stu[i].math);
							    	printf("|    Ӣ��ɼ�:%d    �ܳɼ� :%d   |\n",stu[i].english,stu[i].all);
							        printf("|    ��ǰǷ��:%dԪ               |\n",5000-stu[i].money); 
							        printf("|                                |\n");
							        printf("|                                |\n");
			           		        sum_man++;
							      }
					     	printf("|          ���β�ѯ����          |\n");
					        printf("|            ���鵽%d��           |\n",sum_man);
					    	printf("|            ����1����           |\n");
					        printf("|                                |\n");    
					        printf("+================================+\n");
					        scanf ("%d",&abc);
					        system("cls"); 
						  }
					   }
				       break; 
	    	   case 3://��ѧ�������ѯ
			        for(;;)
			          {
			          	sum_man=0;
					    printf("+================================+\n");
					    printf("|                                |\n");
				     	printf("|    �������ѯ��Ӧ��Ƿ�ѷ�Χ    |\n");
				        printf("|                                |\n");
				    	printf("| ��:��ѯǷ��50��60Ԫ��ͬѧ����Ϣ|\n");
				        printf("| ����: 50 60   ����: 0 0�����ϲ�|\n");    
				        printf("+================================+\n");
				        scanf ("%d%d",&sum_b,&sum_c); 
				        system("cls"); 
				        if(sum_b==0&&sum_c==0) break; 
				        else 
				          {
					       printf("+================================+\n");
				           for(i=0;i<count;i++)
							  if((5000-stu[i].money)>=sum_b&&(5000-stu[i].money)<=sum_c)
							    {	
						            printf("|    ������%s     ѧ�ţ�%s    |\n",stu[i].name,stu[i].number);
								    printf("|                                |\n"); 
							        printf("|    ���ĳɼ�:%d   ��ѧ�ɼ�:%d   |\n",stu[i].chinese,stu[i].math);
							    	printf("|    Ӣ��ɼ�:%d    �ܳɼ� :%d   |\n",stu[i].english,stu[i].all);
							        printf("|    ��ǰǷ��:%dԪ               |\n",5000-stu[i].money); 
					                printf("|                                |\n");
			           		        printf("|                                |\n");
			           		        sum_man++;
							    } 
					     	printf("|          ���β�ѯ����          |\n");
					        printf("|            ���鵽%d��           |\n",sum_man);
					    	printf("|            ����1����           |\n");
					        printf("|                                |\n");    
					        printf("+================================+\n");
					        scanf ("%d",&abc);
					        system("cls"); 
			               }
		              }
				       break; 
			   case 4://�������˵� 
			        return count; 
		      }
		   }
	} 


    int payment(int count)//�ɷѹ���(��5000,��ʾǷ�Ѻ��ѽ���) 
    { 
    	int sum_1,sum_money,i,abc,sum_man;
    	char sum_name[20];
    	for(;;)
		   { 
			printf("+================================+\n");
		    printf("|                                |\n");
	     	printf("|        ���������밴 1          |\n");
	        printf("|                                |\n");
	    	printf("|        ������ҳ�밴 0          |\n");
	        printf("|                                |\n");    
	        printf("+================================+\n");
	        scanf ("%d",&sum_1);
	        system("cls"); 
	        if(sum_1!=0&&sum_1!=1)
	           {
				printf("+================================+\n");
			    printf("|                                |\n");
		     	printf("|          �������            |\n");
		        printf("|                                |\n");
		    	printf("|        ���������밴 1          |\n");
		        printf("|                                |\n");    
		        printf("+================================+\n");
		        scanf ("%d",&abc);  
		        system("cls"); 
	           }	        
	        else if(sum_1==0) return count;
	        else if(sum_1==1)
	          {
	          	sum_man=0;
				printf("+================================+\n");
			    printf("|                                |\n");
		     	printf("|                                |\n");
		        printf("|         �����븶����           |\n");
		    	printf("|                                |\n");
		        printf("|                                |\n");    
		        printf("+================================+\n");
		        scanf("%s",sum_name);
		        system("cls"); 
		        for(i=0;i<count;i++)
		           if(strcmp(sum_name,stu[i].name)==0)
		             {
						printf("+================================+\n");
					    printf("|                                |\n");
				     	printf("|                                |\n");
				        printf("|        �����븶����          |\n");
				    	printf("|                                |\n");
				        printf("|                                |\n");    
				        printf("+================================+\n");
				        scanf("%d",&sum_money);//////////////////���û��Ƿ����ô�죡��
						system("cls"); 
						stu[i].money=stu[i].money+sum_money;
						sum_man=1;
						break;
					 }
				if(sum_man==1)
				  {
					printf("+================================+\n");
				    printf("|                                |\n");
			     	printf("|           ����ɹ���           |\n");
			        printf("|                                |\n");
			    	printf("|          ��ǰ��Ƿ��%dԪ        |\n",5000-stu[i].money);
			        printf("|           ����1����            |\n");    
			        printf("+================================+\n");
		          }
		        else
				  {
					printf("+================================+\n");
					printf("|                                |\n");
				    printf("|         �޷�������ѧ����       |\n");
				   	printf("|                                |\n");
				    printf("|            ����0����           |\n"); 
				    printf("|                                |\n");   
				    printf("+================================+\n");
				  }
				scanf("%d",&abc);///////////////////////////////���û��Ƿ����ô�죡�� 
		        system("cls"); 
	          }
           }
    }


    int payment_stu(int count,char sum_number[])//ѧ���ɷѹ���(��5000,��ʾǷ�Ѻ��ѽ���) 
    { 
    	int sum_1,sum_money,i,abc;
    	for(;;)
		   { 
			printf("+================================+\n");
		    printf("|                                |\n");
	     	printf("|        ���������밴 1          |\n");
	        printf("|                                |\n");
	    	printf("|        ������ҳ�밴 0          |\n");
	        printf("|                                |\n");    
	        printf("+================================+\n");
	        scanf ("%d",&sum_1);
	        system("cls"); 
	        if(sum_1!=0&&sum_1!=1)
	           {
				printf("+================================+\n");
			    printf("|                                |\n");
		     	printf("|          �������            |\n");
		        printf("|                                |\n");
		    	printf("|        ���������밴 1          |\n");
		        printf("|                                |\n");    
		        printf("+================================+\n");
		        scanf ("%d",&abc);  
		        system("cls"); 
	           }	        
	        else if(sum_1==0) return count;
	        else if(sum_1==1)
	          {
		        for(i=0;i<count;i++)
		           if(strcmp(sum_number,stu[i].number)==0)
		             {
						printf("+================================+\n");
					    printf("|                                |\n");
				     	printf("|                                |\n");
				        printf("|        �����븶����          |\n");
				    	printf("|                                |\n");
				        printf("|                                |\n");    
				        printf("+================================+\n");
				        scanf("%d",&sum_money);//////////////////���û��Ƿ����ô�죡��
						system("cls"); 
						stu[i].money=stu[i].money+sum_money;
						break;
					 }
				printf("+================================+\n");
			    printf("|                                |\n");
		     	printf("|           ����ɹ���           |\n");
		        printf("|                                |\n");
		    	printf("|          ��ǰ��Ƿ��%dԪ        |\n",5000-stu[i].money);
		        printf("|           ����1����            |\n");    
		        printf("+================================+\n");
		        scanf("%d",&abc);///////////////////////////////���û��Ƿ����ô�죡�� 
		        system("cls"); 
	          }
           }
    }


	int entering(int count)//��������(��Ϣ¼��:����,������ɼ����ܷ�,ѧ��)
    {
    	int sum_1=1,abc;
    	for(;;)
		   { 
			printf("+================================+\n");
		    printf("|                                |\n");
	     	printf("|        ��Ϣ�����밴 1          |\n");
	        printf("|                                |\n");
	    	printf("|        ������ҳ�밴 0          |\n");
	        printf("|                                |\n");    
	        printf("+================================+\n");
	        scanf ("%d",&sum_1); 
	        system("cls"); 
	        if(sum_1!=0&&sum_1!=1)
	           {
				printf("+================================+\n");
			    printf("|                                |\n");
		     	printf("|          �������            |\n");
		        printf("|                                |\n");
		    	printf("|        ���������밴 1          |\n");
		        printf("|                                |\n");    
		        printf("+================================+\n");
		        scanf ("%d",&abc);  
		        system("cls"); 
	           }
	        else if(sum_1==0) return count;
	        else if(sum_1==1) 
	          {
			   printf("+================================+\n");
			   printf("|                                |\n");
		       printf("|       ���������������         |\n");
		       printf("|                                |\n");
		       printf("|        ���� ѧ�� ��ѧ�ɼ�      |\n");
		       printf("|     Ӣ��ɼ� ���ĳɼ� �ܳɼ�   |\n");    
		       printf("+================================+\n");
	           scanf("%s%s%d%d%d%d",stu[count].name,stu[count].number,&stu[count].math,&stu[count].english,&stu[count].chinese,&stu[count].all);
	           stu[count].money=0;
	           for(abc=0;abc<20;abc++)
	              stu[count].mm[abc]=stu[count].number[abc];
	           count++;
	          }
	        system("cls"); 
	       } 
	}
    
    
	int validate(char zh[],char mm[])//��½ϵͳ(���ô����˺��ļ�����ƥ��)
	{   
	    FILE *fp; 
    	fp=fopen("mima.in","r");
		int t=0;
	    char zh0[20]/*={'1','2','3'}*/,mm0[20]/*={'1','2','3'}*/;/////////////////�ļ���ȡ�����˺� 
	    fscanf(fp,"%s%s",zh0,mm0); 
		if(strcmp(zh,zh0)==0&&strcmp(mm,mm0)==0)
		  t=1;
		fclose(fp); 
        return t;
	}
	
	
	int validate_stu(int count,char zh[],char mm[])//ѧ����½ϵͳ(���ô����˺��ļ�����ƥ��)
	{  
	 int i,t=0;
	 for(i=0;i<count;i++)
	 	{
	 		if(strcmp(zh,stu[i].number)==0&&strcmp(mm,stu[i].mm)==0)
                t=1;
	 	}
	 return t;
	}
