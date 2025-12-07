#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[10][100][1<<10];
int CNT[1<<10];
int n,k;
//考虑到第i行，选了j个点，当前（这一行）状态为k时的方案数
//1：使得当前行状态合法
//2：使得上一行状态合法
//3：使得上一行和当前行构成的情况合法
//求每个数二进制下位数为1的个数，可以考虑先预处理，省去log
//int count(int x){
//	int cnt = 0;
//	while (x){
//		cnt += x&1;
//		x >>= 1;
//	}
//	return cnt;
//}
int lowbit(int x){
	return x&(-x);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> k;
	for (int i=1;i<(1<<n);i++){
		CNT[i] = CNT[i-lowbit(i)] + 1;
	}
	dp[0][0][0] = 1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=k;j++){
			for (int now=0;now<(1<<n);now++){
				if (now&(now<<1)||now&(now>>1)) continue;//1
				int cnt = CNT[now];
				for (int lst=0;lst<(1<<n);lst++){
					if (lst&(lst<<1)||lst&(lst>>1)) continue;//2
					if (lst&now||(lst>>1)&now||(lst<<1)&now) continue;//3
					if (j<cnt) continue;//3
					dp[i][j][now] += dp[i-1][j-cnt][lst];
				}
			}
		}
	}
	int ans = 0;
	for (int i=0;i<(1<<n);i++) ans += dp[n][k][i];
	cout << ans;
	return 0;
}
