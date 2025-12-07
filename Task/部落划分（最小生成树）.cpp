#include <bits/stdc++.h>
using namespace std;
struct edge{
	int p,q;
	double dis;
}e[1000005];
int fa[1005];
int x[1005];
int y[1005];
double Dis[1000005];
int n,k;
int Find(int x)
{
	if (x!=fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}
int main()
{
	int n,k;
	cin >> n >> k;
	int pos = 0;
	for (int i=1;i<=n;i++){
		fa[i] = i;
		cin >> x[i] >> y[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<i;j++){
			pos++;
			e[pos].p = i;
			e[pos].q = j;
			e[pos].dis = sqrt((double)((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
		}
	}
	auto cmp = [&](edge a,edge b){
		return a.dis < b.dis;
	};
	sort(e+1,e+pos+1,cmp);
	int cnt = 0;
	for (int i=1;i<=pos;i++){
		int X = Find(e[i].p);
		int Y = Find(e[i].q);
		if (X!=Y){
			if (cnt==n-k+1) break;
			fa[X] = Y;
			cnt++;
			Dis[cnt] = e[i].dis;
		}
	}
	cout << fixed << setprecision(2) << Dis[n-k+1];
	return 0;
}
