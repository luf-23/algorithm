#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int t[n+1];
	int ans[n+1] = {0};
	stack<int> stk;
	for (int i=1;i<=n;i++)
	{
		cin >> t[i];
	}
	for (int i=1;i<=n;i++)
	{
		while (!stk.empty()&&t[i]>t[stk.top()])
		{
			ans[stk.top()] = i - stk.top();
			stk.pop();
		}
		stk.push(i);
	}
	for (int i=1;i<=n;i++)
		cout << ans[i] << ' ';
	cout << endl;
	int ret = 0;
	for (int i=1;i<=n;i++)
		ret = max(ret,ans[i]);
	cout << ret << endl;
	return 0;
}
