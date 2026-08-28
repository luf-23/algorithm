#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	cin >> m >> n;
	map<int,bool> mp;
	int ans,cnt;
	ans = 0;
	cnt = 0;
	int x;
	queue<int> q;
	for (int i=1;i<=n;i++)
	{
		cin >> x;
		if (!mp[x])
		{
			ans++;
			if (cnt<m)
			{
				q.push(x);
				cnt++;
				mp[x] = 1;
			}else{
				int temp = q.front();
				q.pop();
				mp[temp] = 0;
				q.push(x);
				mp[x] = 1;
			}
		}else{
			continue;
		}
	}
	cout << ans << '\n';
	return 0;
}
