#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ll n,q;
	cin >> n >> q;
	map<ll,map<ll,ll>> mp;
	while (q--)
	{
		int a;
		cin >> a;
		if (a==1)
		{
			ll i,j,k;
			cin >> i >> j >> k;
			mp[i][j] = k;
		}else if (a==2)
		{
			ll p,q;
			cin >> p >> q;
			cout << mp[p][q] << endl;
		}
	}
	return 0;
}
