#include <bits/stdc++.h>
using namespace std;
signed main(){
	//求左边的右边比自己大的位置
	int n;
	cin >> n;
	int ans1[n+1];
	int ans2[n+1];
	for (int i=1;i<=n;i++){
		ans1[i] = -1;
		ans2[i] = -1;
	}
	int num[n+1];
	for (int i=1;i<=n;i++) cin >> num[i];
	stack<int>stk;
	for (int i=1;i<=n;i++){
		while (!stk.empty()&&num[stk.top()]<=num[i]) stk.pop();
		if (!stk.empty()) ans1[i] = stk.top();
		stk.push(i);
	}
	while (!stk.empty()) stk.pop();
	for (int i=n;i>=1;i--){
		while (!stk.empty()&&num[stk.top()]<=num[i]) stk.pop();
		if (!stk.empty()) ans2[i] = stk.top();
		stk.push(i);
	}
	for (int i=1;i<=n;i++) cout << ans1[i] << ' ';
	cout << '\n';
	for (int i=1;i<=n;i++) cout << ans2[i] << ' ';
	cout << '\n';
	return 0;
}
