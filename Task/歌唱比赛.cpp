#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	float ave[n];
	int i,j;
	for (i=0;i<n;i++)
	{
		int max_v = 0;
		int min_v = 10;
		float average = 0;
		for (j=0;j<m;j++)
		{
			int x;
			cin >> x;
			if (x>max_v)
			{
				max_v = x;
			}
			if (x<min_v)
			{
				min_v = x;
			}
			average += x;
		}
		average = (average-max_v-min_v)/(m-2.0);
		ave[i] = average;
	}
	sort(ave+0,ave+n);
	cout << fixed << setprecision(2) << ave[n-1];
}
