#include <bits/stdc++.h>
using namespace std;
int n,m,s;
int depth[500005];
int fa[500005][22];
vector<int>arr[500005];
void dfs(int node,int fath)
{
	depth[node] = depth[fath] + 1;
	fa[node][0] = fath;
	for (int i=1;i<=21;i++){
		fa[node][i] = fa[fa[node][i-1]][i-1];
	}
	for (int i=0;i<arr[node].size();i++){
		if (arr[node][i]!=fath) dfs(arr[node][i],node);
	}
}
int lca(int x,int y)
{
	if (depth[x]<depth[y]) swap(x,y);
	for (int i=21;i>=0;i--){
		if (depth[fa[x][i]]>=depth[y]){
			x = fa[x][i];
		}
	}
	if (x==y) return x;
	for (int i=21;i>=0;i--){
		if (fa[x][i]!=fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
int main()
{
	cin >> n >> m >> s;
	for (int i=1;i<=n-1;i++){
		int x,y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	dfs(s,s);
	for (int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		cout << lca(x,y) << endl;
	}
	return 0;
}
