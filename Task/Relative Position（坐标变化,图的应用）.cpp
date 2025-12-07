#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<pair<int,int>,int>>arr[200005];
int vis[200005];
int X[200005];
int Y[200005];
int n,m;
void dfs(int node)
{
	for (int i=0;i<arr[node].size();i++){
		if (vis[arr[node][i].second]) continue;
		vis[arr[node][i].second] = 1;
		X[arr[node][i].second] = X[node] + arr[node][i].first.first;
		Y[arr[node][i].second] = Y[node] + arr[node][i].first.second;
		dfs(arr[node][i].second);
	}
}
signed main()
{
	cin >> n >> m;
	for (int i=1;i<=m;i++){
		int a,b,x,y;
		cin >> a >> b >> x >> y;
		arr[a].push_back(make_pair(make_pair(x,y),b));
		arr[b].push_back(make_pair(make_pair(-x,-y),a));
	}
	vis[1] = 1;
	dfs(1);
	for (int i=1;i<=n;i++){
		if (vis[i]==0) cout << "undecidable" << endl;
		else cout << X[i] << ' ' << Y[i] << endl;
	}
	return 0;
}
