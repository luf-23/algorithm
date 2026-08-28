#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n,k;
	cin >> n >> k;
	ll num[n+1];
	for (int i=1;i<=n;i++)
		cin >> num[i];
	sort(num+1,num+n+1);
	set<ll>st;
	for (int i=1;i<=n;i++)
		if (num[i]%k||st.find(num[i]/k)==st.end())
			st.insert(num[i]);
	cout << st.size() << '\n';
	return 0;
}
