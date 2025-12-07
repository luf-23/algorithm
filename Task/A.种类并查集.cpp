#include <bits/stdc++.h>
using namespace std;
int fa[1000005];
int Find(int x){
	if (x!=fa[x]) return fa[x] = Find(fa[x]);
	else return fa[x];
}
signed main(){
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=2*n;i++) fa[i] = i;
	for (int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		if (Find(x)==Find(y)||Find(x+n)==Find(y+n)){
			cout << x;
			return 0;
		}
		fa[Find(x)] = Find(y+n);
		fa[Find(y)] = Find(x+n);
	}
	return 0;
}
