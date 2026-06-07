#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>>arr[120];
int f[120][120];//以node为结点，保留k个分支
int n,q;
void dfs(int node,int fa){
	for (auto e : arr[node]){
		auto [nxt,val] = e;
		if (nxt!=fa){
			dfs(nxt,node);
			for (int k=q;k>=0;k--){
				for (int j=0;j<k;j++){
					f[node][k] = max(f[node][k],f[node][j]+f[nxt][k-j-1]+val);
				}
			}
		}
	}
}
signed main(){
	cin >> n >> q;
	for (int i=1;i<=n-1;i++){
		int x,y,z;
		cin >> x >> y >> z;
		arr[x].push_back(make_pair(y,z));
		arr[y].push_back(make_pair(x,z));
	}
	dfs(1,0);
	cout << f[1][q];
	return 0;
}
