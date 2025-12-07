#include <bits/stdc++.h>
using namespace std;
int main()
{
	int w,n;
	cin >> w >> n;
	int num[n+1];
	num[0] = 0;
	for (int i=1;i<=n;i++)
		cin >> num[i];
	sort(num+1,num+n+1);
	int l = 1;
	int r = n;
	int cnt = 0;
	while (l<=r)
	{
		if (num[l]+num[r]<=w)
		{
			l++,r--;
			cnt++;
		}else{
			r--;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
