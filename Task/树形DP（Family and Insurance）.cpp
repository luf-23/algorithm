#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	int num[n+1];
	num[1] = 1;
	for (int i=2;i<=n;i++) cin >> num[i];
	int own[n+1] = {0};
	for (int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		own[x] = max(own[x],y+1);
	}
	int dp[n+1] = {0};
	int cnt = 0;
	for (int i=1;i<=n;i++) dp[i] = max(dp[num[i]]-1,own[i]);
	for (int i=1;i<=n;i++){
		if (dp[i]>0) cnt++;
	}
	cout << cnt;
	return 0;
}
