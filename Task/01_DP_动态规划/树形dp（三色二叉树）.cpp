#include <bits/stdc++.h>
#define int long long
using namespace std;
string str;
vector<int>arr[500005];
int cur = 2;
int dpmin[500005][3];
int dpmax[500005][3];
//dfs建树
void pre(int node){
	int cnt = str[node]-'0';
	for (int i=1;i<=cnt;i++){
		arr[node].push_back(cur);
		cur++;
		pre(cur-1);
	}
}
void dfs(int node){
	dpmax[node][0] = 1;
	dpmin[node][0] = 1;
	for (auto ele : arr[node]) dfs(ele);
	if (arr[node].size()==1){
		for (int i=0;i<3;i++){
			int e = arr[node][0];
			int x = (i+1)%3;
			int y = (i+2)%3;
			dpmax[node][i] = max(dpmax[e][x],dpmax[e][y])+(i==0);
			dpmin[node][i] = min(dpmin[e][x],dpmin[e][y])+(i==0);
		}
	}else if (arr[node].size()==2){
		for (int i=0;i<3;i++){
			int e1 = arr[node][0];
			int e2 = arr[node][1];
			int x = (i+1)%3;
			int y = (i+2)%3;
			dpmax[node][i] = max(dpmax[e1][x]+dpmax[e2][y],dpmax[e1][y]+dpmax[e2][x])+(i==0);
			dpmin[node][i] = min(dpmin[e1][x]+dpmin[e2][y],dpmin[e1][y]+dpmin[e2][x])+(i==0);
		}
	}
}
signed main(){
	cin >> str;
	str = ' ' + str;
	pre(1);
	dfs(1);
	cout << max({dpmax[1][0],dpmax[1][1],dpmax[1][2]}) << ' ' << min({dpmin[1][0],dpmin[1][1],dpmin[1][2]});
	return 0;
}
