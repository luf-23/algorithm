#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int rit[7];
	int i;
	for (i=0;i<7;i++)
	{
		cin >> rit[i];
	}
	int s = 0;
	int num[8] = {0};
	while (s<n)
	{
		int z = 0;
		int cnt = 0;
		while (z<7)
		{
			int q;
			cin >> q;
			for (i=0;i<7;i++)
			{
				if (q==rit[i])
				{
					cnt++;
					break;
				}
			}
			z++;
		}
		num[7-cnt]++;
		s++;
	}
	for (i=0;i<7;i++)
	{
		cout << num[i] << ' ';
	}
	return 0;
}
