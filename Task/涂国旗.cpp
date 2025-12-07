#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> m >> n;
	char x[60][60];
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			cin >> x[i][j];
	int cnt[1300] = {0};
	int count = 0;
	for (int i=1;i<=m-1;i++)
	{
		for (int j=i+1;j<=m-1;j++)
		{
			for (int k=1;k<=i;k++)
			{
				for (int h=1;h<=n;h++)
				{
					if (x[k][h]!='W') cnt[count]++;
				}
			}
			for (int k=i+1;k<=j;k++)
			{
				for (int h=1;h<=n;h++)
				{
					if (x[k][h]!='B') cnt[count]++;
				}
			}
			for (int k=j+1;k<=m;k++)
			{
				for (int h=1;h<=n;h++)
				{
					if (x[k][h]!='R') cnt[count]++;
				}
			}
			count++;
		}
	}
	sort(cnt,cnt+count);
	cout << cnt[0] << endl;
	return 0;
}
