#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n,m;
	cin >> n >> m;
	int ans = 0;
	int pos[n+1];
	for (int i=1;i<=n;i++) cin >> pos[i];
	sort(pos+1,pos+n+1);
	int i,j;
	i = j = 1;
	for (i=1;i<=n;i++)
	{
		while (j<=n&&pos[j]-pos[i]<m) j++;
		ans = max(ans,j-i);
	}
	return 0*printf("%d",ans);
}
