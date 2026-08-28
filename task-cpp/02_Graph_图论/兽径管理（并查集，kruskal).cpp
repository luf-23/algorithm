#include <bits/stdc++.h>
using namespace std;
int n,w;
int fa[205];
struct edge{
	int x,y;
	int dis;
};
int m;
int Find(int x)
{
	if (x!=fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}
bool cmp(edge a,edge b)
{
	return a.dis < b.dis;
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	cin >> n >> w;
	edge e[w+1];
	int ans = 0;
	for (int i=1;i<=w;i++){
		for (int j=1;j<=n;j++) fa[j] = j;
		cin >> e[i].x >> e[i].y >> e[i].dis;
		if (m==1&&e[i].dis>=e[i-1].dis){
			cout << ans << '\n';
			continue;
		}
		ans = 0;
		int t = 0;
		sort(e+1,e+i+1,cmp);
		for (int j=1;j<=i;j++){
			int X = Find(e[j].x);
			int Y = Find(e[j].y);
			if (X!=Y){
				t++;
				fa[X] = Y;
				ans += e[j].dis;
				if (t==n-1){
					break;
				}
			}
		}
		int flag = 1;
		if (m!=1){
			int T = Find(1);
			for (int j=1;j<=n;j++){
				if (Find(j)!=T){
					flag = 0;
					break;
				}
			}
		}
		if (!flag) cout << -1 << '\n';
		else {
			cout << ans << '\n';
			m = 1;
		}
	}
	return 0;
}
