#include <bits/stdc++.h>
using namespace std;
int n,m,s;
vector<int>arr[500005];
int fa[500005];
vector<pair<int,int>> q[500005];
int vis[500005];
int ans[500005];
int Find(int x){
	if (x!=fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}
void tarjan(int node)
{
	vis[node] = 1;
	for (int i=0;i<arr[node].size();i++){
		if (!vis[arr[node][i]]){
			tarjan(arr[node][i]);
			fa[arr[node][i]] = node;
		}
	}
	for (int i=0;i<q[node].size();i++){
		if (vis[q[node][i].first]==1){
			ans[q[node][i].second] = Find(q[node][i].first);
		}
	}
}
int main()
{
	cin >> n >> m >> s;
	for (int i=1;i<=n;i++) fa[i] = i;
	for (int i=1;i<=n-1;i++){
		int x,y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	for (int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		q[x].push_back({y,i});
		q[y].push_back({x,i});
	}
	tarjan(s);
	for (int i=1;i<=m;i++) cout << ans[i] << endl;
	return 0;
}
