#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int num[n][n];
	memset(num,0,sizeof(num));
	int flag = 0;
	int i,j;
	int x;
	cin >> x;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (x>0)
			{
				if (!flag)
				{
					num[i][j] = 0;
					x--;
				}else{
					num[i][j] = 1;
					x--;
				}
			}else{
				flag = !flag;
				cin >> x;
				//i--;
				//j--;
				if (!flag)
				{
					num[i][j] = 0;
					x--;
				}else{
					num[i][j] = 1;
					x--;
				}
			}
		}
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			cout << num[i][j];
		}
		cout << endl;
	}
	return 0;
}
