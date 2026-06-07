//暴力做法：：

/*#include <bits/stdc++.h>
  using namespace std;
  int n,m,s,t;
  vector<pair<int,int>>arr[10005];
  int vis[10005];
  int ans = INT_MAX;
  int cnt = 0;
  void dfs(int node,int cnt)
  {
  if (node==t){
  ans = min(ans,cnt);
  return;
  }
  vis[node] = 1;
  for (int i=0;i<arr[node].size();i++){
  if (vis[arr[node][i].first]==0){
  dfs(arr[node][i].first,max(cnt,arr[node][i].second));
  vis[arr[node][i].first] = 0;
  }
  }
  }
  int main()
  {
  cin >> n >> m >> s >> t;
  for (int i=1;i<=m;i++){
  int u,v,w;
  cin >> u >> v >> w;
  arr[u].push_back(make_pair(v,w));
  arr[v].push_back(make_pair(u,w));
  }
  dfs(s,0);
  cout << ans;
  return 0;
  }*/
//克鲁斯卡树：
#include <bits/stdc++.h>
using namespace std;
int fa[10005];
int n,m,s,t;
struct edge{
	int x,y,w;
};
int Find(int x)
{
	if (x!=fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}
void Join(int x,int y)
{
	fa[Find(x)] = Find(y);
}
int main()
{
	cin >> n >> m >> s >> t;
	edge e[m+1];
	for (int i=1;i<=m;i++){
		cin >> e[i].x >> e[i].y >> e[i].w;
	}
	auto cmp = [&](edge a,edge b){
		return a.w < b.w;
	};
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=n;i++) fa[i] = i; 
	for (int i=1;i<=m;i++){
		if (Find(e[i].x)!=Find(e[i].y)) Join(e[i].x,e[i].y);
		if (Find(s)==Find(t)){
			cout << e[i].w;
			exit(0);
		}
	}
	return 0;
}
