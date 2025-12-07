#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll>arr;
void dfs(ll num,ll e)
{
	if (num==-1) return;
	dfs(num-1,e);
	e = e*10 + num;
	arr.push_back(e);
	dfs(num-1,e);
}
int main()
{
	ll n;
	cin >> n;
	dfs(9,0);
	sort(arr.begin(),arr.end());
	for (auto ele:arr) cout << ele << ' ';
	cout << endl;
	cout << arr[n];
	return 0;
}

