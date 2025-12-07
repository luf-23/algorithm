#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num[3];
	int a;
	cin >> a;
	for (int i=2;i>=0;i--)
	{
		num[i] = a%10;
		a /= 10;
	}
	int cnt = 1;
	sort(num+0,num+3);
	while (num[0]!=4||num[1]!=9||num[2]!=5)
	{
		sort(num+0,num+3);
		int max,min;
		max = num[2]*100+num[1]*10+num[0];
		min = num[0]*100+num[1]*10+num[2];
		int x =  max - min;
		printf("%d: %d - %d = %d\n",cnt,max,min,x);
		for (int i=2;i>=0;i--)
		{
			num[i] = x%10;
			x /= 10;
		}
		cnt++;
	}
	return 0;
}
