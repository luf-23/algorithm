#include <bits/stdc++.h>
using namespace std;
int main()
{
	int leave = 0;
	int cnt = 0;
	for (int i=1;i<=12;i++)
	{
		int cost;
		cin >> cost;
		if (300+leave<cost)
		{
			cout << '-' << i;
			return 0;
		}else{
			leave = leave + 300 - cost ;
			cnt += leave/100;
			leave %= 100;
		}
	}
	cout << leave+cnt*100*6/5;
	return 0;
}
