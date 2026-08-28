#include <bits/stdc++.h>
using namespace std;
vector<int> tt, cc;
int dp[1005]; 
//题目链接：https://www.luogu.com.cn/problem/P1833
signed main() {
	int t, n;
	int a1, a2, b1, b2;
	scanf("%d:%d %d:%d %d", &a1, &a2, &b1, &b2, &n);
	t = (b1 - a1) * 60 + b2 - a2;
	
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c == 0) c = 1000;
		int k = 1;
		while (c > 0) {
			int take = min(k, c);
			tt.push_back(a * take);
			cc.push_back(b * take);
			c -= take;
			k <<= 1;
		}
	}
	// 倒序更新
	for (int i = 0; i < tt.size(); i++) {
		for (int j = t; j >= 0; j--) {
			if (j >= tt[i]) {
				dp[j] = max(dp[j], dp[j - tt[i]] + cc[i]);
			}
		}
	}
	cout << dp[t];
	return 0;
}