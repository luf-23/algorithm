#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>arr[100005];
int vis[100005];
void dfs(int node)
{
	vis[node] = 1;
	cout << node << ' ';
	for (int i=0;i<arr[node].size();i++){
		if (vis[arr[node][i]]==0){
			dfs(arr[node][i]);
		}
	}
}
void bfs(int node)
{
	queue<int>q;
	q.push(node);
	cout << node << ' ';
	vis[node] = 1;
	while (!q.empty())
	{
		int now = q.front();
		for (int i=0;i<arr[now].size();i++){
			if (vis[arr[now][i]]==0){
				q.push(arr[now][i]);
				cout << arr[now][i] << ' ';
				vis[arr[now][i]] = 1;
			}
		}
		q.pop();
	}
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		arr[x].push_back(y);
	}
	for (int i=0;i<n+1;i++){
		sort(arr[i].begin(),arr[i].end());
	}
	dfs(1);
	cout << endl;
	memset(vis,0,sizeof(vis));
	bfs(1);
	cout << endl;
	return 0;
}
