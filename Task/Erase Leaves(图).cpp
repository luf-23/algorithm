#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
vector<int>arr[300005];
int vis[300005];
void dfs(int node){
	//cout << node << endl;
	for (int i=0;i<arr[node].size();i++){
		if (!vis[arr[node][i]]&&arr[node][i]!=node){
			vis[arr[node][i]] = 1;
			cnt++;
			dfs(arr[node][i]);
		}
	}
}
int main()
{
	cin >> n;
	for (int i=1;i<=n-1;i++){
		int x,y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	vector<int>ans;
	vis[1] = 1;
	for (int i=0;i<arr[1].size();i++){
		cnt = 1;
		vis[arr[1][i]] = 1;
		dfs(arr[1][i]);
		//cout << "cnt=" << cnt << endl;
		ans.push_back(cnt);
	}
	sort(ans.begin(),ans.end());
	int ret = 0;
	for (int i=0;i<ans.size();i++){
		ret += ans[i];
	}
	if (ans.size()>1){
		ret -= ans[ans.size()-1];
		ret++;
	}else{
		ret = 1;
	}
	cout << ret;
	return 0;
}
