#include <bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	int n;
	cin >> n;
	string t;
	cin >> t;
	vector<int>arr;
	for (int i=1;i<=n;i++)
	{
		string s;
		cin >> s;
		if (s==t){
			arr.push_back(i);
			continue;
		}else if (s.length()==t.length()+1){
			int p,q;
			p = q = 0;
			int cnt = 0;
			for (q=0;q<s.length();q++)
			{
				if (s[q]==t[p]) p++;
				else cnt++;
			}
			if (p==t.size()&&cnt==1) arr.push_back(i);
		}else if (s.length()==t.length()-1)
		{
			int p,q;
			p = q = 0;
			int cnt = 0;
			for (p=0;p<t.length();p++)
			{
				if (t[p]==s[q]) q++;
				else cnt++;
			}
			if (q==s.size()&&cnt==1) arr.push_back(i);
		}else if (s.length()==t.length())
		{
			int cnt = 0;
			for (int p=0;p<s.length();p++)
			{
				if (s[p]!=t[p]) cnt++;
			}
			if (cnt==1) arr.push_back(i);
		}
	}
	cout << arr.size() << endl;
	for (int i=0;i<arr.size();i++) cout << arr[i] << ' ';
	return 0;
}
