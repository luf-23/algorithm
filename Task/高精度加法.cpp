#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	cin >> a >> b;
	vector <int> A,B;
	int i;
	for (i=0;i<a.length();i++)
	{
		A.push_back(a[a.length()-1-i]-'0');
	}
	for (i=0;i<b.length();i++)
	{
		B.push_back(b[b.length()-i-1]-'0');
	}
	int t = 0;
	int LEN;
	vector <int> C;
	if (a.length()>b.length())
	{
		LEN = a.length();
		for (i=0;i<a.length();i++)
		{
			t += A[i];
			if (i<b.length())
			{
				t += B[i];
			}
			C.push_back(t%10);
			t /= 10;
		}
	}
	if (a.length()<=b.length())
	{
		LEN = b.length();
		for (i=0;i<b.length();i++)
		{
			t += B[i];
			if (i<a.length())
			{
				t += A[i];
			}
			C.push_back(t%10);
			t /= 10;
		}
	}
	if (t>0)
	{
		C.push_back(t);
	}
	for (i=LEN-1;i>=0;i--)
	{
		cout << C[i];
	}
	return 0;
}
