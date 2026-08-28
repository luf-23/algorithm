#include <bits/stdc++.h>
using namespace std;
vector<int> multi(vector<int>A,vector<int>B)
{
	vector<int>C(A.size()+B.size()+10,0);
	int t = 0;
	for (int i=0;i<A.size();i++)
	{
		for (int j=0;j<B.size();j++)
		{
			C[i+j] += A[i]*B[j];
		}
	}
	for (int i=0;i<C.size();i++)
	{
		t += C[i];
		C[i] = t%10;
		t /= 10;
	}
	while (C.size()>1&&C.back()==0) C.pop_back();
	return C;
}
vector<int> quick(int a,int b)
{
	vector<int>C;
	C.push_back(1);
	vector<int>base;
	base.push_back(a);
	while (b)
	{
		if (b&1)
		{
			C = multi(C,base);
			C.resize(520);
		}
		b >>= 1;
		base = multi(base,base);
		base.resize(520);
	}
	return C;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int p;
	cin >> p;
	vector<int>ans = quick(2,p);
	ans[0] -= 1;
	int ret = p*log10(2)+1;
	cout << ret << endl;
	int cnt = 0;
	for (int i=ans.size()-21;i>=0;i--)
	{
		cout << ans[i];
		cnt++;
		if (cnt%50==0) cout << endl;
	}
	return 0;
}
