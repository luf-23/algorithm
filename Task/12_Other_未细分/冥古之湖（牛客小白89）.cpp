#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q,x;
int ans[5005][5005];
int cnt[1000005];
int dist[1000005];
vector<int>arr[1000005];
int vis[1000005];
queue<int>qq;
int mod = 1000000007;
void bfs(int node){
	qq.push(x);
	while (!qq.empty()){
		int now = qq.front();
		qq.pop();
		for (auto ele : arr[now]){
			if (!vis[ele]){
				vis[ele] = 1;
				dist[ele] = dist[now] + 1;
				qq.push(ele);
			}
		}
	}
}
signed main(){
	cin >> n >> m >> q >> x;
	for (int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	vis[x] = 1;
	bfs(x);
	for (int i=1;i<=n;i++) cnt[dist[i]]++;
	int mx = 1;
	for (int i=n;i>=1;i--){
		if (cnt[i]!=0){
			mx = i;
			break;
		}
	}
	//考虑到距离为i的点时，选j个点的方案数
	for (int i=0;i<=mx;i++) ans[i][0] = 1;
	for (int i=1;i<=mx;i++){
		for (int j=1;j<=i;j++){
			ans[i][j] = (ans[i-1][j]+ans[i-1][j-1]*cnt[i])%mod;
		}
	}
	while (q--){
		int p;
		cin >> p;
		cout << ans[mx][p]%mod << '\n';
	}
	return 0;
}
