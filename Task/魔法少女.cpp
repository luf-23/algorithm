#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,j;
	int n,m;
	cin >> n >> m;
	int num[n+1][n+1];
	int cnt = 1;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			num[i][j] = cnt++;
		}
	}
	int x,y,r,z;
	int p;
	int temp[n+1][n+1];
	for (p=0;p<m;p++)
	{
		cin >> x >> y >> r >> z;
		if (z==0)
		{
			for (i=x-r;i<=x+r;i++)
			{
				for (j=y-r;j<=y+r;j++)
				{
					temp[x-y+j][x+y-i] = num[i][j];
				}
			}
			for (i=x-r;i<=x+r;i++)
			{
				for (j=y-r;j<=y+r;j++)
				{
					num[i][j] = temp[i][j];
				}
			}
		}else if (z==1)
		{
			for (i=x-r;i<=x+r;i++)
			{
				for (j=y-r;j<=y+r;j++)
				{
					temp[x+y-j][y-x+i] = num[i][j];
				}
			}
			for (i=x-r;i<=x+r;i++)
			{
				for (j=y-r;j<=y+r;j++)
				{
					num[i][j] = temp[i][j];
				}
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			cout << num[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
