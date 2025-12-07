#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[200005][2][2];
signed main(){
	int n;
	cin >> n;
	string str;
	cin >> str;
	int num[n+1];
	for (int i=1;i<=n;i++) cin >> num[i];
	str = ' ' + str;
	for (int i=0;i<=n;i++){
		for (int j=0;j<2;j++){
			for (int k=0;k<2;k++){
				dp[i][j][k] = LONG_LONG_MAX;
			}
		}
	}
	dp[1][0][str[1]-'0'] = 0;
	dp[1][0][(str[1]-'0')^1] = num[1];
	for (int i=2;i<=n;i++){
		for (int k=0;k<2;k++){
			dp[i][0][k] = dp[i-1][0][k^1];
			dp[i][1][k] = min(dp[i-1][1][k^1],dp[i-1][0][k]);
			if (str[i]-'0'!=k){
				dp[i][0][k] += num[i];
				dp[i][1][k] += num[i];
			}
		}
	}
	cout << (dp[n][1][1]>dp[n][1][0]?dp[n][1][0]:dp[n][1][1]);
	return 0;
}
