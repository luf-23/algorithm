#include <bits/stdc++.h>
using namespace std;
using ll = long long;
set<ll>st;
void dfs(ll x,ll t)
{
	if (t>10000000000) return;
	t = t*10 + x;
	dfs(7,t);
	st.insert(t);
	dfs(4,t);
	t = t*10 + x;
	st.insert(t);
}
int main()
{
	dfs(4,0);
	dfs(7,0);
	ll l,r;
	cin >> l >> r;
	ll cnt = 0;
	ll ans = 0;
	for (auto it=st.begin();it!=st.end();++it){
		cout << *it << ' ';
		//while (*it>=l){
		//	ans += *it;
		//	l++;
		//	if (l==r+1){
		//		cout << ans;
		//		exit(0);
		//	}
		//}
	}
	return 0;
}
