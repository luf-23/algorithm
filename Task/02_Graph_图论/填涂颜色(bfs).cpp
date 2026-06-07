/*想选择一个圈外的点开始bfs，但是不知道这个圈外的点有哪些，
而且不是所有圈外的点都是连起来的，因此需要再套一层，从（0，0）开始bfs*/
#include <bits/stdc++.h>
using namespace std;
int Map[40][40];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n;
struct Node{
	int x,y;
};
queue<Node> q;
bool vis[40][40] = {0};
void bfs(int _x,int _y)
{
	q.push(Node{_x,_y});
	while (!q.empty())
	{
		Node now = q.front();
		vis[now.x][now.y] = 1;
		q.pop();
		for (int i=0;i<4;i++)
		{
			int nxt_x = now.x+dx[i];
			int nxt_y = now.y+dy[i];
			if (nxt_x>n+1||nxt_x<0||nxt_y>n+1||nxt_y<0||vis[nxt_x][nxt_y]==1||Map[nxt_x][nxt_y]==1) continue;
			q.push(Node{nxt_x,nxt_y});
		}
	}
}
int main()
{
	cin >> n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin >> Map[i][j];
	bfs(0,0);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (Map[i][j]!=1&&vis[i][j]!=1) Map[i][j] = 2;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cout << Map[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
