#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int cnt = 0;
	int vis[n+1] = {0};
	for (int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		vis[y] = 1;
	}
	int ans = 0;
	for (int i=1;i<=n;i++){
		if (!vis[i]){
			cnt++;
			ans = i;
		}
		if (cnt==2){
			cout << -1;
			exit(0);
		} 
	}
	cout << ans;
	return 0;
}
