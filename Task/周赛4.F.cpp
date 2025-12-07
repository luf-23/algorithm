#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n,x;
	cin >> n >> x;
	int num[3*n+1];
	int sum[3*n+1];
	int pre[3*n+1];
	pre[0] = sum[0] = 0;
	for (int i=1;i<=n;i++){
		cin >> num[i];
		num[n+i] = num[i];
		num[2*n+i] = num[i];
	}
	for (int i=1;i<=3*n;i++){
		pre[i] = pre[i-1] + num[i];
		sum[i] = sum[i-1] + (num[i]+1)*num[i]/2;
	}
	int l,r;
	int ans = 1;
	l = 1;
	r = 1;
	for (r=1;r<=3*n;r++){
		while (l<r&&pre[r]-pre[l]>x) l++;
		int ret = sum[r] - sum[l];
		int lft = x - (pre[r]-pre[l]);
		if (l!=1) ret += lft*(2*num[l]-lft+1)/2;
		ans = max(ans,ret);
	}
	cout << ans;
	return 0;
}
