#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	if (n==0)
	{
		cout << 0;
	}
	int flag = 1;
	if (n<0)
	{
		flag = 0;
	}
	n = fabs(n);
	if (flag==0)
	{
		cout << '-';
	}
	int fg = 0;
	while (n>0)
	{
		int x = n%10;
		if (x!=0)
		{
			fg = 1;
		}
		n /= 10;
		if (fg==1)
		{
			cout << x;
		}
	}
	return 0;
}
