#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[400005];
int n,l,r;
int num[400005];
signed main(){
	cin >> n >> l >> r;
	for (int i=0;i<=n;i++) cin >> num[i];
	dp[0] = 0;
	priority_queue<int>pq;
	map<int,int>mp;
	for (int i=1;i<=n+r+1;i++) dp[i] = -INT_MAX;
	for (int i=l;i<=n+r+1;i++){
		mp[dp[i-l]]++;
		pq.push(dp[i-l]);
		if (i-r-1>=0) mp[dp[i-r-1]]--;
		while (!pq.empty()&&mp[pq.top()]==0) pq.pop();
		dp[i] = pq.top() + num[i];
	}
	int ans = -INT_MAX;
	for (int i=n+1;i<=n+r;i++) ans = max(ans,dp[i]);
	cout << ans;
	return 0;
}
