#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int i;
	int sum = 0;
	int cnt = 1;
	for (i=0;i<str.length()-1;i++)
	{
		if (str[i]!='-')
		{
			sum += (str[i]-'0')*cnt++;
			//printf("sum=%d\n",sum);
		}
	}
	sum %= 11;
	if (sum==(str[str.length()-1]-'0'))
	{
		cout << "Right";
	}else{
		if (str[str.length()-1]=='X')
		{
			if (sum==10)
			{
				cout << "Right";
			}else{
				for (int j=0;j<str.length()-1;j++)
				{
					cout << str[j];
				}
				cout << sum;
			}
		}else if (str[str.length()-1]!='X')
		{
			for (int j=0;j<str.length()-1;j++)
			{
				cout << str[j];
			}
			if (sum==10)
			{
				cout << 'X';
			}else{
				cout << sum;
			}
		}
	}
	return 0;
}
