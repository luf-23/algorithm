#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	int m;
	cin >> m;
	getchar();
	getline(cin,str);
	char x[120][120];
	memset(x,' ',sizeof(x));
	int pos = 0;
	int i,j;
	i = 1;
	j = 1;
	while (pos!=str.length())
	{
		if (i<=m)
		{
			x[i++][j] = str[pos++];
		}else{
			i -= m;
			j++;
		}
	}
	char y[120][120];
	memset(y,' ',sizeof(y));
	for (int p=1;p<=m;p++)
	{
		for (int q=1;q<=j;q++)
		{
			y[p][q] = x[p][j-q+1];
		}
	}
	for (int p=1;p<=m;p++)
	{
		for (int q=1;q<=j;q++)
		{
			cout << y[p][q];
		}
		if (p<m) cout << endl;
	}
	return 0;
}
