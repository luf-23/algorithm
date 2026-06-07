#include <bits/stdc++.h>
using namespace std;
int BOOL[120];
vector<int>arr[120];
int n;
void dfs(int node)
{
	for (int i=0;i<arr[node].size();i++){
		BOOL[arr[node][i]]++;
		dfs(arr[node][i]);
	}
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n-1;i++){
		int x,y;
		cin >> x >> y;
		arr[x].push_back(y);
	}
	for (int i=1;i<=n;i++){
		dfs(i);
	}
	for (int i=0;i<=n;i++){
		if (BOOL[i]==n-1){
			cout << i;
			exit(0);
		}
	}
	cout << -1;
	return 0;
}
