#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int num[26] = {0};
	int i;
	for (i=0;i<str.length();i++)
	{
		num[str[i]-'a']++;
	}
	sort(num+0,num+26);
	for (i=0;i<26;i++)
	{
		if (num[i]!=0)
		{
			num[0] = num[i];
			break;
		}
	}
	int j;
	int flag = 0;
	int ret = num[25]-num[0];
	for (i=2;i<100;i++)
	{
		int isPrime = 1;
		for (j=2;j<i;j++)
		{
			if (i%j==0)
			{
				isPrime = 1;
			}
		}
		if (isPrime==1&&i==ret)
		{
			cout << "Lucky Word" << endl << ret;
			flag = 1;
			break;
		}
	}
	if (flag==0)
	{
		cout << "No Answer" << endl << 0;
	}
	return 0;
}
