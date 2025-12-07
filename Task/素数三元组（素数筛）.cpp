#include <bits/stdc++.h>
#define n 1000000
using namespace std;
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	int t;
	cin >> t;
	bool prime[1000005];
	for (int i=1;i<=n;i++) prime[i] = 1;
	prime[0] = prime[1] = false;
	for (int i=2;i<=n;i++){
		if (prime[i]&&i<=sqrt(n)){
			for (int j=i*i;j<=n;j+=i){
				prime[j] = false;
			}
		}
	}
	int dp[1000005];
	for (int i=1;i<=n;i++) dp[i] = 0;
	for (int i=5;i<=n;i++){
		dp[i] = dp[i-1] + (prime[i]&&prime[i-2]);
	}
	while (t--){
		int a;
		cin >> a;
		cout << dp[a] << '\n';
	}
}
