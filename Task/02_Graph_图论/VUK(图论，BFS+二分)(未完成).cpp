#include <bits/stdc++.h>
using namespace std;
int n,m;
int sx,sy,tx,ty;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char mapp[505][505];
int dist[505][505];
int vis[505][505];
int ans = 0;
int t;
struct node{
	int x;
	int y;
	int cnt = 0;
};
queue<node>q;
void bfs()
{
	while (!q.empty()){
		node now = q.front();
		vis[now.x][now.y] = 1;
		while (!q.empty()&&vis[q.front().x][q.front().y]==1) q.pop();
		dist[now.x][now.y] = now.cnt;
		for (int i=0;i<4;i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx<1||nx>m||ny<1||ny>n||vis[nx][ny]==1) continue;
			q.push({nx,ny,now.cnt+1});
		}
	}
}
void BFS(int xx,int yy)
{
	queue<node>qq;
	qq.push({xx,yy,0});
	while (!qq.empty()){
		node now = qq.front();
		vis[now.x][now.y] = 1;
		while (!qq.empty()&&vis[qq.front().x][qq.front().y]==1) qq.pop();
		for (int i=0;i<4;i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx<1||nx>m||ny<1||ny>n||vis[nx][ny]==1||dist[nx][ny]<t) continue;
			qq.push({nx,ny,0});
		}
	}
}
int main()
{
	cin >> m >> n;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			cin >> mapp[i][j];
			if (mapp[i][j]=='+'){
				q.push({i,j,0});
				vis[i][j] = 1;
			}else if (mapp[i][j]=='V'){
				sx = i;
				sy = j;
			}else if (mapp[i][j]=='J'){
				tx = i;
				ty = j;
			}
		}
	}
	bfs();
	//	for (int i=1;i<=m;i++){
	//		for (int j=1;j<=n;j++){
	//			cout << dist[i][j];
	//		}
	//		cout << endl;
	//	}
	int max_v = m + n;
	for (t=0;t<=max_v;t++){
		for (int i=1;i<=m;i++){
			for (int j=1;j<=n;j++){
				vis[i][j] = 0;
			}
		}
		if (dist[sx][sy]<t) continue;;
		BFS(sx,sy);
		if (vis[tx][ty]==1) ans = t;
	}
	cout << ans;
	return 0;
}
