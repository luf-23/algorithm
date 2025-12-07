#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int pos[n+1];
		for (int x,i=1;i<=n;i++){
			cin >> x;
			pos[x] = i;
		}
		string ans = "";
		int mn = n;
		int mx = 1;
		for (int i=1;i<=n;i++){
			mn = min(mn,pos[i]);
			mx = max(mx,pos[i]);
			if (mx-mn+1==i) ans += '1';
			else ans += '0';
		}
		cout << ans << '\n';
	}
	return 0;
}
/*You are given a permutation p=[p1,p2,…,pn] of integers from 1 to n. Let's call the number m (1≤m≤n) beautiful, if there exists two indices l,r (1≤l≤r≤n), such that the numbers [pl,pl+1,…,pr] is a permutation of numbers 1,2,…,m.
  
  For example, let p=[4,5,1,3,2,6]. In this case, the numbers 1,3,5,6 are beautiful and 2,4 are not. It is because:
  
  if l=3 and r=3 we will have a permutation [1] for m=1;
  if l=3 and r=5 we will have a permutation [1,3,2] for m=3;
  if l=1 and r=5 we will have a permutation [4,5,1,3,2] for m=5;
  if l=1 and r=6 we will have a permutation [4,5,1,3,2,6] for m=6;
  it is impossible to take some l and r, such that [pl,pl+1,…,pr] is a permutation of numbers 1,2,…,m for m=2 and for m=4.
  You are given a permutation p=[p1,p2,…,pn]. For all m (1≤m≤n) determine if it is a beautiful number or not.*/
