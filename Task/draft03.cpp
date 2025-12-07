#include <bits/stdc++.h>
#define int long long
using namespace std;
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
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	return 0;
}
