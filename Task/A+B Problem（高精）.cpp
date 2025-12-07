#include <bits/stdc++.h>
using namespace std;
vector<int>add(vector<int>A,vector<int>B)
{
	vector<int>C;
	int len1 = A.size();
	int len2 = B.size();
	if (len1<len2)
	{
		return add(B,A);
	}
	int t = 0;
	for (int i=0;i<len1;i++)
	{
		t += A[i];
		if (i<len2)
		{
			t += B[i];
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
int main()
{
	string a,b;
	cin >> a >> b;
	int L1 = a.length();
	int L2 = b.length();
	vector<int>x,y,z;
	int j;
	for (j=L1-1;j>=0;j--)
	{
		x.push_back(a[j]-'0');
	}
	for (j=L2-1;j>=0;j--)
	{
		y.push_back(b[j]-'0');
	}
	z = add(x,y);
	for (j=z.size()-1;j>=0;j--)
	{
		cout << z[j];
	}
	return 0;
}
