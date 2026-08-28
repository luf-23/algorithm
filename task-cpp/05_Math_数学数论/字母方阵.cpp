#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	char x[n+1][n+1];
	int cnt = 0;
	int flag = 1;
	int i,j;
	i = 1;
	j = n;
	while (cnt<n*n)
	{
		if (flag==1)
		{
			for (int p=1;p<=n;p++)
			{
				x[p][j] = 'a'+cnt%26;
				cnt++;
			}
			flag = 0;
			j--;
		}
		if (flag==0)
		{
			for (int p=n;p>=1;p--)
			{
				x[p][j] = 'a'+cnt%26;
				cnt++;
			}
			flag = 1;
			j--;
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<n;j++)
		{
			cout << x[i][j] << ' ';
		}
		cout << x[i][n] << endl;
	}
	return 0;
}
