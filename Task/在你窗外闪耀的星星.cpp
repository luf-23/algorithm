#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll x[N];
ll sum[N];
int main()
{
	int n,w;
	cin >> n >> w;
	int a,b;
	for (int i=1;i<=n;i++)
	{
		cin >> a >> b;
		x[a] += b;
	}
	for (int i=1;i<=N;i++)
	{
		sum[i] = sum[i-1] + x[i];
	}
	ll ans = 0;
	for (int i=1;i<=N-w+1;i++)
		ans = max(ans,sum[i+w-1]-sum[i-1]);
	cout << ans << endl;
	return 0;
}
