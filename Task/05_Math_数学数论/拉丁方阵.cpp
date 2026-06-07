#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int num[n+1][n+1];
	int pos[n+1];
	int k = 1;
	memset(num,0,sizeof(num));
	for (int i=1;i<=n;i++)
	{
		cin >> num[1][i];
		pos[num[1][i]] = i;
	}
	int arr[n+1];
	for (int i=1;i<=n;i++)
	{
		k = 1;
		arr[k] = pos[i];
		k++;
		int p;
		for (int j=1;j<=n;j++)
		{
			if (num[1][j]==pos[i])
			{
				p = j;
				break;
			}
		}
		for (int j=1;j<=n-1;j++)
		{
			p++;
			while (p>n) p -= n;
			arr[k] = num[1][p];
			k++;
		}
		for (int j=1;j<=n;j++)
			num[j][arr[j]] = i;
		for (int j=1;j<=n;j++)
			arr[j] = 0;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (j<n) cout << num[i][j] << ' ';
			else cout << num[i][j];
		}
		if (i<n) cout << endl;
	}
	return 0;
}
