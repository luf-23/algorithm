#include <bits/stdc++.h>
using namespace std;
int n;
int a[12];
int b[12];
int ans = 1e9;
void dfs(int mul,int sum,int k,int pos)
{
	if (k==0)
	{
		ans = min(ans,abs(mul-sum));
		return;
	}
	for (int i=pos;i<=n;i++)
	{
		dfs(mul*a[i],sum+b[i],k-1,i+1);
	}
}
int main()
{
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i];
	}
	for (int i=1;i<=n;i++)
	{
		dfs(1,0,i,1);
	}
	cout << ans;
	return 0;
}
