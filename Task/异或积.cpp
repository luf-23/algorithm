#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	ll t;
	cin >> t;
	while (t--)
	{
		ll n,k;
		cin >> n >> k;
		ll a[n+1];
		for (int i=1;i<=n;i++)
			cin >> a[i];
		if (n%2==0&&k%2==1||(n%2!=0))
		{
			ll all = a[1];
			for (int i=2;i<=n;i++)
				all ^= a[i];
			for (int i=1;i<=n;i++)
				a[i] = all ^ a[i];
			for (int i=1;i<=n;i++)
				cout << a[i] << ' ';
			cout << '\n';
		}else{
			for (int i=1;i<=n;i++)
				cout << a[i] << ' ';
			cout << '\n';
		}
	}
	return 0;
}
