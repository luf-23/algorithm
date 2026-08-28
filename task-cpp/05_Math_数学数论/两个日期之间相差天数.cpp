#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool is_gap(int year)
{
	if (year%4==0&&year%100!=0||year%400==0) return true;
	return false;
}
int over(int y,int m,int d)
{
	int sum = 0;
	for (int i=1;i<m;i++)
		sum += day[i];
	if (m>2&&is_gap(y)) sum += 1;
	sum += d;
	return sum;
}
int left(int y,int m,int d)
{
	int sum = 0;
	for (int i=1;i<m;i++)
		sum += day[i];
	if (m>2&&is_gap(y)) sum += 1;
	sum += d;
	if (is_gap(y)) return (365-sum);
	else return (364-sum);
}
int main()
{
	int y1,m1,d1,y2,m2,d2;
	scanf("%4d-%2d-%2d %4d-%2d-%2d",&y1,&m1,&d1,&y2,&m2,&d2);
	ll sum = 0;
	for (int i=y1+1;i<y2;i++)
	{
		if (is_gap(i)) sum += 365;
		else sum += 364;
	}
	if (y2>y1) sum = sum + over(y2,m2,d2) + left(y1,m1,d1);
	else{
		if (is_gap(y1)) sum = over(y2,m2,d2) + left(y1,m1,d1) - 365;
		else sum = over(y2,m2,d2) + left(y1,m1,d1) - 364;
	}
	sum += y2 - y1;
	cout << sum;
	return 0;
}
