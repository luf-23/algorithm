#include <bits/stdc++.h>
using namespace std;
int cnt;
int L,n,m;
int len[100000];
int judge(int x)
{
	cnt = 0;
	int now = 0;
	int i =1;
	while (i<=n+1)
	{
		if (len[i]-len[now]<x)
		{
			cnt++;
		}else{
			now = i;
		}
		i++;
	}
	if (cnt<=m) return true;
	else return false;
}
int main()
{
	cin >> L >> n >> m;
	len[0] = 0;
	int d[n+10];
	for (int i=1;i<=n;i++)
	{
		cin >> len[i];
		d[i] = len[i] - len[i-1];
	}
	len[n+1] = L;
	d[n+1] = L - len[n];
	sort(d+1,d+n+2);
	//for (int i=1;i<=n+1;i++)
	//	cout << d[i] << ' ';
	//cout << endl;
	int l,r;
	l = 1;
	r = L;
	int mid;
	int ans;
	while (l<=r)
	{
		mid = (l+r)/2;
		if (judge(mid))
		{
			l = mid + 1;
			ans = mid;
		}else{
			r = mid - 1;
		}
	}
	cout << ans;
}
