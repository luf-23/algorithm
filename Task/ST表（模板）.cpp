#include <bits/stdc++.h>
using namespace std;
int ans[100005][25];
int n,m;
int num[100005];
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> num[i];
	for (int i=1;i<=n;i++) ans[i][0] = num[i];
	for (int j=1;j<=18;j++){
		for (int i=1;i+(1<<j)-1<=n;i++){
			ans[i][j] = max(ans[i][j-1],ans[i+(1<<(j-1))][j-1]);
		}
	}
	for (int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		int t = log2(y-x+1);
		cout << max(ans[x][t],ans[y-(1<<t)+1][t]) << '\n';
	}
	return 0;
}
