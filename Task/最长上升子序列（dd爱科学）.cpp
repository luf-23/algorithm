#include<bits/stdc++.h>
using namespace std;
int main()
{
	//dp[i]表示以字母i结尾的最长上升子序列
	int n;
	cin >> n;
	string str;
	cin >> str;
	str = ' ' + str;
	int num[n+1];
	for (int i=1;i<=n;i++) num[i] = str[i] - 'A';
	int dp[26] = {0};
	for (int i=1;i<=n;i++){
		for (int j=0;j<num[i];j++){
			dp[num[i]] = max(dp[num[i]],dp[j]);
		}
		dp[num[i]]++;
	}
	int ans = 0;
	for (int i=0;i<26;i++) ans = max(ans,dp[i]);
	cout << n-ans;
	return 0;
}
