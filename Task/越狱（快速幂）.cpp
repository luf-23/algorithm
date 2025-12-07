#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll ans;
const int k = 100003;
ll ksm(ll a,ll b)
{
	ll ans = 1;
	ll base = a;
	while (b)
	{
		if (b&1) ans = (ans*base)%k;
		b >>= 1;
		base = (base*base)%k;
	}
	return ans;
}
int main()
{
	ll m,n;
	cin >> m >> n;
	ans += ksm(m,n);
	ans -= m*ksm(m-1,n-1);
	while (ans<0)
	{
		ans = (ans+k)%k;
	}
	cout << ans;
	return 0;
}
