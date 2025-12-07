#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll m,n;
	cin >> m >> n;
	ll sch[1002000];
	ll sco[1002000];
	for (int i=1;i<=m;i++)
		cin >> sch[i];
	sort(sch+1,sch+m+1);
	for (int i=1;i<=n;i++)
		cin >> sco[i];
	ll sum = 0;
	for (int i=1;i<=n;i++)
	{
		ll pos = lower_bound(sch+1,sch+m+1,sco[i]) - sch;
		if (pos==m+1)
		{
			sum += sco[i] - sch[m];
		}else if (pos==1){
			sum += sch[1] - sco[i];
		}else{
			ll x = abs(sch[pos]-sco[i]);
			ll y = abs(sch[pos-1]-sco[i]);
			sum += min(x,y);
		}
	}
	cout << sum;
	return 0;
}
