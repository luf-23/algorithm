#include <bits/stdc++.h>
using namespace std;
int n;
int t[10005];
int c[10005];
int p[10005];
int dp[10005][1002];
int main()
{
	int h1,h2,m1,m2;
	scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
	int dh = h2-h1;
	int dm = m2-m1;
	int T = dh*60+dm;
	cin >> n;
	for (int i=1;i<=n;i++){
		int P;
		cin >> t[i] >> c[i];
		cin >> P;
		if (!P) p[i] = 999999;
		else p[i] = P;
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<=T;j++){
			for (int k=0;k<=p[i];k++){
				if (j-t[i]*k>=0){
					dp[i][j] = max(dp[i][j],dp[i-1][j-k*t[i]]+c[i]*k);
				}else{
					break;
				}
			}
		}
	}
	cout << dp[n][T];
	return 0;
}
