#include <bits/stdc++.h>
using namespace std;
int n;
int num[200000];
int mem[200000];
int dfs(int step)
{
	if (mem[step]) return mem[step];
	if (step>n) return 0;
	return mem[step] = max(dfs(step+1),dfs(step+2)+num[step]);
}
int main()
{
	cin >> n;
	for (int i=1;i<=n;i++) num[i] = i;
	int ans = dfs(1);
	int dp[n+1] = {0};
	dp[1] = num[1];
	for (int i=2;i<=n;i++) dp[i] = max(dp[i-1],dp[i-2]+num[i]);
	cout << ans << endl;
	cout << dp[n];
	return 0;
}
