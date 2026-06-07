#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n,m;
	cin >> n >> m;
	vector<ll> arr;
	arr.push_back(0);
	ll a;
	for (int i=1;i<=n;i++)
	{
		cin >> a;
		arr.push_back(a);
	}
	vector<ll>::iterator it;
	while (m--)
	{
		ll x;
		cin >> x;
		it = lower_bound(arr.begin()+1,arr.end(),x);
		int pos = it - arr.begin();
		if (*it==x) cout << pos << ' ';
		else cout << -1 << ' ';
	}
	return 0;
}
