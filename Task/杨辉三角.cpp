#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n+1][n+1];
	memset(a,0,sizeof(a));
	int i,j;
	for (i=1;i<=n;i++)
	{
		a[i][1] = 1;
		a[i][i] = 1;
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=i;j++)
		{
			if (a[i][j]!=1)
			{
				a[i][j] = a[i-1][j]+a[i-1][j-1];
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=i;j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
