#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int num[n+1];
	for (int i=1;i<=n;i++)
		cin >> num[i];
	int m;
	cin >> m;
	int s[n+1];
	s[0] = 0;
	s[1] = num[1];
	for (int i=2;i<=n;i++)
	{
		s[i] = s[i-1] + num[i];
	}
	int x,y;
	for (int i=0;i<m;i++)
	{
		cin >> x >> y;
		cout << s[y]-s[x-1] << endl;
	}
	return 0;
}
