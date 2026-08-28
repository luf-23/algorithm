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
	num[1][1] = 1;
	cnt++;
	//int flag = 1;
	j = 2;
	i = 3;
	while (cnt<=(n*n-n)/2)
	{
		//if (flag==1)
		{
			for (int q=j;q>=1;q--)
				num[j-q+1][q] = cnt++;
			j += 2;
			//flag = 0;
		}
		//if (flag==0)
		if (i!=n)
		{
			for (int p=i;p>=1;p--)
				num[p][i-p+1] = cnt++;
			i += 2;
			//flag = 1;
		}
	}
	i = 2;
	j = 1;
	//flag = 1;
	while (cnt<=n*n)
	{
		//if (flag==1)
		{
			for (int q=j;q<=n;q++)
				num[n-q+j][q] = cnt++;
			j += 2;
			//flag = 0;
		}
		//if (flag==0)
		{
			for (int p=i;p<=n;p++)
				num[p][n-p+i] = cnt++;
			i += 2;
			//flag = 1;
		}
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
