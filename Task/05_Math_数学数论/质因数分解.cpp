#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int i;
	for (i=2;i<n;i++)
	{
		if (n%i==0)
		{
			cout << n/i;
			break;
		}
	}
	return 0;
}
