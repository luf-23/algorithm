#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int n,q;
	cin >> n >> q;
	cin >> s;
	int a[n+1];
	memset(a,0,sizeof(a));
	for (int i=1;i<n;i++)
	{
		if (s[i-1]==s[i])
		{
			a[i]++;
		}
	}
	int cnt[n+1];
	cnt[0] = 0;
	for (int i=1;i<=n;i++)
	{
		cnt[i] = cnt[i-1]+a[i];
	}
	while (q--)
	{
		int x,y;
		cin >> x >> y;
		cout << cnt[y-1]-cnt[x-1] << endl;
	}
	return 0;
}
