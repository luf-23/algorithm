#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int k;
	cin >> k;
	if (s.length()<=k)
	{
		cout << '0';
		exit(EXIT_SUCCESS);
	}
	for (int i=0;i<s.length()-1;i++)
	{
		if (s[i]>s[i+1])
		{
			if (k>0)
			{
				s.erase(i,1);
				k--;
				i = -1;
			}
		}
	}
	while (k>0&&s.length()>0)
	{
		reverse(s.begin(),s.end());
		s.erase(0,1);
		k--;
		reverse(s.begin(),s.end());
	}
	reverse(s.begin(),s.end());
	while (s.back()=='0') s.pop_back();
	reverse(s.begin(),s.end());
	cout << s;
	if (s.empty()) cout << '0';
}
