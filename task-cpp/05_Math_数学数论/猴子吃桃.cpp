#include <bits/stdc++.h>
using namespace std;
int main()
{
	int sum = 1;
	int n;
	cin >> n;
	for (int i=0;i<n-1;i++)
	{
		sum += 1;
		sum *= 2;
	}
	cout << sum;
	return 0;
}
