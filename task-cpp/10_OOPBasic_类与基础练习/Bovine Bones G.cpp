#include <bits/stdc++.h>
using namespace std;
int main()
{
	int BOOL[10000] = {0};
	int i,j,k;
	int a,b,c;
	cin >> a >> b >> c;
	int maxx = 0;
	for (i=1;i<=a;i++)
	{
		for (j=1;j<=b;j++)
		{
			for (k=1;k<=c;k++)
			{
				BOOL[i+j+k]++;
				if (BOOL[i+j+k]>maxx)
				{
					maxx = BOOL[i+j+k];
				}
			}
		}
	}
	int ret;
	for (i=0;i<10000;i++)
	{
		if (BOOL[i]==maxx)
		{
			ret = i;
			break;
		}
	}
	cout << ret;
	return 0;
}
