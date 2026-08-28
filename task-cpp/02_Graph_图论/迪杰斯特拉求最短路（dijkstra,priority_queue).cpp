#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<pair<int,int>>arr[200005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
int dist[200005];
int vis[200005];
signed main()
{
	cin >> n;
	for (int i=1;i<=n-1;i++){
		int a,b,x;
		cin >> a >> b >> x;
		arr[i].push_back(make_pair(i+1,a));
		arr[i].push_back(make_pair(x,b));
	}
	auto dijkstra = [&]{
		for (int i=0;i<=n;i++) dist[i] = LONG_LONG_MAX;
		dist[1] = 0;
		pq.push(make_pair(0,1));
		while (!pq.empty()){
			int node = pq.top().second;
			pq.pop();
			if (vis[node]) continue;
			vis[node] = 1;
			for (int i=0;i<arr[node].size();i++){
				if (dist[arr[node][i].first]>dist[node]+arr[node][i].second){
					dist[arr[node][i].first] = dist[node] + arr[node][i].second;
					pq.push(make_pair(dist[arr[node][i].first],arr[node][i].first));
				}
			}
		}
		return dist[n];
	};
	cout << dijkstra();
	return 0;
}
