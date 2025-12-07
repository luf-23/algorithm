#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n+1],b[n+1],pre[n+1];
		for (int i=1;i<=n;i++) cin >> a[i];
		for (int i=1;i<=n;i++) cin >> b[i];
		int vis[n+1],dp[n+1];
		pre[0] = 0;
		vector<pair<int,int>>arr[n+1];
		for (int i=1;i<=n;i++){
			vis[i] = 0;
			pre[i] = pre[i-1] + a[i];
			dp[i] = LONG_LONG_MAX-1e10;
		}
		for (int i=1;i<=n;i++){
			arr[i].push_back(make_pair(b[i],a[i]));
			if (i!=1) arr[i].push_back(make_pair(i-1,0));
		}
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
		dp[1] = 0;
		pq.push(make_pair(0,1));
		while (!pq.empty()){
			auto [val,node] = pq.top();
			pq.pop();
			if (vis[node]) continue;
			vis[node] = 1;
			for (auto [nxt,cost] : arr[node]){
				if (dp[nxt]>dp[node]+cost){
					dp[nxt] = dp[node] + cost;
					pq.push(make_pair(dp[nxt],nxt));
				}
			}
		}
		int ans = 0;
		for (int i=1;i<=n;i++){
			ans = max(ans,pre[i]-dp[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}
