#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int pos;
	int i,j;
	int flag = 0;
	if (str.find(".")!=string::npos)
	{
		pos = str.find(".");
		for (i=pos-1;i>=0;i--)
		{
			if (str[i]!='0')
			{
				flag = 1;
			}
			if (flag==1)
			{
				cout << str[i];
			}
		}
		if (flag==0)
		{
			cout << 0;
		}
		cout << '.';
		int ret = str.length();
		for (i=pos+1;i<str.length();i++)
		{
			if (str[i] != '0')
			{
				ret = i;
				break;
			}
		}
		//cout << endl << ret << endl;
		for (i=str.length()-1;i>=ret;i--)
		{
			cout << str[i];
		}
		if (ret==str.length())
		{
			cout << 0;
		}
	}else if (str.find("/")!=string::npos)
	{
		flag = 0;
		pos = str.find("/");
		for (i=pos-1;i>=0;i--)
		{
			if (str[i]!='0')
			{
				flag = 1;
			}
			if (flag==1)
			{
				cout << str[i];
			}
		}
		if (flag==0)
		{
			cout << 0;
		}
		cout << '/';
		flag = 0;
		for (i=str.length()-1;i>=pos+1;i--)
		{
			if (str[i]!='0')
			{
				flag = 1;
			}
			if (flag==1)
			{
				cout << str[i];
			}
		}
	}else if (str.find("%")!=string::npos)
	{
		flag = 0;
		for (i=str.length()-2;i>=0;i--)
		{
			if (str[i]!='0')
			{
				flag = 1;
			}
			if (flag==1)
			{
				cout << str[i];
			}
		}
		if (flag==0)
		{
			cout << 0;
		}
		cout << '%';
	}else{
		flag = 0;
		for (i=str.length()-1;i>=0;i--)
		{
			if (str[i]!='0')
			{
				flag = 1;
			}
			if (flag==1)
			{
				cout << str[i];
			}
		}
		if (flag==0)
		{
			cout << 0;
		}
	}
	return 0;
}
