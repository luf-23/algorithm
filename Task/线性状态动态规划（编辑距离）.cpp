#include <bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2;
int dp[2005][2005];
//将字符串s1的前i个字符变成s2的前j个字符所需要的最小操作数
signed main(){
	cin >> s1 >> s2;
	s1 = ' ' + s1;
	s2 = ' ' + s2;
	dp[0][0] = 0;
	int len1 = s1.length() - 1;
	int len2 = s2.length() - 1;
	for (int i=1;i<=len1;i++) dp[i][0] = i;
	for (int i=1;i<=len2;i++) dp[0][i] = i;
	for (int i=1;i<=len1;i++){
		for (int j=1;j<=len2;j++){
			if (s1[i]==s2[j]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
		}
	}
	cout << dp[len1][len2];
	return 0;
}
