#include <bits/stdc++.h>
#define int long long
using namespace std;
int h,w;
int mod = 998244353;
int cnt = 1;
char mapp[1005][1005];
int vis[1005][1005];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int ksm(int a,int b)
{
	int ans = 1;
	int base = a;
	while (b){
		if (b&1) ans = (ans*base)%mod;
		base = (base*base)%mod;
		b >>= 1;
	}
	return ans%mod;
}
void bfs(int xx,int yy){
	queue<pair<int,int>>q;
	q.push(make_pair(xx,yy));
	while (!q.empty()){
		pair<int,int> now = q.front();
		q.pop();
		if (vis[now.first][now.second]) continue;
		vis[now.first][now.second] = cnt;
		for (int i=0;i<4;i++){
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx<1||nx>h||ny<1||ny>w||mapp[nx][ny]=='.'||vis[nx][ny]!=0) continue;
			q.push(make_pair(nx,ny));
		}
	}
}
signed main()
{
	cin >> h >> w;
	for (int i=1;i<=h;i++){
		getchar();
		for (int j=1;j<=w;j++){
			cin >> mapp[i][j];
		}
	}
	for (int i=1;i<=h;i++){
		for (int j=1;j<=w;j++){
			if (mapp[i][j]=='#'&&vis[i][j]==0){
				bfs(i,j);
				cnt++;
			}
		}
	}
	set<int>st;
	for (int i=1;i<=h;i++){
		for (int j=1;j<=w;j++){
			if (vis[i][j]!=0){
				st.insert(vis[i][j]);
			}
		}
	}
	int ret = st.size();
	int ans = 0;
	cnt = 0;
	for (int i=1;i<=h;i++){
		for (int j=1;j<=w;j++){
			if (vis[i][j]==0){
				set<int>s;
				if (vis[i+1][j]!=0) s.insert(vis[i+1][j]);
				if (vis[i-1][j]!=0) s.insert(vis[i-1][j]);
				if (vis[i][j+1]!=0) s.insert(vis[i][j+1]);
				if (vis[i][j-1]!=0) s.insert(vis[i][j-1]);
				ans = (ans+ret-s.size()+1)%mod;
				cnt = (cnt+1)%mod;
			}
		}
	}
	cout << ans*ksm(cnt,mod-2)%mod << endl;
	return 0;
}

