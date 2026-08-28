#include <bits/stdc++.h>
using namespace std;
int num[12];
int u[20];
int v[20];
int m,n;
int ans;
void dfs(int step)
{
	if (step==m+1){
		int cnt = 0;
		for (int i=2;i<=n;i++){
			if (num[i]>num[1]) cnt++;
		}
		ans = min(ans,cnt+1);
		return;
	}
	num[u[step]] += 3;
	dfs(step+1);
	num[u[step]] -= 3;
	num[v[step]] += 3;
	dfs(step+1);
	num[v[step]] -= 3;
	num[u[step]]++;
	num[v[step]]++;
	dfs(step+1);
	num[u[step]]--;
	num[v[step]]--;
}
int main()
{
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i=1;i<=n;i++) cin >> num[i];
		for (int i=1;i<=m;i++){
			cin >> u[i] >> v[i];
		}
		ans = n;
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}
