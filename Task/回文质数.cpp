#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i;
	int a,b;
	cin >> a >> b;
	vector<int>Num;
	for (i=a;i<=b;i++)
	{
		int num[15];
		int x = i;
		int cnt = 0;
		while (x>0)
		{
			num[cnt] = x%10;
			x /= 10;
			cnt++;
		}
		int j;
		int ishuiwen = 1;
		for (j=0;j<cnt;j++)
		{
			if (num[j]!=num[cnt-1-j])
			{
				ishuiwen = 0;
				break;
			}
		}
		if (ishuiwen==1)
		{
			if (i%2==1)
			{
				Num.push_back(i);
			}
		}
	}
	//cout << Num.size() << endl;
	for (i=0;i<Num.size();i++)
	{
		int isPrime = 1;
		int k;
		for (k=2;k<=sqrt(Num[i]);k++)
		{
			if (Num[i]%k==0)
			{
				isPrime = 0;
				break;
			}
		}
		if (isPrime==1)
		{
			cout << Num[i] << endl;
		}
	}
	return 0;
}
