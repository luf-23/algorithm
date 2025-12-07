#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>,pair<int,int>);
int main()
{
	vector<pair<int,int>> arr;
	int n;
	cin >> n;
	int x;
	for (int i=0;i<n;i++)
	{
		cin >> x;
		arr.push_back({x,0});
	}
	for (int i=0;i<n;i++)
	{
		int t = arr[i].first;
		if (t==1) {
			arr[i].second = 0;
			continue;
		}
		for (int j=1;j<t;j++)
		{
			if (t%j==0) arr[i].second += j;
		}
	}
	sort(arr.begin(),arr.end(),cmp);
	for (int i=0;i<arr.size();i++)
	{
		cout << arr[i].first << '(' << arr[i].second << ')' << ' ';
	}
	return 0;
}
bool cmp(pair<int,int>a,pair<int,int>b)
{
	if (a.second!=b.second) return a.second < b.second;
	else return a.first < b.first;
}
