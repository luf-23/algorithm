#include <bits/stdc++.h>
using namespace std;
int n,m;
int st[100005][25];
int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> st[i][0];
	for (int i=1;i<=24;i++){
		for (int j=1;j+(1<<i)-1<=n;j++){
			st[j][i] = min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
	for (int i=1;i<=n-m+1;i++){
		int k = log2(m);
		cout << min(st[i][k],st[m+i-(1<<k)][k]) << endl;
	}
	return 0;
}
