#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ll n;
	cin >> n;
	ll cost = 0;
	ll num[n+1];
	num[0] = 0;
	for (int i=1;i<=n;i++)
		cin >> num[i];
	sort(num+0,num+n+1);
	ll l = 0;
	ll r = n;
	ll cnt = 0;
	while (l<=r)
	{
		cost += (num[l]-num[r])*(num[l]-num[r]);
		cnt++;
		if (cnt%2==1) l++;
		else r--;
	}
	cout << cost;
	return 0;
}
