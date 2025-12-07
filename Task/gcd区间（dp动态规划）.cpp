#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll GCD(ll a,ll b)
{
	if (b==0) return a;
	return GCD(b,a%b);
}
int main()
{
	ll f[1005][1005];
	ll n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> f[i][i];
	for (int i=n-1;i>=1;i--){
		for (int j=i+1;j<=n;j++){
			f[i][j] = GCD(f[i][i],f[i+1][j]);
		}
	}
	while (m--){
		ll l,r;
		cin >> l >> r;
		cout << f[l][r] << endl;
	}
	return 0;
}
