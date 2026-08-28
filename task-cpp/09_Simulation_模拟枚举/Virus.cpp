#include <bits/stdc++.h>
using namespace std;
struct Node{
	int x,y;
	int id;
};
double dis(Node a,Node b){
	double ans = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	return ans;
}
int main()
{
	int n,d;
	cin >> n >> d;
	Node node[n+1];
	for (int i=1;i<=n;i++){
		cin >> node[i].x >> node[i].y;
		node[i].id = i;
	}
	queue<Node>q;
	q.push(node[1]);
	int vis[n+1] = {0};
	while (!q.empty()){
		Node now = q.front();
		q.pop();
		if (vis[now.id]) continue;
		vis[now.id] = 1;
		for (int i=1;i<=n;i++){
			if (i!=now.id&&dis(now,node[i])<=d){
				
				q.push(node[i]);
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (vis[i]) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	return 0;
}
