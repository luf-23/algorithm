#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,bg,mx;
ll num[100];
ll dp[120][1020];
int main()
{
	cin >> n >> bg >> mx;
	for (int i=1;i<=n;i++) cin >> num[i];
	dp[0][bg] = 1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=mx;j++)
		{
			if (dp[i-1][j]==1)
			{
				if (j-num[i]>=0) dp[i][j-num[i]] = 1;
				if (j+num[i]<=mx) dp[i][j+num[i]] = 1;
			}
		}
	}
	ll ans = -1;
	for (int i=mx;i>=0;i--)
	{
		if (dp[n][i]==1)
		{
			ans = i;
			break;
		}
	}
	cout << ans;
	return 0;
}
