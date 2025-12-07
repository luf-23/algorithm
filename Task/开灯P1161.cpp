#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	int BOOL[1000000] = {0};
	while (cnt<n)
	{
		double a;
		int t;
		cin >> a >> t;
		int i;
		for (i=1;i<=t;i++)
		{
			if (BOOL[(int)(i*a)]==0)
			{
				BOOL[(int)(i*a)] = 1;
			}else if (BOOL[(int)(i*a)]==1){
				BOOL[(int)(i*a)] = 0;
			}
		}
		cnt++;
	}
	int j;
	for (j=1;j<=1000000;j++)
	{
		if (BOOL[j]==1)
		{
			cout << j;
			break;
		}
	}
	return 0;
}
