#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	int n;
	cin >> n;
	int num[n+1];
	for (int i=1;i<=n;i++) cin >> num[i];
	ll ans = 0;
	stack<int>stk;
	for (int i=1;i<=n;i++){
		while (!stk.empty()&&stk.top()<=num[i]){
			stk.pop();
		}
		ans += stk.size();
		stk.push(num[i]);
	}
	cout << ans;
	return 0;
}
