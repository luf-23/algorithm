#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	char x;
	while ((x=getchar())!='E')
	{
		if (x!='\n') s += x;
	}
	if (s.empty()){
		cout << "0:0" << endl << endl << "0:0";
		exit(EXIT_SUCCESS);
	}
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i=0;i<s.length();i++)
	{
		if (s[i]=='W') cnt1++;
		if (s[i]=='L') cnt2++;
		if ((cnt1>=11||cnt2>=11)&&abs(cnt1-cnt2)>=2)
		{
			cout << cnt1 << ':' << cnt2 << endl;
			cnt1 = cnt2 =0;
		}
	}
	cout << cnt1 << ':' << cnt2 << endl;
	cout << endl;
	cnt1 = 0;
	cnt2 = 0;
	for (int i=0;i<s.length();i++)
	{
		if (s[i]=='W') cnt1++;
		if (s[i]=='L') cnt2++;
		if ((cnt1>=21||cnt2>=21)&&abs(cnt1-cnt2)>=2)
		{
			cout << cnt1 << ':' << cnt2 << endl;
			cnt1 = cnt2 =0;
		}
	}
	if (cnt1||cnt2) cout << cnt1 << ':' << cnt2 << endl;
	return 0;
}
