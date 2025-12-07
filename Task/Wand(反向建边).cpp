#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>arr[100001];
int vis[100005];
int flag = 1;
void dfs(int node)
{
	if (!flag){
		vis[node] = 1;
	}
	for (int i=0;i<arr[node].size();i++){
		flag = 0;
		if (!vis[arr[node][i]]){
			dfs(arr[node][i]);
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		arr[y].push_back(x);
	}
	dfs(1);
	if (arr[1].empty()) vis[1] = 1;
	for (int i=1;i<=n;i++) cout << vis[i];
	return 0;
}
