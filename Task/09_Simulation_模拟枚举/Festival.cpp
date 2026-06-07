#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	int n,m;
	cin >> n >> m;
	int x;
	queue<int>pos;
	for (int i=1;i<=m;i++)
	{
		cin >> x;
		pos.push(x);
	}
	for (int i=1;i<=n;i++)
	{
		cout << pos.front()-i << endl;
		if (i==pos.front()) pos.pop();
	}
	return 0;
}
