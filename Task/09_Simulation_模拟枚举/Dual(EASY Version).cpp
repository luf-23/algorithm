#include <bits/stdc++.h>
using namespace std;
pair<int,int>p[105];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int num[n+1];
		for (int i=1;i<=n;i++)
			cin >> num[i];
		int abs_max_v = 0;
		int pos;
		for (int i=1;i<=n;i++)
		{
			if (abs(num[i])>abs(abs_max_v))
			{
				abs_max_v = num[i];
				pos = i;
			}
		}
		if (abs_max_v==0) 
		{
			cout << 0 << '\n';
			continue;
		}
		int cnt = 0;
		
		for (int i=1;i<=n;i++)
		{
			if (i==pos) continue;
			num[i] += abs_max_v;
			p[++cnt] = {i,pos};
		}
		if (abs_max_v<0)
		{
			for (int i=n;i>1;i--)
			{
				p[++cnt] = {i-1,i};
			}
		}else if (abs_max_v>0)
		{
			for (int i=2;i<=n;i++)
			{
				p[++cnt] = {i,i-1};
			}
		}
		cout << cnt << '\n';
		for (int i=1;i<=cnt;i++)
			cout << p[i].first << ' ' << p[i].second << '\n';
	}
	return 0;
}
