#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[15][1<<15];
int mod = 100000000;
int n,m;
signed main() {
	while (cin>>n>>m){
		int num[n+1][m+1];
		map<int,int>mp;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cin >> num[i][j];
				mp[i] = (mp[i]<<1) + num[i][j];
			}
		}
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for (int i=1;i<=n;i++){
			for (int j=0;j<(1<<m);j++){
				if ((j&mp[i])!=j) continue;//当前状态不合法//必须加括号，位运算优先级太低了坑死了
				if (j&(j>>1)) continue;//和左右有相邻
				//开始转移，由上推下,先确保当前状态合法，再由上面状态推下来
				for (int k=0;k<(1<<m);k++){
					if (k&j) continue;//和上一行有相邻
					dp[i][j] = (dp[i][j]+dp[i-1][k])%mod;
				}
			}
		}
		int ans = 0;
		for (int i=0;i<(1<<m);i++) ans = (ans+dp[n][i])%mod;
		cout << ans;
	}
	return 0;
}
