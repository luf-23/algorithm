#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<int> arr;
	int q;
	cin >> q;
	arr.push_back(1);
	while (q--)
	{
		int a;
		cin >> a;
		if (a==1)
		{
			int x,y;
			cin >> x >> y;
			int pos = find(arr.begin(),arr.end(),x)-arr.begin();
			arr.insert(arr.begin()+pos+1,1,y);
		}else if (a==2)
		{
			int x;
			cin >> x;
			int pos = find(arr.begin(),arr.end(),x)-arr.begin();
			if (pos+1<arr.size()) cout << arr[pos+1] << '\n';
			else cout << 0 << '\n';
		}else if (a==3)
		{
			int x;
			cin >> x;
			int pos = find(arr.begin(),arr.end(),x)-arr.begin();
			if (arr.begin()+pos<arr.end()-1) arr.erase(arr.begin()+pos+1);
		}
	}
	return 0;
}
