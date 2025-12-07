#include <bits/stdc++.h>
using namespace std;
int price[105][120];//第i天每种物品的价格
int dp[14000000];//用i元钱去购买商品能获得的最大盈利
int main()
{
	int t,n,m;
	cin >> t >> n >> m;
	for (int i=1;i<=t;i++){
		for (int j=1;j<=n;j++){
			cin >> price[i][j];
		}
	}
	for (int k=1;k<t;k++){
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=n;i++){
			for (int j=price[k][i];j<=m;j++){
				dp[j] = max(dp[j],dp[j-price[k][i]]+price[k+1][i]-price[k][i]);
			}
		}
		m += dp[m];
	}
	cout <<m << endl;
	return 0;
}
