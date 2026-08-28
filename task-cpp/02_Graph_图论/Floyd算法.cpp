#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[405][405];
int n,m;
signed main(){
	cin >> n >> m;
	int q;
	cin >> q;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i==j) dp[i][j] = 0;
			else dp[i][j] = INT_MAX;
		}
	}
	for (int i=1;i<=m;i++){
		int x,y,w;
		cin >> x >> y >> w;
		dp[x][y] = min(dp[x][y],w);
		dp[y][x] = min(dp[y][x],w);
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while (q--){
		int st,ed;
		cin >> st >> ed;
		cout << dp[st][ed] << '\n';
	}
	return 0;
}
