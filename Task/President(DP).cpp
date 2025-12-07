#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
int X[120];
int Y[120];
int Z[120]; 
ll dp[100005];
int w[120];
int v[120];
int cnt = 0;
int main()
{
	cin >> n;
	ll sumz = 0;
	ll need = 0;
	ll sumzt = 0;
	for (int i=1;i<=n;i++){
		cin >> X[i] >> Y[i] >> Z[i];
		sumz += Z[i];
		if (X[i]>Y[i]) sumzt += Z[i];
		else{
			++cnt;
			w[cnt] = (X[i]+Y[i])/2 + 1 - X[i];
			v[cnt] = Z[i];
		}
	}
	need = sumz/2 + 1 - sumzt;
	if (need<=0){
		cout << 0;
		exit(0);
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0] = 0;
	for (int i=1;i<=cnt;i++){
		for (int j=1e5;j>=v[i];j--){
			dp[j] = min(dp[j],dp[j-v[i]]+w[i]);
		}
	}
	long long ans = LONG_LONG_MAX;
	for (int i=need;i<=100000;i++) ans = min(ans,dp[i]);
	cout << ans;
	return 0;
}
