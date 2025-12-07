#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ll n,q;
	cin >> n >> q;
	ll num[n+1];
	ll BOOL[n+1] = {0};
	set<ll>st;
	for (int i=1;i<=n;i++)
	{
		cin >> num[i];
		if (num[i]>=n) continue;
		BOOL[num[i]]++;
	}
	for (int i=0;i<=n;i++)
	{
		if (BOOL[i]==0) st.insert(i);
	}
	while (q--)
	{
		ll pos,x;
		cin >> pos >> x;
		if (num[pos]<n)
		{
			BOOL[num[pos]]--;
			if (BOOL[num[pos]]==0) st.insert(num[pos]);
		}
		num[pos] = x;
		if (x<n)
		{
			if (BOOL[x]==0) st.erase(x);
			BOOL[x]++;
		}
		auto it = st.begin();
		cout << *it << endl;
	}
	return 0;
}
