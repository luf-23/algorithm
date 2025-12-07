#include <bits/stdc++.h>
using namespace std;
int depth[30005];
vector<int>arr[30005];
int fa[30005][25];
int n,m;
void dfs(int node,int fath)
{
	depth[node] = depth[fath] + 1;
	fa[node][0] = fath;
	for (int i=1;i<=24;i++){
		fa[node][i] = fa[fa[node][i-1]][i-1];
	}
	for (int i=0;i<arr[node].size();i++){
		if (arr[node][i]!=fath){
			dfs(arr[node][i],node);
		}
	}
}
int lca(int x,int y)
{
	if (depth[x]<depth[y]) swap(x,y);
	for (int i=24;i>=0;i--){
		if (depth[fa[x][i]]>=depth[y]){
			x = fa[x][i];
		}
	}
	if (x==y) return x;
	for (int i=24;i>=0;i--){
		if (fa[x][i]!=fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
int main()
{
	cin >> n;
	for (int i=1;i<=n-1;i++){
		int x,y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	dfs(1,1);
	//for (int i=1;i<=n;i++) cout << depth[i] << ' ';
	//cout << endl;
	cin >> m;
	int ans = 0;
	int num[m+1];
	for (int i=1;i<=m;i++){
		cin >> num[i];
	}
	for (int i=2;i<=m;i++){
		int dis1 = depth[num[i]]-1;
		int dis2 = depth[num[i-1]]-1;
		int dis3 = 2*(depth[lca(num[i],num[i-1])]-1);
		ans += dis1+dis2-dis3;
		//cout << "dis1,2,3=" << dis1 << ' ' << dis2 << ' ' << dis3 << ' ';
		//cout << "ans=" << ans << endl;
	}
	cout << ans;
	return 0;
}
