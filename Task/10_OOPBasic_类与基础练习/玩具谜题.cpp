#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	string name[n+1];
	int iscw[n+1];
	int i;
	for (i=1;i<=n;i++)
	{
		cin >> iscw[i] >> name[i];
	}
	int pos = 1;
	int isys;
	int x;
	for (i=0;i<m;i++)
	{
		cin >> isys >> x;
		if (iscw[pos]==isys) pos -= x;
		else pos += x;
		while (pos>n) pos -= n;
		while (pos<1) pos += n;
	}
	cout << name[pos] << endl;
	return 0;
}
