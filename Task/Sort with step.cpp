#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,k;
		cin >> n >> k;
		int cnt = 0;
		int x;
		for (int i=1;i<=n;i++)
		{
			cin >> x;
			if (x!=i&&(x-i)%k!=0) cnt++;
		}
		if (cnt==0) cout << 0 << endl;
		else if (cnt==2) cout << 1 << endl;
		else cout << -1 << endl;
	}
	return 0;
}
