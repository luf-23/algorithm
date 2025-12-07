#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,p;
	cin >> n >> p;
	int score[n+1];
	score[0] = 0;
	int d[n+10] = {0};
	for (int i=1;i<=n;i++)
	{
		cin >> score[i];
	}
	int x,y,z;
	for (int i=1;i<=n;i++)
	{
		d[i] = score[i] - score[i-1];
	}
	for (int i=1;i<=p;i++)
	{
		cin >> x >> y >> z;
		d[x] += z;
		d[y+1] -= z;
	}
	int min_v = 110;
	for (int i=1;i<=n;i++)
	{
		score[i] = score[i-1] + d[i];
		if (min_v>score[i])
		{
			min_v = score[i];
		}
	}
	cout << min_v;
	return 0;
}
