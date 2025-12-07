#include <bits/stdc++.h>
using namespace std;
int Max(int num[],int pos)
{
	if (pos==1) return num[pos];
	int max_v = Max(num,pos-1);
	return max_v > num[pos] ? max_v : num[pos];
}
int main()
{
	int n;
	cin >> n;
	int num[n+1];
	for (int i=1;i<=n;i++) cin >> num[i];
	int max_v = Max(num,n);
	cout << max_v;
	return 0;
}
