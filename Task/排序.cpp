#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,x;
	cin >> n;
	vector<ll>arr;
	for (int i=0;i<n;i++)
	{
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(),arr.end());
	for (int i=0;i<n-1;i++)
		cout << arr[i] << ' ';
	cout << arr[n-1] << endl;
	return 0;
}
