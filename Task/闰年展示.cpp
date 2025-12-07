#include <bits/stdc++.h>
using namespace std;
int is_leap(int x)
{
	int ret = 0;
	if (x%4==0&&x%100!=0||x%400==0)
	{
		ret = 1;
	}
	return ret;
}
int main()
{
	vector<int>num;
	int x,y;
	cin >> x >> y;
	for (int i=x;i<=y;i++)
	{
		if (is_leap(i))
		{
			num.push_back(i);
		}
	}
	cout << num.size() << endl;
	for (int i=0;i<num.size();i++)
	{
		cout << num[i] << ' ';
	}
	return 0;
}
