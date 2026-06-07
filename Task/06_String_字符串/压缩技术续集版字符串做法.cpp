#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a[220];
	cin >> a[0];
	int n = a[0].length();
	int i;
	for (i=1;i<n;i++)
	{
		cin >> a[i];
	}
	cout << n << ' ';
	int j;
	int cnt = 0;
	char flag = '0';
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (a[i][j]!=flag)
			{
				cout << cnt << ' ';
				if (flag=='0')
				{
					flag = '1';
				}else{
					flag = '0';
				}
				cnt = 1;
			}else{
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
