#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[105][105][105];//i,j个1,k个2
int n,m;
int mod = 9999973;
signed main(){
	dp[0][0][0] = 1;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=m;j++){
			for (int k=0;k<=m;k++){
				if (j+k>m) continue;
				//不放
				dp[i][j][k] = (dp[i][j][k]+dp[i-1][j][k])%mod;
				//放1个在0里
				if (j>=1) dp[i][j][k] = (dp[i][j][k]+(m-j-k+1)*dp[i-1][j-1][k])%mod;
				//放1个在1里
				if (k>=1) dp[i][j][k] = (dp[i][j][k]+(j+1)*dp[i-1][j+1][k-1])%mod;
				//放两个在0里
				if (j>=2) dp[i][j][k] = (dp[i][j][k]+(m-j-k+2)*(m-j-k+1)/2*dp[i-1][j-2][k])%mod;
				//放1个在0里，放1个在1里
				if (k>=1) dp[i][j][k] = (dp[i][j][k]+(m-j-k+1)*j*dp[i-1][j][k-1])%mod;
				//放两个在1里
				if (k>=2)dp[i][j][k] = (dp[i][j][k]+(j+2)*(j+1)/2*dp[i-1][j+2][k-2])%mod;
			}
		}
	}
	int ans = 0;
	for (int i=0;i<=m;i++){
		for (int j=0;j<=m;j++){
			if (i+j>m) continue;
			ans = (ans+dp[n][i][j])%mod;
		}
	}
	cout << ans;
	return 0;
}
