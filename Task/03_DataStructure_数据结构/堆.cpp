#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ll n;
	cin >> n;
	priority_queue<ll,vector<ll>,greater<ll>> q;
	int op;
	while (n--)
	{
		cin >> op;
		if (op==1)
		{
			ll x;
			cin >> x;
			q.push(x);
		}else if (op==2)
		{
			cout << q.top() << endl;
		}else if (op==3)
		{
			q.pop();
		}
	}
	return 0;
}
