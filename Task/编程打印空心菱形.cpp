#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int k = n/2;
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=k-i+1;j++) cout << ' ';
		cout << '*';
		for (int j=1;j<=2*i-3;j++) cout << ' ';
		if (i!=1) cout << '*';
		cout << endl;
	}
	cout << '*';
	for (int i=1;i<=2*(k+1)-3;i++) cout << ' ';
	cout << '*' << endl;
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=i;j++) cout << ' ';
		cout << '*';
		for (int j=1;j<=2*k-2*i-1;j++) cout << ' ';
		if (i!=k) cout << '*';
		cout << endl;
	}
	cout << endl;
	return 0;
}
