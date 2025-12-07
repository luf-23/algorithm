#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n,m;
	cin >> n >> m;
	ll num[n+1];
	for (int i=1;i<=n;i++)
		cin >> num[i];
	while (m--)
	{
		ll x;
		cin >> x;
		int pos = lower_bound(num+1,num+n+1,x) - num;
		if (num[pos]==x) cout << pos << ' ';
		else cout << -1 << ' ';
	}
	return 0;
}
