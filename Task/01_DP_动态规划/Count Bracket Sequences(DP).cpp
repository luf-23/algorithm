#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
long long dp[3005][3005];
int main()
{
	//dp[i][j]表示前i个字符里还剩j个左括号没有匹配的方案数
	string s;
	cin >> s;
	s = ' ' + s;
	dp[0][0] = 1;
	for (int i=1;i<s.length();i++){
		if (s[i]=='('){
			for (int j=1;j<s.length();j++){
				dp[i][j] = dp[i-1][j-1]%mod;
			}
		}else if (s[i]==')'){
			for (int j=0;j<s.length()-1;j++){
				dp[i][j] = dp[i-1][j+1]%mod;
			}
		}else if (s[i]=='?'){
			for (int j=0;j<s.length()-1;j++){
				dp[i][j] = dp[i-1][j+1];
			}
			for (int j=1;j<s.length();j++){
				dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mod;
			}
		}
	}
	cout << dp[s.length()-1][0];
	return 0;
}
