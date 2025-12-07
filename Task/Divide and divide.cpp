#include <bits/stdc++.h>
#define int long long
using namespace std;
#define N 10000000
int mem[N];
int dfs(int x)
{
	if (x==1) return 0;
	if (x<N&&mem[x]) return mem[x]; 
	int ans = x;
	if (x&1) ans += dfs(x/2)+dfs(x/2+1);
	else ans += 2*dfs(x/2);
	if (x<N) return mem[x] = ans;
	else return ans;
}
signed main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	int n;
	cin >> n;
	int ans = dfs(n);
	cout << ans;
	return 0;
}
