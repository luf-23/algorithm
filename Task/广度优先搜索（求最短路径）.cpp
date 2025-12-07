#include <bits/stdc++.h>
using namespace std;
int tx,ty,_x,_y;
struct Node{
	int x;
	int y;
	int cnt;
};
int Map[6][6] = {
	0,0,0,0,0,0,
	0,0,0,1,0,0,
	0,0,1,0,0,0,
	0,0,0,0,1,0,
	0,0,1,0,1,0,
	0,0,0,1,0,1,
};
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool vis[6][6];
queue<Node> q;
void bfs()
{
	q.push((Node){_x,_y,1});
	while (!q.empty())
	{
		Node now = q.front();
		vis[now.x][now.y] = 1;
		q.pop();
		if (now.x==tx&&now.y==ty)
		{
			cout << now.cnt-1 << endl;
			break;
		}
		for (int i=0;i<4;i++)
		{
			int nxt_x = now.x+dx[i];
			int nxt_y = now.y+dy[i];
			if (nxt_x>5||nxt_x<1||nxt_y>5||nxt_y<1||vis[nxt_x][nxt_y]==1||Map[nxt_x][nxt_y]==1) continue;
			q.push((Node){nxt_x,nxt_y,now.cnt+1});
		}
	}
}
int main()
{
	memset(vis,0,sizeof(vis));
	cin >> _x >> _y >> tx >> ty;
	bfs();
	return 0;
}
