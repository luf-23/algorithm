#include <bits/stdc++.h>
#define int long long
using namespace std;
int D[1000020];
int f[1000020];
int mod = 1e9 + 7;
int ksm(int a,int b){
	int ans = 1;
	int base = a;
	while (b){
		if (b&1) ans = ans*base%mod;
		base = base*base%mod;
		b >>= 1;
	}
	return ans;
}
//求有多少种1-n的排列a满足恰好有m个位置i使得ai=i
signed main(){
	int t;
	cin >> t;
	D[0] = 1;
	D[1] = 0;
	D[2] = 1;
	for (int i=3;i<=1000000;i++) D[i] = ((i-1)*(D[i-1]+D[i-2]))%mod;
	f[0] = 1;
	for (int i=1;i<=1000000;i++) f[i] = (f[i-1]*i)%mod;
	while (t--){
		int n,m;
		cin >> n >> m;
		int fz = f[n];
		int fm = (f[m]*f[n-m])%mod;
		int ans = ((fz*ksm(fm,mod-2)%mod)*D[n-m])%mod;
		cout << ans << '\n';
	}
	return 0;
}
