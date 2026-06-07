#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ll n,m;
	cin >> n >> m;
	ll num[n+1];
	ll max_v = 0;
	for (int i=1;i<=n;i++)
	{
		cin >> num[i];
		max_v = max(max_v,num[i]);
	}
	ll l,r,mid;
	l = 0;
	r = 1000000001;
	ll sum = 0;
	while (l<=r)
	{
		sum = 0;
		mid = (l+r)/2;
		for (int i=1;i<=n;i++)
		{
			if (num[i]>mid)
			{
				sum += num[i] - mid;
			}
		}
		if (sum>=m) l = mid+1;
		else r = mid-1;
	}
	cout << l-1 << endl;
	return 0;
}
