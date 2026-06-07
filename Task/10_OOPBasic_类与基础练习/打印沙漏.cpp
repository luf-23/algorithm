#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int ret;
	int sum = 0;
	for (int i=1;i<=10010;i++)
	{
		if ((i-2)*(2*i+4)+7<=n)
		{
			ret = i;
			sum = (i-2)*(2*i+4)+7;
		}else{
			break;
		}
	}
	//cout << ret << endl;
	int leave = n - sum;
	//cout << leave << endl;
	for (int i=1;i<=ret;i++)
	{
		for (int j=1;j<=i-1;j++) cout << ' ';
		for (int j=1;j<=2*ret-1+2-2*i;j++) cout << '*';
		cout << endl;
	}
	for (int i=1;i<=ret-1;i++)
	{
		for (int j=1;j<=ret-i-1;j++) cout << ' ';
		for (int j=1;j<=2*i+1;j++) cout << '*';
		cout << endl;
	}
	cout << leave;
	return 0;
}
