#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll x,pos;
	cin >> x >> pos;
	vector<ll> arr;
	ll b;
	for (int i=0;i<x;i++)
	{
		cin >> b;
		arr.push_back(b);
	}
	sort(arr.begin(),arr.end());
	cout << arr[pos];
	return 0;
}
