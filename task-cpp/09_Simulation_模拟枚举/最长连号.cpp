#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int>num;
	int n;
	cin >> n;
	int cnt = 0;
	int a[10000];
	while (cnt<n)
	{
		cin >> a[cnt];
		cnt++;
	}
	int i;
	int count = 1;
	for (i=1;i<cnt;i++)
	{
		if (a[i]==a[i-1]+1)
		{
			count++;
		}else{
			num.push_back(count);
			count = 1;
		}
	}
	if (count!=1)
	{
		num.push_back(count);
	}
	int max_v = 0;
	for (i=0;i<num.size();i++)
	{
		if (num[i]>max_v)
		{
			max_v = num[i];
		}
	}
	cout << max_v;
	return 0;
}
