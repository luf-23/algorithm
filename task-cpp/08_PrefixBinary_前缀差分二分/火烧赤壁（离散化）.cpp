#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	ll a[20010];
	ll b[20010];
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	ll cnt = 0;
	for (int i=1;i<=n;i++)
	{
		cnt += b[i]-a[i];
		if (i<=n-1)
		{
			if (a[i+1]<b[i])
			{
				cnt -= b[i] - a[i+1];
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
