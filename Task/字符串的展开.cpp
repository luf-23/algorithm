#include <bits/stdc++.h>
using namespace std;
int main()
{
	int p1,p2,p3;
	cin >> p1 >> p2 >> p3;
	string str;
	cin >> str;
	for (int i=0;i<str.length();i++)
	{
		if (str[i]=='-'&&i>0&&i<str.length()-1)
		{
			int flag = 0;
			string s="";
			if (isdigit(str[i-1])&&isdigit(str[i+1]))
			{
				int d = str[i+1]-str[i-1] - 1;
				if (d>=0) flag = 1;
				for (int j=1;j<=d;j++)
				{
					for (int k=1;k<=p2;k++)
					{
						if (p1!=3) s += (str[i-1]+j);
						else s += '*';
					}
				}
			}else if (str[i-1]>='a'&&str[i-1]<='z'&&str[i+1]>='a'&&str[i+1]<='z')
			{
				int d = str[i+1] - str[i-1] -1;
				if (d>=0) flag = 1;
				if (p1==1||p1==3)
				{
					for (int j=1;j<=d;j++)
					{
						for (int k=1;k<=p2;k++)
						{
							if (p1!=3) s += (str[i-1]+j);
							else s += '*';
						}
					}
				}else if (p1==2||p1==3)
				{
					for (int j=1;j<=d;j++)
					{
						for (int k=1;k<=p2;k++)
						{
							if (p1!=3) s += (str[i-1]+j-32);
							else s += '*';
						}
					}
				}
			}
			if (p3==2) reverse(s.begin(),s.end());
			cout << s;
			if (!flag) cout << '-';
		}else{
			cout << str[i];
		}
	}
	return 0;
}
