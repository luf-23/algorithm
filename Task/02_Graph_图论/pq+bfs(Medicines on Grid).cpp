#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
char mapp[205][205];
int sx,sy,tx,ty;
struct Node{
	int xx,yy,val;
};
struct cmp{
	bool operator()(Node a,Node b){
		return a.val < b.val;
	};
};
int Val[205][205];
int dp[205][205];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
signed main(){
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		getchar();
		for (int j=1;j<=m;j++){
			cin >> mapp[i][j];
			dp[i][j] = -INT_MAX;
			if (mapp[i][j]=='S'){
				sx = i;
				sy = j;
			}else if (mapp[i][j]=='T'){
				tx = i;
				ty = j;
			}
		}
	}
	int Q;
	cin >> Q;
	while (Q--){
		int x,y,cnt;
		cin >> x >> y >> cnt;
		Val[x][y] = cnt;
	}
	priority_queue<Node,vector<Node>,cmp>pq;
	pq.push(Node{sx,sy,Val[sx][sy]});
	dp[sx][sy] = Val[sx][sy];
	while (!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if (now.val<dp[now.xx][now.yy]||now.val==0) continue;
		for (int i=0;i<4;i++){
			int nx = now.xx + dx[i];
			int ny = now.yy + dy[i];
			if (nx<1||ny<1||nx>n||ny>m||mapp[nx][ny]=='#') continue;
			int mx = max(now.val-1,Val[nx][ny]);
			if (dp[nx][ny]<mx){
				pq.push(Node{nx,ny,mx});
				dp[nx][ny] = mx;
			}
		}
	}
	if (dp[tx][ty]!=-INT_MAX) cout << "Yes";
	else cout << "No";
	return 0;
}
