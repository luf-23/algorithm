#include <stdio.h>
int mday(int,int);
void nday(int,int,int);
int is_gap(int);
int is_correct(int,int,int);
int main()
{
	int year,month,day;
	while (1)
	{
		printf("请输入年份：");
		scanf("%d",&year);
		printf("请输入月份：");
		scanf("%d",&month);
		printf("请输入是该月第几天：");
		scanf("%d",&day);
		if (is_correct(year,month,day))
		{
			nday(year,month,day);
			break;
		}else{
			continue;                    
		}
	}
}
int is_gap(int y)
{
	if (y%4==0&&y%100!=0||y%400==0) return 1;
	else return 0;
}
int mday(int y,int m)
{
	if (m==2)
	{
		if (is_gap(y)) return 29;
		else return 28;
	}
	if (m==1||m==3||m==5||m==7||m==8||m==10||m==12) return 31;
	else return 30;
}
void nday(int y,int m,int d)
{
	int sum = 0;
	for (int i=1;i<=m-1;i++)
		sum += mday(y,i);
	sum += d;
	printf("这是这一年的第%d天\n",sum);
}
int is_correct(int y,int m,int d)
{
	if (y>2023||y<=0||m>12||m<1) return 0;
	else if (d>mday(y,m)||d<1) return 0;
	else return 1;
}
