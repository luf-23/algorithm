#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int>a(1,1),b(1,2);
vector<vector<int>> ret(1200000);
vector<int> add(vector<int> A,vector<int>B)
{
	if (A.size()<B.size()) return add(A,B);
	vector<int>C;
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
vector<int> fff(int m,int n)
{
	if (!ret[n].empty()) return ret[n];
	if (m+1==n) return a;
	if (m+2==n) return b;
	return ret[n] = add(fff(m,n-1),fff(m,n-2));
}
int main()
{
	int m,n;
	cin >> m >> n;
	vector<int> ans = fff(m,n);
	for (int i=ans.size()-1;i>=0;i--)
		cout << ans[i];
	return 0;
}
