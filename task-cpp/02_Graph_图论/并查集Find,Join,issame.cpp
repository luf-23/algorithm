#include <bits/stdc++.h>
using namespace std;
int n,m;
int fa[10005];
int Find(int x)
{
	if (x!=fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}
void Join(int x,int y)
{
	fa[Find(x)] = Find(y);
}
bool issame(int x,int y)
{
	return Find(x) == Find(y);
}
int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++) fa[i] = i;
	while (m--){
		int z,x,y;
		cin >> z >> x >> y;
		if (z==1) Join(x,y);
		else{
			if (issame(x,y)) cout << 'Y' << endl;
			else cout << 'N' << endl;
		}
	}
	return 0;
}
