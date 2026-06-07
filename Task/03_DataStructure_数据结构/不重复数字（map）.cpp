#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int t,n;
	cin >> t;
	while (t--)
	{
		unordered_map<ll,int> mp;
		cin >> n;
		ll x;
		ll num[50010];
		for (int i=1;i<=n;i++)
		{
			cin >> num[i];
			mp[num[i]]++;
		}
		for (int i=1;i<=n;i++)
		{
			if (mp[num[i]]!=0)
			{
				cout << num[i] << ' ';
				mp[num[i]] = 0;
			}
		}
		cout << endl;
	}
	return 0;
}
