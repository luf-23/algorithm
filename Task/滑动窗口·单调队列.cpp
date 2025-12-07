#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n,k;
	cin >> n >> k;
	int num[n+1];
	for (int i=1;i<=n;i++)
		cin >> num[i];
	deque<int> ma_pos;
	deque<int> mi_pos;
	for (int i=1;i<=n;i++)
	{
		while (!mi_pos.empty()&&mi_pos.front()<=i-k) mi_pos.pop_front();
		while (!mi_pos.empty()&&num[i]<=num[mi_pos.back()]) mi_pos.pop_back();
		mi_pos.push_back(i);
		if (i>=k) cout << num[mi_pos.front()] << ' ';
	}
	cout << endl;
	for (int i=1;i<=n;i++)
	{
		while (!ma_pos.empty()&&ma_pos.front()<=i-k) ma_pos.pop_front();
		while (!ma_pos.empty()&&num[i]>=num[ma_pos.back()]) ma_pos.pop_back();
		ma_pos.push_back(i);
		if (i>=k) cout << num[ma_pos.front()] << ' ';
	}
	cout << endl;
	return 0;
}
