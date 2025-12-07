#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
	int n;
	string str;
	cin >> n;
	cin >> str;
	int cnt = 0;
	int x;
	while (cnt<n)
	{
		cin >> x;
		if (x==1)
		{
			string x;
			cin >> x;
			str += x;
			cout << str << endl;
		}else if (x==2)
		{
			int a,b;
			cin >> a >> b;
			str = str.substr(a,b);
			cout << str << endl;
		}else if (x==3)
		{
			int c;
			string tar;
			cin >> c;
			cin >> tar;
			//string m,n;
			//m = str.substr(0,3);
			//n = str.substr(3);
			//str = m + tar + n;
			str = str.insert(c,tar);
			cout << str << endl;
		}else if (x==4)
		{
			string son;
			cin >> son;
			int pos = str.find(son);
			if (pos==string::npos)
			{
				cout << -1 << endl;
			}else{
				cout << pos << endl;
			}
		}
		cnt++;
	}
	return 0;
}
