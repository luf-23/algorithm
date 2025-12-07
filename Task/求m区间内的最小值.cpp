#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n,m;
	cin >> n >> m;
	int num[n+1];
	for (int i=1;i<=n;i++)
		cin >> num[i];
	deque<int> dq;
	cout << 0 << '\n';
	for (int i=1;i<=n-1;i++)
	{
		while (!dq.empty()&&dq.front()<=i-m) dq.pop_front();
		while (!dq.empty()&&num[i]<=num[dq.back()]) dq.pop_back();
		dq.push_back(i);
		cout << num[dq.front()] << '\n';
	}
	return 0;
}
