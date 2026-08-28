#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll m1 = min(min(min(x1,y1),n-x1+1),n-y1+1);
		ll m2 = min(min(min(x2,y2),n-x2+1),n-y2+1);
		ll ans = abs(m1-m2);
		cout << ans << endl;
	}
	return 0;
}
