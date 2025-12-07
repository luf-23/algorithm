#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ll a,b,p;
	cin >> a >> b >> p;
	ll ans = 1;
	ll base = a;
	ll t = b;
	while (b>0)
	{
		if (b&1)
		{
			ans *= base;
			ans %= p;
		}
		base *= base;
		base %= p;
		b >>= 1;
	}
	ans %= p;
	cout << a << '^' << t << " mod " << p << '=' << ans;
	return 0;
}
