#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	cin >> k;
	int sum = 0;
	int ret = 1;
	for (int i=1;i<=k;i++)
	{
		k -= i;
		sum += ret*ret;
		ret++;
	}
	sum += ret*k;
	cout << sum;
	return 0;
}
