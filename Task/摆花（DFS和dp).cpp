/*
  #include <bits/stdc++.h>
  using namespace std;
  using ll = long long;
  int n,m;
  ll dp[120][130];
  int a[120];
  int main()
  {
  cin >> n >> m;
  dp[0][0] = 1;
  for (int i=1;i<=n;i++) cin >> a[i];
  for (int i=1;i<=n;i++){
  for (int j=0;j<=m;j++){//j=0
  for (int k=0;k<=min(a[i],j);k++){
  dp[i][j] = (dp[i][j]+dp[i-1][j-k])%1000007;
  }
  //dp[i][j] %= 1000007;
  }
  }
  cout << dp[n][m];
  return 0;
  }
 */
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[120];
int mem[120][300];
int dfs(int step,int sum)
{
	if (mem[step][sum]) return mem[step][sum];
	if (sum==m) return 1;
	if (sum>m) return 0;
	if (step==n+1) return 0;
	int ans = 0;
	for (int i=0;i<=a[step];i++){
		ans = (ans+dfs(step+1,sum+i))%1000007;
	}
	return mem[step][sum] = ans;
}
int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	int ans = dfs(1,0);
	cout << ans;
	return 0;
}
