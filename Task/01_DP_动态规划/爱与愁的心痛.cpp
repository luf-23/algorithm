#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int num[n];
	int i,j;
	int x = 0;
	int min_v = 1000000;
	for (i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	for (i=0;i<=n-m;i++)
	{
		x = 0;
		for (j=1;j<=m;j++)
		{
			x += num[i+j-1];
		}
		if(x<min_v)
		{
			min_v = x;
		}
	}
	printf("%d",min_v);
	return 0;
}
