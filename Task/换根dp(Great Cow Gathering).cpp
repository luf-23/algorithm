#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int num[100005];
int cnt[100005];
int sum[100005];
vector<pair<int,int>>arr[100005];
int ans = LONG_LONG_MAX;
void pre(int node,int fa){
	cnt[node] = num[node];
	for (auto e : arr[node]){
		auto [nxt,val] = e;
		if (nxt!=fa){
			pre(nxt,node);
			cnt[node] += cnt[nxt];
			sum[node] += sum[nxt] + cnt[nxt]*val;
		}
	}
}
void dfs(int node,int fa){
	ans = min(ans,sum[node]);
	for (auto e : arr[node]){
		auto [nxt,val] = e;
		if (nxt!=fa){
			int last_cntnode = cnt[node];
			int last_cntnxt = cnt[nxt];
			int last_sumnode = sum[node];
			int last_sumnxt = sum[nxt];
			cnt[node] -= cnt[nxt];
			sum[node] -= sum[nxt] + cnt[nxt]*val;
			cnt[nxt] += cnt[node];
			sum[nxt] += sum[node] + cnt[node]*val;
			dfs(nxt,node);
			cnt[node] = last_cntnode;
			cnt[nxt] = last_cntnxt;
			sum[node] = last_sumnode;
			sum[nxt] = last_sumnxt;
		}
	}
}
signed main(){
	cin >> n;
	for (int i=1;i<=n;i++) cin >> num[i];
	for (int i=1;i<=n-1;i++){
		int x,y,z;
		cin >> x >> y >> z;
		arr[x].push_back(make_pair(y,z));
		arr[y].push_back(make_pair(x,z));
	}
	pre(1,0);
	dfs(1,0);
	cout << ans << '\n';
	return 0;
}
