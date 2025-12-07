#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[35][150];
int Gcd(int a,int b){
	if (b>0) return Gcd(b,a%b);
	else return a;
}
signed main()
{
	int n;
	cin >> n;
	if (n==0){
		cout << "1/1";
		return 0;
	}
	for (int i=1;i<=4;i++) dp[1][i] = 1;
	for (int i=2;i<=n;i++){
		for (int j=i;j<=4*i;j++){
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j-2] + (j>=3?dp[i-1][j-3]:0) + (j>=4?dp[i-1][j-4]:0);
		}
	}
	int fz = 0;
	for (int i=3*n;i<=4*n;i++) fz += dp[n][i];
	int fm = pow(4,n);
	int GCD = Gcd(fz,fm);
	fz /= GCD;
	fm /= GCD;
	cout << fz << '/' << fm;
	return 0;
}
