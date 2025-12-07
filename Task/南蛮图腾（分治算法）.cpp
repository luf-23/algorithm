#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	char x[1026][1026];
	int t;
	cin >> t;
	memset(x,' ',sizeof(x));
	x[1][1] = '/';
	x[1][2] = '\\';
	x[2][1] = '/';
	x[2][2] = '_';
	x[2][3] = '_';
	x[2][4] = '\\';
	int m = 2;
	int n = 4;
	while (m<1<<t)
	{
		for (int i=m+1;i<=2*m;i++)
		{
			for (int j=1;j<=n;j++)
			{
				x[i][j] = x[i-m][j];
			}
			for (int j=n+1;j<=2*n;j++)
			{
				x[i][j] = x[i-m][j-n];
			}
		}
		m = m*2;
		n = n*2;
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=m-i;j++) cout << ' ';
		for (int j=1;j<=n;j++) cout << x[i][j];
		cout << endl;
	}
	return 0;
}
