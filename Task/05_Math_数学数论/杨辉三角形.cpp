#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num[40][40];
	memset(num,0,sizeof(num));
	int n;
	cin >> n;
	for (int i=1;i<=n;i++)
		num[i][1] = 1;
	for (int i=1;i<=n;i++)
		num[i][i] = 1;
	for (int i=2;i<=n;i++)
	{
		for (int j=2;j<i;j++)
		{
			num[i][j] = num[i-1][j] + num[i-1][j-1];
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n-i;j++)
			cout << "     ";
		for (int j=1;j<=i;j++)
		{
			cout << setw(10) << num[i][j];
		}
		if (i<n) cout << endl;
	}
	return 0;
}
