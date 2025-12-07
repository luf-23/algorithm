#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;//n朵花，m个花瓶
int num[120][120];
int dp[120][120];//第i朵花插在第j个花瓶里的最大美观程度
signed main(){
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin >> num[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			dp[i][j] = -LONG_LONG_MAX+1e10;
		}
	}
	int ans = -LONG_LONG_MAX+1e10;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (i>j||n-i>m-j) continue;
			for (int k=i-1;k<=j-1;k++){
				dp[i][j] = max(dp[i][j],dp[i-1][k]+num[i][j]);
			}
		}
	}
	for (int i=1;i<=m;i++) ans = max(ans,dp[n][i]);
	cout << ans << '\n';
	vector<int>arr;
	for (int i=n;i>=1;i--){
		for (int j=i;j<=m-n+i;j++){
			if (dp[i][j]==ans){
				ans -= num[i][j];
				arr.push_back(j);
				break;
			}
		}
	}
	reverse(arr.begin(),arr.end());
	for (auto e : arr) cout << e << ' ';
	return 0;
}
