#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt = 0;
int num[15];
void print(int x)
{
	cout << num[1];
	for (int i=2;i<=x;i++) cout << '+' << num[i];
	cout << endl;
}
void dfs(int step)
{
	for (int i=num[step-1];i<=m;i++)
	{
		if (i==n) continue;
		num[step] = i;
		m -= i;
		if (m==0) 
		{
			print(step);
			cnt++;
		}
		else dfs(step+1);
		m += i;
	}
}
int main()
{
	cin >> n;
	m = n;
	num[0] = 1;
	dfs(1);
	cout << cnt;
	return 0;
}
