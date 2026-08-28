#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string f()
{
	string s1="",s2;
	char ch;
	while (cin>>ch)
	{
		if (ch=='\n') break;
		if (ch=='[')
		{
			int t;
			scanf("%d",&t);
			s2 = f();
			while (t--) s1 += s2;
		}
		else if (ch==']') return s1;
		else s1 += ch;
	}
	return s1;
}
int main()
{
	cout << f();
	return 0;
}
