#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>u(100005);
vector<int>v(100005);
vector<int>du(10005);
int main()
{
	cin >> n >> m;
	for (int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		u[i] = x;
		v[i] = y;
		du[u[i]]++;
		du[v[i]]++;
	}
	long long ans = 0;
	for (int i=1;i<=m;i++){
		if (du[u[i]]>1&&du[v[i]]>1){
			ans += (du[u[i]]-1)*(du[v[i]]-1)*2;
		}
	}
	cout << ans;
	return 0;
}
