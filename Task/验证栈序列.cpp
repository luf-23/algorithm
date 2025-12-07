#include <bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		int num[n+1];
		int ck[n+1];
		for (int i=1;i<=n;i++)
			cin >> num[i];
		for (int i=1;i<=n;i++)
			cin >> ck[i];
		stack<int>stk;
		int j =1;
		for (int i=1;i<=n;i++)
		{
			stk.push(num[i]);
			while (stk.top()==ck[j])
			{
				stk.pop();
				j++;
				if (stk.empty()) break;
			}
		}
		if (!stk.empty()) cout << "No" << '\n';
		else cout << "Yes" << '\n';
	}
	return 0;
}
