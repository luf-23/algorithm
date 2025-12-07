#include <bits/stdc++.h>
using namespace std;
int fa[200005];
int Find(int x)
{
	if (x!=fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}
int main()
{
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++) fa[i] = i;
	for (int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		if (x!=y) fa[Find(x)] = Find(y);
	}
	set<pair<int,int>>st;
	int k;
	cin >> k;
	int good = 1;
	while (k--){
		int x,y;
		cin >> x >> y;
		int X = Find(x);
		int Y = Find(y);
		if (X==Y) good = 0;
		st.insert(make_pair(min(X,Y),max(X,Y)));
	}
	int q;
	cin >> q;
	while (q--){
		int x,y;
		cin >> x >> y;
		int X = Find(x);
		int Y = Find(y);
		if (good&&!st.count(make_pair(min(X,Y),max(X,Y)))) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
