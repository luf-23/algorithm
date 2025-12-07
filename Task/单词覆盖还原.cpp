#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin >> a;
	int len;
	len = a.length();
	int b = 0;
	int g = 0;
	int i,j;
	for (i=0;i<len;i++)
	{
		if (a[i]=='b'&&a[i+1]=='o'&&a[i+2]=='y')
		{
			b++;
			for (j=0;j<3;j++)
			{
				a[i+j] = 'X';
			}
		}
		if (a[i]=='g'&&a[i+1]=='i'&&a[i+2]=='r'&&a[i+3]=='l')
		{
			g++;
			for (j=0;j<4;j++)
			{
				a[i+j] = 'X';
			}
		}
	}
	for (i=0;i<len;i++)
	{
		if (a[i]=='b'||a[i+1]=='o'||a[i+2]=='y')
		{
			b++;
		}
		//a[i]=='b'||a[i]=='o'||a[i]=='y'
		if (a[i]=='g'||a[i+1]=='i'||a[i+2]=='r'||a[i+3]=='l')
		{
			g++;
		}
		//a[i]=='g'||a[i]=='i'||a[i]=='r'||a[i]=='l'
	}
	cout << b << endl << g << endl;
	return 0;
}
