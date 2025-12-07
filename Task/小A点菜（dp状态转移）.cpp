#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[120][10010];
int main()
{
	int n,m;
	cin >> n >> m;
	int num[n+1];
	for (int i=1;i<=n;i++) cin >> num[i];
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (num[i]>j) dp[i][j] = dp[i-1][j];
			else if (num[i]==j) dp[i][j] = dp[i-1][j]+1;
			else if (num[i]<j) dp[i][j] = dp[i-1][j] + dp[i-1][j-num[i]];
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			//cout << "dp[" << i << "][" << j << "]=" << dp[i][j] << ' ';
		}
		//cout << endl;
	}
	cout << dp[n][m];
	return 0;
}
