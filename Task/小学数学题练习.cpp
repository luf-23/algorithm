#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
int level=0;
int list();
int work(int&p);
int math_1();
int math_2();
int math_3();
int math_4();
int math_5();
int math_6();
int math_7();
int main()
{
	int score=work(level);
	while (1)
	{
		system ("cls");
		cout<<"*********************小学生学数学*********************"<<endl;
		cout<<"     您获得了"<<score*10<<"分！！"<<endl;
		cout<<"     1.继续该等级"<<endl;
		cout<<"     2.继续下一等级"<<endl;
		cout<<"     3.进入目录选择等级"<<endl;
		cout<<"     4.结束学习"<<endl;
		cout<<"     请输入序号确定你的选择：";
		int k;
		cin>>k;
		if(score<6&&k==2)
		{
			getchar();
			cout<<"     你的分数太低，不能进入下一等级！！";
			getchar();
			continue;
		}
		if(k==2&&level==7)
		{
			cout<<"     你已经达到了最高等级！！";
			getchar();
			continue;
		}
		if(k==1)    score=work(level);
		if(k==2)    score=work(++level);
		if(k==3)    {level=0;score=work(level);}
		if(k==4)     break;
	}
	cout<<"*********************欢迎下次再来*********************"<<endl;
	
	return 0;
}
int work(int &p)
{
	if(p==0)
		p=list();
	int OK=1;
	switch (level)
	{
		case 1:OK=math_1();break;
		case 2:OK=math_2();break;
		case 3:OK=math_3();break;
		case 4:OK=math_4();break;
		case 5:OK=math_5();break;
		case 6:OK=math_6();break;
		case 7:OK=math_7();break;
	}
	return OK;
}
int list()
{
	system ("cls");
	cout<<"*********************小学生学数学*********************"<<endl;
	cout<<"*************************目录*************************"<<endl;
	cout<<"     等级一：十以内加法"<<endl;
	cout<<"     等级二：十以内减法"<<endl;
	cout<<"     等级三：一百以内加减法"<<endl;
	cout<<"     等级四：九九乘法表"<<endl;
	cout<<"     等级五：两位数以内乘法"<<endl;
	cout<<"     等级六：除法（一）"<<endl;
	cout<<"     等级七：除法（二）"<<endl;
	cout<<"     请输入等级：";
	int a;
	cin>>a;
	while(a<=0||a>7||a%1!=0)
	{
		cout<<"     请重新输入等级：";
		cin>>a;
	}
	return a;
}
//等级一：十以内加法
int math_1()
{
	int True=0;
	int a,b,c,sign;
	for(int i=1;i<=10;i++)
	{
		srand(time(0));
		a=rand()%10;
		b=rand()%10;
		sign=rand()%2;
		if(a+b>10)
		{
			i--;
			continue;
		}
		system("cls");
		cout<<"*********************小学生学数学*********************"<<endl;
		cout<<"************************等级一************************"<<endl;
		cout<<"**********************十以内加法**********************"<<endl;
		cout<<"     （"<<i<<"）"<<a<<"+"<<b<<"=";
		cin>>c;
		if(c==a+b)
			True++;
		else
		{
			cout<<"           在考虑一下："<<endl;
			cout<<"             "<<a<<"+"<<b<<"=";
			cin>>c;
			if(c==a+b)
				True++;
			else
			{
				getchar();
				cout<<"           答错了，下次继续努力吧！"<<endl;
				getchar ();
			}
		}
	}
	return True;
}
//等级二：十以内减法
int math_2()
{
	int True=0;
	int a,b,c,sign;
	for(int i=1;i<=10;i++)
	{
		srand(time(0));
		a=rand()%10;
		b=rand()%10;
		sign=rand()%2;
		if(a-b<0)
		{
			i--;
			continue;
		}
		system("cls");
		cout<<"*********************小学生学数学*********************"<<endl;
		cout<<"************************等级二************************"<<endl;
		cout<<"**********************十以内减法**********************"<<endl;
		cout<<"     （"<<i<<"）"<<a<<"-"<<b<<"=";
		cin>>c;
		if(c==a-b)
			True++;
		else
		{
			cout<<"           在考虑一下："<<endl;
			cout<<"             "<<a<<"-"<<b<<"=";
			cin>>c;
			if(c==a-b)
				True++;
			else
			{
				getchar();
				cout<<"           答错了，下次继续努力吧！"<<endl;
				getchar ();
			}
		}
	}
	return True;
}
//等级三：一百以内加减法
int math_3()
{
	int True=0;
	int a,b,c,sign;
	for(int i=1;i<=10;i++)
	{
		srand(time(0));
		a=rand()%100;
		b=rand()%100;
		sign=rand()%2;
		if(sign==1)
		{
			if(a+b>100)
			{
				i--;
				continue;
			}
		}
		else
		{
			if(a-b<0)
			{
				i--;
				continue;
			}
		}
		system("cls");
		cout<<"*********************小学生学数学*********************"<<endl;
		cout<<"************************等级三************************"<<endl;
		cout<<"********************一百以内加减法********************"<<endl;
		if(sign==1)
		{
			cout<<"     （"<<i<<"）"<<a<<"+"<<b<<"=";
			cin>>c;
			if(c==a+b)
				True++;
			else
			{
				cout<<"           在考虑一下："<<endl;
				cout<<"             "<<a<<"+"<<b<<"=";
				cin>>c;
				if(c==a+b)
					True++;
				else
				{
					getchar();
					cout<<"           答错了，下次继续努力吧！"<<endl;
					getchar ();
				}
			}
		}
		else
		{
			cout<<"    （ "<<i<<"）"<<a<<"-"<<b<<"=";
			cin>>c;
			if(c==a-b)
				True++;
			else
			{
				cout<<"           在考虑一下："<<endl;
				cout<<"             "<<a<<"-"<<b<<"=";
				cin>>c;
				if(c==a-b)
					True++;
				else
				{
					getchar();
					cout<<"           答错了，下次继续努力吧！"<<endl;
					getchar ();
				}
			}
		}
	}
	return True;
}
//等级四：九九乘法表
int math_4()
{
	int True=0;
	int a,b,c,sign;
	for(int i=1;i<=10;i++)
	{
		srand(time(0));
		a=rand()%10;
		b=rand()%10;
		sign=rand()%2;
		if(a>=10||b>=10)
		{
			i--;
			continue;
		}
		system("cls");
		cout<<"*********************小学生学数学*********************"<<endl;
		cout<<"************************等级四************************"<<endl;
		cout<<"**********************九九乘法表**********************"<<endl;
		cout<<"     （"<<i<<"）"<<a<<"*"<<b<<"=";
		cin>>c;
		if(c==a*b)
			True++;
		else
		{
			cout<<"           在考虑一下："<<endl;
			cout<<"             "<<a<<"*"<<b<<"=";
			cin>>c;
			if(c==a*b)
				True++;
			else
			{
				getchar();
				cout<<"           答错了，下次继续努力吧！"<<endl;
				getchar ();
			}
		}
	}
	return True;
}
//等级五：两位数以内乘法
int math_5()
{
	int True=0;
	int a,b,c,sign;
	for(int i=1;i<=10;i++)
	{
		srand(time(0));
		a=rand()%100;
		b=rand()%100;
		sign=rand()%2;
		system("cls");
		cout<<"*********************小学生学数学*********************"<<endl;
		cout<<"************************等级四************************"<<endl;
		cout<<"**********************九九乘法表**********************"<<endl;
		cout<<"     （"<<i<<"）"<<a<<"*"<<b<<"=";
		cin>>c;
		if(c==a*b)
			True++;
		else
		{
			cout<<"           在考虑一下："<<endl;
			cout<<"             "<<a<<"*"<<b<<"=";
			cin>>c;
			if(c==a*b)
				True++;
			else
			{
				getchar();
				cout<<"           答错了，下次继续努力吧！"<<endl;
				getchar ();
			}
		}
	}
	return True;
}
//等级六：除法（一）
int math_6()
{
	int True=0;
	int a,b,c,sign;
	for(int i=1;i<=10;i++)
	{
		srand(time(0));
		a=rand()%10+1;
		b=rand()%10+1;
		c=a*b;
		sign=rand()%2;
		if(sign==1)
		{
			if(a<=9&&b<=9);
			else
			{
				i--;
				continue;
			}
		}
		system("cls");
		cout<<"*********************小学生学数学*********************"<<endl;
		cout<<"************************等级五************************"<<endl;
		cout<<"**********************除法（一）**********************"<<endl;
		cout<<"     （"<<i<<"）"<<c<<"/"<<b<<"=";
		cin>>a;
		if(a==c/b)
			True++;
		else
		{
			cout<<"           在考虑一下："<<endl;
			cout<<"             "<<c<<"/"<<b<<"=";
			cin>>a;
			if(a==c/b)
				True++;
			else
			{
				getchar();
				cout<<"           答错了，下次继续努力吧！"<<endl;
				getchar ();
			}
		}
	}
	return True;
}
//等级七：除法（二）
int math_7()
{
	int True=0;
	int a,b,c,d,m,n,sign;
	for(int i=1;i<=10;i++)
	{
		srand(time(0));
		a=rand()%10+1;
		b=rand()%10+1;
		d=rand()%10+1;
		c=a*b+d;
		if((a<=9)&&(b<=9)&&(d<b));
		else
		{
			i--;
			continue;
		}
		system("cls");
		cout<<"*********************小学生学数学*********************"<<endl;
		cout<<"************************等级七************************"<<endl;
		cout<<"**********************除法（二）**********************"<<endl;
		cout<<"     （"<<i<<"）"<<c<<"/"<<b<<"=m……n"<<endl;
		cout<<"             m=";
		cin>>m;
		cout<<"             n=";
		cin>>n;
		if(m==a&&n==d)
			True++;
		else
		{
			cout<<"           在考虑一下："<<endl;
			cout<<"             "<<c<<"/"<<b<<"=m……n"<<endl;
			cout<<"             m=";
			cin>>m;
			cout<<"             n=";
			cin>>n;
			if(m==a&&n==d)
				True++;
			else
			{
				getchar();
				cout<<"           答错了，下次继续努力吧！"<<endl;
				getchar ();
			}
		}
	}
	return True;
}
