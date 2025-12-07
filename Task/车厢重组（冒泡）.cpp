#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n;
	cin >> n;
	int num[n+1];
	for (int i=1;i<=n;i++)
		cin >> num[i];
	int cnt = 0;
	for (int i=1;i<=n-1;i++)
	{
		for (int j=1;j<=n-i;j++)
		{
			if (num[j+1]<num[j])
			{
				int temp = num[j];
				num[j] = num[j+1];
				num[j+1] = temp;
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
