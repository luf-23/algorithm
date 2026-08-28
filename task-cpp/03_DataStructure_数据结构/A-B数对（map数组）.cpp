#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,c;
	cin >> n >> c;
	map<ll,ll> mp;
	ll a[n];
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	ll cnt = 0;
	for (int i=0;i<n;i++)
	{
		cnt += mp[a[i]+c];
	}
	cout << cnt;
	return 0;
}
