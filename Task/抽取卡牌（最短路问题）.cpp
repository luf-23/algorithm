#include <bits/stdc++.h>
#define int long long
using namespace std;
int vis[50005];
int dist[50005];
int n,m,k;
signed main()
{
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m >> k;
		vector<pair<int,int>>arr[n+1];
		for (int i=1;i<=m;i++){
			int a,b;
			cin >> a >> b;
			for (int j=1;j<=n;j++){
				int nxt = j+a;
				if (nxt>n) nxt -= n;
				arr[j].push_back(make_pair(nxt,b));
			}
		}
		auto dijkstra = [&]{
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
			for (int i=1;i<=n;i++) vis[i] = 0;
			for (int i=1;i<=n;i++) dist[i] = LONG_LONG_MAX;
			dist[k] = 0;
			pq.push(make_pair(0,k));
			while (!pq.empty()){
				int node = pq.top().second;
				pq.pop();
				if (vis[node]) continue;
				vis[node] = 1;
				for (int i=0;i<arr[node].size();i++){
					int nxt = arr[node][i].first;
					int val = arr[node][i].second;
					if (dist[nxt]>dist[node]+val){
						dist[nxt] = dist[node] + val;
						pq.push(make_pair(dist[nxt],nxt));
					}
				}
			}
			return dist[n];
		};
		if (dijkstra()==LONG_LONG_MAX) cout << -1 << '\n';
		else cout << dijkstra() << '\n';
	}
	return 0;
}
