#include <bits/stdc++.h>
using namespace std;
int dp[1020][1020];
int main()
{
	int n;
	cin >> n;
	int num[1020][1020];
	for (int i=0;i<1020;i++){
		for (int j=0;j<1020;j++){
			num[i][j] = 0;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			cin >> num[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			dp[i][j] = max(dp[i-1][j],dp[i-1][j-1])+num[i][j];
		}
	}
	int ans = 0;
	for (int i=1;i<=n;i++) ans = max(dp[n][i],ans);
	cout << ans;
	return 0;
}
