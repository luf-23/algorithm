#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int m,n;
int ans = 0;
int mapp[120][120];
int vis[120][120];
struct Node{
	int x;
	int y;
};
void bfs(int a,int b)
{
	queue<Node> q;
	q.push({a,b});
	vis[a][b] = 1;
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();
		for (int i=0;i<4;i++)
		{
			int na = now.x + dx[i];
			int nb = now.y + dy[i];
			if (na<1||na>m||nb<1||nb>n) continue;
			if (mapp[na][nb]&&!vis[na][nb])
			{
				q.push({na,nb});
				vis[na][nb] = 1;
			}
		}
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
				bfs(i,j);
				ans++;
			}
		}
	}
	cout << ans;
}
