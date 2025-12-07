#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>>arr[100005];
int ans[100005];
int n,m,q;
int fa[100005];
int vis[100005];
int Find(int x)
{
	if (x!=fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}
void dfs(int node){
	for (int i=0;i<arr[node].size();i++){
		if (!vis[arr[node][i].first]){
			ans[arr[node][i].first] = ans[node]^arr[node][i].second;
			vis[arr[node][i].first] = 1;
			dfs(arr[node][i].first);
		}
	}
}
signed main()
{
	cin >> n >> m >> q;
	for (int i=1;i<=n;i++) fa[i] = i;
	for (int i=1;i<=m;i++){
		int x,y,c;
		cin >> x >> y >> c;
		int X = Find(x);
		int Y = Find(y);
		if (X!=Y){
			fa[X] = Y;
			arr[x].push_back(make_pair(y,c));
			arr[y].push_back(make_pair(x,c));
		}
	}
	ans[1] = 0;
	vis[1] = 1;
	dfs(1);
	while (q--){
		int x,y;
		cin >> x >> y;
		cout << (long long)(ans[x]^ans[y]) << '\n';
	}
	return 0;
}

