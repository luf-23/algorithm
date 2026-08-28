#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	int len;
	cin >> len;
	cin >> str;
	int i;
	int cnt = 0;
	for (i=0;i<len;i++)
	{
		if (str[i]=='V'&&str[i+1]=='K')
		{
			cnt++;
			str[i] = 'X';
			str[i+1] = 'X';
		}
	}
	for (i=0;i<len;i++)
	{
		if (str[i]!='X'&&str[i]==str[i+1])
		{
			cnt++;
			break;
		}
	}
	cout << cnt;
	return 0;
}
