#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	cin >> x;
	vector<int>num;
	num.push_back(x);
	while (x!=1)
	{
		if (x%2==1)
		{
			x = 3*x+1;
			num.push_back(x);
		}else{
			x /= 2;
			num.push_back(x);
		}
	}
	for (int i=num.size()-1;i>=0;i--)
	{
		cout << num[i] << ' ';
	}
	return 0;
}
