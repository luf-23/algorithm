#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int num[1005];
int dp[1005][1005];
int mod = 19650827;
signed main(){
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> num[i];
		dp[i][i] = 1;
	}
	for (int len=2;len<=n;len++){
		for (int i=1;i+len-1<=n;i++){
			int j = i + len - 1;
			if (num[j]>num[j-1]) dp[i][j] += dp[i][j-1];
			if (num[i+1]>num[i]) dp[j][i] += dp[j][i+1];
			if (num[j]>num[i]&&len!=2) dp[i][j] += dp[j-1][i];
			if (num[i]<num[j]&&len!=2) dp[j][i] += dp[i+1][j];
			dp[i][j] %= 19650827;
			dp[j][i] %= 19650827;
		}
	}
	cout << (dp[1][n]+dp[n][1])%mod;
	return 0;
}
