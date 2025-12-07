#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	char x[10010];
	char X;
	int BOOL[120][120];
	char a[120][120];
	memset(BOOL,0,sizeof(BOOL));
	int i,j = 0;
	while ((X=getchar())!=EOF)
	{
		if (X!='\n')
		{
			x[j++] = X;
		}
	}
	int cnt = 0;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			a[i][j] = x[cnt++];
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (a[i][j]=='*')
			{
				BOOL[i-1][j]++;
				BOOL[i+1][j]++;
				BOOL[i][j-1]++;
				BOOL[i][j+1]++;
				BOOL[i-1][j-1]++;
				BOOL[i-1][j+1]++;
				BOOL[i+1][j-1]++;
				BOOL[i+1][j+1]++;
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (a[i][j]=='*')
			{
				cout << a[i][j];
			}else{
				cout << BOOL[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}
