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
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int l = 0;
		int r = 2*n;
		while (l+1<r){
			int mid = (l+r)/2;
			int a[n];
			a[0] = 0;
			for (int i=1;i<n;i++){
				a[i] = mid^a[i-1];
			}
			sort(a,a+n);
			int ok = 1;
			for (int i=0;i<n;i++){
				if (a[i]<i) ok = 0;
			}
			if (ok) r = mid;
			else l = mid;
		}
		int x = r;
		int ans[n];
		ans[0] = 0;
		for (int i=1;i<n;i++) ans[i] = ans[i-1]^x;
		for (int i=0;i<n;i++) cout << ans[i] << ' ';
		cout << '\n';
		
		
	}
	
	
	return 0;
}
