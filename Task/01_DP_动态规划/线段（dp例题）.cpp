#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int dp[50005][2];
int l[50005];
int r[50005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> l[i] >> r[i];
	}
	dp[1][0] = r[1]-1+r[1]-l[1];
	dp[1][1] = l[1]-1 + r[1]-l[1];
	for (int i=2;i<=n;i++){
		dp[i][0] = min(dp[i-1][0]+abs(l[i-1]-r[i])+r[i]-l[i]+1,dp[i-1][1]+abs(r[i-1]-r[i])+r[i]-l[i]+1);
		dp[i][1] = min(dp[i-1][0]+abs(l[i-1]-l[i])+r[i]-l[i]+1,dp[i-1][1]+abs(r[i-1]-l[i])+r[i]-l[i]+1);
	}
	int ans = min(dp[n][0]+n-l[n],dp[n][1]+n-r[n]);
	cout << ans;
	return 0;
}
