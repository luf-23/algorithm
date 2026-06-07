#include <bits/stdc++.h>
using namespace std;
int fa[1005];
int n,m;
struct edge{
	int x,y,t;
};
int Find(int x)
{
	if (x!=fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}
int main()
{
	cin >> n >> m;
	edge e[m+1];
	for (int i=1;i<=n;i++) fa[i] = i;
	for (int i=1;i<=m;i++){
		cin >> e[i].x >> e[i].y >> e[i].t;
	}
	auto cmp = [&](edge a,edge b){
		return a.t < b.t;
	};
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=m;i++){
		int X,Y;
		X = Find(e[i].x);
		Y = Find(e[i].y);
		if (X!=Y){
			fa[X] = Y;
		}
		int flag = 1;
		int T = Find(1);
		for (int j=2;j<=n;j++){
			if (Find(j)!=T){
				flag = 0;
				break;
			}
		}
		if (flag){
			cout << e[i].t;
			exit(0);
		}
	}
	cout << -1;
	return 0;
}
