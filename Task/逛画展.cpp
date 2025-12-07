#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int num[n+1];
	int pos[m+1];
	int ans = n+1;
	int ll,rr;
	int l;
	l = 1;
	int cnt = 0;
	memset(pos,-1,sizeof pos);
	for (int i=1;i<=n;i++)
	{
		cin >> num[i];
		if (pos[num[i]]==-1) cnt++;
		pos[num[i]] = i;
		while (l!=i&&l<pos[num[l]]) l++;
		if (cnt==m&&i-l+1<ans)
		{
			ans = i-l+1;
			ll = l;
			rr = i;
		}
	}
	cout << ll << ' ' << rr << '\n';
	return 0;
}
