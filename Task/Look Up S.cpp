#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int h[n+1];
	for (int i=1;i<=n;i++)
		cin >> h[i];
	int ans[n+1];
	ans[n] = 0;
	int j;
	for (int i=n-1;i>=1;i--)
	{
		j = i + 1;
		while (h[i]>=h[j]&&j>0) j = ans[j];
		ans[i] = j;
	}
	for (int i=1;i<=n;i++)
		cout << ans[i] << '\n';
	return 0;
}
