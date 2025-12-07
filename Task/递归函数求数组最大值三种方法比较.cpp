#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int Max1(int num[],int pos)
{
	++cnt;
	if (pos==1) return num[pos];
	return Max1(num,pos-1) > num[pos] ? Max1(num,pos-1) : num[pos];
}
int Max2(int num[],int n,int max_v)
{
	++cnt;
	if (n==0) return max_v;
	num[n]>max_v ? Max2(num,n-1,num[n]) : Max2(num,n-1,max_v);
}
int Max3(int num[],int pos)
{
	++cnt;
	if (pos==1) return num[pos];
	int max_v = Max3(num,pos-1);
	return max_v > num[pos] ? max_v : num[pos];
}
int main()
{
	srand(0);
	int n;
	cin >> n;
	int num[n+1];
	for (int i=1;i<=n;i++)
	{
		num[i] = n - i + 1;
		//num[i] = rand()%4000;
	}
	int m1 = Max1(num,n);
	cout << m1 << ' ' << cnt << endl;
	cnt = 0;
	int m2 = Max2(num,n,0);
	cout << m2 << ' ' << cnt << endl;
	cnt = 0;
	int m3 = Max3(num,n);
	cout << m3 << ' ' << cnt << endl;
	return 0;
}

