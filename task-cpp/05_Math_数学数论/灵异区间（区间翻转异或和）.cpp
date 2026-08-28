#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n;
	cin >> n;
	ll num[n+1];
	for (ll i=1;i<=n;i++)
		cin >> num[i];
	ll cnt = 0;
	map<ll,ll> mp;
	mp[0] = 1;
	ll x = 0;
	for (int i=1;i<=n;i++)
	{
		x ^= num[i];
		cnt += mp[x]++;
	}
	cout << cnt << endl;
	return 0;
}
