#include <bits/stdc++.h>
using namespace std;
int isPrime(int x)
{
	if (x==1)
	{
		return 0;
	}
	int ret = 1;
	for (int i=2;i<=sqrt(x);i++)
	{
		if (x%i==0)
		{
			ret = 0;
			break;
		}
	}
	return ret;
}
int main()
{
	int n;
	cin >> n;
	for (int i=4;i<=n;i+=2)
	{
		int p;
		for (p=2;p<i-1;p++)
		{
			if (isPrime(p)&&isPrime(i-p))
			{
				cout << i << '=' << p << '+' << i-p << endl;
				break;
			}
		}
	}
	return 0;
}
