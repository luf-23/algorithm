#include <bits/stdc++.h>
using namespace std;
int n,k;
int cnt = 0;
int num[30];
bool isprime(int x)
{
	if (x==2) return true;
	if (x<=1) return false;
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0) return false;
	return true;
}
void dfs(int step,int sum,int start_pos)
{
	if (step==k+1)
	{
		if (isprime(sum))
		{
			cnt++;
		}
		return;
	}
	for (int i=start_pos;i<=n;i++)
	{
		dfs(step+1,sum+num[i],i+1);
	}
	return;
}
int main()
{
	cin >> n >> k;
	for (int i=1;i<=n;i++)
		cin >> num[i];
	dfs(1,0,1);
	cout << cnt;
	return 0;
}
