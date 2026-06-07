#include <bits/stdc++.h>
using namespace std;
int n,m,_x,_y,tx,ty;
int num[410][410];
int Map[410][410];
int dx[] = {-2,-2,-1,1,2,2,1,-1};
int dy[] = {-1,1,2,2,1,-1,-2,-2};
bool vis[410][410];
struct Node{
	int x;
	int y;
	int cnt;
};
queue<Node> q;
void bfs(int _x,int _y)
{
	//if (!q.empty()) q.pop();
	//memset(vis,0,sizeof(vis));
	q.push(Node{_x,_y,1});
	while (!q.empty())
	{
		Node now = q.front();
		vis[now.x][now.y] = 1;
		q.pop();
		//if (now.x==tx&&now.y==ty)
		//{
		//	num[tx][ty] = now.cnt-1;
		//	break;
		//}
		for (int i=0;i<8;i++)
		{
			int nxt_x = now.x+dx[i];
			int nxt_y = now.y+dy[i];
			if (nxt_x<1||nxt_x>m||nxt_y<1||nxt_y>n||vis[nxt_x][nxt_y]==1) continue;
			num[nxt_x][nxt_y] = now.cnt;
			q.push(Node{nxt_x,nxt_y,now.cnt+1});
			vis[nxt_x][nxt_y] = 1;
		}
	}
}
int main()
{
	cin >> m >> n >> _x >> _y;
	memset(num,0,sizeof(num));
	memset(Map,0,sizeof(Map));
	bfs(_x,_y);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			if (num[i][j]==0) num[i][j] = -1;
	num[_x][_y] = 0;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cout << num[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}

/*
  #include <bits/stdc++.h>
  using namespace std;
  using ll = long long;
  int m,n,x,y;
  int cnt = 0;
  int mapp[420][420];
  int dx[] = {-2,-2,-1,1,2,2,1,-1};
  int dy[] = {-1,1,2,2,1,-1,-2,-2};
  struct Node{
  int _x,_y;
  int cnt;
  };
  int ans[420][420];
  queue<Node> q;
  void bfs(int x,int y)
  {
  q.push(Node{x,y,0});
  while (!q.empty())
  {
  Node now = q.front();
  q.pop();
  mapp[now._x][now._y] = 1;
  for (int i=0;i<8;i++)
  {
  int nxt_x = now._x + dx[i];
  int nxt_y = now._y + dy[i];
  if (!mapp[nxt_x][nxt_y]&&!mapp[nxt_x][nxt_y]&&nxt_x>0&&nxt_x<=m&&nxt_y>0&&nxt_y<=n)
  {
  ans[nxt_x][nxt_y] = now.cnt + 1;
  q.push(Node{nxt_x,nxt_y,now.cnt+1});
  mapp[nxt_x][nxt_y] = 1;
  }
  }
  }
  }
  int main()
  {
  cin >> m >> n >> x >> y;
  for (int i=1;i<=m;i++)
  {
  for (int j=1;j<=n;j++)
  {
  ans[i][j] = -1;
  }
  }
  bfs(x,y);
  ans[x][y] = 0;
  for (int i=1;i<=m;i++)
  {
  for (int j=1;j<=n;j++)
  {
  cout << ans[i][j] << ' ';
  }
  cout << '\n';
  }
  return 0;
  }
 */
