#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int m,n;
	cin >> n >> m;
	int a[n+1];
	int b[m+1];
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=m;i++) cin >> b[i];
	int mx1,mx2,mn1,mn2;
	mx1 = mx2 = -LONG_LONG_MAX;
	mn1 = mn2 = LONG_LONG_MAX;
	//cout << "mx1,mn1,mx2,mn2=" << mx1 << ' ' << mn1 << ' ' << mx2 << ' ' << mn2 << '\n';
	for (int i=1;i<=n;i++){
		mx1 = max(mx1,a[i]);
		mn1 = min(mn1,a[i]);
	}
	for (int i=1;i<=m;i++){
		mx2 = max(mx2,b[i]);
		mn2 = min(mn2,b[i]);
	}
	//cout << "mx1,mn1,mx2,mn2=" << mx1 << ' ' << mn1 << ' ' << mx2 << ' ' << mn2 << '\n';
	int t1,t2;
	t1 = t2 = a[1];
	for (int i=2;i<=n;i++){
		t1 = max(a[i],t1+a[i]);
		t2 = min(a[i],t2+a[i]);
		mx1 = max(mx1,t1);
		mn1 = min(mn1,t2);
	}
	t1 = t2 = b[1];
	for (int i=2;i<=m;i++){
		t1 = max(b[i],t1+b[i]);
		t2 = min(b[i],t2+b[i]);
		mx2 = max(mx2,t1);
		mn2 = min(mn2,t2);
	}
	//cout << "mx1,mn1,mx2,mn2=" << mx1 << ' ' << mn1 << ' ' << mx2 << ' ' << mn2 << '\n';
	int ans = max({mx1*mx2,mx1*mn2,mn1*mx2,mn1*mn2});
	cout << ans;
	return 0;
}
