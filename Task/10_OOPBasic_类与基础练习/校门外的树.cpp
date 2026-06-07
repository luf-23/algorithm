#include <bits/stdc++.h>
using namespace std;
int main()
{
	int l,m;
	cin >> l >> m;
	int BOOL[l+1];
	int i;
	for (i=0;i<=l;i++)
	{
		BOOL[i] = 1;
	}
	for (i=0;i<m;i++)
	{
		int u,v;
		cin >> u >> v;
		int j;
		for (j=u;j<=v;j++)
		{
			BOOL[j]--;
		}
	}
	int cnt = 0;
	for (i=0;i<=l;i++)
	{
		if (BOOL[i]==1)
		{
			cnt++;
		}
		//cout << BOOL[i] << ' ';
	}
	cout << cnt;
	return 0;
}
