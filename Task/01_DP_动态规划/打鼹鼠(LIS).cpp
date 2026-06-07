#include<bits/stdc++.h>
using namespace std;
int dp[10005];
//以i号鼹鼠结尾时抓到的鼹鼠最多的个数
int n,m;
struct Node{
	int t,x,y;
};
signed main(){
	cin >> n >> m;
	Node node[m+1];
	for (int i=1;i<=m;i++){
		cin >> node[i].t >> node[i].x >> node[i].y;
	}
	for (int i=1;i<=m;i++) dp[i] = 1;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=i-1;j++){
			int dist = abs(node[i].x-node[j].x) + abs(node[i].y-node[j].y);
			int t = node[i].t - node[j].t;
			if (t>=dist) dp[i] = max(dp[i],dp[j]+1);
		}
	}
	int ans = 1;
	for (int i=1;i<=m;i++) ans = max(ans,dp[i]);
	cout << ans;
	return 0;
}
