#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[300005][2];
signed main()
{
	int x,y,z;
	cin >> x >> y >> z;
	string str;
	cin >> str;
	str = ' ' + str;
	dp[0][0] = 0;
	dp[0][1] = z;
	for (int i=1;i<str.length();i++){
		if (islower(str[i])){
			dp[i][0] = min(dp[i-1][0]+x,dp[i-1][1]+z+x);
			dp[i][1] = min(dp[i-1][0]+z+y,dp[i-1][1]+y);
		}else{
			dp[i][0] = min(dp[i-1][0]+y,dp[i-1][1]+z+y);
			dp[i][1] = min(dp[i-1][0]+z+x,dp[i-1][1]+x);
		}
	}
	cout << min(dp[str.length()-1][0],dp[str.length()-1][1]);
	return 0;
}
