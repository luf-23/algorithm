#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int num[n+1][n+1];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin >> num[i][j];
	int a[n+1];
	for (int i=1;i<=n;i++)
		a[i] = num[i][1];
	memset(a,0,sizeof(a));
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			a[i] |= num[i][j];
			a[j] |= num[i][j];
		}
	}
	for (int i=1;i<=n;i++)
		cout << a[i] << ' ';
	return 0;
}
