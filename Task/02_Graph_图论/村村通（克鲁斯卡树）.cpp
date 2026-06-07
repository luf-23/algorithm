#include <bits/stdc++.h>
using namespace std;
int fa[1005];
int Find(int x){
	if (x!=fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}
int main()
{
	while (1){
		int n;
		cin >> n;
		if (!n) break;
		int m;
		cin >> m;
		for (int i=1;i<=n;i++) fa[i] = i;
		int ans = 0;
		for (int i=1;i<=m;i++){
			int x,y;
			cin >> x >> y;
			if (Find(x)!=Find(y)){
				fa[Find(x)] = Find(y);
			}
		}
		int T = Find(1);
		for (int i=2;i<=n;i++){
			if (Find(i)!=T){
				ans++;
				fa[Find(i)] = T;
			}
		}
		cout << ans << endl;
	}
}
