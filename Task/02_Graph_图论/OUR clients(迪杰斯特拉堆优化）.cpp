#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>>D[1005];
int vis[1005];
int n,a,b,c;
int num[1005][1005];
int dis1[1005];
int dis2[1005];
void dijcar()
{
	for (int i=1;i<=n;i++){
		dis1[i] = LONG_LONG_MAX;
		vis[i] = 0;
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push(make_pair(0,1));
	dis1[1] = 0;
	while (!pq.empty()){
		int node = pq.top().second;
		pq.pop();
		if (vis[node]) continue;
		vis[node] = 1;
		for (int i=0;i<D[node].size();i++){
			int nxt = D[node][i].first;
			int val = D[node][i].second*a;
			if (dis1[nxt]>dis1[node]+val){
				dis1[nxt] = dis1[node] + val;
				pq.push(make_pair(dis1[nxt],nxt));
			}
		}
	}
}
void dijtrain()
{
	for (int i=1;i<=n;i++){
		vis[i] = 0;
		dis2[i] = LONG_LONG_MAX;
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	dis2[n] = 0;
	pq.push(make_pair(0,n));
	while (!pq.empty()){
		int node = pq.top().second;
		pq.pop();
		if (vis[node]) continue;
		vis[node] = 1;
		for (int i=0;i<D[node].size();i++){
			int nxt = D[node][i].first;
			int val = D[node][i].second*b+c;
			if (dis2[nxt]>dis2[node]+val){
				dis2[nxt] = dis2[node] + val;
				pq.push(make_pair(dis2[nxt],nxt));
			}
		}
	}
}
int ans = LONG_LONG_MAX;
signed main()
{
	cin >> n >> a >> b >> c;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin >> num[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			D[i].push_back(make_pair(j,num[i][j]));
			D[j].push_back(make_pair(i,num[i][j]));
		}
	}
	dijcar();
	dijtrain();
	for (int i=1;i<=n;i++){
		ans = min(ans,dis1[i]+dis2[i]);
	}
	cout << ans;
	return 0;
}
