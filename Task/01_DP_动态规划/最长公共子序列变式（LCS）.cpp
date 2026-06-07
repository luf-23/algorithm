#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[1005][1005];
//最长回文子序列问题=将原串翻转后与原串求最长公共子序列问题=
//给定一个字符串，求需要插入多少字符使其成为回文串问题，答案为原串长度减去最长回文子序列
int len;
signed main(){
	string s1;
	cin >> s1;
	string s2 = s1;
	reverse(s1.begin(),s1.end());
	len = s1.length();
	s1 = ' ' + s1;
	s2 = ' ' + s2;
	for (int i=1;i<=len;i++){
		for (int j=1;j<=len;j++){
			if (s1[i]==s2[j]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout << len-dp[len][len];
	return 0;
}
