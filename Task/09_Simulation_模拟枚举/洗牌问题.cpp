#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int i = 1;
	int pos = i;
	int cnt = 0;
	while (1)
	{
		pos = (2*pos)%(2*n+1);
		cnt++;
		if (i==pos) break;
	}
	cout << cnt;
	return 0;
}
