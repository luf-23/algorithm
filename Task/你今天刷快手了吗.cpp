#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string,int>x,pair<string,int>y)
{
	if (x.second!=y.second) return x.second > y.second;
	return x.first < y.first;
}
int main()
{
	int n,m;
	cin >> n >> m;
	map<string,int> mp;
	while (m--)
	{
		string s;
		cin >> s;
		int h1,h2,m1,m2,s1,s2;
		scanf("%02d:%02d:%02d %02d:%02d:%02d",&h1,&m1,&s1,&h2,&m2,&s2);
		int ans = (h2-h1)*3600 + (m2-m1)*60 + s2-s1;
		mp[s] += ans;
	}
	vector<pair<string,int>> arr;
	for (map<string,int>::iterator it=mp.begin();it!=mp.end();++it)
	{
		arr.push_back({it->first,it->second});
	}
	sort(arr.begin(),arr.end(),cmp);
	for (int i=0;i<arr.size();i++)
	{
		int h,m,s;
		h = 0,m = 0,s = 0;
		h = arr[i].second / 3600;
		arr[i].second %= 3600;
		m = arr[i].second / 60;
		arr[i].second %= 60;
		s = arr[i].second;
		if (arr[i].first.length()<3)
		{
			int t = 3 - arr[i].first.length();
			while (t--) cout << 0;
		}
		cout << arr[i].first << ' ';
		printf("%02d:%02d:%02d\n",h,m,s);
	}
	return 0;
}
