#include <bits/stdc++.h>
using namespace std;
struct Node{
	int x,y;
};
int dx[] = {0,1};
int dy[] = {1,0};
int vis[1050][1050];
int main()
{
	int n,m;
	cin >> n >> m;
	char mapp[n+1][m+1];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin >> mapp[i][j];
		}
	}
	vector<Node>arr[2];
	int now = 0;
	string str;
	arr[now].push_back({1,1});
	str += mapp[1][1];
	vis[1][1] = 1;
	for (int i=1;i<=n+m-2;i++){
		char minn = 'z';
		for (auto ele : arr[now]){
			for (int j=0;j<2;j++){
				int nx = ele.x + dx[j];
				int ny = ele.y + dy[j];
				if (nx>n||ny>m) continue;
				minn = min(minn,mapp[nx][ny]);
			}
		}
		str += minn;
		for (auto ele : arr[now]){
			for (int j=0;j<2;j++){
				int nx = ele.x + dx[j];
				int ny = ele.y + dy[j];
				if (nx>n||ny>m) continue;
				if (mapp[nx][ny]==minn&&!vis[nx][ny]){
					vis[nx][ny] = 1;
					arr[now^1].push_back({nx,ny});
				}
			}
		}
		arr[now].clear();
		now ^= 1;
	}
	cout << str;
	return 0;
}
