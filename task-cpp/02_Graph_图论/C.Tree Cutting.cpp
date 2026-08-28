#include <bits/stdc++.h>
using namespace std;
vector<int>arr[100005];
int vis[100005];
int sz[100005];
int n;
int cnt;
int l,r,mid;
void dfs(int node){
	vis[node] = 1;
	sz[node] = 1;
	for (auto ele : arr[node]){
		if (!vis[ele]){
			dfs(ele);
			sz[node] += sz[ele];
		}
	}
	if (sz[node]>=mid){
		cnt++;
		sz[node] = 0;
	}
}
int main(){
	int t;
	cin >> t;
	while (t--){
		int n,k;
		cin >> n >> k;
		for (int i=1;i<=n;i++) arr[i].clear(),vis[i] = 0;
		for (int i=1;i<=n-1;i++){
			int x,y;
			cin >> x >> y;
			arr[x].push_back(y);
			arr[y].push_back(x);
		}
		l = 0;
		r = n;
		while (l+1<r){
			mid = (l+r)>>1;
			cnt = 0;
			for (int i=1;i<=n;i++) vis[i] = 0;
			dfs(1);
			if (cnt>=k+1) l = mid;
			else r = mid;
		}
		cout << l << '\n';
	}
}
