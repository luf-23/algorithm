#include <bits/stdc++.h>
using namespace std;
vector<int>arr[100005];
int ans[100005];
int n,m;
void dfs(int node,int ret)
{
	if (ans[node]) return;
	ans[node] = ret;
	for (int i=0;i<arr[node].size();i++){
		dfs(arr[node][i],ret);
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
	for (int i=n;i>=1;i--){
		dfs(i,i);
	}
	for (int i=1;i<=n;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
