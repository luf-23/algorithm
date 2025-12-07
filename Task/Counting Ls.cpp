#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n;
	cin >> n;
	string str[n];
	for (int i=0;i<n;i++) cin >> str[i];
	ll f[3000] = {0};
	ll g[3000] = {0};
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (str[i][j]=='o')
			{
				++f[i];
				++g[j];
			}
		}
	}
	ll ans = 0;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (str[i][j]=='o')
			{
				ans += (f[i]-1)*(g[j]-1);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
