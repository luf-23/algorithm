#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<ctype.h>
int grade=0;
char A[13];
const char PS[13]={'H','E','L','L','O',' ','W','O','R','L','D','!'};
void p(const char* string,int sleeptime)
{
	int i = 0;
	while(string[i] != '\0')
	{
		printf("%c", string[i]);
		Sleep(sleeptime);
		i++;
	}
	printf("\n");
}
void re_set()
{
	grade=0;
	memset(A,'0',sizeof(A));
}
void border()
{
	for(int i=1;i<=80;i++)
		printf("=");
}
void border1()
{
	for (int i=1;i<=80;i++)
		printf("-");
}
void page1()
{
	system("cls");
	border1();
	int i,j,a[100][100],tag=0;
	for(i=1;i<=5;i++)
		for(j=1;j<=80;j++)
			printf("*",a[i][j]);
	for(i=6;i<=15;i++)
	{
		for(j=1;j<=80;j++)
		{
			if(j>=16&&j<=64&&i<=15&&i>=6)
			{
				printf("*****************");
				printf("   @@@@    @@@@@@@@      @@      @@@@@    @@@@@@@@ *************");
				printf("***************");
				printf("  @@          @@        @@@@     @@  @@      @@    *************");
				printf("***************");
				printf(" @@           @@       @@  @@    @@   @@     @@    *************");
				printf("***************");
				printf(" @@           @@      @@    @@   @@   @@     @@    *************");
				printf("***************");
				printf("  @@@@@       @@      @@@@@@@@   @@@@@@      @@    *************");
				printf("***************");
				printf("      @@      @@      @@    @@   @@ @        @@    *************");
				printf("***************");
				printf("       @@     @@      @@    @@   @@ @@       @@    *************");
				printf("***************");
				printf("      @@      @@      @@    @@   @@   @@     @@    *************");
				printf("***************");
				printf("  @@@@@       @@      @@    @@   @@    @@    @@    ********************");
				tag=1;
				break;
			}
			if(tag)
				break;
		}
	}
	for(i=16;i<=20;i++)
		for(j=1;j<=80;j++)
			printf("*");
	border1();
	printf("                                                             信安1502班\n");
	printf("                                                              LJW  BXY\n");
	getch();
}
void s1()
{
	system("cls");
	border();
	for(int i=1;i<=19;i++)
	{
		if (i==6)
			printf("                                 请选择你要挑战的等级 \n");
		else if (i==8)
			printf("                                 1 . 大师\n");
		else if (i==10)
			printf("                                 2 . 普通\n");
		else if (i==12)
			printf("                                 3 . 新手\n");
		else
			printf("\n");
	}
	border();
}
void s2(char f)
{
	system("cls");
	border();
	for(int i=1;i<=19;i++)
	{
		if (i==10)
		{
			if(f=='1')
				printf("                                 你再考虑考虑 ？\n");
			else if (f=='3')
				printf("                            资金不足，没有做新手题 ！\n");
			else if (f=='2')
				printf("                           恭喜你，做出了正确的选择！\n");
			else
				printf("                                Error：请重新输入......\n");
		}
		else
			printf("\n");
	}
	border();
	if(f !='2')
	{
		getch();
		s1();
		s2(getch());
	}
	else
		getch();
}
void s3()
{
	system("cls");
	border();
	for(int i=1;i<=19;i++)
	{
		if (i==10)
			printf("                                那么问题来了......\n");
		else
			printf("\n");
	}
	border();
	getch();
}
void q_fun1()
{
	system("cls");
	border();
	for (int i=1;i<=19;i++)
	{
		if (i==6)
			printf("                                 一、你相信星座吗\n");
		else if (i==9)
			printf("                                  A.信\n");
		else if (i==11)
			printf("                                  B.不信\n");
		else
			printf("\n");
	}
	border();
	char k=getch();
	if(k!='A'&&k!='a'&&k!='B'&&k!='b')
		q_fun1();
}
void q_fun2()
{
	system("cls");
	border();
	for (int i=1;i<=19;i++)
	{
		if (i==6)
			printf("                                 二、你相信血型吗\n");
		else if (i==9)
			printf("                                  A.相信\n");
		else if (i==11)
			printf("                                  B.不信\n");
		else
			printf("\n");
	}
	border();
	char k=getch();
	if(k!='A'&&k!='a'&&k!='B'&&k!='b')
		q_fun2();
}
void q_fun3()
{
	system("cls");
	border();
	for (int i=1;i<=19;i++)
	{
		if (i==6)
			printf("                                 三、你相信算命的结果吗\n");
		else if (i==9)
			printf("                                  A.相信\n");
		else if (i==11)
			printf("                                  B.不信\n");
		else
			printf("\n");
	}
	border();
	char k=getch();
	if(k!='A'&&k!='a'&&k!='B'&&k!='b')
		q_fun3();
}
void q_fun4()
{
	system("cls");
	border();
	for (int i=1;i<=19;i++)
	{
		if (i==6)
			printf("                                 四、你相信外星人存在吗\n");
		else if (i==9)
			printf("                                  A.相信\n");
		else if (i==11)
			printf("                                  B.不信\n");
		else
			printf("\n");
	}
	border();
	char k=getch();
	if(k!='A'&&k!='a'&&k!='B'&&k!='b')
		q_fun4();
}
void q0()
{
	system("cls");
	border();
	for (int i=1;i<=19;i++)
	{
		if (i==10)
			printf("                   刚才的题只是娱乐娱乐~现在正是开始答题......\n");
		else
			printf("\n");
	}
	border();
	getch();
}
void q1()
{
	system("cls");
	border();
	for (int i=1;i<=18;i++)
	{
		if (i==6)
			printf("Q1.B同学喜欢做数学题，现在她遇到了一道题，知道答案后，她大喊“坑爹！”题目是这样的：\n");
		else if (i==7)
			printf("                                  1=4···\n");
		else if (i==8)
			printf("                                  2=9···\n");
		else if (i==9)
			printf("                                  3=15···\n");
		else if (i==10)
			printf("                                  4=?···\n");
		else if (i==14)
			printf("                  A. 20     B. 22      C. 24    D. 1\n");
		else
			printf("\n");
	}
	border();
	char X=getch();
	if(tolower(X)=='d')
		A[1]='1';
}

