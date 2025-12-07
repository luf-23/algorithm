#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ll n,x;
	cin >> n >> x;
	ll num[n+1];
	memset(num,0,sizeof(num));
	for (int i=1;i<=n;i++)
		cin >> num[i];
	ll cnt = 0;
	if (num[1]>x)
	{
		cnt += num[1] - x;
		num[1] = x;
	}
	for (int i=2;i<=n;i++)
	{
		if (num[i]+num[i-1]>x)
		{
			cnt += num[i]+num[i-1] - x;
			num[i] = x - num[i-1];
		}
	}
	cout << cnt << endl;
	return 0;
}
