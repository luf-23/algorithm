#include <bits/stdc++.h>
using namespace std;
struct Man{
	int wait;
	int xuhao;
};
bool cmp(Man x,Man y)
{
	return x.wait < y.wait;
}
int main()
{
	int n;
	cin >> n;
	Man m[n+1];
	double ave = 0;
	for (int i=1;i<=n;i++)
	{
		cin >> m[i].wait;
		m[i].xuhao = i;
	}
	sort(m+1,m+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		cout << m[i].xuhao << ' ';
	}
	for (int i=1;i<=n;i++)
	{
		ave += m[i].wait*(n-i);
	}
	ave /= (n*1.0);
	cout << endl << fixed << setprecision(2) << ave;
	return 0;
}
