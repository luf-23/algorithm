#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n;
	cin >> n;
	int num[n+1];
	for (int i=1;i<=n;i++) cin >> num[i];
	int L,R;
	cin >> L >> R;
	sort(num+1,num+n+1);
	int ans = 0;
	int add = 0;
	int dec = 0;
	for (int i=1;i<=n;i++){
		if (num[i]<L) add += L-num[i];
		else if (num[i]>R) dec += num[i]-R;
	}
	int x = add - dec;
	ans = max(add,dec);
	int f = 1;
	if (x>0){
		int ok = 0;
		for (int i=1;i<=n;i++){
			if (num[i]>=L&&num[i]<=R) ok += num[i]-L;
		}
		if (ok<x) f = 0;
	}else if (x<0){
		int ok = 0;
		x = -x;
		for (int i=1;i<=n;i++){
			if (num[i]>=L&&num[i]<=R) ok += R-num[i];
		}
		if (ok<x) f = 0;
	}
	if (f) cout << ans;
	else cout << -1;
	return 0;
}
