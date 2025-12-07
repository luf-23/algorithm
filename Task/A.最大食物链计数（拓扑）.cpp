#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int>arr[5005];
int n,m;
int in[5005];
int out[5005];
int mod = 80112002;
int ans[5005];
signed main(){
	cin >> n >> m;
	for (int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		in[y]++;
		out[x]++;
		arr[x].push_back(y);
	}
	queue<int>q;
	for (int i=1;i<=n;i++){
		if (in[i]==0){
			ans[i] = 1;
			q.push(i);
		}
	}
	while (!q.empty()){
		int now = q.front();
		q.pop();
		for (auto ele : arr[now]){
			ans[ele] = (ans[ele] + ans[now])%mod;
			in[ele]--;
			if (in[ele]==0) q.push(ele);
		}
	}
	int ret = 0;
	for (int i=1;i<=n;i++){
		if (out[i]==0){
			ret = (ret+ans[i])%mod;
		}
	}
	cout << ret;
	return 0;
}
