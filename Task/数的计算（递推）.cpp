#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num[1010];
	int n;
	cin >> n;
	num[1] = 1;
	num[2] = 2;
	if (n==1||n==2){
		cout << n;
		exit(EXIT_SUCCESS);
	}
	for (int i=3;i<=n;i++)
	{
		if (i%2==0) num[i] = num[i-1] + num[i/2];
		else num[i] = num[i-1];
	}
	//for (int i=1;i<=n;i++)
	//	cout << num[i] << ' ';
	cout << num[n];
	return 0;
}
