#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[120];
int ans = 0;
void dfs(int step,int money)
{
	if (money==0)
	{
		ans++;
		return;
	}else if (money<0) return;
	if (step==n+1) return;
	dfs(step+1,money-a[step]);
	dfs(step+1,money);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	dfs(1,m);
	cout << ans;
}
