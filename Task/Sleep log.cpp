#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n;
	cin >> n;
	ll num[n+1];
	for (int i=1;i<=n;i++) cin >> num[i];
	ll sum[n+1] = {0};
	for (int i=3;i<=n;i+=2){
		sum[i] = sum[i-2] + num[i] - num[i-1];
		sum[i-1] = sum[i-2];
	}
	//	for (int i=1;i<=n;i++){
	//		cout << sum[i] << ' ';
	//	}
	int q;
	cin >> q;
	while (q--){
		int x,y;
		cin >> x >> y;
		ll ans = 0;
		int p1 = lower_bound(num+1,num+n+1,x)-num;
		int p2 = lower_bound(num+1,num+n+1,y)-num;
		//cout << "p1,p2=" << p1 << ' ' << p2 << endl;
		if (num[p1]!=x){
			if (p1%2==1) ans += num[p1]-x;
		}
		if (num[p2]!=y){
			if (p2%2==1) ans -= num[p2]-y;
		}
		ans += sum[p2]-sum[p1];
		if (y>num[n]) ans += y - num[n];
		cout << ans << endl;
	}
}
