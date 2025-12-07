#include <bits/stdc++.h>
using namespace std;
map<int,bool> vis;
int a,b;
int ans;
struct node{
	int to,w;
};
vector<node>arr[100005];
void dfs(int u,int self,int val,int _)
{
	if (_==0&&u==b) return;
	if (_==0) vis[val] = 1;
	else ans |= (u!=b&&vis[val]==1);
	for (node i : arr[u]){
		if (i.to != self){
			dfs(i.to,u,val^i.w,_);
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n >> a >> b;
		for (int i=0;i<100005;i++) arr[i].clear();
		vis.clear();
		ans = 0;
		for (int i=1;i<=n-1;i++){
			int x,y,w;
			cin >> x >> y >> w;
			arr[x].emplace_back((node){y,w});
			arr[y].emplace_back((node){x,w});
		}
		dfs(a,0,0,0);
		dfs(b,0,0,1);
		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
