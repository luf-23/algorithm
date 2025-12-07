#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int b[n+1];
		for (int i=1;i<n;i++)
			cin >> b[i];
		b[0] = b[1];
		b[n] = b[n-1];
		int a[n+1];
		for (int i=1;i<=n;i++)
			a[i] = min(b[i],b[i-1]);
		for (int i=1;i<=n;i++)
			cout << a[i] << ' ';
		cout << endl;
	}
	return 0;
}
