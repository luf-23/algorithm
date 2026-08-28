#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int m,n,c;
	cin >> m >> n >> c;
	int num[m+1][n+1];
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			cin >> num[i][j];
	ll sum[m+1][n+1];
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+num[i][j];
	ll max_v = -1e9;
	ll x,y;
	for (int i=c;i<=m;i++)
	{
		for (int j=c;j<=n;j++)
		{
			if (sum[i][j]-sum[i-c][j]-sum[i][j-c]+sum[i-c][j-c]>max_v)
			{
				max_v = sum[i][j]-sum[i-c][j]-sum[i][j-c]+sum[i-c][j-c];
				x = i;
				y = j;
			}
		}
	}
	x = x-c+1;
	y = y-c+1;
	cout << x << ' ' << y;
	return 0;
}
