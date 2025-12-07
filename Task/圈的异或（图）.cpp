#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>arr[60];
bool vis[60];
int n,m;
bool check(int self,int val,int node)
{
	for (int i=0;i<arr[node].size();i++){
		int nxt = arr[node][i].first;
		int v = arr[node][i].second;
		if (nxt==self&&(val^v)!=0) return false;
		if (vis[nxt]) continue;
		vis[nxt] = true;
		if (!check(self,v^val,nxt)) return false;
	}
	return true;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		for (int i=0;i<60;i++) arr[i].clear();
		cin >> n >> m;
		for (int i=1;i<=m;i++){
			int x,y,val;
			cin >> x >> y >> val;
			arr[x].push_back(make_pair(y,val));
			arr[y].push_back(make_pair(x,val));
		}
		bool flag = true;
		for (int i=1;i<=n;i++){
			memset(vis,false,sizeof(vis));
			vis[i] = true;
			if (!check(i,0,i)) flag = 0;
			if (!flag) break;
		}
		if (flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
