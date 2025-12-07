#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int num[n+1][n+1];
	memset(num,0,sizeof(num));
	int cnt = 1;
	int max_v = (n*n+n)/2;
	num[n][1] = cnt;
	cnt++;
	int i,j;
	i = n;
	j = 1;
	while (cnt<=max_v)
	{
		i--;
		j = 1;
		for (int p=i;p<=n;p++)
			num[p][p-i+1] = cnt++;
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=i;j++)
		{
			printf("%5d",num[i][j]);
		}
		printf("\n");
	}
	return 0;
}
