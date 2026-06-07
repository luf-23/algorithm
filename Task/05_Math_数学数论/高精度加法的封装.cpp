#include <bits/stdc++.h>
using namespace std;
vector<int> add(vector<int>,vector<int>);
int main()
{
	string a,b;
	cin >> a >> b;
	int i;
	vector<int>L,M,N;
	for (i=a.length()-1;i>=0;i--)
	{
		M.push_back(a[i]-'0');
	}
	for (i=b.length()-1;i>=0;i--)
	{
		N.push_back(b[i]-'0');
	}
	L = add(M,N);
	for (i=L.size()-1;i>=0;i--)
	{
		cout << L[i];
	}
	return 0;
}
vector<int> add(vector<int>A,vector<int>B)
{ 
	if (A.size()<B.size())
	{
		return add(B,A);
	}
	int t = 0;
	int k;
	vector<int>C;
	for (k=0;k<A.size();k++)
	{
		t += A[k];
		if (k<B.size())
		{
			t += B[k];
		}
		C.push_back(t%10);
		t /= 10;
	} 
	if (t>0)
	{
		C.push_back(t);
	}
	return C;
}
