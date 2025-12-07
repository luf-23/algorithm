#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll>HW;
vector<int>num;
int ishw(ll a)
{
	ll b = a;
	while (b>0)
	{
		num.push_back(b%10);
		b /= 10;
	}
	for (int i=0,j=num.size()-1;i<num.size(),j>=0;i++,j--)
	{
		if (num[i]!=num[j]) return 0;
	}
	return 1;
}
int main()
{
	ll x;
	cin >> x;
	ll y = x;
	vector<int>arr;
	while (y>0)
	{
		arr.push_back(y%10);
		y /= 10;
	}
	int hw = 1;
	for (int i=0,j=arr.size()-1;i<arr.size(),j>=0;i++,j--)
	{
		if (arr[i]!=arr[j]){
			hw = 0;
			break;
		}
	}
	if (hw==1)
	{
		cout << x << endl << 1;
		exit(EXIT_SUCCESS);
	}
	HW[0] = x;
	int cnt = 1;
	cout << x;
	for (int i=1;i<=10;i++)
	{
		sort(arr.begin(),arr.end());
		ll m,n;
		m = 0,n = 0;
		ll p;
		for (int j=0;j<arr.size();j++)
		{
			m = m*10 + arr[j];
		}
		sort(arr.begin(),arr.end(),greater<int>());
		for (int j=0;j<arr.size();j++)
		{
			n = n*10 + arr[j];
		}
		p = m+n;
		HW[cnt++] = p;
		arr.clear();
		while (p>0)
		{
			arr.push_back(p%10);
			p /= 10;
		}
	}
	int rst;
	for (int i=1;i<10;i++)
	{
		if (!ishw(HW[i]))
		{
			cout << "--->" << HW[i];
		}else{
			rst = i;
			cout << "--->" << HW[i];
			break;
		}
	}
	cout << endl << rst;
	return 0;
}
