#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n;
	cin >> n;
	int y = n;
	ll cost = 0;
	priority_queue <ll,vector<ll>,greater<ll>> pq;
	while (y--)
	{
		ll x;
		cin >> x; 
		pq.push(x);
	}
	for (int i=1;i<=n-1;i++)
	{
		ll a,b;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		pq.push(a+b);
		cost += a+b;
	}
	cout << cost;
	return 0;
}
