#include <bits/stdc++.h>
using namespace std;
int num[5005];
int n,m;
int dp[5005][5005];
int main()
{
	cin >> n >> m;
	dp[0][1] = 1;
	for (int i=1;i<=m;i++){
		int x;
		cin >> x;
		for (int j=1;j<=n;j++){
			x %= n;
			int to1 = j + x;
			if (to1>n) to1 -= n;
			dp[i][to1] |= dp[i-1][j];
			int to2 = j - x;
			if (to2<1) to2 += n;
			dp[i][to2] |= dp[i-1][j];
		}
	}
	if (dp[m][1]==1) cout << "Yes";
	else cout << "No";
	return 0;
}
