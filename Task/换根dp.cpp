#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int dp[1000005];//以i为根节点时求得的深度之和
int sz[1000005];
int ans = INT_MAX;
vector<int>arr[1000005];
void dfs(int node,int fa){
	sz[node] = 1;
	for (auto e : arr[node]){
		if (e!=fa){
			dfs(e,node);
			sz[node] += sz[e];
			dp[node] += dp[e]+sz[e];
		}
	}
}
void dfs2(int node,int fa){
	ans = min(ans,dp[node]);
	//换根，依次将以node为根的情况转化为以e为根的情况
	for (auto e : arr[node]){
		if (e!=fa){
			int last_sze = sz[e];
			int last_sznode = sz[node];
			int last_dpe = dp[e];
			int last_dpnode = dp[node];
			dp[node] -= dp[e]+sz[e];
			sz[node] -= sz[e];
			sz[e] += sz[node];
			dp[e] += dp[node]+sz[node];
			dfs2(e,node);
			dp[node] = last_dpnode;
			sz[node] = last_sznode;
			sz[e] = last_sze;
			sz[node] = last_sznode;
		}
	}
}
signed main(){
	cin >> n;
	for (int i=1;i<=n-1;i++){
		int x,y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	dfs(1,0);
	dfs2(1,0);
	cout << ans;
	return 0;
}
