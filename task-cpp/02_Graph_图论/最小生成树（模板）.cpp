#include <bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
	int x,y,z;
};
int cnt = 0;
int fa[5005];
int Find(int x)
{
	if (x!=fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}
int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++) fa[i] = i;
	edge e[m+1];
	int sum = 0;
	auto cmp = [&](edge a,edge b){
		return a.z < b.z;
	};
	for (int i=1;i<=m;i++){
		cin >> e[i].x >> e[i].y >> e[i].z;
	}
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=m;i++){
		int X = Find(e[i].x);
		int Y = Find(e[i].y);
		if (X!=Y){
			fa[X] = Y;
			sum += e[i].z;
		}
	}
	int T = Find(1);
	int flag = 1;
	for (int i=1;i<=n;i++){
		if (Find(i)!=T){
			flag = 0;
			break;
		}
	}
	if (!flag) cout << "orz";
	else cout << sum;
	return 0;
}
