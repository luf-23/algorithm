#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int sum = 0;
	int x,k;
	int flag = 0;
	for (k=1;;k++)
	{
		for (x=100;x>=1;x--)
		{
			for (int j=1;j<=7;j++)
			{
				sum += 52*(x+k*(j-1));
			}
			if (sum==n)
			{
				flag = 1;
				break;
			}else{
				sum = 0;
			}
		}
		if (flag==1)
		{
			break;
		}
	}
	cout << x << endl << k;
	return 0;
}
