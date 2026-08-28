#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int cur;
int t[6000020][2];
int cnt[40];
//t[p][c]:从p号节点出发，通过边权为c的边能到达节点t[p][c]即nxt
void insert(int *num,int len){
	int p = 0;
	for (int i=1;i<=len;i++){
		if (!t[p][num[i]]) t[p][num[i]] = ++cur;
		p = t[p][num[i]];
	}
	
}
int query(int *num,int len){
	int p = 0;
	int ret = 0;
	for (int i=1;i<=len;i++){
		if (t[p][num[i]]){
			ret += (1<<(len-i));
			p = t[p][num[i]];
		}else{
			p = t[p][num[i]^1];
		}
	}
	return ret;
}
signed main(){
	cin >> n >> m;
	int a[n+1];
	int ans = 0;
	for (int i=1;i<=n;i++){
		int x;
		cin >> x;
		a[i] = x;
		int num[40];
		for (int j=1;j<=m;j++) num[j]=x%2,x/=2;
		int t[40];
		for (int j=1;j<=m;j++) t[j] = num[m-j+1];
		if (i>1) ans = max(ans,query(t,m));
		insert(t,m);
	}
	for (int i=0;i<=30;i++){
		for (int j=0;j<2;j++){
			cout << t[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << ans;
	return 0;
}
