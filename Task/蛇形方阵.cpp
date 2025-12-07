#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int num[n+1][n+1];
	//memset(num,0,sizeof(num));
	int x = 0;
	int i,j;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			num[i][j] = 0;
		}
	}
	i = 1;
	j = 0;
	while (x<=n*n)
	{
		while (j<n&&!num[i][j+1])
		{
			x += 1;
			num[i][j+1] = x;
			//cout << num[i][j+1] << ' ';
			j++;
		}
		while (i<n&&!num[i+1][j])
		{
			x += 1;
			num[i+1][j] = x;
			//cout << num[i+1][j] << ' ';
			i++;
		}
		while (j>1&&!num[i][j-1])
		{
			x += 1;
			num[i][j-1] = x;
			//cout << num[i][j-1] << ' '; 
			j--;
		}
		while (i>1&&!num[i-1][j])
		{
			x += 1;
			num[i-1][j] = x;
			//cout << num[i-1][j] << ' ';
			i--;
		}
		if (x==n*n)
		{
			break;
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			printf("%3d",num[i][j]);
		}
		printf("\n");
	}
	return 0;
}
