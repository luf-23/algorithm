#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	int num[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
	int len = str.length();
	int i;
	int cnt = 0;
	for (i=0;i<len;i++)
	{
		if (str[i]>='a'&&str[i]<='z')
		{
			cnt += num[str[i]-'a'];
		}
		if (str[i]==' ')
		{
			cnt += 1;
		}
	}
	cout << cnt;
	return 0;
}
