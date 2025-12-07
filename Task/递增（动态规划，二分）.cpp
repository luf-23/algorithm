#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ll n;
	cin >> n;
	ll num[n+1];
	num[0] = 0;
	ll now = 0;
	ll x;
	ll cnt = 0;
	for (int i=1;i<=n;i++)
	{
		cin >> x;
		if (x>num[now]) num[++now] = x;
		else{
			*lower_bound(num+1,num+now+1,x) = x;
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}
