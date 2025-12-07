#include <bits/stdc++.h>
using namespace std;
int fa[10005];
int n,p;
int val[10005];
struct edge{
	int x,y,t;
};
int Find(int x)
{
	if (x!=fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}
bool cmp(edge a,edge b)
{
	return a.t < b.t;
}
int main()
{
	cin >> n >> p;
	edge e[p+1];
	int ans = 0;
	int min_v = INT_MAX;
	for (int i=1;i<=n;i++){
		fa[i] = i;
		cin >> val[i];
		min_v = min(min_v,val[i]);
	}
	for (int i=1;i<=p;i++){
		cin >> e[i].x >> e[i].y >> e[i].t;
		e[i].t = e[i].t*2 + val[e[i].x] + val[e[i].y];
	}
	sort(e+1,e+p+1,cmp);
	for (int i=1;i<=p;i++){
		int X = Find(e[i].x);
		int Y = Find(e[i].y);
		if (X!=Y){
			fa[X] = Y;
			ans += e[i].t;
		}
	}
	ans += min_v;
	cout << ans;
	return 0;
}
