/*#include <bits/stdc++.h>
  using namespace std;
  int n,m;
  int dp[60][30010];
  int price[60];
  int x[60];
  int main()
  {
  cin >> n >> m;
  for (int i=1;i<=m;i++){
  cin >> price[i] >> x[i];
  }
  for (int i=1;i<=m;i++)
  {
  for (int j=1;j<=n;j++)
  {
  if (j>=price[i]) dp[i][j] = max(dp[i-1][j],dp[i-1][j-price[i]]+x[i]*price[i]);
  else dp[i][j] = dp[i-1][j];
  }
  }
  cout << dp[m][n];
  return 0;
  }*/
//  dfs写法
#include <bits/stdc++.h>
using namespace std;
int n,m;
int book[60];
int price[60];
int x[60];
int ans = 0;
void dfs(int step)
{
	if (step==m+1)
	{
		int V = 0;
		for (int i=1;i<=m;i++){
			V += book[i]*price[i];
		}
		if (V<=n){
			int temp = 0;
			for (int i=1;i<=m;i++){
				if (book[i]==1){
					temp += x[i]*price[i];
				}
			}
			ans = max(ans,temp);
		}
		return;
	}
	book[step] = 0;
	dfs(step+1);
	book[step] = 1;
	dfs(step+1);
}
int main()
{
	cin >> n >> m;
	for (int i=1;i<=m;i++){
		cin >> price[i] >> x[i];
	}
	dfs(1);
	cout << ans;
}
