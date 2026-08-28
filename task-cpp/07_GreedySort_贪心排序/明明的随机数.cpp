#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<int,int> mp;
	int n;
	cin >> n;
	int num[n];
	for (int i=0;i<n;i++)
	{
		cin >> num[i];
		mp[num[i]]++;
	}
	int cnt = 0;
	for (auto ele : mp)
		cnt++;
	cout << cnt << endl;
	for (auto ele : mp)
		cout << ele.first << ' ';
	return 0;
}