void q2()
{
	system("cls");
	border();
	for (int i=1;i<=19;i++)
	{
		if (i==6)
			printf(" Q2.A正看着B,而B正看着C，A已婚,C未婚,请问是否正有一位已婚人士看着一位未婚人士？\n");
		else if (i==10)
			printf("                               A. 有的     B. 没有\n");
		else
			printf("\n");
	}
	border();
	char X=getch();
	if(tolower(X)=='a')
		A[2]='1';
}
void q3()
{
	system("cls");
	border();
	for(int i=1;i<=19;i++)
	{
		if(i==6)
			printf("         Q3:有一对夫妇有两个孩子，其中一个是女孩，问另一个也是女孩的概率\n");
		else if(i==11)
			printf("                    A. 1      B. 1/2      C. 1/3     D. 1/4\n");
		else
			printf("\n");
	}
	border();
	char X=getch();
	if(tolower(X)=='c')
		A[3]='1';
}
void q4()
{
	system("cls");
	border();
	for (int i=1;i<=18;i++)
	{
		if (i==6)
			printf("Q4.B同学上周末去听了一节音乐会，L问她有没有印象深刻的曲目，B同学回答：踹鸡鸡。请问她说可能是哪首曲目\n");
		else if (i==9)
			printf("           A. 克罗地亚狂想曲     B. 蜂鸟     C. 出埃及记    D. 野蜂飞舞\n");
		else
			printf("\n");
	}
	border();
	char X=getch();
	if(tolower(X)=='c')
		A[4]='1';
}
void q5()
{
	system("cls");
	border();
	
	for(int i=1;i<=19;i++)
	{
		if(i==6)
			printf("                    Q5:什么时候你会觉得比别人穷？\n");
		else if (i==8)
			printf("                    A. 别人打水，你烧水\n");
		else if (i==9)
			printf("                    B. 别人点名，你喊道\n");
		else if (i==10)
			printf("                    C. 别人摁-1，你摁1\n");
		else if (i==11)
			printf("                    D. 别人八点起床，你七点\n");
		else
			printf("\n");
	}
	border();
	char X=getch();
	if(tolower(X)=='c')
		A[5]='1';
}
void q6()
{
	system("cls");
	border();
	for(int i=1;i<=19;i++)
	{
		if(i==8)
			printf("                  Q6:数学脑筋急转弯：sinx/x=?\n");
		else if(i==11)
			printf("                  A. 4      B. 5      C. 6     D. 1/n\n");
		else
			printf("\n");
	}
	border();
	char X=getch();
	if(tolower(X)=='c')
		A[6]='1';
}
void q7()
{
	system("cls");
	border();
	for (int i=1;i<=18;i++)
	{
		if (i==6)
			printf("Q7.L同学喜欢做脑经急转弯，现在B同学给他出了一道题，看到L同学苦思冥想，她又给出了提示：注意美元符号可能代表的其他含义，现在题目是这样的：\n");
		else if (i==8)
			printf("                                  6美元\n");
		else if (i==10)
			printf("                     A. 2     B. 4      C. 6    D. 9\n");
		else
			printf("\n");
	}
	border();
	char X=getch();
	if(tolower(X)=='d')
		A[7]='1';
}
void q8()
{
	system("cls");
	border();
	for (int i=1;i<=19;i++)
	{
		if (i==6)
			printf("Q8.听闻B同学现在学高数很吃力，L同学专门去问了一道数学题，现在题目是这样的：\n");
		else if (i==8)
			printf("     当“肉”的值趋向无穷小时，“鱼香肉丝”的极限为“炒萝卜丝”，那么当“馅”的值趋向于无穷小时，包子的极限为？ \n");
		else if (i==10)
			printf("              A. 披萨     B. 烧饼      C. 饺子    D. 馒头");
		else
			printf("\n");
	}
	border();
	char X=getch();
	if(tolower(X)=='d')
		A[8]='1';
}
void q9()
{
	system("cls");
	border();
	for(int i=1;i<=19;i++)
	{
		if(i==6)
			printf("             Q9:为什么微软在推出Win8后，直接推出了Win10，而没有推出Win9？\n");
		else if(i==9)
			printf("                  A. 太丑，没脸见人\n");
		else if(i==10)
			printf("                  B. 今年限号，不让单号露脸\n");
		else if(i==11)
			printf("                  C. 去斩华雄了\n");
		else if(i==12)
			printf("                  D. 比尔盖茨不喜欢9这个数字\n");
		else
			printf("\n");
	}
	border();
	char X=getch();
	if(tolower(X)=='c')
		A[9]='1';
}
void q10()
{
	system("cls");
	border();
	for (int i=1;i<=13;i++)
	{
		if (i==5)
			printf("Q10.题目是这样的：\n      假设某种疾病由XYZ病毒引起，该病的发病率为千分之一假设现在有一种化验方法可以100%检测到XYZ病毒，但是，使用这种化验方法的假阳性率为5%。也就是说，如果一人携带XYZ病毒，通过这种化验一定可以被发现.但是如果未携带病毒的健康人接收这种化验，有5%的可能性被误诊为XYZ病毒携带者。\n现在，从人群中随机啊选取一人进行检测，化验结果为阳性（阳性意味着受检者可能是XYZ携带者）。那么在完全不考虑个人信息，病史的情况下，这位受检者携带XYZ病毒的概率是多少？");
		else if(i==8)
			printf("                A. 50%%       B. 85%%        C. 95%%       D. 100%%\n");
		else
			printf("\n");
	}
	border();
	char X=getch();
	if(tolower(X)=='c')
		A[10]='1';
}
void q11()
{
	system("cls");
	border();
	for (int i=1;i<=19;i++)
	{
		if (i==6)
			printf("Q11.某啤酒品牌新推出了一款高档啤酒A，已知市场上已经有抵低档品牌B，中档品牌C，A要怎样才能突围");
		else if(i==10)
			printf("                  A. 发广告大力吹捧啤酒A   \n");
		else if(i==11)
			printf("                  B. 发广告大力诋毁啤酒B,C \n");
		else if(i==12)
			printf("                  C. 新推出一段同样高档的啤酒D \n");
		else if(i==13)
			printf("                  D. 新推出一款更高端的啤酒E\n ");
		else
			printf("\n");
	}
	border();
	char X=getch();
	if(tolower(X)=='d')
		A[11]='1';
}
void q12()
{
	system("cls");
	border();
	for(int i=1;i<=18;i++)
	{
		if(i==7)
			printf("    Q12:计算机系毕业的Srona就职于一家互联网公司，司职程序员，每天上下班经过霞飞路，近日霞飞路正在修路挖沟，为了不让他掉进沟里，警示牌上应该写什么？\n");
		else if(i==9)
			printf("                  A. Warning!!!\n");
		else if(i==10)
			printf("                  B. Error!!!\n");
		else if(i==11)
			printf("                  C. Caution!!!\n");
		else if(i==12)
			printf("                  D. Attention!!!\n");
		else
			printf("\n");
	}
	border();
	char X=getch();
	if(tolower(X)=='b')
		A[12]='1';
}
/****************************************后续开发***************************************/
void password1()
{
	system("cls");
	border();
	for (int i=1;i<=19;i++)
	{
		if (i==8)
			printf("你已经连续游戏三次，为了感谢你的支持，你将获得内部password，通关后输入将能查看题目的详细解析\n");
		else if (i==9)
		{
			printf("                              ");
			p("password:",50);
			printf("                                  ");
			p("HELLO WORLD!",100);
		}
		else
			printf("\n");
	}
	border();
	char X=getch();
}
void password2()
{
	system("cls");
	border();
	for(int i=1;i<=19;i++)
	{
		if(i==6)
		{
			printf("                      ");
			p("YOUR GRADE is: \n",50);
		}
		if(i==7)
			printf("                                          %d\n\n",grade);
		if(i==8)
		{
			printf("                      ");
			p("THE END",50);
		}
		else if(i==10)
		{
			printf("                      ");
			p("YOU   ARE   666!",50);
		}
		else if(i==17)
			p("恭喜你以高分完成游戏，我们将奖励你一个内部密码以查看题目解析:",20);
		else if(i==18)
		{
			p("password:",100);
			printf("                                    ");
			p("HELLO WORLD!",100);
		}
		else
			printf("\n");
	}
	border();
	getch();
}
void analyze()
{
	system("cls");
	border1();
	p("A1:D。神奇海螺1号",20);
	p("A2:A。神奇海螺2号",20);
	p("A3:C。本来有4种可能，现在排除2男的可能，于是乎就是1/3",20);
	p("A4:C。谐音水题",20);
	p("A5:C。故事情景发生电梯里，按-1的到停车房，按1的....大家都是按1的，就不用解释了~",20);
	p("A6:C。分子分母约去n，剩下six",20);
	p("A7:D。划去s，剩下IX，是不是很熟悉，罗马数字9",20);
	p("A8:D。没馅就成了馒头了",20);
	p("A9:C。这只是一道脑经急转弯，饮9斩华雄",20);
	p("A10:C。思维水题",20);
	p("A11:D。用更贵的产品E作为诱饵，E本身不会有太多的市场份额，但是它会产生一种吸引效应，把消费者的眼光往上拉，从而扩大A的市场份额",20);
	p("A12:B。别跟我提ERROR！",20);
	p("感谢试玩~按任意键结束游戏........",20);
	border1();
	getch();
	exit(1);
}
void shell()
{
	char B[15];
	system("cls");
	printf("请键入内部密码(大小字母敏感)：");
	scanf("%s",&B);
	if (strcmp(PS,B)==0);
	//此处指向解析
	analyze();
}
void end_()
{
	for(int i=1;i<=12;i++)
		if(A[i]=='1')
			grade++;
	if(grade==12)
		password2();
	system("cls");
	border();
	for(int i=1;i<=19;i++)
	{
		if(i==5)
		{
			printf("                       ");
			p("YOUR GRADE is: ",50);
		}
		else if(i==6)
			printf("                                     %d\n",grade);
		else if(i==8)
		{
			printf("                       错题有： \n");
			printf("                        ");
			for (int j=1;j<=12;j++)
				if(A[j]!='1')
					printf("%d  ",j);
			printf("\n\n");
		}
		else if(i==9)
		{
			printf("                                  ");
			p("THE END",50);
		}
		else if(i==11)
		{
			printf("                               ");
			p("YOU   ARE   6!",50);
		}
		else if(i==17)
			p("注：如果你从游戏中获得了内部密码，按Y进入密码输入页面，否则请按任意键重新开始~",20);
		else
			printf("\n");
	}
	border();
	char X=getch();
	if(tolower(X)=='y')
		shell();
}

int main()
{
	int passtime=1;
	while(passtime++){
		re_set();
		page1();
		s1();
		s2(getch());
		s3();
		if(passtime==2)
		{
			q_fun1();
			q_fun2();
			q_fun3();
			q_fun4();
		}
		q0();
		q1();
		q2();
		q3();
		q4();
		q5();
		q6();
		q7();
		q8();
		q9();
		q10();
		q11();
		q12();
		end_();
		if(passtime>4)
			password1();
	}
}

