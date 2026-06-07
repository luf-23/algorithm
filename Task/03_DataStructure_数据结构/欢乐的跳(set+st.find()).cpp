#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	set<int> st;
	vector<int> arr;
	int x;
	while (scanf("%d",&x)!=EOF)
	{
		arr.push_back(x);
	}
	int len = arr.size();
	for (int i=0;i<arr.size()-1;i++)
	{
		st.insert(abs(arr[i+1]-arr[i]));
	}
	int istrue = 1;
	for (int i=1;i<=len-2;i++)
	{
		if (st.find(i)==st.end())
		{
			istrue = 0;
			break;
		}
	}
	if (istrue) cout << "Jolly";
	else cout << "Not jolly";
	return 0;
}
