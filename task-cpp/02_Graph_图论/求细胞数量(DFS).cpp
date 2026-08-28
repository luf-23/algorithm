#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int m,n;
int ans = 0;
int mapp[120][120];
int vis[120][120];
void dfs(int x,int y)
{
	vis[x][y] = 1;
	for (int i=0;i<4;i++)
	{
		int nxt_x = x + dx[i];
		int nxt_y = y + dy[i];
		if (nxt_x<1||nxt_x>m||nxt_y<1||nxt_y>n) continue;
		if (mapp[nxt_x][nxt_y]&&!vis[nxt_x][nxt_y]) dfs(nxt_x,nxt_y);
	}
}
int main()
{
	cin >> m >> n;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			scanf("%1d",&mapp[i][j]);
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (mapp[i][j]&&!vis[i][j])
			{
				dfs(i,j);
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
