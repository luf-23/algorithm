#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
int flag=1;//该变量控制背景音乐
int flag1=1;//该变量控制光效果
void showproblem();//该函数打印出菜单
void choose();//该函数接受用户的选择并调用相应功能函数
void add();//加法功能函数，训练加法
void sub();//减法功能函数，训练减法
void multi();//乘法功能函数，训练乘法
void Div();//除法功能函数，训练除法
void all();//四则运算功能函数，训练四则运算
void showright();//当输入正确结果时调用此函数
void showerror();//当输入错误结果时调用此函数
void color_setting();//改变flag1设置光效果
void color();//调用此函数会产生光效果
void music();//调用此函数将产生背景音乐
void settings();//改变flag控制背景音乐
void warning();//训练不达标调用此函数
void victory();//训练达标调用此函数
void play_tiankongzhicheng();//保存了天空之城的播放数据
void play_yedegangqinqu5();//保存了夜的钢琴曲的播放数据
void play_youmeidexiaodiao();//保存了优美的小调的播放数据
void out();//退出程序时调用此函数
int main()
{
	showproblem();
	out();
	return 0;
}
void showproblem()
{
	system("color F1");
	system("CLS");
	printf("\n\n\n");
	printf("\t\t\t\t\t┌──────────────────────┐\n");
	printf("\t\t\t\t\t│ 欢迎来到小学生学数学 │\n");
	printf("\t\t\t\t\t│──────────────────────│\n");
	printf("\t\t\t\t\t│ 输入你想训练的内容。 │\n");
	printf("\t\t\t\t\t│ 1：加法              │\n");
	printf("\t\t\t\t\t│ 2：减法              │\n");
	printf("\t\t\t\t\t│ 3：乘法              │\n");
	printf("\t\t\t\t\t│ 4：除法              │\n");
	printf("\t\t\t\t\t│ 5：四则运算          │\n");
	printf("\t\t\t\t\t│ 6: 设置背景音乐      │\n");
	printf("\t\t\t\t\t│ 7: 设置光效果        │\n");
	printf("\t\t\t\t\t│ 8: 结束程序          │\n");
	printf("\t\t\t\t\t└──────────────────────┘\n");
	printf("\t\t\t\t\t●你的选择是：");
	music();
	choose();
}
void choose()
{
	int c;
	scanf("%d",&c);
	switch(c)
	{
		case 1:add();break;
		case 2:sub();break;
		case 3:multi();break;
		case 4:Div();break;
		case 5:all();break;
		case 6:settings();showproblem();break;
		case 7:color_setting();showproblem();break;
		case 8:exit;break;
	default:
		system("CLS");
		printf("\n\n\n");
		printf("\t\t\t\t\t┌────────────────────────────────┐\n");
		printf("\t\t\t\t\t│       !   FBI WARNING   !      │\n");
		printf("\t\t\t\t\t│────────────────────────────────│\n");
		printf("\t\t\t\t\t│你的选择不正确，请再选择一次吧！│\n");
		printf("\t\t\t\t\t│   your choice is not correct！ │\n");
		printf("\t\t\t\t\t│          按任意键确定。        │\n");
		printf("\t\t\t\t\t│    press any key to continue.  │\n");
		printf("\t\t\t\t\t└────────────────────────────────┘\n");
		printf("\a");
		color();
		getch();system("CLS");showproblem();break;
	}
}
void add()
{
	system("CLS");
	printf("\n\n\n");
	printf("\t\t\t\t\t┌────────────────────────────────┐\n");
	printf("\t\t\t\t\t│       !   FBI WARNING   !      │\n");
	printf("\t\t\t\t\t│────────────────────────────────│\n");
	printf("\t\t\t\t\t│ 加法运算的因子都是100以内整数！│\n");
	printf("\t\t\t\t\t│      all integers in adding!   │\n");
	printf("\t\t\t\t\t│          按任意键确定。        │\n");
	printf("\t\t\t\t\t│    press any key to continue.  │\n");
	printf("\t\t\t\t\t└────────────────────────────────┘\n");
	printf("\a");
	color();
	getch();
	int a,b,number=10;
	int answer;
	int score=10;
	int i=0;
	while(number--)
	{
		i++;
		system("CLS");
		srand(time(NULL));
		a=rand()%99+1;
		b=rand()%99+1;
		system("color F5");
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t┌───────────────────┐\n");
		printf("\t\t\t\t\t│第%-2d题：%-2d+%-2d=【 】│\n",i,a,b);
		printf("\t\t\t\t\t└───────────────────┘\n");
		printf("\t\t\t\t\t你的答案是:");
		music();
		scanf("%d",&answer);
		if(answer==a+b)
		{
			showright();
			if(number!=0)
			{
				printf("按任意键进入下一题......\n");
				getch();
			}
		}
		else
		{
			score--;
			showerror();
			if(number!=0)
			{
				printf("按任意键进入下一题......\n");
				getch();
			}
		}
		
	}
	if(score<=7)
	{
		warning();
		getch();
		add();
	}
	else
	{
		victory();
	}
}
void sub()
{
	system("CLS");
	printf("\n\n\n");
	printf("\t\t\t\t\t┌────────────────────────────────┐\n");
	printf("\t\t\t\t\t│       !   FBI WARNING   !      │\n");
	printf("\t\t\t\t\t│────────────────────────────────│\n");
	printf("\t\t\t\t\t│ 减法运算的因子都是100以内整数！│\n");
	printf("\t\t\t\t\t│  all integers in subtraction!  │\n");
	printf("\t\t\t\t\t│          按任意键确定。        │\n");
	printf("\t\t\t\t\t│    press any key to continue.  │\n");
	printf("\t\t\t\t\t└────────────────────────────────┘\n");
	printf("\a");
	color();
	getch();
	int a,b,number=10;
	int answer;
	int score=10;
	int i=0;
	while(number--)
	{
		i++;
		system("CLS");
		srand(time(NULL));
		a=rand()%99+1;
		b=rand()%99+1;
		system("color F5");
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t┌───────────────────┐\n");
		printf("\t\t\t\t\t│第%-2d题：%-2d-%-2d=【 】│\n",i,a,b);
		printf("\t\t\t\t\t└───────────────────┘\n");
		printf("\t\t\t\t\t你的答案是:");
		music();
		scanf("%d",&answer);
		if(answer==a-b)
		{
			showright();
			if(number!=0)
			{
				printf("按任意键进入下一题......\n");
				getch();
			}
		}
		else
		{
			score--;
			showerror();
			if(number!=0)
			{
				printf("按任意键进入下一题......\n");
				getch();
			}
		}
		
	}
	if(score<=7)
	{
		warning();
		getch();
		sub();
	}
	else
	{
		victory();
	}
}
void multi()
{
	system("CLS");
	printf("\n\n\n");
	printf("\t\t\t\t\t┌────────────────────────────────┐\n");
	printf("\t\t\t\t\t│       !   FBI WARNING   !      │\n");
	printf("\t\t\t\t\t│────────────────────────────────│\n");
	printf("\t\t\t\t\t│ 乘法运算的因子都是100以内整数！│\n");
	printf("\t\t\t\t\t│ all integers in multiplication │\n");
	printf("\t\t\t\t\t│          按任意键确定。        │\n");
	printf("\t\t\t\t\t│    press any key to continue.  │\n");
	printf("\t\t\t\t\t└────────────────────────────────┘\n");
	printf("\a");
	color();
	getch();
	int a,b,number=10;
	int answer;
	int score=10;
	int i=0;
	while(number--)
	{
		i++;
		system("CLS");
		srand(time(NULL));
		a=rand()%99+1;
		b=rand()%99+1;
		system("color F5");
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t┌───────────────────┐\n");
		printf("\t\t\t\t\t│第%-2d题：%-2d*%-2d=【 】│\n",i,a,b);
		printf("\t\t\t\t\t└───────────────────┘\n");
		printf("\t\t\t\t\t你的答案是:");
		music();
		scanf("%d",&answer);
		if(answer==a*b)
		{
			showright();
			if(number!=0)
			{
				printf("按任意键进入下一题......\n");
				getch();
			}
		}
		else
		{
			score--;
			showerror();
			if(number!=0)
			{
				printf("按任意键进入下一题......\n");
				getch();
			}
		}
		
	}
	if(score<=7)
	{
		warning();
		getch();
		multi();
	}
	else
	{
		victory();
	}
}
void Div()
{
	system("CLS");
	printf("\n\n\n");
	printf("\t\t\t\t\t┌────────────────────────────────┐\n");
	printf("\t\t\t\t\t│       !   FBI WARNING   !      │\n");
	printf("\t\t\t\t\t│────────────────────────────────│\n");
	printf("\t\t\t\t\t│     除法运算请保留两位小数！   │\n");
	printf("\t\t\t\t\t│     please keep 2 decimals!    │\n");
	printf("\t\t\t\t\t│          按任意键确定。        │\n");
	printf("\t\t\t\t\t│    press any key to continue.  │\n");
	printf("\t\t\t\t\t└────────────────────────────────┘\n");
	printf("\a");
	color();
	getch();
	int a,b,number=10;
	float answer;
	int score=10;
	int i=0;
	while(number--)
	{
		i++;
		system("CLS");
		srand(time(NULL));
		a=rand()%99+1;
		b=rand()%99+1;
		system("color F5");
		if(a<b)
		{
			int t;
			t=a;
			a=b;
			b=t;
		}
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t┌───────────────────┐\n");
		printf("\t\t\t\t\t│第%-2d题：%-2d/%-2d=【 】│\n",i,a,b);
		printf("\t\t\t\t\t└───────────────────┘\n");
		printf("\t\t\t\t\t你的答案是:");
		music();
		scanf("%f",&answer);
		if((fabs(answer-a*1.0/b))<=10e-3)
		{
			showright();
			if(number!=0)
			{
				printf("按任意键进入下一题......\n");
				getch();
			}
		}
		else
		{
			score--;
			showerror();
			if(number!=0)
			{
				printf("按任意键进入下一题......\n");
				getch();
			}
		}
		
	}
	if(score<=7)
	{
		warning();
		getch();
		Div();
	}
	else
	{
		victory();
	}
}
void all()
{
	system("CLS");
	printf("\n\n\n");
	printf("\t\t\t\t\t┌────────────────────────────────┐\n");
	printf("\t\t\t\t\t│       !   FBI WARNING   !      │\n");
	printf("\t\t\t\t\t│────────────────────────────────│\n");
	printf("\t\t\t\t\t│   运算的因子都是100以内整数！  │\n");
	printf("\t\t\t\t\t│  all integers in calculating!  │\n");
	printf("\t\t\t\t\t│     除法运算请保留两位小数！   │\n");
	printf("\t\t\t\t\t│     please keep 2 decimals!    │\n");
	printf("\t\t\t\t\t│          按任意键确定。        │\n");
	printf("\t\t\t\t\t│    press any key to continue.  │\n");
	printf("\t\t\t\t\t└────────────────────────────────┘\n");
	printf("\a");
	color();
	getch();
	int a,b,c,number=10;
	float answer;
	int score=10;
	int i=0;
	while(number--)
	{
		i++;
		system("CLS");
		srand(time(NULL));
		a=rand()%99+1;
		b=rand()%99+1;
		c=rand()%4;
		
		system("color F5");
		printf("\n\n\n\n\n");
		if(c==0)
		{
			printf("\t\t\t\t\t┌───────────────────┐\n");
			printf("\t\t\t\t\t│第%-2d题：%-2d+%-2d=【 】│\n",i,a,b);
			printf("\t\t\t\t\t└───────────────────┘\n");
			printf("\t\t\t\t\t你的答案是:");
			music();
			scanf("%f",&answer);
			if(answer==a+b)
				answer=1;
			else
				answer=0;
		}
		if(c==1)
		{
			printf("\t\t\t\t\t┌───────────────────┐\n");
			printf("\t\t\t\t\t│第%-2d题：%-2d-%-2d=【 】│\n",i,a,b);
			printf("\t\t\t\t\t└───────────────────┘\n");
			printf("\t\t\t\t\t你的答案是:");
			music();
			scanf("%f",&answer);
			if(answer==a-b)
				answer=1;
			else
				answer=0;
		}
		if(c==2)
		{
			printf("\t\t\t\t\t┌───────────────────┐\n");
			printf("\t\t\t\t\t│第%-2d题：%-2d*%-2d=【 】│\n",i,a,b);
			printf("\t\t\t\t\t└───────────────────┘\n");
			printf("\t\t\t\t\t你的答案是:");
			music();
			scanf("%f",&answer);
			if(answer==a*b)
				answer=1;
			else
				answer=0;
		}
		if(c==3)
		{
			if(a<b)
			{
				int t;
				t=a;
				a=b;
				b=t;
			}
			printf("\t\t\t\t\t┌───────────────────┐\n");
			printf("\t\t\t\t\t│第%-2d题：%-2d/%-2d=【 】│\n",i,a,b);
			printf("\t\t\t\t\t└───────────────────┘\n");
			printf("\t\t\t\t\t你的答案是:");
			music();
			scanf("%f",&answer);
			if((fabs(answer-a*1.0/b))<=10e-3)
				answer=1;
			else
				answer=0;
		}
		if(answer==1)
		{
			showright();
			if(number!=0)
			{
				printf("按任意键进入下一题......\n");
				getch();
			}
		}
		else
		{
			score--;
			showerror();
			if(number!=0)
			{
				printf("按任意键进入下一题......\n");
				getch();
			}
		}
		
	}
	if(score<=7)
	{
		warning();
		getch();
		all();
	}
	else
	{
		victory();
	}
}
void showright()
{
	system("color F2");
	int a;
	srand(time(NULL));
	a=rand()%4;
	printf("\t\t\t\t\t");
	switch(a)
	{
		case 0:printf("Very good!\n");Beep(440,1000);break;
		case 1:printf("Excellent!\n");Beep(440,1000);break;
		case 2:printf("Nice work!\n");Beep(440,1000);break;
		case 3:printf("Keep up the good work!\n");Beep(440,1000);break;
	}
}
void showerror()
{
	system("color F4");
	int a;
	srand(time(NULL));
	a=rand()%4;
	printf("\t\t\t\t\t");
	switch(a)
	{
		case 0:printf("No,please try again!\n\a");break;
		case 1:printf("Wrong,try once more!\n\a");break;
		case 2:printf("Don't give up!\n\a");break;
		case 3:printf("Not correct,keep trying!\n\a");break;
	}
}
void music()
{
	switch(flag)
	{
		case 1 : play_tiankongzhicheng();break;
		case 2 : play_yedegangqinqu5();break;
		case 3 : play_youmeidexiaodiao();break;
	}
}
void bell(double a,int b)//编后发现只有这样调整才能发出声音。。。
{
	if(a==0.1)
	{
		a=262;
	}
	else if(a==0.11)
	{
		a=277;
	}
	else if(a==0.2)
	{
		a=294;
	}
	else if(a==0.21)
	{
		a=311;
	}
	else if(a==0.3)
	{
		a=330;
	}
	else if(a==0.4)
	{
		a=349;
	}
	else if(a==0.41)
	{
		a=370;
	}
	else if(a==0.5)
	{
		a=392;
	}
	else if(a==0.51)
	{
		a=415;
	}
	else if(a==0.6)
	{
		a=440;
	}
	else if(a==0.61)
	{
		a=466;
	}
	else if(a==0.7)
	{
		a=494;
	}
	else if(a==1.2)
	{
		a=523;
	}
	else if(a==1.3)
	{
		a=554;
	}
	else if(a==2.2)
	{
		a=587;
	}
	else if(a==2.1)
	{
		a=622;
	}
	else if(a==3.2)
	{
		a=659;
	}
	else if(a==4.2)
	{
		a=698;
	}
	else if(a==4.3)
	{
		a=740;
	}
	else if(a==5.2)
	{
		a=784;
	}
	else if(a==5.3)
	{
		a=831;
	}
	else if(a==6.2)
	{
		a=880;
	}
	else if(a==6.3)
	{
		a=932;
	}
	else if(a==7.2)
	{
		a=988;
	}
	else if(a==10.2)
	{
		a=1046;
	}
	else if(a==11.2)
	{
		a=1109;
	}
	else if(a==20.2)
	{
		a=1175;
	}
	else if(a==21.2)
	{
		a=1245;
	}
	else if(a==30.2)
	{
		a=1318;
	}
	else if(a==40.2)
	{
		a=1397;
	}
	else if(a==41.2)
	{
		a=1480;
	}
	else if(a==50.2)
	{
		a=1568;
	}
	else if(a==51.2)
	{
		a=1661;
	}
	else if(a==60.2)
	{
		a=1760;
	}
	else if(a==61.2)
	{
		a=1865;
	}
	else if(a==70.2)
	{
		a=1976;
	}
	if(b!=0&&flag!=3)
	{
		int c=(int)a;
		Beep(c,b*350);
	}
	else if(flag!=3)
		Sleep(600);
	else
	{
		int c=(int)a;
		Beep(c,b*250);
	}
	
}
void play_tiankongzhicheng()
{
	double a[]={6,7,10,7,10,30,7,3,6,5,6,10,5,3,3,4,3,4,10,3,10,10,10,7,4.1,4,7,7,6,7,10,7,10,30,7,3,6,5,6,10,5,3,3,4,10,7,10,20,30,10,10,7,6,7,5.1,6,10,20,30,20,30,50,20,5,10,7,10,30,7,5,5,6,7,10,7,10,20,10,5,40,30,20,10,30,30,60,50,30,20,10,10,20,10,20,50,30,30,60,50,30,20,10,10,20,10,20,10,6};
	int b[]={1,1,3,1,2,2,6,2,3,1,2,2,6,1,1,3,1,1,3,4,1,1,1,2,1,2,2,6,1,1,3,1,2,2,6,2,3,1,2,2,6,1,1,2,1,3,2,2,1,5,1,1,2,2,2,6,1,1,2,1,2,4,6,2,3,1,2,2,6,1,1,1,1,2,1,1,2,4,4,2,2,2,2,6,2,4,4,1,1,4,2,3,1,2,2,6,2,4,4,1,1,4,2,3,1,2,2,4};
	int i=0;
	for(i=0;i<108;i++)
	{
		if(a[i]>0.9)
			a[i]+=0.2;
	}
	
	i=0;
	while(!kbhit())
	{
		bell(a[i],b[i]);
		i++;
		i=i%108;
	}
}
void play_yedegangqinqu5()
{
	double a[]={1,2,1.9,5,10,1,2,1.9,5,10,40,21,20,21,10,0,1,2,1.9,5,10,1,2,1.9,5,10,40,21,20,21,10,0,5,6.1,10,50,40,50,40,50,40,21,40,40,50,61,50,6.1,5,6.1,5,6.1,40,21,1,2,1.9,5,10,50,50,40,50,40,20,40,21,20,21,10};
	int b[]={1,1,1,1,4,1,1,1,1,4,1,1,1,1,9,0,1,1,1,1,4,1,1,1,1,4,1,1,1,1,9,0,1,1,1,1,3,1,1,1,1,1,4,1,1,1,1,3,1,1,1,1,1,4,1,1,1,1,3,1,1,1,1,1,4,1,1,1,1,8};
	int i;
	for(i=0;i<70;i++)
	{
		if(a[i]>0.9)
			a[i]+=0.2;
	}
	
	i=0;
	while(!kbhit())
	{
		bell(a[i],b[i]);
		i++;
		i=i%70;
	}
}
void play_youmeidexiaodiao()//把调号看错了，尴尬
{
	int i;
	double a[]={5.1,10,5.1,20,40,30,20,10,5,5.1,10,5,10,4,2,4,2,5,5,5.1,5.1,5,3,2,2,0.51,1,0.51,2,4,0.51,3,2,1,0.5,0.51,1,0.5,1,0.4,0.2,0.4,0.2,0.5,0.5,0.51,0.51,0.5,0.3,0.2,0.2,0.51,1,2,4,3,2,1,0.51,0.51,1,0.51,2,4,3,4,5,5,0.51,1,0.51,2,4,3,2,1,0.51,0.51,1,0.51,2,4,3,4,5,5.1};
	int b[]={2,1,1,6,2,2,2,2,2,2,2,2,2,4,2,1,1,4,2,2,2,2,2,2,9,2,1,1,6,1,1,2,2,2,2,2,2,2,2,4,2,1,1,4,2,2,2,2,2,2,9,2,2,6,2,4,2,2,9,2,1,1,6,2,4,2,2,9,2,1,1,6,2,4,2,2,9,2,1,1,6,2,4,2,2,9};
	for(i=0;i<86;i++)
	{
		
		if(a[i]==5.1)
			a[i]=6;
		else if(a[i]==0.51)
			a[i]=0.6;
		if(a[i]>0.9)
			a[i]+=0.2;
	}
	
	i=0;
	while(!kbhit())
	{
		bell(a[i],b[i]);
		i++;
		i=i%86;
	}
}
void settings()
{
	system("CLS");
	printf("\n\n\n");
	printf("\t\t\t\t\t┌────────────────────────────────┐\n");
	printf("\t\t\t\t\t│          ! 声音设置 !          │\n");
	printf("\t\t\t\t\t│────────────────────────────────│\n");
	printf("\t\t\t\t\t│  1:天空之城（默认）            │\n");
	printf("\t\t\t\t\t│  2:夜的钢琴曲五                │\n");
	printf("\t\t\t\t\t│  3:优美的小调                  │\n");
	printf("\t\t\t\t\t│  4:关闭背景音效                │\n");
	printf("\t\t\t\t\t└────────────────────────────────┘\n");
	color();
	scanf("%d",&flag);
	if(flag!=1&&flag!=2&&flag!=3&&flag!=4)
	{
		flag=1;
		system("CLS");
		printf("\n\n\n");
		printf("\t\t\t\t\t┌────────────────────────────────┐\n");
		printf("\t\t\t\t\t│       !   FBI WARNING   !      │\n");
		printf("\t\t\t\t\t│────────────────────────────────│\n");
		printf("\t\t\t\t\t│你的选择不正确，请再选择一次吧！│\n");
		printf("\t\t\t\t\t│   your choice is not correct！ │\n");
		printf("\t\t\t\t\t│          按任意键确定。        │\n");
		printf("\t\t\t\t\t│    press any key to continue.  │\n");
		printf("\t\t\t\t\t└────────────────────────────────┘\n");
		printf("\a");
		color();
		getch();
		system("CLS");
		settings();
	}
	else
	{
		system("CLS");
		printf("\n\n\n");
		printf("\t\t\t\t\t┌────────────────────────────────┐\n");
		printf("\t\t\t\t\t│       !   FBI WARNING   !      │\n");
		printf("\t\t\t\t\t│────────────────────────────────│\n");
		printf("\t\t\t\t\t│          音效设置完毕！        │\n");
		printf("\t\t\t\t\t│    voice setting was saved !   │\n");
		printf("\t\t\t\t\t│          按任意键确定。        │\n");
		printf("\t\t\t\t\t│    press any key to continue.  │\n");
		printf("\t\t\t\t\t└────────────────────────────────┘\n");
		printf("\a");
		color();
		getch();
	}
	
}
void color_setting()
{
	system("CLS");
	printf("\n\n\n");
	printf("\t\t\t\t\t┌────────────────────────────────┐\n");
	printf("\t\t\t\t\t│          ! 光效设置 !          │\n");
	printf("\t\t\t\t\t│────────────────────────────────│\n");
	printf("\t\t\t\t\t│  1:开启（默认）                │\n");
	printf("\t\t\t\t\t│  2:关闭                        │\n");
	printf("\t\t\t\t\t└────────────────────────────────┘\n");
	color();
	scanf("%d",&flag1);
	if(flag1!=1&&flag1!=2)
	{
		flag1=1;
		system("CLS");
		printf("\n\n\n");
		printf("\t\t\t\t\t┌────────────────────────────────┐\n");
		printf("\t\t\t\t\t│       !   FBI WARNING   !      │\n");
		printf("\t\t\t\t\t│────────────────────────────────│\n");
		printf("\t\t\t\t\t│你的选择不正确，请再选择一次吧！│\n");
		printf("\t\t\t\t\t│   your choice is not correct！ │\n");
		printf("\t\t\t\t\t│          按任意键确定。        │\n");
		printf("\t\t\t\t\t│    press any key to continue.  │\n");
		printf("\t\t\t\t\t└────────────────────────────────┘\n");
		printf("\a");
		color();
		getch();
		system("CLS");
		color_setting();
	}
	else
	{
		system("CLS");
		printf("\n\n\n");
		printf("\t\t\t\t\t┌────────────────────────────────┐\n");
		printf("\t\t\t\t\t│       !   FBI WARNING   !      │\n");
		printf("\t\t\t\t\t│────────────────────────────────│\n");
		printf("\t\t\t\t\t│          光效设置完毕！        │\n");
		printf("\t\t\t\t\t│    color setting was saved !   │\n");
		printf("\t\t\t\t\t│          按任意键确定。        │\n");
		printf("\t\t\t\t\t│    press any key to continue.  │\n");
		printf("\t\t\t\t\t└────────────────────────────────┘\n");
		printf("\a");
		color();
		getch();
	}
	
}
void color()
{
	int time;
	if(flag1==1)
	{
		while(!kbhit())
		{
			system("color Fa");
			for (time = 0; time<999999; time++);
			system("color Fb");
			for (time = 0; time<999999; time++);
			system("color Fc");
			for (time = 0; time<999999; time++);
			system("color Fd");
			for (time = 0; time<999999; time++);
			system("color Fe");
			for (time = 0; time<999999; time++);
			system("color F1");
			for (time = 0; time<999999; time++);
			system("color F2");
			for (time = 0; time<999999; time++);
			system("color F3");
			for (time = 0; time<999999; time++);
			system("color F4");
			for (time = 0; time<999999; time++);
			system("color F5");
			for (time = 0; time<999999; time++);
			system("color F6");
			for (time = 0; time<999999; time++);
			system("color F9");
		}
	}
	else
	{
		while(!kbhit())
			system("color F1");
		
	}
}
void warning()
{
	system("CLS");
	printf("\n\n\n");
	printf("\t\t\t\t\t┌────────────────────────────────┐\n");
	printf("\t\t\t\t\t│       !   FBI WARNING   !      │\n");
	printf("\t\t\t\t\t│────────────────────────────────│\n");
	printf("\t\t\t\t\t│   你的正确率低于75%%！需要重做！│\n");
	printf("\t\t\t\t\t│   your score is less than 75!  │\n");
	printf("\t\t\t\t\t│    please do the work again!   │\n");
	printf("\t\t\t\t\t│          按任意键确定。        │\n");
	printf("\t\t\t\t\t│    press any key to continue.  │\n");
	printf("\t\t\t\t\t└────────────────────────────────┘\n");
	printf("\a");
	color();
}
void victory()
{
	system("CLS");
	printf("\n\n\n");
	printf("\t\t\t\t\t┌────────────────────────────────┐\n");
	printf("\t\t\t\t\t│       !   FBI WARNING   !      │\n");
	printf("\t\t\t\t\t│────────────────────────────────│\n");
	printf("\t\t\t\t\t│        你的正确率高于75%%！     │\n");
	printf("\t\t\t\t\t│   your score is more than 75!  │\n");
	printf("\t\t\t\t\t│            继续努力！          │\n");
	printf("\t\t\t\t\t│        keep on working !       │\n");
	printf("\t\t\t\t\t│          按任意键确定。        │\n");
	printf("\t\t\t\t\t│    press any key to continue.  │\n");
	printf("\t\t\t\t\t└────────────────────────────────┘\n");
	printf("\a");
	color();
	getch();
	showproblem();
}
void out()
{
	system("CLS");
	printf("\n\n\n");
	printf("\t\t\t\t\t┌────────────────────────────────┐\n");
	printf("\t\t\t\t\t│       !   FBI WARNING   !      │\n");
	printf("\t\t\t\t\t│────────────────────────────────│\n");
	printf("\t\t\t\t\t│           程序运行结束！       │\n");
	printf("\t\t\t\t\t│        the work is over!       │\n");
	printf("\t\t\t\t\t│            感谢使用！          │\n");
	printf("\t\t\t\t\t│        thanks for using!       │\n");
	printf("\t\t\t\t\t│          按任意键确定。        │\n");
	printf("\t\t\t\t\t│    press any key to continue.  │\n");
	printf("\t\t\t\t\t└────────────────────────────────┘\n");
	printf("\a");
	color();
}

//-input-charset=UTF-8
//-fexe-charset=GBK
