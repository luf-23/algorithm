#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int num[n];
	int i;
	for (i=0;i<n;i++)
	{
		cin >> num[i];
	}
	int j;
	for (i=0;i<n;i++)
	{
		int cnt = 0;
		for (j=0;j<i;j++)
		{
			if (num[i]>num[j])
			{
				cnt++;
			}
		}
		cout << cnt << ' ';
	}
	return 0;
}
