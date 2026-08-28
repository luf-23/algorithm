#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int num[n+1][n+1];
	memset(num,0,sizeof(num));
	int d[n+10][n+10];
	memset(d,0,sizeof(d));
	int x1,y1,x2,y2;
	for (int i=1;i<=m;i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j=x1;j<=x2;j++)
		{
			d[j][y1] += 1;
			d[j][y2+1] -= 1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			num[i][j] = num[i][j-1] + d[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cout << num[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
