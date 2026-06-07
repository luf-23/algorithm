#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	double sum = 0;
	double x,y;
	double zxf = 0;
	for (int i=0;i<n;i++)
	{
		cin >> x >> y;
		sum += x*y;
		zxf = y;
	}
	double ret = sum/zxf;
	cout << ret;
}
