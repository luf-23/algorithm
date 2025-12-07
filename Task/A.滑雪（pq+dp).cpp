#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
struct Node{
	int xx,yy,num;
};
struct cmp{
	bool operator()(Node a,Node b){
		return a.num < b.num;
	};
};
int dp[120][120];
priority_queue<Node,vector<Node>,cmp>pq;
int main(){
	int n,m;
	int mx = 0;
	int p,q;
	cin >> n >> m;
	int num[n+1][m+1];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin >> num[i][j];
			Node now;
			now.xx = i;
			now.yy = j;
			now.num = num[i][j];
			dp[i][j] = 1;
			pq.push(now);
		}
	}
	int ans = 1;
	while (!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for (int i=0;i<4;i++){
			int nx = now.xx + dx[i];
			int ny = now.yy + dy[i];
			if (nx>n||nx<1||ny>m||ny<1||num[nx][ny]<=num[now.xx][now.yy]) continue;
			dp[now.xx][now.yy] = max(dp[now.xx][now.yy],dp[nx][ny]+1);
		}
		ans = max(ans,dp[now.xx][now.yy]);
	}
	cout << ans;
	return 0;
}
