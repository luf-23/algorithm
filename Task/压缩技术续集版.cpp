#include <bits/stdc++.h>
using namespace std;
int main()
{
	char x[220][220] = {'0'};
	char a;
	int n = 0;
	int i,j;
	for (i=1;i<=220;i++)
	{
		a = getchar();
		if (a!='\n')
		{
			x[1][i] = a;
			n++;
		}else{
			break;
		}
	}
	for (i=2;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			cin >> x[i][j];
		}
	}
	//for (i=1;i<=n;i++)
	//{
	//	for (j=1;j<=n;j++)
	//	{
	//		cout << x[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	cout << n << ' ';
	int cnt = 0;
	char flag = '0';
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (x[i][j]==flag)
			{
				cnt++;
			}else{
				cout << cnt << ' ';
				cnt = 0;
				if (flag=='0')
				{
					flag = '1';
				}else if (flag=='1')
				{
					flag = '0';
				}
				if (x[i][j]==flag)
				{
					cnt++;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
