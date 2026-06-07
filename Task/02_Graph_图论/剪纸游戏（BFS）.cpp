#include <bits/stdc++.h>
using namespace std;
char mapp[1005][1005];
int vis[1005][1005];
int m,n;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int min_i,min_j,max_i,max_j;
int cnt = 0;
long long ans = 0;
struct Node{
	int x,y;
};
void bfs(int xx,int yy){
	queue<Node>q;
	q.push((Node){xx,yy});
	while (!q.empty()){
		Node now = q.front();
		q.pop();
		while(!q.empty()&&vis[q.front().x][q.front().y]==1) q.pop();
		if (vis[now.x][now.y]==0) cnt++;
		vis[now.x][now.y] = 1;
		min_i = min(min_i,now.x);
		min_j = min(min_j,now.y);
		max_i = max(max_i,now.x);
		max_j = max(max_j,now.y);
		for (int i=0;i<4;i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx<1||ny<1||nx>m||ny>n||mapp[nx][ny]=='*'||vis[nx][ny]==1) continue;
			q.push((Node){nx,ny});
		}
	}
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout.tie(nullptr);
	cin >> m >> n;
	for (int i=1;i<=m;i++){
		getchar();
		for (int j=1;j<=n;j++){
			cin >> mapp[i][j];
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			if (mapp[i][j]=='.'&&vis[i][j]==0){
				min_i = 1300,min_j = 1300;
				max_i = 0,max_j = 0;
				cnt = 0;
				bfs(i,j);
				if (cnt==((max_i-min_i+1)*(max_j-min_j+1))) ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
