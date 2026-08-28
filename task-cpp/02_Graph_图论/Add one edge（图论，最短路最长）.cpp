#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n1,n2,m;
vector<int>arr[300005];
int dist[300005];
int vis[300005];
int cnt = 0;
void bfs(int node)
{
	queue<int>q;
	q.push(node);
	vis[node] = 1;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i=0;i<arr[now].size();i++){
			if (vis[arr[now][i]]==0){
				dist[arr[now][i]] = dist[now] + 1;
				q.push(arr[now][i]);
				vis[arr[now][i]] = 1;//注意标记的位置，push之后立刻标记掉
			}
		}
	}
}
int main()
{
	cin >> n1 >> n2 >> m;
	for (int i=1;i<=m;i++){
		int a,b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	bfs(1);
	bfs(n1+n2);
	int mx1 = 0;
	int mx2 = 0;
	for (int i=1;i<=n1;i++) mx1 = max(mx1,dist[i]);
	for (int i=n1+1;i<=n1+n2;i++) mx2 = max(mx2,dist[i]);
	cout << mx1+mx2+1;
	return 0;
}
