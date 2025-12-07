#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int num[n+1][n+1];
	memset(num,0,sizeof(num));
	int i,j;
	int cnt = 1;
	i = 1;
	num[1][1] = 1;
	cnt++;
	while (cnt<=(n*n-n)/2)
	{
		i++;
		for (int p=i;p>=1;p--)
			num[p][i-p+1] = cnt++;
	}
	j = 1;
	while (cnt<=n*n)
	{
		for (int q=j;q<=n;q++)
			num[n-q+j][q] = cnt++;
		j++;
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			printf("%5d",num[i][j]);
		}
		printf("\n");
	}
	return 0;
}
