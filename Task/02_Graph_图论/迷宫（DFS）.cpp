#include <bits/stdc++.h>
using namespace std;
int m,n;
bool mapp[15][15];
bool vis[15][15];
int _x,_y,ex,ey;
int cnt = 0;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
void dfs(int x,int y)
{
	if (x==ex&&y==ey)
	{
		cnt++;
		return;
	}
	vis[x][y] = 1;
	for (int i=0;i<4;i++)
	{
		int n_x = x + dx[i];
		int n_y = y + dy[i];
		if (n_x>m||n_x<1||n_y>n||n_y<1||vis[n_x][n_y]==1||mapp[n_x][n_y]==1) continue;
		dfs(n_x,n_y);
		vis[n_x][n_y] = 0;
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> m >> n >> t;
	cin >> _x >> _y >> ex >> ey;
	for (int i=1;i<=t;i++)
	{
		int a,b;
		cin >> a >> b;
		mapp[a][b] = 1;
	}
	dfs(_x,_y);
	cout << cnt << '\n';
	return 0;
}
