#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int dist;
	string node;
	struct cmp{
		bool operator () (Node a,Node b){
			if (a.dist!=b.dist) return a.dist < b.dist;
			return a.node > b.node;
		};
	};
};
priority_queue<Node,vector<Node>,Node::cmp>pq;
map<string,int>dp,vis;
map<string,vector<string>>mp;
int n;
string str[2005];
int du[2005];
signed main(){
	cin >> n;
	for (int i=1;i<=n;i++) cin >> str[i];
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if (str[j].find(str[i])==0){
				mp[str[i]].push_back(str[j]);
				du[j]++;
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (!du[i]){
			dp[str[i]] = 1;
			pq.push({1,str[i]});
		}
	}
	while (!pq.empty()){
		auto [dist,node] = pq.top();
		pq.pop();
		if (vis[node]) continue;
		vis[node] = 1;
		for (auto e : mp[node]){
			if (dp[e]<dp[node]+1){
				dp[e] = dp[node] + 1;
				pq.push({dp[e],e});
			}
		}
	}
	int ans = 1;
	for (int i=1;i<=n;i++) ans = max(ans,dp[str[i]]);
	cout << ans << '\n';
	//	for (int i=1;i<=n;i++){
	//		if (dp[str[i]]==2) cout << str[i] << '\n';
	//	}
	return 0;
}
