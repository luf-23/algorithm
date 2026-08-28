#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str,tar;
	getline(cin,tar);
	getline(cin,str);
	int cnt = 0;
	int pos = -1;
	for (int i=0;i<tar.length();i++)
	{
		tar[i] = tolower(tar[i]);
	}
	for (int i=0;i<str.length();i++)
	{
		str[i] = tolower(str[i]);
	}
	for (int i=0;i<str.length();i++)
	{
		if (i>=1&&!isspace(str[i-1])||i<str.length()-tar.length()&&!isspace(str[i+tar.length()]))
		{
			continue;
		}else if (str.substr(i,tar.length())==tar)
		{
			if (pos==-1)
			{
				pos = i;
			}
			cnt++;
		}
	}
	if (pos==-1)
	{
		cout << -1;
	}else{
		cout << cnt << ' ' << pos;
	}
	return 0;
}
