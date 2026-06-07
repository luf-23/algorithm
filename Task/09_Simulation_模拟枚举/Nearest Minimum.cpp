#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n;
	cin >> n;
	ll num[n];
	ll min_v = 1e9;
	ll dis = 1e9;
	for (int i=0;i<n;i++)
	{
		cin >> num[i];
		if (min_v>num[i]) min_v = num[i];
	}
	ll weizhi[n];
	int cnt = 0;
	for (int i=0;i<n;i++)
	{
		if (num[i]==min_v) weizhi[cnt++] = i;
	}
	for (int i=1;i<cnt;i++)
	{
		if (dis>(weizhi[i]-weizhi[i-1]))
		{
			dis = weizhi[i] - weizhi[i-1];
		}
	}
	cout << dis;
	return 0;
}
