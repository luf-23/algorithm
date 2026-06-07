#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int>arr(1,1);
vector<int> ans;
vector<vector<int>> mark(100000);
vector<int> add(vector<int>A,vector<int>B)
{
	if (A.size()<B.size()) return add(B,A);
	vector<int> C;
	int t = 0;
	for (int i=0;i<A.size();i++)
	{
		t += A[i];
		if (i<B.size()) t += B[i];
		C.push_back(t%10);
		t /= 10;
	}
	while (t)
	{
		C.push_back(t%10);
		t /= 10;
	}
	return C;
}
vector<int> fibo(int n)
{
	if (!mark[n].empty()) return mark[n];
	if (n==1||n==2) return arr;
	return mark[n] = add(fibo(n-1),fibo(n-2));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int n;
	cin >> n;
	ans = fibo(n);
	for (int i=ans.size()-1;i>=0;i--)
		cout << ans[i];
	ll cnt = 0;
	cnt = ans.size();
	cout << endl << cnt << endl;
	return 0;
}
