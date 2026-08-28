#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	int BOOL[2000][2000];
	int i,j;
	memset(BOOL,0,sizeof(BOOL));
	int cnt1 = 0;
	while (cnt1<m)
	{
		int x,y;
		cin >> x >> y;
		for (i=y-2;i<=y+2;i++)
		{
			BOOL[x][i] = 1;
		}
		for (i=x-2;i<=x+2;i++)
		{
			BOOL[i][y] = 1;
		}
		BOOL[x-1][y-1] = 1;
		BOOL[x+1][y-1] = 1;
		BOOL[x-1][y+1] = 1;
		BOOL[x+1][y+1] = 1;
		cnt1++;
	}
	int cnt2 = 0;
	while (cnt2<k)
	{
		int o,p;
		cin >> o >> p;
		for (i=o-2;i<=o+2;i++)
		{
			for (j=p-2;j<=p+2;j++)
			{
				BOOL[i][j] = 1;
			}
		}
		cnt2++;
	}
	int cnt = 0;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (BOOL[i][j]==0)
			{
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
