#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		string str;
		cin >> str;
		int num[n+1];
		int ans = 1;
		for (int i=1;i<=n;i++) num[i] = str[i-1]-'0';
		for (int k=1;k<=n;k++){
			int tt[n+1];
			for (int i=1;i<=n;i++) tt[i] = num[i];
			int endd[2*n+5];
			for (int i=1;i<=2*n;i++) endd[i] = 0;
			int cnt = 0;
			for (int i=1;i<=n;i++){
				cnt += endd[i];
				tt[i] ^= (cnt&1);
				if (tt[i]==0&&i<=n-k+1){
					tt[i] = 1;
					endd[i+k]--;
					cnt++;
				}
			}
			int f = 1;
			for (int i=1;i<=n;i++) if (tt[i]!=1) f = 0;
			if (f) ans = k;
		}
		cout << ans << '\n';
	}
}
