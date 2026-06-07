#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int>arr[100005];
int n;
int num[100005];
int cnt[100005];
int vis[100005];
void dfs(int node)
{
	for (int i=0;i<arr[node].size();i++){
		if (!vis[arr[node][i]]){
			vis[arr[node][i]] = 1;
			dfs(arr[node][i]);
			cnt[node] += cnt[arr[node][i]]+num[arr[node][i]];
		}
	}
}
signed main()
{
	cin >> n;
	string s;
	cin >> s;
	s = ' ' + s;
	for (int i=1;i<=n;i++) num[i] = s[i]-'0';
	for (int i=1;i<=n-1;i++){
		int x,y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	vis[1] = 1;
	dfs(1);
	for (int i=1;i<=n;i++){
		cout << cnt[i] << '\n';
	}
	return 0;
}
