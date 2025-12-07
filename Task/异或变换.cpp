#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n,t;
	cin >> n >> t;
	int s[n+1] = {0};
	string ss;
	cin >> ss;
	for (int i=1;i<=n;i++)
	{
		s[i] = ss[i-1]-'0';
	}
	ll x = 1;
	while (x<n) x <<= 1;
	t %= x;
	while (t--)
	{
		for (int i=n;i>1;i--)
			s[i] ^= s[i-1];
	}
	for (int i=1;i<=n;i++)
		cout << s[i];
	return 0;
}
