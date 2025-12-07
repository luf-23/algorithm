#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int s[m+1];
	string str[n+1];
	for (int i=1;i<=m;i++) cin >> s[i];
	for (int i=1;i<=n;i++) cin >> str[i];
	int maxx = 0;
	int p[n+1];
	for (int i=1;i<=n;i++) p[i] = 0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<str[i].length();j++)
		{
			if (str[i][j]=='o') p[i] += s[j+1];
		}
		p[i] += i;
		maxx = max(maxx,p[i]);
	}
	for (int i=1;i<=n;i++)
	{
		if (p[i]>=maxx) cout << 0 << endl;
		else{
			int cnt = 0;
			priority_queue<int>pq;
			for (int j=0;j<str[i].length();j++)
			{
				if (str[i][j]=='x') pq.push(s[j+1]);
			}
			while (p[i]<maxx&&!pq.empty())
			{
				p[i] += pq.top();
				pq.pop();
				cnt++;
			}
			cout << cnt << endl;
		}
	}
	return 0;
}
