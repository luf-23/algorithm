#include <bits/stdc++.h>
using namespace std;
int main()
{
	//正方形数min(i,j)，矩形数量i*j
	int n,m;
	cin >> n >> m;
	long long sum1 = 0;
	long long sum = 0;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			sum1 += min(i,j);
			sum += i*j;
		}
	}
	cout << sum1 << ' ' << sum-sum1 << endl;
	return 0;
}
