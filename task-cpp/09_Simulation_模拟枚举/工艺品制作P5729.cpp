#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	int n;
	cin >> n;
	int BOOL[a+1][b+1][c+1];
	int i,j,k;
	for (i=0;i<=a;i++)
	{
		for (j=0;j<=b;j++)
		{
			for (k=0;k<=c;k++)
			{
				BOOL[i][j][k] = 1;
			}
		}
	}
	int cnt = 0;
	while (cnt<n)
	{
		int x1,y1,z1,x2,y2,z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		for (i=x1;i<=x2;i++)
		{
			for (j=y1;j<=y2;j++)
			{
				for (k=z1;k<=z2;k++)
				{
					BOOL[i][j][k] = 0;
				}
			}
		}
		cnt++;
	}
	int ret = 0;
	for (i=1;i<=a;i++)
	{
		for (j=1;j<=b;j++)
		{
			for (k=1;k<=c;k++)
			{
				if (BOOL[i][j][k]==1)
				{
					ret++;
				}
			}
		}
	}
	cout << ret;
	return 0;
}
