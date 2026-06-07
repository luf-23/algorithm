#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>arr[2000];
vector<int>val[2000];
int ans[2000];
int in[2000];
signed main(){
	cin >> n >> m;
	for (int i=2;i<=n;i++) ans[i] = -1e9;
	for (int i=1;i<=m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		arr[x].push_back(y);
		val[x].push_back(z);
		in[y]++;
	}
	queue<int>q;
	for (int i=2;i<=n;i++) if (in[i]==0) q.push(i);
	while (!q.empty()){
		int node = q.front();
		q.pop();
		for (auto ele : arr[node]){
			if (!(--in[ele])) q.push(ele);
		}
	}
	q.push(1);
	while (!q.empty()){
		int node = q.front();
		q.pop();
		for (int i=0;i<arr[node].size();i++){
			if (ans[arr[node][i]]<ans[node]+val[node][i]) ans[arr[node][i]] = ans[node] + val[node][i];
			if (!(--in[arr[node][i]])) q.push(arr[node][i]);
		}
	}
	if (ans[n]==-1e9) cout << "-1";
	else cout << ans[n];
	return 0;
}

