#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> arr;
	int a,b,n;
	cin >> a >> b >> n;
	arr.push_back(a);
	arr.push_back(b);
	int pos;
	pos = 0;
	for (int i=1;i<=n+10;i++)
	{
		int ret = arr[pos]*arr[pos+1];
		pos++;
		stack <int> stk;
		if (!ret) arr.push_back(ret);
		while (ret)
		{
			stk.push(ret%10);
			ret /= 10;
		}
		while (!stk.empty()) 
		{
			arr.push_back(stk.top());
			stk.pop();
		}
	}
	for (int i=0;i<n;i++)
	{
		cout << arr[i];
		if (i<n-1) cout << ' ';
	}
	return 0;
}
