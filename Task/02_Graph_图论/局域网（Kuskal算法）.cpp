//不改变原图连通性，使得取出来的图各边之和最小
#include <bits/stdc++.h>
using namespace std;
int fa[105];
struct edge{
	int x,y,c;
};
int Find(int x)
{
	if (x!=fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}
int main()
{
	int n,k;
	cin >> n >> k;
	edge e[k+1];
	int sum = 0;
	int cnt = 0;
	for (int i=1;i<=n;i++) fa[i] = i;
	for (int i=1;i<=k;i++){
		cin >> e[i].x >> e[i].y >> e[i].c;
		sum += e[i].c;
	}
	auto cmp = [&](edge a,edge b){
		return a.c < b.c;
	};
	sort(e+1,e+k+1,cmp);
	for (int i=1;i<=k;i++){
		int X = Find(e[i].x);
		int Y = Find(e[i].y);
		if (X!=Y){
			fa[X] = Y;
			cnt += e[i].c;
		}
	}
	cout << sum-cnt;
	return 0;
}
