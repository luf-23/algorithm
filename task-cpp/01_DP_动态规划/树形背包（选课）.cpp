#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
vector<int>arr[305];
int num[305];
int dp[305][305];//以node作为根节点，选了m个之后的最大值（注意只能选了根节点才能选子节点，所以k从1开始
void dfs(int node,int fa){
	dp[node][1] = num[node];
	for (auto e : arr[node]){
		if (e!=fa){
			dfs(e,node);
			for (int j=m;j>=0;j--){
				for (int k=1;k<=j;k++){
					dp[node][j] = max(dp[node][j],dp[node][k]+dp[e][j-k]);
				}
			}
		}
	}
}
signed main(){
	cin >> n >> m;
	m++;
	for (int i=1;i<=n;i++){
		int x,y;
		cin >> x >> y;
		arr[x].push_back(i);
		arr[i].push_back(x);
		num[i] = y;
	}
	dfs(0,-1);
	//	for (int i=0;i<=n;i++){
	//		for (int j=0;j<=m;j++){
	//			cout << dp[i][j] << ' ';
	//		}
	//		cout << '\n';
	//	}
	cout << dp[0][m];
	return 0;
}
