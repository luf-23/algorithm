#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>>arr[200005];
int n;
int dp[200005];
int ans;
void pre(int node,int fa){
	for (auto e : arr[node]){
		auto [nxt,val] = e;
		if (nxt!=fa){
			pre(nxt,node);
			if (!dp[nxt]) dp[node] += val;
			else dp[node] += min(dp[nxt],val);
		}
	}
}
void dfs(int node,int fa){
	ans = max(ans,dp[node]);
	for (auto e : arr[node]){
		auto [nxt,val] = e;
		if (nxt!=fa){
			int last_dpnode = dp[node];
			int last_dpnxt = dp[nxt];
			if (!dp[nxt]) dp[node] -= val;
			else dp[node] -= min(dp[nxt],val);
			if (!dp[node]) dp[nxt] += val;
			else dp[nxt] += min(dp[node],val);
			dfs(nxt,node);
			dp[node] = last_dpnode;
			dp[nxt] = last_dpnxt;
		}
	}
}
signed main(){
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		for (int i=1;i<=n;i++){
			arr[i].clear();
			dp[i] = 0;
		}
		for (int i=1;i<=n-1;i++){
			int x,y,z;
			cin >> x >> y >> z;
			arr[x].push_back(make_pair(y,z));
			arr[y].push_back(make_pair(x,z));
		}
		pre(1,0);
		ans = 0;
		dfs(1,0);
		cout << ans << '\n';
	}
	return 0;
}
