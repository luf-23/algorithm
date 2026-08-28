#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,q;
	cin >> n >> q;
	int k = 1000001;
	vector<pair<int,int>>arr(3000000);
	for (int i=0;i<n;i++)
	{
		arr[k+i] = {i+1,0};
	}
	//for (int i=k;i<=k+n-1;i++) cout << '(' << arr[i].first << ',' << arr[i].second << ')' << endl;
	while (q--)
	{
		int x;
		cin >> x;
		if (x==1)
		{
			char t;
			cin >> t;
			if (t=='U')
			{
				arr[--k] = {arr[k].first,arr[k].second+1};
				//for (int i=k;i<=k+n-1;i++) cout << '(' << arr[i].first << ',' << arr[i].second << ')' << endl;
			}else if (t=='D')
			{
				arr[--k] = {arr[k].first,arr[k].second-1};
				//for (int i=k;i<=k+n-1;i++) cout << '(' << arr[i].first << ',' << arr[i].second << ')' << endl;
			}else if (t=='L')
			{
				arr[--k] = {arr[k].first-1,arr[k].second};
				//for (int i=k;i<=k+n-1;i++) cout << '(' << arr[i].first << ',' << arr[i].second << ')' << endl;
			}else if (t=='R')
			{
				arr[--k] = {arr[k].first+1,arr[k].second};
				//for (int i=k;i<=k+n-1;i++) cout << '(' << arr[i].first << ',' << arr[i].second << ')' << endl;
			}
		}else if (x==2)
		{
			int m;
			cin >> m;
			cout << arr[k+m-1].first << ' ' << arr[k+m-1].second << endl;
		}
	}
	return 0;
}
