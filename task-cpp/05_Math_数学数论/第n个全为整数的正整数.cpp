#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ll n;
	cin >> n;
	ll num[100] = {0};
	ll m = 1;
	ll i;
	for (i=1;i<=60;i++)
	{
		m *= 5;
		if (n/m==0) break;
	}
	m /= 5;
	int k = 1;
	while (1)
	{
		//cout << "m=" << m << endl;
		int t = n/m;
		num[k++] = t;
		n = n%m;
		m /= 5;
		if (m==0) break;
	}
	int l = k-1;
	while (num[l]==0) l--;
	if (l==k-1) num[l]--;
	else{
		for (int q=l+1;q<=k-1;q++) num[q] = 4;
		num[l] -= 1;
	}
	int cnt[10] = {0,2,4,6,8};
	//for (int j=1;j<k;j++) cout << num[j] << ' ';
	//cout << endl;
	for (int j=1;j<k;j++) num[j] = cnt[num[j]];
	for (int j=1;j<k;j++) cout << num[j];
	return 0;
}
