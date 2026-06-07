#include <bits/stdc++.h>
using namespace std;
int num[1000005];
int Find(int x)
{
	while (x!=num[x]) x = num[x];
	return x;
}
int main()
{
	int m,n;
	cin >> m >> n;
	for (int i=1;i<=m*n;i++) num[i] = i;
	int k;
	cin >> k;
	for (int i=1;i<=k;i++){
		int x,y;
		cin >> x >> y;
		num[Find(x)] = Find(y); 
	}
	int ans = 0;
	for (int i=1;i<=m*n;i++) if (num[i]==i) ans++;
	cout << ans;
	return 0;
}
