#include<conio.h>
#include<stdio.h> 
#include<string.h>
#include<windows.h>
	int validate(char zh[],char mm[]);//登陆系统(调用储存账号文件进行匹配)
	int validate_stu(int count,char zh[],char mm[]);
	int entering(int count);//报到功能(信息录入:姓名,语数外成绩及总分,学费) 
	int payment(int count);//缴费功能(共5000,显示欠费和已交费) 	 
	int payment_stu(int count,char sum_number[]);//缴费功能(共5000,显示欠费和已交费) 
//	int payment2(char );//补交功能(共5000,显示欠费和已交费) 
    int query(int count);//查询功能(姓名、成绩和学费欠缴情况)
    int sort(int count);//排序功能(成绩和学费欠缴分别排序)     
    int ex(int i,int j);//交换
    int old_data(int count);//从文件中读取原有信息 
    int add(int count);//把本次数据放到文件中保存 
	void gaim();//改密 
	int gaim_stu(int count,char zh[]);

    struct student
    {
    	char name[20];
    	int  math;
    	int  english;
    	int  chinese;
    	int  all;
    	int  money;
    	char number[20];//交费情况 
    	char mm[20];
	}stu[100000];


	int main()
	{
     int  a=0/*退出系统标志*/,x/*代号*/,t=0;
	 int  count=0/*人数*/;
	 char zh[20],mm[20]; 
	 int  i,abc;
	 int  man;
	 printf("+================================+\n");
	 printf("|                                |\n");
	 printf("|        欢迎使用报道系统        |\n");
	 printf("|                                |\n");   
	 printf("|          请输入1登陆           |\n");
	 printf("|                                |\n");
	 printf("+================================+\n");
	 scanf("%d",&abc);
	 system("cls");
	 count=old_data(count); 
	 for(;;)
	   {
		 printf("+================================+\n");
		 printf("|                                |\n");
		 printf("|        学生登陆请按 1          |\n");
		 printf("|      管理人员登陆请按 2        |\n");   
		 printf("|        退出系统请按 0          |\n");
		 printf("|                                |\n");
		 printf("+================================+\n");
		 scanf("%d",&man);
		 system("cls");
	     if(man!=1&&man!=2&&man!=0)
	        {
		 	 printf("+================================+\n");
			 printf("|                                |\n");
		     printf("|          输入错误！            |\n");
		     printf("|                                |\n");
		     printf("|        重新输入请按 1          |\n");
		     printf("|                                |\n");    
		     printf("+================================+\n");
		     scanf ("%d",&abc);  
		     system("cls"); 
	        }	
		 else if(man==2)
		   {
			printf("+================================+\n");
			printf("|                                |\n");
			printf("|         请输入账号密码         |\n");
			printf("|                                |\n"); 
		    printf("|          以回车键结束          |\n");
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
					printf("|          账号密码错误          |\n");
					printf("|       请重新输入账号密码       |\n"); 
				    printf("|          以回车键间隔          |\n");
					printf("|                                |\n");
				    printf("+================================+\n");
		           }
			   }
			system("cls");  
			for(a=0;a==0;) 
		   	   {
			    printf("+================================+\n");
			    printf("|1.报到服务 2.缴费服务 3.查询服务|\n");
		     	printf("|                                |\n");
		        printf("|4.排序服务 5.返回上层 6.修改密码|\n");
		    	printf("|                                |\n");
		        printf("|      请输入相应的服务编号      |\n");    
		        printf("+================================+\n");
		        scanf ("%d",&x); 
		        system("cls"); 
		        if(x!=1&&x!=2&&x!=3&&x!=4&&x!=5&&x!=6)
		           {
					printf("+================================+\n");
				    printf("|                                |\n");
			     	printf("|          输入错误！            |\n");
			        printf("|                                |\n");
			    	printf("|        重新输入请按 1          |\n");
			        printf("|                                |\n");    
			        printf("+================================+\n");
			        scanf ("%d",&abc);  
			        system("cls"); 
		           }	    
				else switch(x)
			      {
			       case 1://报道 
		 	   	       count=entering(count);break; 
			       case 2://交费 
				       count=payment(count);break; 
			       case 3://查询 
				       count=query(count);break; 
				   case 4://排序 
				       count=sort(count);break;
			       case 5:
				       a=1;break; 
			       case 6://改密 
				       gaim();break; 
				  }
		       }
	        }
	     else if(man==1)
	       { 
			printf("+================================+\n");
			printf("|                                |\n");
			printf("|         请输入账号密码         |\n");
			printf("|     (初始账号密码均为学号)     |\n"); 
		    printf("|          以回车键结束          |\n");
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
					printf("|          账号密码错误          |\n");
					printf("|       请重新输入账号密码       |\n"); 
				    printf("|          以回车键间隔          |\n");
					printf("|                                |\n");
				    printf("+================================+\n");
		           }
			   }
			system("cls");  
			printf("+================================+\n");
			printf("|                                |\n");
			printf("|            登陆成功            |\n");
		    printf("|                                |\n"); 
			printf("|            输入1继续           |\n");
			printf("|                                |\n");
			printf("+================================+\n");
			scanf("%d",&abc);
			system("cls");			
			printf("+================================+\n");
			printf("|                                |\n");
			printf("|     1.补交学费  2.更改密码     |\n");
		    printf("|                                |\n"); 
			printf("|           输入相应服务         |\n");
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
	 printf("|         请输入新的密码         |\n");
	 printf("|                                |\n"); 
	 printf("|                                |\n");
 	 printf("|                                |\n");
	 printf("+================================+\n");
	 scanf("%s",stu[i].mm);
	 system("cls");
	 printf("+================================+\n");
	 printf("|                                |\n");
	 printf("|            修改成功            |\n");
	 printf("|                                |\n"); 
	 printf("|            输入0继续           |\n");
 	 printf("|                                |\n");
	 printf("+================================+\n");
	 scanf("%d",&abc);
	 system("cls"); 
 	 return count;
    } 
	

	void gaim()//改密
	{
		char zh[20],mm[20];
		int abc; 
		printf("+================================+\n");
		printf("|                                |\n");
		printf("|      请输入新的账号和密码      |\n");
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
		printf("|           修改成功！           |\n");
		printf("|                                |\n"); 
		printf("|         输入0返回上层          |\n");
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
   
   
    int sort(int count)//排序功能(成绩和学费欠缴分别排序) 
    {
     int sum_x,i,j,abc;
     for(;;)
     	{ 
		    printf("+================================+\n");
	     	printf("|   1.按语文成绩  2.按数学成绩   |\n");
	        printf("|   3.按英语成绩  4.按欠费情况   |\n");
	    	printf("|   5.返回主菜单                 |\n");
	        printf("|      请输入查询排序的编号      |\n"); 
		    printf("|         (从小到大排序)         |\n");   
	        printf("+================================+\n");
	        scanf ("%d",&sum_x);
	        system("cls");       
	        if(sum_x!=1&&sum_x!=2&&sum_x!=3&&sum_x!=4&&sum_x!=5)
	           {
				printf("+================================+\n");
			    printf("|                                |\n");
		     	printf("|          输入错误！            |\n");
		        printf("|                                |\n");
		    	printf("|        重新输入请按 1          |\n");
		        printf("|                                |\n");    
		        printf("+================================+\n");
		        scanf ("%d",&abc);  
		        system("cls"); 
	           }	     
			else switch(sum_x)
		      {
		       case 1://语文成绩
		       		for(i=0;i<(count-1);i++)
		       			for(j=i+1;j<count;j++)
		       		   	   if(stu[i].chinese>stu[j].chinese) 
		       		   	   	 ex(i,j);
		            printf("+================================+\n");
		       		for(i=0;i<count;i++)
					   {	
						printf("|    姓名：%s     学号：%s    |\n",stu[i].name,stu[i].number);
						printf("|                                |\n"); 
						printf("|    语文成绩:%d   数学成绩:%d   |\n",stu[i].chinese,stu[i].math);
						printf("|    英语成绩:%d    总成绩 :%d   |\n",stu[i].english,stu[i].all);
						printf("|    当前欠费:%d元               |\n",5000-stu[i].money); 
						printf("|                                |\n");
				        printf("|                                |\n");
         		       }
					printf("|          本次排序结束          |\n");
					printf("|                                |\n"); 
					printf("|            输入1继续           |\n");
					printf("|                                |\n");    
					printf("+================================+\n");
					scanf ("%d",&abc);
					system("cls"); 
                    break;
		       case 2://数学成绩
		       		for(i=0;i<(count-1);i++)
		       			for(j=i+1;j<count;j++)
		       		   	   if(stu[i].math>stu[j].math) 
		       		   	   	 ex(i,j);
		            printf("+================================+\n");
		       		for(i=0;i<count;i++)
					   {	
						printf("|    姓名：%s     学号：%s    |\n",stu[i].name,stu[i].number);
						printf("|                                |\n"); 
						printf("|    语文成绩:%d   数学成绩:%d   |\n",stu[i].chinese,stu[i].math);
						printf("|    英语成绩:%d    总成绩 :%d   |\n",stu[i].english,stu[i].all);
						printf("|    当前欠费:%d元               |\n",5000-stu[i].money); 
						printf("|                                |\n");
				        printf("|                                |\n");
         		       }
					printf("|          本次排序结束          |\n");
					printf("|                                |\n"); 
					printf("|            输入1继续           |\n");
					printf("|                                |\n");    
					printf("+================================+\n");
					scanf ("%d",&abc);
					system("cls"); 
                    break;
	    	   case 3://英语成绩 
		       		for(i=0;i<(count-1);i++)
		       			for(j=i+1;j<count;j++)
		       		   	   if(stu[i].english>stu[j].english) 
		       		   	   	 ex(i,j);
		            printf("+================================+\n");
		       		for(i=0;i<count;i++)
					   {	
						printf("|    姓名：%s     学号：%s    |\n",stu[i].name,stu[i].number);
						printf("|                                |\n"); 
						printf("|    语文成绩:%d   数学成绩:%d   |\n",stu[i].chinese,stu[i].math);
						printf("|    英语成绩:%d    总成绩 :%d   |\n",stu[i].english,stu[i].all);
						printf("|    当前欠费:%d元               |\n",5000-stu[i].money); 
						printf("|                                |\n");
				        printf("|                                |\n");
         		       }
					printf("|          本次排序结束          |\n");
					printf("|                                |\n"); 
					printf("|            输入1继续           |\n");
					printf("|                                |\n");    
					printf("+================================+\n");
					scanf ("%d",&abc);
					system("cls"); 
                    break;
		       case 4://欠费情况
		       		for(i=0;i<(count-1);i++)
		       			for(j=i+1;j<count;j++)
		       		   	   if(stu[i].money<stu[j].money) 
		       		   	   	 ex(i,j);
		            printf("+================================+\n");
		       		for(i=0;i<count;i++)
					   {	
						printf("|    姓名：%s     学号：%s    |\n",stu[i].name,stu[i].number);
						printf("|                                |\n"); 
						printf("|    语文成绩:%d   数学成绩:%d   |\n",stu[i].chinese,stu[i].math);
						printf("|    英语成绩:%d    总成绩 :%d   |\n",stu[i].english,stu[i].all);
						printf("|    当前欠费:%d元               |\n",5000-stu[i].money); 
						printf("|                                |\n");
				        printf("|                                |\n");
         		       }
					printf("|          本次排序结束          |\n");
					printf("|                                |\n");
					printf("|            输入1继续           |\n");
					printf("|                                |\n");    
					printf("+================================+\n");
					scanf ("%d",&abc);
					system("cls"); 
                    break;
			   case 5://主菜单 
		            return count; 
		      }
     	}
    }


    int ex(int i,int j)//交换
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


    int query(int count)//查询功能(姓名、成绩和学费欠缴情况)
    {
    	int sum_x,i,abc,sum_y,sum_man;
    	char sum_name[20];
    	int sum_a,sum_b,sum_c;
    	for(;;)
    	   {
		    printf("+================================+\n");
		    printf("|        1.按姓名查询            |\n");
	     	printf("|        2.按成绩查询            |\n");
	        printf("|        3.按学费情况查询        |\n");
	    	printf("|        4.返回主菜单            |\n");
	        printf("|       请输入查询服务编号       |\n");    
	        printf("+================================+\n");
	        scanf ("%d",&sum_x);
	        system("cls"); 
	        if(sum_x!=3&&sum_x!=1&&sum_x!=2&&sum_x!=4)
	           {
				printf("+================================+\n");
			    printf("|                                |\n");
		     	printf("|          输入错误！            |\n");
		        printf("|                                |\n");
		    	printf("|        重新输入请按 1          |\n");
		        printf("|                                |\n");    
		        printf("+================================+\n");
		        scanf ("%d",&abc);  
		        system("cls"); 
	           }	    
			else switch(sum_x)
		      {
		       case 1://按姓名查询
		            for(sum_y=0;;) 
				       {
				       	sum_y=0;
						printf("+================================+\n");
					    printf("|                                |\n");
				     	printf("|      请输入被查询人姓名        |\n");
				        printf("|                                |\n");
				    	printf("|       输入0返回上一菜单        |\n");
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
							printf("|    姓名：%s     学号：%s    |\n",stu[i].name,stu[i].number);
					        printf("|    语文成绩:%d   数学成绩:%d   |\n",stu[i].chinese,stu[i].math);
					    	printf("|    英语成绩:%d    总成绩 :%d   |\n",stu[i].english,stu[i].all);
					        printf("|    当前欠费:%d元               |\n",5000-stu[i].money); 
						    printf("|            输入0继续           |\n");   
					        printf("+================================+\n");
				          }
				        else
						  {
							printf("+================================+\n");
							printf("|                                |\n");
					        printf("|         无符合条件学生！       |\n");
					    	printf("|                                |\n");
					        printf("|            输入0继续           |\n"); 
						    printf("|                                |\n");   
					        printf("+================================+\n");
				          }
						scanf ("%d",&abc);
				        system("cls"); 
				       }
				       break; 
		       case 2://按成绩查询
			    	for(;;)
			    	   {
			    	   	sum_man=0;
					    printf("+================================+\n");
					    printf("|    语文成绩-1   数学成绩-2     |\n");
				     	printf("|    英语成绩-3    总成绩 -4     |\n");
				        printf("| 请输入查询相应的成绩和分数范围 |\n");
				    	printf("| 如:查询语文50到60分的同学的信息|\n");
				        printf("| 输入:1 50 60  输入0 0 0返回上层|\n");    
				        printf("+================================+\n");
				        scanf ("%d%d%d",&sum_a,&sum_b,&sum_c); 
				        system("cls"); 
				        if(sum_a==0) break; 
				        else 
				          {
					       printf("+================================+\n");
				           if(sum_a==1)//语文 
				             for(i=0;i<count;i++)
							    if(stu[i].chinese>=sum_b&&stu[i].chinese<=sum_c)
								  {	
					            	printf("|    姓名：%s     学号：%s    |\n",stu[i].name,stu[i].number);
								    printf("|                                |\n"); 
							        printf("|    语文成绩:%d   数学成绩:%d   |\n",stu[i].chinese,stu[i].math);
							    	printf("|    英语成绩:%d    总成绩 :%d   |\n",stu[i].english,stu[i].all);
							        printf("|    当前欠费:%d元               |\n",5000-stu[i].money); 
					                printf("|                                |\n");
			           		        printf("|                                |\n");
			           		        sum_man++;
							      }      
				           if(sum_a==2)
				             for(i=0;i<count;i++)
							    if(stu[i].math>=sum_b&&stu[i].math<=sum_c)
								  {	
						            printf("|    姓名：%s     学号：%s    |\n",stu[i].name,stu[i].number);
								    printf("|                                |\n"); 
							        printf("|    语文成绩:%d   数学成绩:%d   |\n",stu[i].chinese,stu[i].math);
							    	printf("|    英语成绩:%d    总成绩 :%d   |\n",stu[i].english,stu[i].all);
							        printf("|    当前欠费:%d元               |\n",5000-stu[i].money);
							        printf("|                                |\n");
							        printf("|                                |\n"); 
			           		        sum_man++; 
							      }
				           if(sum_a==3)
				             for(i=0;i<count;i++)
							    if(stu[i].english>=sum_b&&stu[i].english<=sum_c)
								  {	
					            	printf("|    姓名：%s     学号：%s    |\n",stu[i].name,stu[i].number);
								    printf("|                                |\n"); 
							        printf("|    语文成绩:%d   数学成绩:%d   |\n",stu[i].chinese,stu[i].math);
							    	printf("|    英语成绩:%d    总成绩 :%d   |\n",stu[i].english,stu[i].all);
							        printf("|    当前欠费:%d元               |\n",5000-stu[i].money); 
							        printf("|                                |\n");
							        printf("|                                |\n");
			           		        sum_man++;
							      }				           
				           if(sum_a==4)
				             for(i=0;i<count;i++)
							    if(stu[i].all>=sum_b&&stu[i].all<=sum_c)
								  {	
						            printf("|    姓名：%s     学号：%s    |\n",stu[i].name,stu[i].number);
								    printf("|                                |\n"); 
							        printf("|    语文成绩:%d   数学成绩:%d   |\n",stu[i].chinese,stu[i].math);
							    	printf("|    英语成绩:%d    总成绩 :%d   |\n",stu[i].english,stu[i].all);
							        printf("|    当前欠费:%d元               |\n",5000-stu[i].money); 
							        printf("|                                |\n");
							        printf("|                                |\n");
			           		        sum_man++;
							      }
					     	printf("|          本次查询结束          |\n");
					        printf("|            共查到%d人           |\n",sum_man);
					    	printf("|            输入1继续           |\n");
					        printf("|                                |\n");    
					        printf("+================================+\n");
					        scanf ("%d",&abc);
					        system("cls"); 
						  }
					   }
				       break; 
	    	   case 3://按学费情况查询
			        for(;;)
			          {
			          	sum_man=0;
					    printf("+================================+\n");
					    printf("|                                |\n");
				     	printf("|    请输入查询相应的欠费范围    |\n");
				        printf("|                                |\n");
				    	printf("| 如:查询欠费50到60元的同学的信息|\n");
				        printf("| 输入: 50 60   输入: 0 0返回上层|\n");    
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
						            printf("|    姓名：%s     学号：%s    |\n",stu[i].name,stu[i].number);
								    printf("|                                |\n"); 
							        printf("|    语文成绩:%d   数学成绩:%d   |\n",stu[i].chinese,stu[i].math);
							    	printf("|    英语成绩:%d    总成绩 :%d   |\n",stu[i].english,stu[i].all);
							        printf("|    当前欠费:%d元               |\n",5000-stu[i].money); 
					                printf("|                                |\n");
			           		        printf("|                                |\n");
			           		        sum_man++;
							    } 
					     	printf("|          本次查询结束          |\n");
					        printf("|            共查到%d人           |\n",sum_man);
					    	printf("|            输入1继续           |\n");
					        printf("|                                |\n");    
					        printf("+================================+\n");
					        scanf ("%d",&abc);
					        system("cls"); 
			               }
		              }
				       break; 
			   case 4://返回主菜单 
			        return count; 
		      }
		   }
	} 


    int payment(int count)//缴费功能(共5000,显示欠费和已交费) 
    { 
    	int sum_1,sum_money,i,abc,sum_man;
    	char sum_name[20];
    	for(;;)
		   { 
			printf("+================================+\n");
		    printf("|                                |\n");
	     	printf("|        继续付款请按 1          |\n");
	        printf("|                                |\n");
	    	printf("|        返回主页请按 0          |\n");
	        printf("|                                |\n");    
	        printf("+================================+\n");
	        scanf ("%d",&sum_1);
	        system("cls"); 
	        if(sum_1!=0&&sum_1!=1)
	           {
				printf("+================================+\n");
			    printf("|                                |\n");
		     	printf("|          输入错误！            |\n");
		        printf("|                                |\n");
		    	printf("|        重新输入请按 1          |\n");
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
		        printf("|         请输入付款人           |\n");
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
				        printf("|        请输入付款金额          |\n");
				    	printf("|                                |\n");
				        printf("|                                |\n");    
				        printf("+================================+\n");
				        scanf("%d",&sum_money);//////////////////如果没有欠费怎么办！！
						system("cls"); 
						stu[i].money=stu[i].money+sum_money;
						sum_man=1;
						break;
					 }
				if(sum_man==1)
				  {
					printf("+================================+\n");
				    printf("|                                |\n");
			     	printf("|           付款成功！           |\n");
			        printf("|                                |\n");
			    	printf("|          当前还欠费%d元        |\n",5000-stu[i].money);
			        printf("|           输入1继续            |\n");    
			        printf("+================================+\n");
		          }
		        else
				  {
					printf("+================================+\n");
					printf("|                                |\n");
				    printf("|         无符合条件学生！       |\n");
				   	printf("|                                |\n");
				    printf("|            输入0继续           |\n"); 
				    printf("|                                |\n");   
				    printf("+================================+\n");
				  }
				scanf("%d",&abc);///////////////////////////////如果没有欠费怎么办！！ 
		        system("cls"); 
	          }
           }
    }


    int payment_stu(int count,char sum_number[])//学生缴费功能(共5000,显示欠费和已交费) 
    { 
    	int sum_1,sum_money,i,abc;
    	for(;;)
		   { 
			printf("+================================+\n");
		    printf("|                                |\n");
	     	printf("|        继续付款请按 1          |\n");
	        printf("|                                |\n");
	    	printf("|        返回主页请按 0          |\n");
	        printf("|                                |\n");    
	        printf("+================================+\n");
	        scanf ("%d",&sum_1);
	        system("cls"); 
	        if(sum_1!=0&&sum_1!=1)
	           {
				printf("+================================+\n");
			    printf("|                                |\n");
		     	printf("|          输入错误！            |\n");
		        printf("|                                |\n");
		    	printf("|        重新输入请按 1          |\n");
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
				        printf("|        请输入付款金额          |\n");
				    	printf("|                                |\n");
				        printf("|                                |\n");    
				        printf("+================================+\n");
				        scanf("%d",&sum_money);//////////////////如果没有欠费怎么办！！
						system("cls"); 
						stu[i].money=stu[i].money+sum_money;
						break;
					 }
				printf("+================================+\n");
			    printf("|                                |\n");
		     	printf("|           付款成功！           |\n");
		        printf("|                                |\n");
		    	printf("|          当前还欠费%d元        |\n",5000-stu[i].money);
		        printf("|           输入1继续            |\n");    
		        printf("+================================+\n");
		        scanf("%d",&abc);///////////////////////////////如果没有欠费怎么办！！ 
		        system("cls"); 
	          }
           }
    }


	int entering(int count)//报到功能(信息录入:姓名,语数外成绩及总分,学费)
    {
    	int sum_1=1,abc;
    	for(;;)
		   { 
			printf("+================================+\n");
		    printf("|                                |\n");
	     	printf("|        信息输入请按 1          |\n");
	        printf("|                                |\n");
	    	printf("|        返回主页请按 0          |\n");
	        printf("|                                |\n");    
	        printf("+================================+\n");
	        scanf ("%d",&sum_1); 
	        system("cls"); 
	        if(sum_1!=0&&sum_1!=1)
	           {
				printf("+================================+\n");
			    printf("|                                |\n");
		     	printf("|          输入错误！            |\n");
		        printf("|                                |\n");
		    	printf("|        重新输入请按 1          |\n");
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
		       printf("|       请依次输入各数据         |\n");
		       printf("|                                |\n");
		       printf("|        姓名 学号 数学成绩      |\n");
		       printf("|     英语成绩 语文成绩 总成绩   |\n");    
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
    
    
	int validate(char zh[],char mm[])//登陆系统(调用储存账号文件进行匹配)
	{   
	    FILE *fp; 
    	fp=fopen("mima.in","r");
		int t=0;
	    char zh0[20]/*={'1','2','3'}*/,mm0[20]/*={'1','2','3'}*/;/////////////////文件读取密码账号 
	    fscanf(fp,"%s%s",zh0,mm0); 
		if(strcmp(zh,zh0)==0&&strcmp(mm,mm0)==0)
		  t=1;
		fclose(fp); 
        return t;
	}
	
	
	int validate_stu(int count,char zh[],char mm[])//学生登陆系统(调用储存账号文件进行匹配)
	{  
	 int i,t=0;
	 for(i=0;i<count;i++)
	 	{
	 		if(strcmp(zh,stu[i].number)==0&&strcmp(mm,stu[i].mm)==0)
                t=1;
	 	}
	 return t;
	}
