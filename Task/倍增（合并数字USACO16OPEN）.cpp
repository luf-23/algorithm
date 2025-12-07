#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int num[500005];
int dp[300000][60];//以i为左端点，合并出j时的右端点
signed main(){
	cin >> n;
	for (int i=1;i<=n;i++) cin >> num[i];
	for (int i=1;i<=n;i++) dp[i][num[i]] = i + 1;
	for (int j=2;j<=90;j++){
		for (int i=1;i<=n;i++){
			if (!dp[i][j]){
				dp[i][j] = dp[dp[i][j-1]][j-1];
			}
		}
	}
	int ans = 0;
	for (int j=1;j<=58;j++){
		for (int i=1;i<=n;i++){
			if (dp[i][j]){
				ans = max(ans,j);
			}
		}
	}
	cout << ans;
	return 0;
}
