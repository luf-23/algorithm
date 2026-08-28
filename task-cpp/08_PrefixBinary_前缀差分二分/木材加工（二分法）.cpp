#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n,k;
	cin >> n >> k;
	ll sum = 0;
	ll len[n+1];
	for (int i=1;i<=n;i++)
	{
		cin >> len[i];
	}
	ll ans;
	ll l = 0;
	ll r = 100000001;
	ll mid;
	while (l+1<r)
	{
		mid = (l+r)/2;
		ll s = 0;
		for (int i=1;i<=n;i++)
		{
			s += len[i]/mid;
		}
		if (s>=k){
			l = mid;
		}else {
			r = mid;
		}
	}
	cout << l;
	return 0;
}
