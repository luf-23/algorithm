#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int num[n+1];
	for (int i=1;i<=n;i++)
		cin >> num[i];
	int sum = 0;
	sum += num[1];
	for (int i=2;i<=n;i++)
		if (num[i]>num[i-1]) sum += num[i]-num[i-1];
	cout << sum;
	return 0;
}
