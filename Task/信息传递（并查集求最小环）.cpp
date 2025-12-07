#include <bits/stdc++.h>
using namespace std;
int n;
int fa[200005];
int ans = INT_MAX;
int cnt = 0;
int Find(int x)//路径未压缩
{
	cnt++;
	if (fa[x]==x) return x;
	else return Find(fa[x]);
}
int main()
{
	cin >> n;
	for (int i=1;i<=n;i++) fa[i] = i;
	for (int i=1;i<=n;i++){
		int x;
		cin >> x;
		cnt = 0;
		if (Find(x)==i){
			ans = min(ans,cnt);
		}else{
			fa[i] = x;
		}
	}
	cout << ans;
	return 0;
}
