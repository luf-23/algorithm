#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int num[n];
	int i,j,k;
	for (i=0;i<n;i++)
	{
		cin >> num[i];
	}
	int cnt = 0;
	sort(num+0,num+n);
	for (i=0;i<n;i++)
	{
		cout << num[i] << ' ';
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<i;j++)
		{
			for (k=i+1;k<n;k++)
			{
				if (num[k]==num[i]+num[j])
				{
					cnt++;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}

