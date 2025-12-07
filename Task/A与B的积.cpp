#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	cin >> a >> b;
	vector <int> A,B;
	vector<int>C(A.size()+B.size()+20000,0);
	int i,j;
	for (i=0;i<a.length();i++)
	{
		A.push_back(a[a.length()-1-i]-'0');
	}
	for (i=0;i<b.length();i++)
	{
		B.push_back(b[b.length()-1-i]-'0');
	}
	for (i=0;i<A.size();i++)
	{
		for (j=0;j<B.size();j++)
		{
			C[i+j] += A[i]*B[j];
		}
	}
	int t = 0;
	for (i=0;i<C.size();i++)
	{
		t += C[i];
		C[i] = t % 10;
		t /= 10;
	}
	while (C.size()>1&&C.back()==0)
	{
		C.pop_back();
	}
	for (i=C.size()-1;i>=0;i--)
	{
		cout << C[i];
	}
	return 0;
}
